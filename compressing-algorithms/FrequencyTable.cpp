#include "FrequencyTable.h"
void FrequencyTable::countFrequencesOfSymbolsInStream(std::istream& in) {
	while (in) {
		std::string lineOfText{};
		std::getline(in, lineOfText);
		for (auto& c : lineOfText) {
			++symbolFrequencies[c];
		}
	}
}

void FrequencyTable::insertCharacterWithFrequency(char character, int frequency) {
	symbolFrequencies[character] = frequency;
}