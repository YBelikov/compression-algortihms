//
//  BloomFilter.h
//  BloomFilter
//
//  Created by Yuriy Belikov on 17.11.2022.
//

#ifndef BloomFilter_h
#define BloomFilter_h

#include <vector>
#include <string_view>

class BloomFilter
{
public:
    BloomFilter(int, float);
    bool lookup(std::string_view word);
    void insert(std::string_view word);
    const int getNumberOfHashFunctions() const noexcept { return mNumberOfHashFunctions; }
    
private:
    void hash(std::string_view word);
    uint32_t calculateBitPosition(int indexOfHashFunction);
    
    int mNumberOfHashFunctions;
    std::vector<bool> mFilter;
    uint64_t mHash[2];
    const uint32_t mHashingSeed = 42;
};

#endif /* BloomFilter_h */
