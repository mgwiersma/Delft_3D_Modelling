#ifndef GEO1004_VEC3_H
#define GEO1004_VEC3_H	// TODO -- why is this here? Be prepared to explain to the TA.

#include<iostream>
#include<cfloat>
#include<cmath>
#include<cassert>

/// three-dimensional vector class

class vec3 {
public:
	// default constructor: initialize all elements to be zero
	vec3();

	// initialized constructor
	vec3(float x, float y, float z);

	// copy constructor
	vec3(const vec3& other);

	// destructor
	~vec3();

	// suqared length of the vector
	float length2() const;

	// length of the vector
	float length() const;

	// normalize to a unit vector
	void normalize();

	// compute the dotproduct between this and other
	float dot(const vec3& other) const;

	// compute the crossproduct between this and other
	vec3 cross(const vec3& other) const;

	// operators -- vector-vector
	const vec3& operator+=(const vec3& other);		// cumulative addition
	const vec3& operator-=(const vec3& other);		// cumulative subtraction
	vec3 operator-() const;							// negation (unary operator)
	vec3 operator+(const vec3& other) const;		// addition
	vec3 operator-(const vec3& other) const;		// subtraction

	// operators -- vector-scalar
	const vec3& operator*=(float scalar);			// multiplication by scalar
	const vec3& operator/=(float scalar);			// division by scalar
	vec3 operator*(float scalar);					// vector times scalar
	vec3 operator/(float scalar);					// vector divided by scalar
	const vec3 operator=(const vec3& other);		// assignment operator

	// element access
	float& operator()(int index);       // RW access to element: return the index_th element
	float operator()(int index) const;	// RO access to element: return the index_th element

protected:
	float	m_data[3];	// data array
};


// TODO -- why is the following needed? Be prepared to explain to the TA
inline vec3 operator*(float scalar, const vec3& v) {
	// TODO -- multiply each component of v with scalar, in a new vector. return new vector
	return vec3(v(0)*scalar, v(1)*scalar, v(2)*scalar); 
}


inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    out << v(0) << " " << v(1) << " " << v(2);
	return out;
}


inline std::istream& operator>>(std::istream& in, vec3& v) {
	// TODO: read a vector component-wise from the "in" stream
	char dummy; //have to make sure that 'dummy' is what I actually type in
	in >> v(0) >> dummy >> v(1) >> dummy >> v(2);
	return in;
}


inline vec3::vec3() {
	// TODO -- initialize m_data with 0s
	for (int i = 0; i < 3; i++)
	{
		m_data[i] = float(0);
	}
}


inline vec3::vec3(float x, float y, float z) {
    // TODO -- initialize m_data with x,y,z.
	m_data[0] = x;
	m_data[1] = y;
	m_data[2] = z;
}


inline vec3::vec3(const vec3& other) {
	// TODO -- copy contents of other to this vector
	for (int i = 0; i < 3; i++)
	{
		m_data[i] = other(i);
	}
	//vec3(other(0), other(1), other(2)); //do I have to use m_data, or can I use an empty vector?
}


inline vec3::~vec3() {
	// TODO -- is there anything to do here? Be prepared to explain to the TA.
}


inline float vec3::length2() const {
	// TODO -- compute squared length of the vector
    return float(m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2]); // replace this line
}


inline float vec3::length() const {
	// TODO -- compute the length of the vector
    return float(sqrt(length2())); // replace this line
}


inline void vec3::normalize() {
	// TODO -- if length()==0, do nothing, otherwise normalize the vector
	float magnitude = length();
	if (magnitude != 0) {
		for (int i = 0; i < 3; i++)
		{
			m_data[i] = m_data[i] / magnitude;
		}
	}
}


inline float vec3::dot(const vec3& other) const {
	// TODO -- compute dot product between this vector and other
    return (m_data[0]*other(0)+ m_data[1] * other(1)+m_data[2] * other(2)); 
}


inline vec3 vec3::cross(const vec3& other) const {
	// TODO -- compute the crossproduct between the first three components of this and other
	return vec3(m_data[1]*other(2) - m_data[2]*other(1),
				m_data[2]*other(0) - m_data[0]*other(2),
				m_data[0]*other(1) - m_data[1]*other(0));
}


inline const vec3& vec3::operator+=(const vec3& other) {
	// TODO -- add other to this vector component-wise, store in this vector
	m_data[0] += other(0);
	m_data[1] += other(1);
	m_data[2] += other(2);
	return *this; // TODO -- why would you return a reference to *this? Be prepared to explain to the TA.
}


inline const vec3& vec3::operator-=(const vec3& other) {
	// TODO -- subtract other from this vector component-wise, store in this vector
	m_data[0] -= other(0);
	m_data[1] -= other(1);
	m_data[2] -= other(2);
	return *this;
}


inline vec3 vec3::operator-() const {
	// TODO -- why can't we return a reference, here? Be prepared to explain to the TA.
	// TODO -- return a new vector in which each component is the negated component from this vector

	return vec3(-m_data[0], -m_data[1], -m_data[2]); // replace this line
}


inline vec3 vec3::operator+(const vec3& other) const {
	// TODO -- return a new vector in which each component is the sum of the components of this vector and other

	return vec3(m_data[0]+other(0),
				m_data[1]+other(1),
				m_data[2]+other(2)); // replace this line
}


inline vec3 vec3::operator-(const vec3& other) const {
	// TODO -- return a new vector in which each component is the difference between the components of this vector and other

	return vec3(m_data[0] - other(0),
				m_data[1] - other(1),
				m_data[2] - other(2)); // should it be relative or absolute difference?
}



inline const vec3& vec3::operator*=(float scalar) {
	// TODO -- replace each component of this with the matching component of this multiplied with the scalar
	m_data[0] = m_data[0] * scalar;
	m_data[1] = m_data[1] * scalar;
	m_data[2] = m_data[2] * scalar;
	return *this;
}


inline const vec3& vec3::operator/=(float scalar) {
    assert(scalar != 0);
    // TODO -- replace each component of this with the matching component of this divided by the scalar
	m_data[0] = m_data[0] / scalar;
	m_data[1] = m_data[1] / scalar;
	m_data[2] = m_data[2] / scalar;
	return *this;
}



inline vec3 vec3::operator*(float scalar) {
	// TODO -- return a new vector in which each component equals the matching component of this vector times the scalar

	//vec3::vec3(float x, float y, float z);
	return vec3(m_data[0]*scalar, m_data[1]*scalar, m_data[2]*scalar); // replace this line
}



inline vec3 vec3::operator/(float scalar) {
    assert(scalar != 0);
	// TODO -- return a new vector in which each component equals the matching component of this vector divided by the scalar

	return vec3(m_data[0]/scalar, m_data[1]/scalar, m_data[2]/scalar); // replace this line
}


inline const vec3 vec3::operator=(const vec3& other) {
	// TODO -- overwrite each component in this vector with the matching component of other.
	m_data[0] = other(0);
	m_data[1] = other(1);
	m_data[2] = other(2);
	return *this;
}


inline float& vec3::operator()(int n) {
    assert(n < 3);
	return m_data[n];
}


inline float vec3::operator()(int n) const {
    assert(n < 3);
	return m_data[n];
}


#endif
