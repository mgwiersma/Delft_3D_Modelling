#include "../lib/vec3.h"
#include "../lib/vec4.h"
#include "../lib/mat3.h"
#include "../lib/mat4.h"

#include <iostream>


int main(int argc, char** argv) {
	std::cout << "Hello!!!" << std::endl << std::endl;

	//Testing vectors
	////vec3////
	std::cout << "OPERATIONS WITH VEC3" << std::endl;

	vec3 v3_1(1, 1, 1);
	vec3 v3_2(2, 1, 2);
	vec3 v3_3(3, 1, 1);
	vec3 v3_4(0, 0, 1);
	vec3 v3_5(10, 20, 50);
	std::cout << "vector v1 is:" << std::endl << v3_1 << std::endl;
	std::cout << "vector v2 is:" << std::endl << v3_2 << std::endl;
	std::cout << "vector v3 is:" << std::endl << v3_3 << std::endl;
	std::cout << "vector v4 is:" << std::endl << v3_4 << std::endl;
	std::cout << "vector v5 is:" << std::endl << v3_5 << std::endl;

	//vector initialized with zeros
	vec3 v3_0 = vec3();
	std::cout << "vector v0 is:" << std::endl << v3_0 << std::endl;

	//copy contents of other vector to this vector
	v3_0 = vec3(v3_1);
	std::cout << "vector v0 is changed to v1:" << std::endl << v3_0 << std::endl;

	//compute length and squared length of vector
	float len = v3_1.length();
	float len2 = v3_1.length2();
	std::cout << "the length of v1 is:" << std::endl << len << std::endl;
	std::cout << "the squared length of v1 is:" << std::endl << len2 << std::endl;
	
	//normalize vector (and do nothing if length is 0)
	vec3 v3_zeros = vec3();
	v3_zeros.normalize();
	v3_2.normalize();
	std::cout << "normalized v2 is:" << std::endl << v3_2 << std::endl;

	//compute dot and crossproduct between vectors
	float v3_res3 = v3_1.dot(v3_3);
	vec3 v3_res4 = v3_1.cross(v3_3);
	std::cout << "dot product of v1 and v3 is:" << std::endl << v3_res3 << std::endl;
	std::cout << "crossproduct of v1 and v3 is:" << std::endl << v3_res4 << std::endl;
	
	//compute sum and difference between two vector (changing the vector)
	v3_1 += v3_4;
	v3_2 -= v3_4;
	std::cout << "v1+v4 is:" << std::endl << v3_1 << std::endl;
	std::cout << "v2-v4 is:" << std::endl << v3_2 << std::endl;

	//compute the negative of a vector
	vec3 v3_neg1 = -(v3_1);
	std::cout << "vector -v1 is:" << std::endl << v3_neg1 << std::endl;

	//compute sum and difference between two vector (in a new vector)
	vec3 v3_res5 = v3_3 + v3_4;
	vec3 v3_res6 = v3_4 - v3_5;
	std::cout << "v3+v4 is:" << std::endl << v3_res5 << std::endl;
	std::cout << "v4-v5 is:" << std::endl << v3_res6 << std::endl;

	//compute division and multiplication between vector and scalar (changing the vector)
	v3_1 /= 4;
	v3_5 *= -5;
	std::cout << "v1/=4 is:" << std::endl << v3_1 << std::endl;
	std::cout << "v5*=-5 is:" << std::endl << v3_5 << std::endl;

	//compute division and multiplication between vector and scalar (in new vector)
	vec3 v3_res7 = v3_4 * 2;
	vec3 v3_res8 = v3_4 / 4;
	std::cout << "v4*2 is:" << std::endl << v3_res7 << std::endl;
	std::cout << "v4/4 is:" << std::endl << v3_res8 << std::endl;

	//overwrite this vector with components of other
	v3_1 = v3_4;
	std::cout << "v1 is overwritten with components of v4:" << std::endl << v3_1 << std::endl;

	//vec4///
	std::cout << "OPERATIONS WITH VEC4" << std::endl;

	vec4 v4_1(1, 1, 1, 1);
	vec4 v4_2(2, 1, 2, 1);
	vec4 v4_3(3, 1, 1, 3);
	vec4 v4_4(0, 0, 1, 0);
	vec4 v4_5(10, 20, 50, 10);
	std::cout << "vector v1 is:" << std::endl << v3_1 << std::endl;
	std::cout << "vector v2 is:" << std::endl << v3_2 << std::endl;
	std::cout << "vector v3 is:" << std::endl << v3_3 << std::endl;
	std::cout << "vector v4 is:" << std::endl << v3_4 << std::endl;
	std::cout << "vector v5 is:" << std::endl << v3_5 << std::endl;

	//vector initialized with zeros
	vec4 v4_0 = vec4();
	std::cout << "vector v0 is:" << std::endl << v4_0 << std::endl;
	
	//construct vec4 from vec3
	vec4 v4_v3 = vec4(v3_3);
	std::cout << "the 4D vector of v3_3 is:" << std::endl << v4_v3 << std::endl;

	//copy contents of other vector to this vector
	v4_0 = vec4(v4_1);
	std::cout << "vector v0 is changed to v1:" << std::endl << v4_0 << std::endl;

	//compute length and squared length of vector
	float v4_len = v4_1.length();
	float v4_len2 = v4_1.length2();
	std::cout << "the length of v1 is:" << std::endl << v4_len << std::endl;
	std::cout << "the squared length of v1 is:" << std::endl << v4_len2 << std::endl;

	//normalize vector (and do nothing if length is 0)
	vec4 v4_zeros = vec4();
	v4_zeros.normalize();
	v4_2.normalize();
	std::cout << "normalized v2 is:" << std::endl << v4_2 << std::endl;

	//compute dot and crossproduct between vectors
	float v4_res3 = v4_1.dot(v4_3);
	vec4 v4_res4 = v4_1.cross(v4_3);
	std::cout << "dot product of v1 and v3 is:" << std::endl << v4_res3 << std::endl;
	std::cout << "crossproduct of v1 and v3 is:" << std::endl << v4_res4 << std::endl;

	//compute sum and difference between two vector (changing the vector)
	v4_1 += v4_4;
	v4_2 -= v4_4;
	std::cout << "v1+v4 is:" << std::endl << v4_1 << std::endl;
	std::cout << "v2-v4 is:" << std::endl << v4_2 << std::endl;

	//compute the negative of a vector
	vec4 v4_neg1 = -(v4_1);
	std::cout << "vector -v1 is:" << std::endl << v4_neg1 << std::endl;

	//compute sum and difference between two vector (in a new vector)
	vec4 v4_res5 = v4_3 + v4_4;
	vec4 v4_res6 = v4_4 - v4_5;
	std::cout << "v3+v4 is:" << std::endl << v4_res5 << std::endl;
	std::cout << "v4-v5 is:" << std::endl << v4_res6 << std::endl;

	//compute division and multiplication between vector and scalar (changing the vector)
	v4_1 /= 4;
	v4_5 *= -5;
	std::cout << "v1/=4 is:" << std::endl << v4_1 << std::endl;
	std::cout << "v5*=-5 is:" << std::endl << v4_5 << std::endl;

	//compute division and multiplication between vector and scalar (in new vector)
	vec4 v4_res7 = v4_4 * 2;
	vec4 v4_res8 = v4_4 / 4;
	std::cout << "v4*2 is:" << std::endl << v4_res7 << std::endl;
	std::cout << "v4/4 is:" << std::endl << v4_res8 << std::endl;

	//overwrite this vector with components of other
	v4_1 = v4_4;
	std::cout << "v1 is overwritten with components of v4:" << std::endl << v4_1 << std::endl;

	//Testing matrices
	////mat3////
	std::cout << "OPERATIONS WITH MAT3" << std::endl;
	mat3 m3_1(8, 4, 2,
			6, 1, 5,
			2, 1, 3);

	mat3 m3_2(2, 3, 1,
			1, 0, 4,
			6, 2, 1);
	
	mat3 m3_3(1, 1, 3,
			5, 5, 2,
			0, 3, 0);

	mat3 m3_4(0, 5, 1,
			2, 0, 2,
			0, 1, 6);
	
	mat3 m3_5(1, 2, 1,
			1, 2, 1,
			1, 2, 1);

	std::cout << "matrix m1 is: " << std::endl << m3_1 << std::endl;
	std::cout << "matrix m2 is: " << std::endl << m3_2 << std::endl;

	//matrix initialized with zeros
	mat3 m3_0 = mat3();
	std::cout << "matrix m0 is: " << std::endl << m3_0 << std::endl;

	//multiply each component of M with scalar
	mat3 m3_res1 = m3_1 * 2;
	mat3 m3_res2 = m3_2 * 5;
	std::cout << "m1*2 is: " << std::endl << m3_res1 << std::endl;
	std::cout << "m2*5 is: " << std::endl << m3_res2 << std::endl;

	//copy components of other matrix to this one
	m3_3 =mat3(m3_0);
	std::cout << "m3 is changed to m0: " << std::endl << m3_3 << std::endl;
	
	//overwrite this matrix with zeros
	m3_4.zeros();
	std::cout << "m4 is overwritten with 0s: " << std::endl << m3_4 << std::endl;
	
	//overwrite this matrix with the identity matrix
	m3_4.identity();
	std::cout << "m4 is overwritten with identity matrix: " << std::endl << m3_4 << std::endl;

	//compute the transpose of this matrix
	mat3 m3_res3 = m3_2.transpose();
	std::cout << "the transposed of m2 is: " << std::endl << m3_res3 << std::endl;
	std::cout << "and m2 remains unchanged: " << std::endl << m3_2 << std::endl;
	
	//compute the sum, difference and multiplication of two matrices (in new matrix)
	mat3 m3_res4 = m3_1 + m3_2;
	mat3 m3_res5 = m3_1 - m3_2;
	mat3 m3_res6 = m3_1 * m3_2;
	std::cout << "m1+m2 is: " << std::endl << m3_res4 << std::endl;
	std::cout << "m1-m2 is: " << std::endl << m3_res5 << std::endl;
	std::cout << "m1*m2 is: " << std::endl << m3_res6 << std::endl;

	//compute the negative of a matrix
	mat3 m3_res7 = -(m3_1);
	std::cout << "matrix -m1 is: " << std::endl << m3_res7 << std::endl;

	//compute the sum, difference and multiplication of two matrices(changing this matrix)
	m3_1 += m3_5;
	std::cout << "m1+=m5 is: " << std::endl << m3_1 << std::endl;

	m3_1 -= m3_5;
	std::cout << "m1-=m5 is: " << std::endl << m3_1 << std::endl;

	m3_1 *= m3_5;
	std::cout << "m1*=m5 is: " << std::endl << m3_1 << std::endl;

	//compute matrix-vector product
	vec3 m3_vec(2, 2, 1);
	vec3 m3_vec_res = m3_1 * m3_vec;
	std::cout << "vec is: " << std::endl << m3_vec << std::endl;
	std::cout << "m1*vec is: " << std::endl << m3_vec_res << std::endl;

	//compute division and multiplication of matrix and scalar (in new matrix)
	mat3 m3_res8 = m3_2 * 2;
	mat3 m3_res9 = m3_2/2;
	std::cout << "m2*2 is: " << std::endl << m3_res8 << std::endl;
	std::cout << "m2/2 is: " << std::endl << m3_res9 << std::endl;

	//compute division and multiplication of matrix and scalar (changing this matrix)
	m3_2 *= 2;
	std::cout << "m2*2 is: " << std::endl << m3_2 << std::endl;
	
	m3_2 /= 5;
	std::cout << "m2/2 is: " << std::endl << m3_2 << std::endl;

	//overwrite this matrix with components of other
	m3_2 = m3_4;
	std::cout << "m2 is overwritten with m4 " << std::endl << m3_2 << std::endl;

	////mat4////
	std::cout << "OPERATIONS WITH MAT4" << std::endl;

	mat4 m4_1(1, 2, 1, 2,
			7, 5, 1, 4,
			2, 1, 3, 5,
			1, 3, 2, 0);

	mat4 m4_2(2, 3, 1, 6,
			9, 6, 1, 1,
			1, 0, 4, 8,
			6, 2, 1, 1);

	mat4 m4_3(1, 2, 5, 0,
			4, 4, 1, 0,
			5, 2, 2, 7,
			0, 3, 1, 3);

	mat4 m4_4(1, 2, 7, 4,
			2, 8, 1, 1,
			4, 3, 1, 6,
			0, 1, 6, 2);

	mat4 m4_5(1, 4, 1, 0,
			2, 2, 1, 3,
			5, 3, 1, 1,
			1, 2, 0, 0);

	std::cout << "matrix m1 is: " << std::endl << m4_1 << std::endl;
	std::cout << "matrix m2 is: " << std::endl << m4_2 << std::endl;

	//matrix initialized with zeros
	mat4 m4_0 = mat4();
	std::cout << "matrix m0 is: " << std::endl << m4_0 << std::endl;

	//multiply each component of M with scalar
	mat4 m4_res1 = m4_1 * 2;
	mat4 m4_res2 = m4_2 * 5;
	std::cout << "m1*2 is: " << std::endl << m4_res1 << std::endl;
	std::cout << "m2*5 is: " << std::endl << m4_res2 << std::endl;

	//copy components of other matrix to this one
	m4_3 = mat4(m4_0);
	std::cout << "m3 is changed to m0: " << std::endl << m4_3 << std::endl;

	//overwrite this matrix with zeros
	m4_4.zeros();
	std::cout << "m4 is overwritten with 0s: " << std::endl << m4_4 << std::endl;

	//overwrite this matrix with the identity matrix
	m4_4.identity();
	std::cout << "m4 is overwritten with identity matrix: " << std::endl << m4_4 << std::endl;

	//compute the transpose of this matrix
	mat4 m4_res3 = m4_2.transpose();
	std::cout << "the transposed of m2 is: " << std::endl << m4_res3 << std::endl;
	std::cout << "and m2 remains unchanged: " << std::endl << m4_2 << std::endl;

	//compute the sum, difference and multiplication of two matrices (in new matrix)
	mat4 m4_res4 = m4_1 + m4_2;
	mat4 m4_res5 = m4_1 - m4_2;
	mat4 m4_res6 = m4_1 * m4_2;
	std::cout << "m1+m2 is: " << std::endl << m4_res4 << std::endl;
	std::cout << "m1-m2 is: " << std::endl << m4_res5 << std::endl;
	std::cout << "m1*m2 is: " << std::endl << m4_res6 << std::endl;

	//compute the negative of a matrix
	mat4 m4_res7 = -(m4_1);
	std::cout << "matrix -m1 is: " << std::endl << m4_res7 << std::endl;

	//compute the sum, difference and multiplication of two matrices(changing this matrix)
	m4_1 += m4_5;
	std::cout << "m1+=m5 is: " << std::endl << m4_1 << std::endl;

	m4_1 -= m4_5;
	std::cout << "m1-=m5 is: " << std::endl << m4_1 << std::endl;

	m4_1 *= m4_5;
	std::cout << "m1*=m5 is: " << std::endl << m4_1 << std::endl;

	//compute matrix-vector product
	vec4 m4_vec(3, 3, 1, 1);
	vec4 m4_vec_res = m4_1 * m4_vec;
	std::cout << "vec is: " << std::endl << m4_vec << std::endl;
	std::cout << "m1*vec is: " << std::endl << m4_vec_res << std::endl;

	//compute division and multiplication of matrix and scalar (in new matrix)
	mat4 m4_res8 = m4_2 * 2;
	mat4 m4_res9 = m4_2 / 2;
	std::cout << "m2*2 is: " << std::endl << m4_res8 << std::endl;
	std::cout << "m2/2 is: " << std::endl << m4_res9 << std::endl;

	//compute division and multiplication of matrix and scalar (changing this matrix)
	m4_2 *= 2;
	std::cout << "m2*2 is: " << std::endl << m4_2 << std::endl;

	m4_2 /= 5;
	std::cout << "m2/2 is: " << std::endl << m4_2 << std::endl;

	//overwrite this matrix with components of other
	m4_2 = m4_4;
	std::cout << "m2 is overwritten with m4 " << std::endl << m4_2 << std::endl;

	getchar();
	return 0;
}
