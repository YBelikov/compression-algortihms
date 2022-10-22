#include "HuffmanEncoder.h"
#include <iostream>

using std::string;

void HuffmanEncoder::writeEncodedText(std::istream& in, HuffmanCodeConverter& converter) 
{
	while (in) 
	{
		string lineOfText{};
		std::getline(in, lineOfText);
		lineOfText.append("\n");
		for (auto& character : lineOfText) 
		{
			writeCodeToStream(converter.getCodeOfCharacter(character));
		}
	}
	writeCodeToStream(converter.getCodeOfCharacter(static_cast<char>(256)));
	outStream.finish();
}

void HuffmanEncoder::writeCodeToStream(const string& code) 
{
	for (auto& c : code) 
	{
		if (c == '0')
		{
			outStream.write(0);
		}
		else if (c == '1') 
		{
			outStream.write(1);
		}
	}
}

std::string HuffmanEncoder::encodeString(const std::string& inputString, HuffmanCodeConverter& converter) 
{
	std::string encodedString;
	std::for_each(inputString.begin(), inputString.end(), [&](const auto& character) 
		{
			encodedString.append(converter.getCodeOfCharacter(character));
		});
	return encodedString;
}
