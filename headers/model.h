#ifndef __MODEL_H__
#define __MODEL_H__

#include <iostream>
#include <vector>
#include <cmath>
#include "../headers/matrix.h"

class Model {
private:
	Matrix A, b;
public:
	Model();
    Model(int row, int col);
    //~ double difference(Matrix &a, Matrix &b) const;
    void train(std::vector< std::vector<double> > xTrain, std::vector< std::vector<double> > yTrain);
    Matrix test(std::vector<double> xTest) const;
};

#endif
