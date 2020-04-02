
#include <iostream>
#include <fstream>
#include "FrequencyTable.h"
#include "CodeTree.h"
#include "HuffmanCodeConverter.h"
#include "HuffmanCoding.h"

using std::cout;
using std::ofstream;
using std::ifstream;

int main() {

	ifstream in("textToEncode.txt");
	FrequencyTable table;
	table.countFrequencesOfSymbolsInStream(in);
	CodeTree huffmanTree;
	huffmanTree.buildCodeTree(table);
	HuffmanCodeConverter converter;
	converter.createCodes(huffmanTree);
	ofstream out("encodedText.txt", std::ios::binary);
	HuffmanCoding coding(out);
	in.close();
	in.open("textToEncode.txt");
	coding.writeEncodedText(in, converter);
	return 0;
}