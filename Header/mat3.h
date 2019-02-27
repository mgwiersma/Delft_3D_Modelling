#ifndef GEO1004_MAT3_H
#define GEO1004_MAT3_H

#include "vec3.h"

class mat3
{
public:
	// default constructor
	mat3();

	// initialized constructor
	mat3(
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22);

	// copy constructor
	mat3(const mat3& other);

	// destructor
	~mat3();

	// overwrite this mat3 with all zero entries
	void zeros();

	// overwrite this mat3 with identity
	void identity();

    // compute and return the transposed mat3
	mat3 transpose() const;

	// operators -- mat3-mat3
	mat3 operator+(const mat3& other) const; // addition
	mat3 operator-(const mat3& other) const; // subtraction
	mat3 operator*(const mat3& other) const; // multiplication
	mat3 operator-() const;			 // negation

	const mat3& operator+=(const mat3& other); // cumulative addition
	const mat3& operator-=(const mat3& other); // cumulative subtraction
	const mat3& operator*=(const mat3& other); // cumulative multiplication

	// operators -- mat3-vector
	vec3 operator*(const vec3& v);	// mat3-vector product

	// operators -- mat3-scalar
	const mat3& operator*=(float scalar);	// mat3-scalar product
	const mat3& operator/=(float scalar);	// mat3-scalar division
	mat3 operator*(float scalar);		// mat3-scalar product
	mat3 operator/(float scalar);		// mat3-scalar division

    // assignment operator
	const mat3& operator=(const mat3& other);	// assignment

    // access components
    float& operator()(int i, int j);        // RW access to components: i_th row, j_th column
    float operator()(int i, int j) const;	// RO access to components: i_th row, j_th column

protected:
	float	m_data[9];
};


inline mat3 operator*(float scalar, const mat3& M) {
	// TODO -- multiply each component of M with scalar, in a new mat3. return new mat3
	mat3 temp = mat3();
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				temp(i, j) = M(i, j)*scalar;
			}

		}
		return temp;
}
	
	//return mat3(M(0,0)*scalar, M(0,1)*scalar, M(0,2)*scalar, M(1,0)*scalar, M(1,1)*scalar, M(1,2)*scalar, M(2,0)*scalar, M(2,1)*scalar, M(2,2)*scalar);
	//look up how to do this using istream



inline std::ostream& operator<<(std::ostream& out, const mat3& M) {
	// output a mat3 row-by-row to the "out" stream
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			out << M(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}


inline std::istream& operator>>(std::istream& in, mat3& M) {
	// TODO: read a mat3 row-by-row from the "in" stream
	char dummy;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			in >> M(i, j) >> dummy;
		}
		
	}
	return in;
}



inline mat3::mat3() {
	// TODO -- initialize m_data with 0s
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] = float(0);
		}
	}
}


inline mat3::mat3(
    float m00, float m01, float m02,
	float m10, float m11, float m12,
	float m20, float m21, float m22)
{
	// TODO -- initialize m_data with the provided components.
	m_data[0] = m00;
	m_data[1] = m01;
	m_data[2] = m02;
	m_data[3] = m10;
	m_data[4] = m11;
	m_data[5] = m12;
	m_data[6] = m20;
	m_data[7] = m21;
	m_data[8] = m22;
}


inline mat3::mat3(const mat3& other) {
	// TODO -- copy other to (*this), component by component
	//mat3(other(0), other(1), other(2));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i*3+j] = other(i, j);
		}

	} 
}

inline mat3::~mat3() {
}


inline void mat3::zeros() {
    // overwrite this mat3 with all zero entries
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] = float(0);
		}

	}
}


inline void mat3::identity() {
    // overwrite this mat3 with identity
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j)
				m_data[i * 3 + j] = float(1);
			else
				m_data[i * 3 + j] = float(0);
		}

	}
}


inline mat3 mat3::transpose() const {
	// TODO -- compute the transpose of this mat3 in a new mat3 and return.
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp(j, i) = m_data[i*3+j];
		}

	}
	return temp;
}


inline mat3 mat3::operator+(const mat3& other) const {
	// TODO -- compute a new mat3 (*this)+other, return the new mat3
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp(i, j) = m_data[i * 3 + j]+other(i, j);
		}

	}
	return temp;
}


inline mat3 mat3::operator-(const mat3& other) const {
	// TODO -- compute a new mat3 (*this)-other, return the new mat3
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp(i, j) = m_data[i * 3 + j] - other(i, j);
		}

	}
	return temp;
}


inline mat3 mat3::operator*(const mat3& other) const {
	// TODO -- compute a new mat3 (*this) * other, return the new mat3
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				temp(i, j) += m_data[i * 3 + k] * other(k, j); //add k
			}
		}

	}
	return temp;
}


inline mat3 mat3::operator-() const {
	// TODO -- compute a new mat3 -(*this), return the new mat3
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp(i, j) = m_data[i * 3 + j] *-1;
		}

	}
	return temp;
}


inline const mat3& mat3::operator+=(const mat3& other) {
	// TODO -- add other to this mat3
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] += other(i, j);
		}

	}
	return *this;
}


inline const mat3& mat3::operator-=(const mat3& other) {
	// TODO -- subtract other from this mat3
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] -= other(i, j);
		}

	}
	return *this;
}


inline const mat3& mat3::operator*=(const mat3& other) {
	// TODO -- replace this mat3 by (*this) * other. Make sure you do not overwrite elements that you still need.
	mat3 temp = (*this) * other;
	(*this) = temp;
	return *this;
}


inline vec3 mat3::operator*(const vec3& v) {
	// TODO -- compute the mat3-vector product (*this) * v and return the result
	vec3 temp;
	for (int i = 0; i < 3; ++i) {
		temp(i) = 0;
		for (int j = 0; j < 3; ++j) {
			temp(i) = temp(i) + m_data[i * 3 + j] * v(j);
		}
	}
	return temp; 
}


inline const mat3& mat3::operator*=(float scalar) {
	// TODO -- multiply each mat3 component by scalar.
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] = m_data[i * 3 + j] * scalar;
		}

	}
	return *this;
}


inline const mat3& mat3::operator/=(float scalar) {
    assert(scalar != 0);
	// TODO -- divide each mat3 component by scalar.
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] = m_data[i * 3 + j] / scalar;
		}

	}
	return *this;
}


inline mat3 mat3::operator*(float scalar) {
	// TODO -- compute a new mat3 (*this) * scalar.
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp(i, j) = m_data[i * 3 + j] * scalar;
		}

	}
	return temp;
}


inline mat3 mat3::operator/(float scalar) {
    assert(scalar != 0);
	// TODO -- divide each mat3 component by scalar and store in a new mat3. return the new mat3.
	mat3 temp = mat3();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp(i, j) = m_data[i * 3 + j] / scalar;
		}

	}
	return temp;
}


inline const mat3& mat3::operator=(const mat3& other) {
	// TODO -- overwrite each component in this mat3 by the matching component in other
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m_data[i * 3 + j] = other(i, j);
		}

	}
	return *this;
}


inline float& mat3::operator()(int i, int j) {
    assert(i < 3 && j < 3);
    return m_data[i * 3 + j];
}


inline float mat3::operator()(int i, int j) const {
    assert(i < 3 && j < 3);
    return m_data[i * 3 + j];
}



#endif
