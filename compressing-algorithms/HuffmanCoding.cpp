#include "HuffmanCoding.h"
#include <iostream>

using std::make_unique;
using std::make_pair;
using std::make_shared;

void HuffmanCoding::encodeString(const string& text) {
	initialString = text;
	std::map<char, size_t> frequencesOfCharactersAppearanceInText;
	for (auto& symbol : text) {
		++frequencesOfCharactersAppearanceInText[symbol];
	}
	fillPriorityQueue(frequencesOfCharactersAppearanceInText);
	constructHuffmanCodingTree();
	createSymbolsAndCodesTable(root, 0);
	buildEncodedString();
}

void HuffmanCoding::fillPriorityQueue(std::map<char, size_t>& frequences) {
	for (auto& pair : frequences) {
		huffmanMinHeap.push(std::move(make_shared<HuffmanTreeNode>(pair.first, pair.second)));
	}
}

void HuffmanCoding::constructHuffmanCodingTree() {
	char symbolForSumOfFrequences = '$';
	
	while(huffmanMinHeap.size() > 1) {
		auto minimumFrequencePair = huffmanMinHeap.top();
		huffmanMinHeap.pop();
		auto secondMinimumFrequencePair = huffmanMinHeap.top();
		huffmanMinHeap.pop();
		shared_ptr<HuffmanTreeNode> newNode = make_shared<HuffmanTreeNode>();
		newNode->leftChild = minimumFrequencePair;
		newNode->rightChild = secondMinimumFrequencePair;
		newNode->symbol = symbolForSumOfFrequences;
		newNode->frequency = minimumFrequencePair->frequency + secondMinimumFrequencePair->frequency;
		huffmanMinHeap.push(newNode);

	}	
	root = huffmanMinHeap.top();
}

void HuffmanCoding::createSymbolsAndCodesTable(shared_ptr<HuffmanTreeNode>& node, int bound) {
	if (node->leftChild) {
		codeOfSymbol.insert(bound, "0");
		createSymbolsAndCodesTable(node->leftChild, bound + 1);
	}
	if (node->rightChild) {
		codeOfSymbol.insert(bound, "1");
		createSymbolsAndCodesTable(node->rightChild, bound + 1);
	}
	if(!node->rightChild && !node->leftChild) {
		string code{};
		for (int i = 0; i < bound; ++i) {
			code.push_back(codeOfSymbol[i]);
		}
		symbolAndCode[node->symbol] = code;
	}

}

void HuffmanCoding::buildEncodedString() {
	for (auto& symbol : initialString) {
		encodedString.append(symbolAndCode[symbol]);
	}
}

void HuffmanCoding::decodeString(){
	shared_ptr<HuffmanTreeNode> node = root;
	int index = 0;
	while (index < encodedString.size()) {
		while (node->rightChild && node->leftChild) {
			if (encodedString[index] == '0') {
				node = node->leftChild;
				++index;
			}
			else if (encodedString[index] == '1') {
				node = node->rightChild;
				++index;
			}
		}
		decodedString.push_back(node->symbol);
		node = root;

	}
}

