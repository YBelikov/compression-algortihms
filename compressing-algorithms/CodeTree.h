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
	auto getRoot() const { return root; }
private:

	void fillHeap(FrequencyTable&);
	void constructTree();
	priority_queue<shared_ptr<HuffmanTreeNode>, vector<shared_ptr<HuffmanTreeNode>>, NodeComparator> huffmanMinHeap;
	shared_ptr<HuffmanTreeNode> root;
};

