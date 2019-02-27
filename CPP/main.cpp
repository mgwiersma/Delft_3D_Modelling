#include "vec4.h"
#include "mat.h"

#include <iostream>

int main(int argc, char** argv) {
	std::cout << "program started..." << std::endl;

	// TODO -- test every vector and matrix function. Submit your code with tests in here.
	Matrix m;
	vec4 p(1, 1, 1);

	std::cout << m * p << std::endl;

	return 0;
}
