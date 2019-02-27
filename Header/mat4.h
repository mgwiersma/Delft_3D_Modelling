#ifndef GEO1004_MAT_H
#define GEO1004_MAT_H

#include "vec4.h"

class mat4
{
public:
	// default constructor
	mat4();

	// initialized constructor
	mat4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33);

	// copy constructor
	mat4(const mat4& other);

	// destructor
	~mat4();

	// overwrite this mat4 with all zero entries
	void zeros();

	// overwrite this mat4 with identity
	void identity();

    // compute and return the transposed mat4
	mat4 transpose() const;

	// operators -- mat4-mat4
	mat4 operator+(const mat4& other) const; // addition
	mat4 operator-(const mat4& other) const; // subtraction
	mat4 operator*(const mat4& other) const; // multiplication
	mat4 operator-() const;			 // negation

	const mat4& operator+=(const mat4& other); // cumulative addition
	const mat4& operator-=(const mat4& other); // cumulative subtraction
	const mat4& operator*=(const mat4& other); // cumulative multiplication

	// operators -- mat4-vector
	vec4 operator*(const vec4& v);	// mat4-vector product

	// operators -- mat4-scalar
	const mat4& operator*=(float scalar);	// mat4-scalar product
	const mat4& operator/=(float scalar);	// mat4-scalar division
	mat4 operator*(float scalar);		// mat4-scalar product
	mat4 operator/(float scalar);		// mat4-scalar division

    // assignment operator
	const mat4& operator=(const mat4& other);	// assignment

    // access components
    float& operator()(int i, int j);        // RW access to components: i_th row, j_th column
    float operator()(int i, int j) const;	// RO access to components: i_th row, j_th column

protected:
	float	m_data[16];
};


inline mat4 operator*(float scalar, const mat4& M) {
	// TODO -- multiply each component of M with scalar, in a new mat4. return new mat4
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i, j) = M(i, j)*scalar;
		}

	}
	return temp;
}


inline std::ostream& operator<<(std::ostream& out, const mat4& M) {
	// output a mat4 row-by-row to the "out" stream
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			out << M(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}

inline std::istream& operator>>(std::istream& in, mat4& M) {
	// TODO: read a mat4 row-by-row from the "in" stream
	char dummy;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			in >> M(i, j) >> dummy;
		}

	}
	return in;
}



inline mat4::mat4() {
	// TODO -- initialize m_data with 0s
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] = float(0);
		}
	}
}


inline mat4::mat4(float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{
	m_data[0] = m00;
	m_data[1] = m01;
	m_data[2] = m02;
	m_data[3] = m03;
	m_data[4] = m10;
	m_data[5] = m11;
	m_data[6] = m12;
	m_data[7] = m13;
	m_data[8] = m20;
	m_data[9] = m21;
	m_data[10] = m22;
	m_data[11] = m23;
	m_data[12] = m30;
	m_data[13] = m31;
	m_data[14] = m32;
	m_data[15] = m33;

}


inline mat4::mat4(const mat4& other) {
	// TODO -- copy other to (*this) component by component
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] = other(i, j);
		}

	}
}


inline mat4::~mat4() {
}


inline void mat4::zeros() {
    // overwrite this mat4 with all zero entries
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] = float(0);
		}

	}
}


inline void mat4::identity() {
    // overwrite this mat4 with identity
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i == j)
				m_data[i * 4 + j] = float(1);
			else
				m_data[i * 4 + j] = float(0);
		}

	}
}


inline mat4 mat4::transpose() const {
	// TODO -- compute the transpose of this mat4 in a new mat4 and return.
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(j, i) = m_data[i * 4 + j];
		}

	}
	return temp;
}


inline mat4 mat4::operator+(const mat4& other) const {
	// TODO -- compute a new mat4 (*this)+other, return the new mat4
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i, j) = m_data[i * 4 + j] + other(i, j);
		}

	}
	return temp;
}


inline mat4 mat4::operator-(const mat4& other) const {
	// TODO -- compute a new mat4 (*this)-other, return the new mat4
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i, j) = m_data[i * 4 + j] - other(i, j);
		}

	}
	return temp;
}


inline mat4 mat4::operator*(const mat4& other) const {
	// TODO -- compute a new mat4 (*this) * other, return the new mat4
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				temp(i, j) += m_data[i * 4 + k] * other(k, j); //add k
			}
		}

	}
	return temp;
}


inline mat4 mat4::operator-() const {
	// TODO -- compute a new mat4 -(*this), return the new mat4
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i, j) = m_data[i * 4 + j] * -1;
		}

	}
	return temp;
}


inline const mat4& mat4::operator+=(const mat4& other) {
	// TODO -- add other to this mat4
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] += other(i, j);
		}

	}
	return *this;
}


inline const mat4& mat4::operator-=(const mat4& other) {
	// TODO -- subtract other from this mat4
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] -= other(i, j);
		}

	}
	return *this;
}


inline const mat4& mat4::operator*=(const mat4& other) {
	// TODO -- replace this mat4 by (*this) * other. Make sure you do not overwrite elements that you still need.
	mat4 temp = (*this) * other;
	(*this) = temp;
	return *this;
}


inline vec4 mat4::operator*(const vec4& v) {
	// TODO -- compute the mat4-vector product (*this) * v and return the result
	vec4 temp = vec4();
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i) = m_data[i * 4 + j] * v(j);
		}
	}
	return temp;
}


inline const mat4& mat4::operator*=(float scalar) {
	// TODO -- multiply each mat4 component by scalar.
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] = m_data[i * 4 + j] * scalar;
		}

	}
	return *this;
}


inline const mat4& mat4::operator/=(float scalar) {
    assert(scalar != 0);
	// TODO -- divide each mat4 component by scalar.
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] = m_data[i * 4 + j] / scalar;
		}

	}
	return *this;
}


inline mat4 mat4::operator*(float scalar) {
	// TODO -- compute a new mat4 (*this) * scalar.
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i, j) = m_data[i * 4 + j] * scalar;
		}

	}
	return temp;
}


inline mat4 mat4::operator/(float scalar) {
    assert(scalar != 0);
	// TODO -- divide each mat4 component by scalar and store in a new mat4. return the new mat4.
	mat4 temp = mat4();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			temp(i, j) = m_data[i * 4 + j] / scalar;
		}

	}
	return temp;
}


inline const mat4& mat4::operator=(const mat4& other) {
	// TODO -- overwrite each component in this mat4 by the matching component in other
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_data[i * 4 + j] = other(i, j);
		}

	}
	return *this;
}


inline float& mat4::operator()(int i, int j) {
    assert(i < 4 && j < 4);
    return m_data[i * 4 + j];
}


inline float mat4::operator()(int i, int j) const {
    assert(i < 4 && j < 4);
    return m_data[i * 4 + j];
}



#endif
