#include "../headers/matrix.h"

std::ostream &operator<< (std::ostream &os, const Matrix &obj) {
	for(int i = 0; i < obj.row; i++) {
		for(int j = 0; j < obj.col; j++) {
			os << std::setw(5) << obj.matr[i][j];
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>> (std::istream& is, Matrix& obj) {
	std::cout << "Give N x M: " << std::endl;
	is >> obj.row >> obj.col;
	obj.matr.resize(obj.row, std::vector<double>(obj.col, 0));
	std::cout << "Fill it: " << std::endl;
	for(int i = 0; i < obj.row; i++) {
		for(int j = 0; j < obj.col; j++) {
			std::cout << "matrix[" << i << "][" << j << "] = ";
			is >> obj.matr[i][j];
			std::cout << std::endl;
		}
	}
	return is;
}

Matrix::Matrix() {
	row = 0;
	col = 0;
}

Matrix::Matrix(int newRow, int newCol) {
	row = newRow;
	col = newCol;
	matr.resize(row, std::vector<double>(col, 0));
}


Matrix::Matrix(std::vector<double> &vector) {
    row = vector.size();
    col = 1;
    matr.resize(row, std::vector<double>(1));
    for (int i = 0; i < row; i++) {
        matr[i][0] = vector[i];
    }
}

std::vector<double> & Matrix::operator[](int i) {
	return matr[i];
}

void Matrix::print() {
	for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int Matrix::getRow() const {
	return row;
}

int Matrix::getCol() const {
	return col;
}

Matrix Matrix::operator+(Matrix rhs) {
	Matrix ans(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans.matr[i][j] = matr[i][j] + rhs.matr[i][j];
		}
	}
	return ans;
}

const Matrix& Matrix::operator=(const Matrix& rhs) {
	row = rhs.getRow();
	col = rhs.getCol();
	matr.resize(row, std::vector<double>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr[i][j] = rhs.matr[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator-(Matrix rhs) {
	Matrix ans(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans.matr[i][j] = matr[i][j] - rhs.matr[i][j];
		}
	}
	return ans;
}

Matrix Matrix::operator*(Matrix rhs) const{
	Matrix ans(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans.matr[i][j] = 0;
			for (int k = 0; k < col; k++)
				ans.matr[i][j] += matr[i][k] * rhs.matr[k][j];
		}
	}
	return ans;
}

Matrix Matrix::operator*(std::vector<double> rhs) const {
	Matrix ans(row, 1);
	for (int i = 0; i < row; i++) {
		ans.matr[i][0] = 0;
		for (int k = 0; k < col; k++) {
			ans.matr[i][0] += matr[i][k] * rhs[k];
		}
	}
	return ans;
}

Matrix Matrix::operator*(double rhs) {
	Matrix ans(row, 1);
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			ans.matr[i][k] = matr[i][k] * rhs;
		}
	}
	return ans;
}

Matrix Matrix::transpose() {
	Matrix ans(col, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ans.matr[j][i] = matr[i][j];
        }
    }
    return ans;
}
