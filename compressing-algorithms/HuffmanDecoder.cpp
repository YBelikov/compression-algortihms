#include "HuffmanDecoder.h"

void HuffmanDecoder::decodeText(const CodeTree& huffmanTree, std::ostream& out) 
{
	auto node = huffmanTree.getRoot();
	int bit = inputStream.readWithoutEOF();
	try 
	{
		while (true) 
		{
			while (node->rightChild && node->leftChild) 
			{
				if (bit == 0) 
				{
					node = node->leftChild;
					bit = inputStream.readWithoutEOF();
				}
				else if (bit == 1) 
				{
					node = node->rightChild;
					bit = inputStream.readWithoutEOF();
				}
			}
			int symbolCode = static_cast<int>(node->symbol);
			if (symbolCode == 0) 
			{
				return;
			}
			out << node->symbol;
			node = huffmanTree.getRoot();
		}
	} 
	catch(...)
	{
		return;
	}
}

std::string HuffmanDecoder::decodeString(const CodeTree& huffmanTree, std::string_view encodedString) 
{
	auto node = huffmanTree.getRoot();
	int index = 0;
	std::string decodedString;

	try
	{
		while (true)
		{
			while (node->leftChild && node->rightChild && index < encodedString.size())
			{
				if (encodedString[index] == '0')
				{
					node = node->leftChild;
					++index;
				}
				else if (encodedString[index] == '1')
				{
					node = node->rightChild;
					++index;
				}
			}
			int symbolCode = static_cast<int>(node->symbol);
			if (index >= encodedString.size()) 
			{
				decodedString.push_back(node->symbol);
				return decodedString;
			}
			
			if (symbolCode == 0)
			{
				return decodedString;
			}

			decodedString.push_back(node->symbol);
			node = huffmanTree.getRoot();
		}
	}
	catch (...)
	{
		return "";
	}
}
