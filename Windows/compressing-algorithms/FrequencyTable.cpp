#include "FrequencyTable.h"

using std::string;

void FrequencyTable::countFrequencesOfSymbolsInStream(std::istream& in) 
{
	while (in) 
	{
		std::string lineOfText{};
		std::getline(in, lineOfText);
		lineOfText.append("\n");
		for (auto& c : lineOfText) 
		{
			++symbolFrequencies[string(1, c)];
		}
	}
}

void FrequencyTable::countFrequencesOfSymbolsInString(const std::string_view inputString)
{
	for (auto& c : inputString)
	{
		++symbolFrequencies[string(1, c)];
	}
}

void FrequencyTable::insertCharacterWithFrequency(const string& character, int frequency) 
{
	symbolFrequencies[character] = frequency;
}