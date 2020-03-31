#include "Encoder.h"
#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::ofstream;

int main() {

	ofstream out("huffmanTest.txt", std::ios::binary);
	Encoder<HuffmanCoding> encoder(out);
	string text = "BCAADDDCCACACAC";
	encoder.encodeString(text);
	cout << encoder.encodedString() << '\n';
	//cout << encoder.decodedString() << '\n';
	return 0;
}