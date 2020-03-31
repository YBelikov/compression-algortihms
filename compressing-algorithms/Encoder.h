#pragma once
#include <string>
#include <ostream>
using std::string;
using std::ostream;

template<typename Algorithm>
class Encoder {
public:
	Encoder(ostream& out): encodingAlgorithm(out) {}

	void encodeTextFile(const string& fileName);
	void encodeString(const string& text) { encodingAlgorithm.encodeString(text); }
	string encodedString() { return encodingAlgorithm.getEncodedString(); }
	string decodedString() { return encodingAlgorithm.getDecodedString(); }
private:

	Algorithm encodingAlgorithm;
};

