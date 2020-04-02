#pragma once
#include "BitOutputStream.h"
#include "HuffmanCodeConverter.h"
#include <string>
#include <istream>

class HuffmanCoding {
public:
	HuffmanCoding(ostream& out) : outStream(out) {}
	void writeEncodedText(std::istream& in, HuffmanCodeConverter&);
private:
	BitOutputStream outStream;
	void writeCodeToStream(const std::string&);
};