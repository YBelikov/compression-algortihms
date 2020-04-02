//#include "HuffmanCoding.h"
//#include <iostream>
//
//using std::make_unique;
//using std::make_pair;
//using std::make_shared;
//
//void HuffmanCoding::encodeString(const string& text) {
//	initialString = text;
//
//	
//	constructHuffmanCodingTree();
//	//createSymbolsAndCodesTable(root, 0);
//	buildEncodedString();
//	buildEncodedText();
//	
//}
//
//
//void HuffmanCoding::constructHuffmanCodingTree() {
//	
//}
//
////void HuffmanCoding::createSymbolsAndCodesTable(shared_ptr<HuffmanTreeNode>& node, int bound) {
////	if (node->leftChild) {
////		codeOfSymbol.insert(bound, "0");
////		createSymbolsAndCodesTable(node->leftChild, bound + 1);
////	}
////	if (node->rightChild) {
////		codeOfSymbol.insert(bound, "1");
////		createSymbolsAndCodesTable(node->rightChild, bound + 1);
////	}
////	if(!node->rightChild && !node->leftChild) {
////		string code{};
////		for (int i = 0; i < bound; ++i) {
////			code.push_back(codeOfSymbol[i]);
////		}
////		symbolAndCode[node->symbol] = code;
////	}
////
////}
//
////void HuffmanCoding::buildEncodedString() {
////	for (auto& symbol : initialString) {
////		encodedString.append(symbolAndCode[symbol]);
////	}
////}
////
////void HuffmanCoding::buildEncodedText() {
////	for (auto& symbol : initialString) {
////		string symbolCode = symbolAndCode[symbol];
////		writeCodeToStream(symbolCode);
////	}
////}
//
//void HuffmanCoding::writeCodeToStream(const string& code) {
//	for (auto& c : code) {
//		if (c == '0') outStream.write(0);
//		else if (c == '1') outStream.write(1);
//	}
//}
//
////void HuffmanCoding::writeDecodedText() {
////	shared_ptr<HuffmanTreeNode> node = root;
////	try {
////		while (true) {
////			int bit = inputStream.readWithoutEOF();
////			while (node->rightChild && node->leftChild) {
////				if (bit == 0) {
////					node = node->leftChild;
////					bit = inputStream.readWithoutEOF();
////				}
////				else if (bit == 1) {
////					node = node->rightChild;
////					bit = inputStream.readWithoutEOF();
////				}
////			}
////			std::cout << node->symbol;
////			node = root;
////		}
////	}
////	catch(...){
////		return;
////	}
////}
//
////void HuffmanCoding::decodeString(){
////	shared_ptr<HuffmanTreeNode> node = root;
////	int index = 0;
////	while (index < encodedString.size()) {
////		while (node->rightChild && node->leftChild) {
////			if (encodedString[index] == '0') {
////				node = node->leftChild;
////				++index;
////			}
////			else if (encodedString[index] == '1') {
////				node = node->rightChild;
////				++index;
////			}
////		}
////		decodedString.push_back(node->symbol);
////		node = root;
////	}
////}
//
