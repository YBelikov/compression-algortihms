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
			std::string symbol(1, character);
			writeCodeToStream(converter.getCodeOfCharacter(symbol));
		}
	}
	string symbol(1, static_cast<char>(256));
	writeCodeToStream(converter.getCodeOfCharacter(symbol));
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
			string symbol(1, character);
			encodedString.append(converter.getCodeOfCharacter(symbol));
		});
	return encodedString;
}
