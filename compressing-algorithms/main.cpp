#include "Encoder.h"
#include "HuffmanCoding.h"
#include <iostream>

using std::cout;

int main() {
	Encoder<HuffmanCoding> encoder;
	string text = "BCAADDDCCACACAC";
	encoder.encodeString(text);
	cout << encoder.encodedString() << '\n';
	cout << encoder.decodedString() << '\n';
	return 0;
}