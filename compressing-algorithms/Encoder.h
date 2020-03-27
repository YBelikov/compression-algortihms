#pragma once
#include <string>

using std::string;

template<typename Algorithm>
class Encoder {
public:
	void encodeTextFile(const string& fileName);
	void encodeString(const string& text) { encodingAlgorithm.encodeString(text); }
	string encodedString() { return encodingAlgorithm.getEncodedString(); }
	string decodedString() { return encodingAlgorithm.getDecodedString(); }
private:
	Algorithm encodingAlgorithm;
};
