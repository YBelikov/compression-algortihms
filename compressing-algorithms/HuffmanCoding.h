#pragma once
#include <queue>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "BitOutputStream.h"

using std::priority_queue;
using std::pair;
using std::greater;
using std::unique_ptr;
using std::shared_ptr;
using std::string;
using std::vector;
using std::map;


struct HuffmanTreeNode {
	char symbol;
	size_t frequency;
	shared_ptr<HuffmanTreeNode> leftChild;
	shared_ptr<HuffmanTreeNode> rightChild;
	void insert(shared_ptr<HuffmanTreeNode>& node) {
		if (node->frequency >= frequency && rightChild) {
			rightChild->insert(node);
		} else if(node->frequency >= frequency && !rightChild) {
			rightChild = std::move(node);
			return;
		}else if (node->frequency < frequency && leftChild) {
			leftChild->insert(node);
		}else if(node->frequency < frequency && !leftChild) {
			leftChild = std::move(node);
			return;
		}
	}
	HuffmanTreeNode() = default;
	HuffmanTreeNode(HuffmanTreeNode&&) = default;
	HuffmanTreeNode(const HuffmanTreeNode&) = default;
	HuffmanTreeNode(char symbol_, size_t frequency_) : symbol{ symbol_ }, frequency{frequency_} {}
};

struct NodeComparator {
	bool operator()(shared_ptr<HuffmanTreeNode> a, shared_ptr<HuffmanTreeNode> b) {
		return a->frequency > b->frequency;
	}
};

class HuffmanCoding {
public:
	HuffmanCoding(ostream& out) : outStream(out){}
	void encodeString(const string&);
	void decodeString();
	string getEncodedString() const { return encodedString; }
	string getDecodedString(){
		decodeString();
		return decodedString; 
	}
private:
	
	shared_ptr<HuffmanTreeNode> root;
	priority_queue<shared_ptr<HuffmanTreeNode>, vector<shared_ptr<HuffmanTreeNode>>, NodeComparator> huffmanMinHeap;
	map<char, string> symbolAndCode;
	string codeOfSymbol;
	string encodedString;
	string decodedString;
	string initialString;
	BitOutputStream outStream;
 	void fillPriorityQueue(std::map<char, size_t>&);	
	void constructHuffmanCodingTree();
	void createSymbolsAndCodesTable(shared_ptr<HuffmanTreeNode>&, int);
	void buildEncodedString();
	void buildEncodedText();
	void writeCodeToStream(const string&);
};