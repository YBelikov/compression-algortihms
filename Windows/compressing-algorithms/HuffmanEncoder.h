#pragma once
#include "BitOutputStream.h"
#include "HuffmanCodeConverter.h"
#include <string>
#include <istream>

class HuffmanEncoder 
{

public:
	HuffmanEncoder(ostream& out) : outStream(out) {}
	void writeEncodedText(std::istream& in, HuffmanCodeConverter&);
	std::string encodeString(const std::string& inputString, HuffmanCodeConverter& converter);

private:
	void writeCodeToStream(const std::string&);

	BitOutputStream outStream;
};