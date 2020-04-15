#include "FrequencyTable.h"
void FrequencyTable::countFrequencesOfSymbolsInStream(std::istream& in) {
	while (in) {
		std::string lineOfText{};
		std::getline(in, lineOfText);
		lineOfText.append("\n");
		for (auto& c : lineOfText) {
			++symbolFrequencies[c];
		}
	}
}

void FrequencyTable::insertCharacterWithFrequency(char character, int frequency) {
	symbolFrequencies[character] = frequency;
}