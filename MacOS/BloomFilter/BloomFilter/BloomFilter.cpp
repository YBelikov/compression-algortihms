//
//  BloomFilter.cpp
//  BloomFilter
//
//  Created by Yuriy Belikov on 17.11.2022.
//

#include <stdio.h>
#include <cmath>
#include "BloomFilter.h"
#include "MurmurHash3.h"

BloomFilter::BloomFilter(int maxNumberOfItems, float probabilityThreshold)
{
    int bitArraySize = - ceil(maxNumberOfItems * log(probabilityThreshold)) / (log(2) * log(2));
    mFilter.resize(bitArraySize);
    std::fill(mFilter.begin(), mFilter.end(), 0);
    mNumberOfHashFunctions = round(static_cast<float>(bitArraySize) / maxNumberOfItems * log(2));
    std::fill(mHash, mHash + 2 * sizeof(uint64_t), 0);
}

bool BloomFilter::lookup(std::string_view word)
{
    hash(word);
    for (int i = 0; i < mNumberOfHashFunctions; ++i)
    {
        if (mFilter[calculateBitPosition(i)])
        {
            return true;
        }
    }
    return false;
}

void BloomFilter::insert(std::string_view word)
{
    hash(word);
    for (int i = 0; i < mNumberOfHashFunctions; ++i)
    {
        mFilter[calculateBitPosition(i)] = true;
    }
    std::fill(mHash, mHash + 2 * sizeof(uint64_t), 0);
}

void BloomFilter::hash(std::string_view word)
{
    MurmurHash3_x64_128(word.data(), static_cast<int>(word.size()), mHashingSeed, mHash);
}

uint32_t BloomFilter::calculateBitPosition(int indexOfHashFunction)
{
    return static_cast<uint32_t>((mHash[0] + mHash[1] * indexOfHashFunction) % mFilter.size());
}
