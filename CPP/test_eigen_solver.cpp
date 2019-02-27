#include "../lib/eigen_solver.h"

#include <iostream>

int main(int argc, char** argv) {
	std::cout << "Hello!!!" << std::endl << std::endl;

	std::cout << "A real symmetric matrix" << std::endl;
	mat3 A(
		1, 3, 5,
		2, 4, 2,
		3, 7, 1);
	A = A * A.transpose(); // make it symmetric
	std::cout << "The input matrix is: " << std::endl << A << std::endl << std::endl;

	EigenSolver solver;
	solver.solve(A);

	std::cout << "The results: eigen value - eigen vector" << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << solver.get_eigen_value(i) << " - (" << solver.get_eigen_vector(i) << ")" << std::endl;
	}

    std::cout << "\nNow let\'s check if the results are correct (A*v - d*v should 5be 0-vector)..." << std::endl;
	for (int i = 0; i < 3; ++i) {
		float d = solver.get_eigen_value(i);
		const vec3& v = solver.get_eigen_vector(i);
		std::cout << i << ": " << A * v - d * v << std::endl;
	}
	
	getchar();
	return 0;
}

