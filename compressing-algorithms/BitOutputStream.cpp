#include "BitOutputStream.h"

void BitOutputStream::write(int bit) {
	if (bit != 0 && bit != 1) throw std::domain_error("bit value have to be 0 or 1");
	currentByte = (currentByte << 1) | bit;
	++bitCounter;
	if (bitCounter == numberOfBitsInByte) {
		outputStream.put(bit);
		currentByte = 0;
		bitCounter = 0;
	}
}

void BitOutputStream::finish() {
	while (bitCounter != 0) {
		write(0);
	}
}