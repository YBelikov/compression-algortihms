#pragma once
#include <istream>
using std::istream;

class BitInputStream {
public:
	int readWithoutEOF();
	BitInputStream(istream& in) : inputStream(in), bitsRemains{ 0 }, currentByte{0} {}
private:
	istream& inputStream;
	int bitsRemains;
	int currentByte;
	int read();
};

