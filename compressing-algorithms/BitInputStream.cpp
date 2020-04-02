#include "BitInputStream.h"
#include <stdexcept>
int BitInputStream::readWithoutEOF() {
	int bit = read();
	if (bit != -1) {
		return bit;
	}
	else {
		throw std::domain_error("Reach to the end of file");
	}
}

int BitInputStream::read() {
	if (currentByte == -1) {
		return -1;
	}
	if (bitsRemains == 0) {
		currentByte = inputStream.get();
		if (currentByte == EOF) return -1;
		
		bitsRemains = 8;
	}
	--bitsRemains;
	return (currentByte >> bitsRemains) & 1;
}