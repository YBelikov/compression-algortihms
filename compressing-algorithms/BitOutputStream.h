#pragma once
#include <cstdint>
#include <stdexcept>
#include <ostream>
using std::ostream;

class BitOutputStream {
private:
	ostream& outputStream;
	int currentByte;
	int bitCounter;
	const int numberOfBitsInByte = 8;
public:
	BitOutputStream(ostream& stream) : outputStream(stream), currentByte{ 0 }, bitCounter{0} {}
	void write(int);
	void finish();
};



