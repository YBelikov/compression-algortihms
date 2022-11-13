//
//  HammingCodesGenerator.h
//  HammingCode
//
//  Created by Yuriy Belikov on 09.11.2022.
//

#ifndef HammingCodesGenerator_h
#define HammingCodesGenerator_h

#include <vector>

class HammingCodesGenerator
{

public:
    using Matrix = std::vector<std::vector<int>>;
	
    explicit HammingCodesGenerator(int numberOfParityBits);
    void createCodeGeneratorMatrix();
    void printMatrices();
    Matrix encode(const Matrix&);
    std::string decode(Matrix& code);
    Matrix correct(Matrix& code, int errorPosition);
    int check(const Matrix&);
    
private:
    void createParityCheckMatrix();
    Matrix multiply(const Matrix&, const Matrix&);
    
    int mNumberOfParityBits;
    int mNumberOfTotalBits;
    Matrix mCodeGeneratorMatrix;
    Matrix mParityCheckMatrix;
    std::vector<int> mParityBitsCoverage;
};


#endif /* HammingCodesGenerator_h */
