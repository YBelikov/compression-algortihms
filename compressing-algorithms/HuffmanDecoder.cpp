#include "HuffmanDecoder.h"

void HuffmanDecoder::decodeText(const CodeTree& huffmanTree, std::ostream& out) {
	auto node = huffmanTree.getRoot();
	int bit = inputStream.readWithoutEOF();
	try {
		while (true) {
			while (node->rightChild && node->leftChild) {
				if (bit == 0) {
					node = node->leftChild;
					bit = inputStream.readWithoutEOF();
				}
				else if (bit == 1) {
					node = node->rightChild;
					bit = inputStream.readWithoutEOF();
				}
			}
			int symbolCode = static_cast<int>(node->symbol);
			if (symbolCode == 0) {
				return;
			}
			out << node->symbol;
			node = huffmanTree.getRoot();
			}
		}
		catch(...){
			return;
		}
}
