//
//  HammingCodesGenerator.cpp
//  HammingCode
//
//  Created by Yuriy Belikov on 09.11.2022.
//

#include <stdio.h>
#include <math.h>
#include "HammingCodesGenerator.h"
#include <iostream>

HammingCodesGenerator::HammingCodesGenerator(int numberOfParityBits)
{
    mNumberOfParityBits = numberOfParityBits;
    createParityCheckMatrix();
}

void HammingCodesGenerator::createCodeGeneratorMatrix()
{
    Matrix I(mNumberOfTotalBits - mNumberOfParityBits);
    for (auto& row : I)
    {
        row.resize(mNumberOfTotalBits - mNumberOfParityBits);
        std::fill(row.begin(), row.end(), 0);
    }
    
    for (int row = 0 ; row < (mNumberOfTotalBits - mNumberOfParityBits); ++row)
    {
        for (int column = 0; column < (mNumberOfTotalBits - mNumberOfParityBits); ++column)
        {
            if (row == column)
            {
                I[row][column] = 1;
            }
        }
    }
    
    Matrix H_k(mNumberOfParityBits);
    for (auto& row : H_k)
    {
        row.resize(mNumberOfTotalBits - mNumberOfParityBits);
        std::fill(row.begin(), row.end(), 0);
    }
    
    for (int parityMatrixColumn = 0, column = 0; parityMatrixColumn < mNumberOfTotalBits; ++parityMatrixColumn)
    {
        if (std::find(mParityBitsCoverage.begin(), mParityBitsCoverage.end(), (parityMatrixColumn+ 1)) == mParityBitsCoverage.end())
        {
            for (int row = 0; row < mParityCheckMatrix.size(); ++row)
            {
                H_k[row][column] = mParityCheckMatrix[row][parityMatrixColumn];
            }
            ++column;
        }
    }
    
    int diagonalMatrixShift = 0;
    int parityMatrixShift = 0;
    for (int i = 0; i < mNumberOfTotalBits; ++i)
    {
        if(std::find(mParityBitsCoverage.begin(), mParityBitsCoverage.end(), (i + 1)) != mParityBitsCoverage.end())
        {
            mCodeGeneratorMatrix.push_back(H_k[parityMatrixShift]);
            ++parityMatrixShift;
        }
        else
        {
            mCodeGeneratorMatrix.push_back(I[diagonalMatrixShift]);
            ++diagonalMatrixShift;
        }
    }
}

void HammingCodesGenerator::createParityCheckMatrix()
{
    mNumberOfTotalBits = pow(2, mNumberOfParityBits) - 1;
    for (int i = 1; i <= mNumberOfTotalBits; ++i)
    {
        if ((i & (i - 1)) == 0)
        {
            mParityBitsCoverage.push_back(i);
        }
    }
    
    mParityCheckMatrix.resize(mNumberOfParityBits);
    for (auto& row : mParityCheckMatrix)
    {
        row.resize(mNumberOfTotalBits);
        std::fill(row.begin(), row.end(), 0);
    }
    
    int row = 0;
    for (auto& coverage : mParityBitsCoverage)
    {
        for (int column = coverage - 1; column < mNumberOfTotalBits; column += coverage)
        {
            int shift = 0;
        	for (; shift < coverage && column + shift < mNumberOfTotalBits; ++shift)
        	{
            	mParityCheckMatrix[row][column + shift] = 1;
        	}
            column = column + shift;
        }
        ++row;
    }
}

HammingCodesGenerator::Matrix HammingCodesGenerator::encode(const Matrix& data)
{
    Matrix result = multiply(mCodeGeneratorMatrix, data);
    for (int row = 0; row < result.size(); ++row)
    {
        result[row][0] = result[row][0] % 2;
    }
    return result;
}

void HammingCodesGenerator::printMatrices()
{
    std::cout << "G\n";
    for (auto& row : mCodeGeneratorMatrix)
    {
        for (auto& elt : row)
        {
            std::cout << elt << ' ';
        }
        std::cout << '\n';
    }
    
    std::cout << "H\n";
    for (auto& row : mParityCheckMatrix)
    {
        for (auto& elt : row)
        {
            std::cout << elt << ' ';
        }
        std::cout << '\n';
    }
}

HammingCodesGenerator::Matrix HammingCodesGenerator::multiply(const Matrix& a , const Matrix& b)
{
    Matrix result(a.size());
    for (auto& row : result)
    {
        row.resize(b[0].size());
        std::fill(row.begin(), row.end(), 0);
    }
    
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b[0].size(); j++)
        {
            for(int k = 0; k < a[0].size(); k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int HammingCodesGenerator::check(const Matrix& data)
{
    Matrix result = multiply(mParityCheckMatrix, data);
    for (auto& elt : result)
    {
        elt[0] %= 2;
    }
    int sum = 0;
    for (const auto& row : result)
    {
        for (const auto& elt : row)
        {
            sum += elt;
        }
    }
    
    if (sum == 0)
    {
        return 0;
    }
    int flippedBit = 0;
    bool found = true;
    for (int column = 0; column < mParityCheckMatrix[0].size() && found; ++column)
    {
        for (int row = 0; row < mParityCheckMatrix.size(); ++row)
        {
            if (mParityCheckMatrix[row][column] != result[row][0])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            flippedBit = column + 1;;
            break;
        }
        else
        {
            found = true;
        }
    }
    return flippedBit;
}

std::string HammingCodesGenerator::decode(HammingCodesGenerator::Matrix& code)
{
    std::string decoded;
    for (int i = 0; i < code.size(); ++i)
    {
        if (((i + 1) & i) != 0)
        {
            decoded.push_back(std::to_string(code[i][0])[0]);
        }
    }
    return decoded;
}

HammingCodesGenerator::Matrix HammingCodesGenerator::correct(HammingCodesGenerator::Matrix& code, int errorPosition)
{
    if (code[errorPosition - 1][0] == 0)
    {
        code[errorPosition][0] = 1;
    }
    else
    {
        code[errorPosition][0] = 0;
    }
    return code;
}
