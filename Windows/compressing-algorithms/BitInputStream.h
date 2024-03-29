#pragma once
#include <istream>
using std::istream;

class BitInputStream 
{
public:
	int readWithoutEOF();
	BitInputStream(istream& in) : inputStream(in), bitsRemains{ 0 }, currentByte{0} {}

private:

	int bitsRemains;
	int currentByte;
	int read();
	istream& inputStream;
};

