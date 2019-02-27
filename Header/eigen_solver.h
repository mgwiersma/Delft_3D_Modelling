#ifndef GEO1004_EIGEN_SOLVER_H
#define GEO1004_EIGEN_SOLVER_H

#include "vec3.h"
#include "mat3.h"

class EigenSolver
{
public:
	EigenSolver();
	~EigenSolver();

	// compute the eigen values and eigen vectors of matrix m.
	void solve(const mat3& m);

	// after computation, allow the user to retrieve the index_th eigen value
	float get_eigen_value(int index) const { return m_eigen_values[index]; }

	// after computation, allow the user to retrieve the index_th eigen vector
	const vec3& get_eigen_vector(int index) const { return m_eigen_vectors[index]; }

private:
	float m_eigen_values[3];
	vec3  m_eigen_vectors[3];
};


#endif
