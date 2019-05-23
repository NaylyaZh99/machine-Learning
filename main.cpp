#include <iostream>
#include <vector>
#include <cmath>
#include "headers/matrix.h"
#include "headers/model.h"

int main(void) {
	int countOfVec, xLen, yLen;
    std::vector< std::vector<double> > xVector, yVector;
    std::vector<double> xTest, yTest;
    std::cout << "Enter number of vectors:" << std::endl;
    std::cin >> countOfVec;
    std::cout << "Enter size of vectors x:" << std::endl;
    std::cin >> xLen;
    std::cout << "Enter size of vectors y:" << std::endl;
     std::cin >> yLen;
	
	Model neuron(yLen, xLen);
    xVector.resize(countOfVec, std::vector<double>(xLen));
    yVector.resize(countOfVec, std::vector<double>(yLen));
    xTest.resize(xLen);
    yTest.resize(yLen);
    std::cout << "Enter x vectors:" << std::endl;
    for (int i = 0; i < countOfVec; ++i) {
        for (int j = 0; j < xLen; ++j) {
            std::cin >> xVector[i][j];
        }
    }
    std::cout << "Enter y vectors:" << std::endl;
    for (int i = 0; i < countOfVec; ++i) {
        for (int j = 0; j < yLen; ++j) {
            std::cin >> yVector[i][j];
        }
    }
    std::cout << "Enter x test vector:" << std::endl;
    for (int i = 0; i < xLen; ++i) {
        std::cin >> xTest[i];
    }
    neuron.train(xVector, yVector);
    Matrix ans = neuron.test(xTest);
    ans.print();
	return 0;
}
