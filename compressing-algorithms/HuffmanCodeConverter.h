#pragma once
#include <map>
#include <string>
#include "CodeTree.h"

class HuffmanCodeConverter 
{
public:
	void createCodes(const CodeTree&);
	std::string getCodeOfCharacter(const std::string&);
	friend std::ostream& operator<< (std::ostream& os, const HuffmanCodeConverter&);

private:
	void calculateCodes(shared_ptr<HuffmanTreeNode>&, int);
	std::map<std::string, std::string> charactersAndCodes;
	std::string codeString;
};