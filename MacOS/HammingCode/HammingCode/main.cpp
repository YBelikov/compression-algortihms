//
//  main.cpp
//  HammingCode
//
//  Created by Yuriy Belikov on 08.11.2022.
//

#include <iostream>
#include <string>
#include "HammingCodesGenerator.h"

int main(int argc, const char * argv[])
{
    const int WRONG_NUMBER_OF_ARGUMENTS = -1;
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments\n";
        return WRONG_NUMBER_OF_ARGUMENTS;
    }
    int parityBits = std::stoi(argv[1]);
    HammingCodesGenerator codeGenerator(parityBits);
    codeGenerator.createCodeGeneratorMatrix();
    codeGenerator.printMatrices();
    HammingCodesGenerator::Matrix input;
    std::cout << "Enter data that is to be encoded: \n";
    std::string code;
    std::cin >> code;
    for (const auto& bit : code)
    {
        input.push_back({ bit - '0' });
    }
    auto encodedData = codeGenerator.encode(input);
    std::cout << "Encoded data: ";
    for (int row = 0; row < encodedData.size(); ++row)
    {
        std::cout << encodedData[row][0];
    }
    std::cout <<'\n';
    std::cout << "Enter encoded data as it is was received: ";
    std::cin >> code;
    input.clear();
    for (const auto& bit : code)
    {
        input.push_back({ bit - '0' });
    }
    
    int errorPosition = codeGenerator.check(input);
    if (errorPosition == 0)
    {
        std::cout << "No errors\n";
    }
    else
    {
        std::cout << "Bit on a position " << errorPosition << ' ' << "is flipped\n";
        encodedData = codeGenerator.correct(encodedData, errorPosition);
        std::cout << "Corrected code: ";
        for (int row = 0; row < encodedData.size(); ++row)
        {
            std::cout << encodedData[row][0];
        }
        std::cout << '\n';
    }
    std::string decoded = codeGenerator.decode(encodedData);
    std::cout << "Decoded: " << decoded << '\n';
    
    return 0;
}
