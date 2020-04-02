#include "Encoder.h"
#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::ofstream;
using std::ifstream;

int main() {

	ofstream out("huffmanTest.txt", std::ios::binary);
	ifstream in("huffmanDecodedTest.txt", std::ios::binary);
	Encoder<HuffmanCoding> encoder(cout, in);
	string text = "BCAADDDCCACACAC";
	encoder.encodeString(text);
	encoder.writeDecodedText();
	//cout << encoder.decodedString() << '\n';
	return 0;
}