#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>
#include <iomanip>

class Matrix {
private:
	friend std::ostream &operator<< (std::ostream &, const Matrix &);
	friend std::istream & operator>> (std::istream &, Matrix &);
	int row, col;
	std::vector< std::vector<double> > matr;
public:
	Matrix();
	Matrix(int newRow, int newCol);
	Matrix(std::vector<double> &vector);
	std::vector<double> &operator[](int i);
	void print();
	int getRow() const;
	int getCol() const;
	Matrix operator+(Matrix rhs);
	const Matrix& operator=(const Matrix &rhs);
    Matrix operator-(Matrix rhs);
    Matrix operator*(Matrix rhs) const;
    Matrix operator*(std::vector<double> rhs) const;
    Matrix operator*(double rhs);
    Matrix transpose();
	
};

#endif
