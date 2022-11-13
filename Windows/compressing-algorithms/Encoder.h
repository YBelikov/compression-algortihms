#pragma once
#include <string>
#include <ostream>
using std::string;
using std::ostream;
using std::istream;

template<typename Algorithm>
class Encoder 
{
public:
	Encoder(ostream& out, istream& in): encodingAlgorithm(out, in) {}
	void encodeTextFile(const string& fileName);
	void encodeString(const string& text) { encodingAlgorithm.encodeString(text); }
	string encodedString() { return encodingAlgorithm.getEncodedString(); }
	string decodedString() { return encodingAlgorithm.getDecodedString(); }
	void writeDecodedText() { encodingAlgorithm.writeDecodedText(); }

private:
	Algorithm encodingAlgorithm;
};

