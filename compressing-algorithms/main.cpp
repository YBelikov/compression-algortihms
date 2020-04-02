
#include <iostream>
#include <fstream>
#include "FrequencyTable.h"
#include "CodeTree.h"
#include "HuffmanCodeConverter.h"
#include "HuffmanCoding.h"
#include "HuffmanDecoder.h"

using std::cout;
using std::ofstream;
using std::ifstream;

int main() {

	ifstream in("textToEncode.txt");
	FrequencyTable table;
	table.countFrequencesOfSymbolsInStream(in);
	table.insertCharacterWithFrequency(static_cast<char>(256), 1);
	CodeTree huffmanTree;
	huffmanTree.buildCodeTree(table);
	HuffmanCodeConverter converter;
	converter.createCodes(huffmanTree);
	ofstream out("encodedText.txt", std::ios::binary);
	HuffmanCoding coding(out);
	in.close();
	in.open("textToEncode.txt");
	coding.writeEncodedText(in, converter);
	in.close();
	out.close();
	in.open("encodedText.txt", std::ios::binary);
	HuffmanDecoder decoder(in);
	decoder.decodeText(huffmanTree, cout);
	return 0;
}