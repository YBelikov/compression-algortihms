#include <iostream>
#include <fstream>
#include <filesystem>
#include "FrequencyTable.h"
#include "CodeTree.h"
#include "HuffmanCodeConverter.h"
#include "HuffmanEncoder.h"
#include "HuffmanDecoder.h"

using std::cout;
using std::ofstream;
using std::ifstream;
using std::filesystem::path;
using std::string;

int main(int argc, char** argv) {
	const string encodedFilePostfix = "_encoded";
	const string decodedFilePostfix = "_decoded";
	const string fileCompressionMode = "--file";
	const string keyboard = "--keyboard";

	std::string compressionMode = argv[1];
	
	
	if (compressionMode == fileCompressionMode)
	{
		path pathToTheFile = path(argv[2]);

		ifstream in(pathToTheFile);
		FrequencyTable table;
		table.countFrequencesOfSymbolsInStream(in);
		table.insertCharacterWithFrequency(static_cast<char>(256), 1);
		CodeTree huffmanTree;
		huffmanTree.buildCodeTree(table);
		HuffmanCodeConverter converter;
		converter.createCodes(huffmanTree);
		std::cout << converter;
		path pathToEncodedFile = pathToTheFile;
		pathToEncodedFile.replace_filename(pathToEncodedFile.stem().string() + encodedFilePostfix + pathToEncodedFile.extension().string());

		ofstream out(pathToEncodedFile, std::ios::binary);
		HuffmanEncoder coding(out);
		in.close();
		in.open(pathToTheFile);
		coding.writeEncodedText(in, converter);
		in.close();
		out.close();

		path pathToTheDecodedFile = pathToTheFile;
		pathToTheDecodedFile.replace_filename(pathToTheDecodedFile.stem().string() + decodedFilePostfix + pathToTheDecodedFile.extension().string());

		in.open(pathToEncodedFile, std::ios::binary);
		out = ofstream(pathToTheDecodedFile);
		HuffmanDecoder decoder(in);
		decoder.decodeText(huffmanTree, out);
	}
	else
	{
		std::string text;
		std::string inputString;
		std::cout << "Enter your string here: ";
		std::getline(std::cin, text);

		FrequencyTable table;
		table.countFrequencesOfSymbolsInString(text);
		CodeTree huffmanTree;
		huffmanTree.buildCodeTree(table);
		HuffmanCodeConverter converter;
		converter.createCodes(huffmanTree);
		std::cout << converter;
		HuffmanEncoder encoder(std::cout);
		std::string encodedString = encoder.encodeString(text, converter);
		std::cout << encodedString << '\n';
		HuffmanDecoder decoder(std::cin);
		std::cout << decoder.decodeString(huffmanTree, encodedString);
	}
	return 0;
}