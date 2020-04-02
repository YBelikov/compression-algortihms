#include "HuffmanCoding.h"
#include <iostream>
using std::string;


void HuffmanCoding::writeEncodedText(std::istream& in, HuffmanCodeConverter& converter) {
	while (in) {
		string lineOfText{};
		std::getline(in, lineOfText);
		for (auto& character : lineOfText) {
			std::cout << converter.getCodeOfCharacter(character);
			writeCodeToStream(converter.getCodeOfCharacter(character));
		}
	}
	writeCodeToStream(converter.getCodeOfCharacter(static_cast<char>(256)));
	outStream.finish();
}

void HuffmanCoding::writeCodeToStream(const string& code) {
	for (auto& c : code) {
		if (c == '0') outStream.write(0);
		else if (c == '1') outStream.write(1);
	}
}

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
