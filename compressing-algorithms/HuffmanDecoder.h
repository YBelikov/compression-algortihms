#pragma once
#include "BitInputStream.h"
#include "CodeTree.h"

class HuffmanDecoder {
public:
	HuffmanDecoder(std::istream& in) : inputStream{ in } {}
	void decodeText(const CodeTree&, std::ostream&);
private:
	BitInputStream inputStream;
};
