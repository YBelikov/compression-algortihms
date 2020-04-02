//#pragma once
//
//#include <memory>
//#include <string>
//
//
//#include "BitOutputStream.h"
//#include "BitInputStream.h"
//
//
//
//using std::pair;
//
//
//
//using std::string;
//
//
//
//
//
//
//class HuffmanCoding {
//public:
//	HuffmanCoding(ostream& out, istream& in) : outStream(out), inputStream{ in }{}
//	void encodeString(const string&);
//	/*void decodeString();*/
//	string getEncodedString() const { return encodedString; }
//	string getDecodedString(){
//		decodeString();
//		return decodedString; 
//	}
//	/*void writeDecodedText();*/
//private:
//	
//	
//	
//	//map<char, string> symbolAndCode;
//	string codeOfSymbol;
//	string encodedString;
//	string decodedString;
//	string initialString;
//	BitOutputStream outStream;
//	BitInputStream inputStream;
//
//	void constructHuffmanCodingTree();
////	void createSymbolsAndCodesTable(shared_ptr<HuffmanTreeNode>&, int);
//	/*void buildEncodedString();
//	void buildEncodedText();*/
//	void writeCodeToStream(const string&);
//};