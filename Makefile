install:
		mkdir -p bin && g++ main.cpp sources/matrix.cpp sources/model.cpp -g -Wall -o bin/main -std=c++17
