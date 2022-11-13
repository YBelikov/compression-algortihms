#include "HuffmanCodeConverter.h"
#include <iostream>

void HuffmanCodeConverter::createCodes(const CodeTree& tree) 
{
	auto root = tree.getRoot();
	calculateCodes(root, 0);
}

std::ostream& operator<< (std::ostream& os, const HuffmanCodeConverter& converter)
{
	for (auto&& [character, code] : converter.charactersAndCodes)
	{
		os << character << " - " << code << '\n';
	}
	os << '\n';
	return os;
}


void HuffmanCodeConverter::calculateCodes(std::shared_ptr<HuffmanTreeNode>& node, int bound) 
{
	if (node->leftChild) 
	{
		codeString.insert(bound, "0");
		calculateCodes(node->leftChild, bound + 1);
	}

	if (node->rightChild) 
	{
		codeString.insert(bound, "1");
		calculateCodes(node->rightChild, bound + 1);
	}
	if(!node->rightChild && !node->leftChild) 
	{
		std::string code{};
		for (int i = 0; i < bound; ++i) 
		{
			code.push_back(codeString[i]);
		}
		charactersAndCodes[node->symbol] = code;
	}
}

std::string HuffmanCodeConverter::getCodeOfCharacter(const string& character)
{
	return charactersAndCodes[character];
}