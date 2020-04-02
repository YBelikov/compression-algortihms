#pragma once
#include <map>
#include <istream>
#include <iterator>
#include <string>


class FrequencyTable {
public:
	auto begin() { return std::begin(symbolFrequencies); }
	auto end() { return std::end(symbolFrequencies); }
	auto cbegin() const { return std::cbegin(symbolFrequencies); }
	auto ñend() const { return std::cend(symbolFrequencies); }
	

	FrequencyTable() = default;
	FrequencyTable(const FrequencyTable&) = default;
	void countFrequencesOfSymbolsInStream(std::istream& in);
private:
	std::map<char, int> symbolFrequencies;
};


void FrequencyTable::countFrequencesOfSymbolsInStream(std::istream& in) {
	while (in) {
		std::string lineOfText{};
		std::getline(in, lineOfText);
		for (auto& c : lineOfText) {
			++symbolFrequencies[c];
		}
	}
}