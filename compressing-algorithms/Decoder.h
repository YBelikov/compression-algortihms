#pragma once

template<typename DecodingAlgortihm>
class Decoder {
public:
	Decoder(istream& in) : decoder(in){}
	void writeDecodedTextToStream(ostream& out) {decoder.writeDecodedText}
private:
	DecodingAlgortihm decoder;
};