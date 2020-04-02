
#include <iostream>
#include <fstream>
#include "FrequencyTable.h"
#include "CodeTree.h"
#include "HuffmanCodeConverter.h"

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
	return 0;
}