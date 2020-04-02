
#include <iostream>
#include <fstream>
#include "FrequencyTable.h"
#include "CodeTree.h"

using std::cout;
using std::ofstream;
using std::ifstream;

int main() {

	ifstream in("textToEncode.txt");
	FrequencyTable table;
	table.countFrequencesOfSymbolsInStream(in);
	CodeTree huffmanTree;
	huffmanTree.buildCodeTree(table);
	return 0;
}