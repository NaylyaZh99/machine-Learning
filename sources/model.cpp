#include "../headers/model.h"

Model::Model() {}

Model::Model(int newRow, int newCol) {
	A = Matrix(newRow, newCol);
	b = Matrix(newRow, 1);
}

void Model::train(std::vector< std::vector<double> > xTrain, std::vector< std::vector<double> > yTrain) {
	//~ A.resize(yTrain[0].size(), std::vector<double>(xTrain[0].size(), 0));
    Matrix oldA(yTrain[0].size(), xTrain[0].size());
    //~ b.resize(yTrain[0].size(), std::vector<double>(1, 0));
    Matrix oldB(yTrain[0].size(), 1);
    for (int k = 0; k < 10; k++) {
            oldA = A;
            oldB = b;
            Matrix tmpA(yTrain[0].size(), xTrain[0].size());
            Matrix tmpB(yTrain[0].size(), 1);
            for (unsigned int i = 0; i < xTrain.size(); i++) {
                tmpA = tmpA + (oldA * xTrain[i] - Matrix(yTrain[i]) + Matrix(oldB)) * (Matrix(xTrain[i])).transpose();
                tmpB = tmpB + (oldA * xTrain[i] - Matrix(yTrain[i]) + Matrix(oldB));
            }
            A = oldA - tmpA * 0.01;
            b = oldB - tmpB * 0.01;
           
    }
}

Matrix Model::test(std::vector<double> xTrain) const {
    return A * xTrain;
}
