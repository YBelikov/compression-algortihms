#include "HuffmanCodeConverter.h"
#include <iostream>

void HuffmanCodeConverter::createCodes(const CodeTree& tree) {
	auto root = tree.getRoot();
	calculateCodes(root, 0);
	for (auto& x : charactersAndCodes) {
		std::cout << x.first << '|' << x.second << '\n';
	}
}

void HuffmanCodeConverter::calculateCodes(std::shared_ptr<HuffmanTreeNode>& node, int bound) {
		if (node->leftChild) {
		codeString.insert(bound, "0");
		calculateCodes(node->leftChild, bound + 1);
	}
	if (node->rightChild) {
		codeString.insert(bound, "1");
		calculateCodes(node->rightChild, bound + 1);
	}
	if(!node->rightChild && !node->leftChild) {
		std::string code{};
		for (int i = 0; i < bound; ++i) {
			code.push_back(codeString[i]);
		}
		charactersAndCodes[node->symbol] = code;
	}
}

std::string HuffmanCodeConverter::getCodeOfCharacter(char character) {
	return charactersAndCodes[character];
}