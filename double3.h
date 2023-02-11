#pragma once
//#include <iostream>

struct double3
{
	double x, y, z;

	double3()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}

	double3(double new_x, double new_y, double new_z)
		: x(new_x), y(new_y), z(new_z)
	{

	}

	double3(double3 const&) = default;

	double3 operator + (const double3& other) const
	{
		return double3(x + other.x, y + other.y, z + other.z);
	}

	void operator += (const double3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	double3 operator - (const double3& other) const
	{
		return double3(x - other.x, y - other.y, z - other.z);
	}

	void operator -= (const double3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	double3 operator - () const
	{
		return double3(-x, -y, -z);
	}

	double3 operator * (const double3& other) const
	{
		return double3(x * other.x, y * other.y, z * other.z);
	}

	void operator *= (const double3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
	}	   

	double3 operator * (double other) const
	{
		return double3(x * other, y * other, z * other);
	}

	void operator *= (double other)
	{
		x *= other;
		y *= other;
		z *= other;
	}

	double3 operator / (const double3& other) const
	{
		return double3(x / other.x, y / other.y, z / other.z);
	}

	void operator /= (const double3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
	}

	double3 operator / (double other) const
	{
		return double3(x / other, y / other, z / other);
	}

	void operator /= (double other)
	{
		x /= other;
		y /= other;
		z /= other;
	}

	void normalize()
	{
		double len = sqrt(x * x + y * y + z * z);
		x /= len;
		y /= len;
		z /= len;
	}

	double3 normalized() const
	{
		double len = sqrt(x * x + y * y + z * z);
		return double3(x / len, y / len, z / len);
	}

	double length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

//#ifdef _IOSFWD_
//
//	operator std::string()
//	{
//		std::stringstream ss;
//		ss << "x: " << x << ", y: " << y << ", z: " << z;
//		return ss.str();
//	}
//
//#endif // _IOSFWD_

};

double dot(const double3& a, const double3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

#ifdef _IOSFWD_

std::ostream& operator << (std::ostream& outstream, const double3& value)
{
	return outstream << "x: " << value.x << ", y: " << value.y << ", z: " << value.z;
}

#endif // _IOSFWD_