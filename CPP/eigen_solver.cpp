#include "eigen_solver.h"
#include "eigen_symmetric.h"


EigenSolver::EigenSolver()
{

}


EigenSolver::~EigenSolver()
{

}


// compute the eigen values and eigen vectors of matrix m.
void EigenSolver::solve(const mat3& m) {
    // after computation:
    //  - the eigen values are stored in the member "m_eigen_values"
    //  - the eigen vectors are stored in the member "m_eigen_vectors"

    // TODO -> call the function defined in "eigen_symmetric.h"
    // Please read carefully the manual of the function.
	float upper_tri_mat[6];
	float eigen_vectors[9];

	int count = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i <= j)
			{
				upper_tri_mat[count] = m(i, j);
				count++;
			}

		}
	}


	for (int i = 0; i < 6; ++i)
		std::cout << upper_tri_mat[i] << "  " << std::endl;
	
	eigen::eigen_symmetric(upper_tri_mat,
		3,
		eigen_vectors,
		m_eigen_values);
 
	int count2 = 0;
	for (int i = 2; i > 0; i--)
	{
		for (int j = 2; j > 0; j--)
		{
			m_eigen_vectors[i](j) = eigen_vectors[count2];
			count2++;
		}
	}
	for (int i = 0; i < 9; ++i)
		std::cout << eigen_vectors[i] << "  " << std::endl;
}
