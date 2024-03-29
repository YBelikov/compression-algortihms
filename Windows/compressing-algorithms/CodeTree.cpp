#include "CodeTree.h"

using std::string;

void CodeTree::buildCodeTree(FrequencyTable& table) 
{
	fillHeap(table);
	constructTree();
}

void CodeTree::fillHeap(FrequencyTable& table) 
{
	for (auto& pair : table) 
	{
		huffmanMinHeap.push(std::move(make_shared<HuffmanTreeNode>(pair.first, pair.second)));
	}
}

void CodeTree::constructTree() 
{
	while (huffmanMinHeap.size() > 1) 
	{
		auto minimumFrequencePair = huffmanMinHeap.top();
		huffmanMinHeap.pop();
		auto secondMinimumFrequencePair = huffmanMinHeap.top();
		huffmanMinHeap.pop();
		shared_ptr<HuffmanTreeNode> newNode = make_shared<HuffmanTreeNode>();
		newNode->leftChild = minimumFrequencePair;
		newNode->rightChild = secondMinimumFrequencePair;
		newNode->symbol = minimumFrequencePair->symbol + secondMinimumFrequencePair->symbol;
		newNode->frequency = minimumFrequencePair->frequency + secondMinimumFrequencePair->frequency;
		huffmanMinHeap.push(newNode);

	}
	root = huffmanMinHeap.top();
}
