#pragma once
#include <map>
#include <string>
#include "CodeTree.h"

class HuffmanCodeConverter {
public:
	void createCodes(const CodeTree&);
	std::string getCodeOfCharacter(char);
private:
	void calculateCodes(shared_ptr<HuffmanTreeNode>&, int);
	std::map<char, std::string> charactersAndCodes;
	std::string codeString;
};