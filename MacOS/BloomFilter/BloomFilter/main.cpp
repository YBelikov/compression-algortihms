//
//  main.cpp
//  BloomFilter
//
//  Created by Yuriy Belikov on 17.11.2022.
//

#include <iostream>
#include "BloomFilter.h"

int main(int argc, const char * argv[]) {
 
    std::cout << "Enter the threshold of false positive probability (must be in interval [0; 1]): ";
    float threshold = 0;
    std::cin >> threshold;
    int maxNumberOfItems = 0;
    std::cout << "Enter number of max items to store: ";
    std::cin >> maxNumberOfItems;
    BloomFilter bloomFilter(maxNumberOfItems, threshold);
    std::string word;
    
    while(true)
    {
        std::cin >> word;
        auto numberOfHashFunctions = bloomFilter.getNumberOfHashFunctions();
        if (numberOfHashFunctions < 1)
        {
            std::cout << "Filter is too small! Number of hash functions in filter: " << numberOfHashFunctions << '\n';
            return -1;
        }
        
        if (bloomFilter.lookup(word))
        {
            std::cout << "Encountered duplicate: " << word << '\n';
        }
        else
        {
            std::cout << "New word saved: " << word << '\n';
            bloomFilter.insert(word);
        }
    }

    return 0;
}
