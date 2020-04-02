#pragma once
#include <memory>
#include <vector>
#include <queue>
#include "FrequencyTable.h"

using std::priority_queue;
using std::shared_ptr;
using std::vector;
using std::greater;
using std::make_shared;

struct HuffmanTreeNode {
	char symbol;
	size_t frequency;
	shared_ptr<HuffmanTreeNode> leftChild;
	shared_ptr<HuffmanTreeNode> rightChild;
	void insert(shared_ptr<HuffmanTreeNode>& node) {
		if (node->frequency >= frequency && rightChild) {
			rightChild->insert(node);
		}
		else if (node->frequency >= frequency && !rightChild) {
			rightChild = std::move(node);
			return;
		}
		else if (node->frequency < frequency && leftChild) {
			leftChild->insert(node);
		}
		else if (node->frequency < frequency && !leftChild) {
			leftChild = std::move(node);
			return;
		}
	}
	HuffmanTreeNode() = default;
	HuffmanTreeNode(HuffmanTreeNode&&) = default;
	HuffmanTreeNode(const HuffmanTreeNode&) = default;
	HuffmanTreeNode(char symbol_, size_t frequency_) : symbol{ symbol_ }, frequency{ frequency_ } {}
};

struct NodeComparator {
	bool operator()(shared_ptr<HuffmanTreeNode> a, shared_ptr<HuffmanTreeNode> b) {
		return a->frequency > b->frequency;
	}
};

class CodeTree {
public:

	void buildCodeTree(FrequencyTable&);
private:

	void fillHeap(FrequencyTable&);
	void constructTree();
	priority_queue<shared_ptr<HuffmanTreeNode>, vector<shared_ptr<HuffmanTreeNode>>, NodeComparator> huffmanMinHeap;
	shared_ptr<HuffmanTreeNode> root;
};

void CodeTree::buildCodeTree(FrequencyTable& table) {
	fillHeap(table);
	constructTree();
}

void CodeTree::fillHeap(FrequencyTable& table) {
	for (auto& pair : table) {
		huffmanMinHeap.push(std::move(make_shared<HuffmanTreeNode>(pair.first, pair.second)));
	}
}

void CodeTree::constructTree() {
	char symbolForSumOfFrequences = '$';

	while (huffmanMinHeap.size() > 1) {
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