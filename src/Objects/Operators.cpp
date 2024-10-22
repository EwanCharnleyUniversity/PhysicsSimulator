
#include "ObjectDatatypes.h"


// POINT 3D OPERATORS //
////////////////////////

// Point3D input Operators
Point3D Point3D::operator +(const Point3D& rhs) {
	X += rhs.X;
	Y += rhs.Y;
	Z += rhs.Z;

	return *this;
}

Point3D Point3D::operator -(const Point3D& rhs) {
	X -= rhs.X;
	Y -= rhs.Y;
	Z -= rhs.Z;

	return *this;
}

Point3D Point3D::operator *(const Point3D& rhs) {
	X *= rhs.X;
	Y *= rhs.Y;
	Z *= rhs.Z;

	return *this;
}

Point3D Point3D::operator /(const Point3D& rhs) {
	X /= rhs.X;
	Y /= rhs.Y;
	Z /= rhs.Z;

	return *this;
}

Point3D Point3D::operator +=(const Point3D& rhs) {
	X += rhs.X;
	Y += rhs.Y;
	Z += rhs.Z;

	return *this;
}

Point3D Point3D::operator -=(const Point3D& rhs) {
	X -= rhs.X;
	Y -= rhs.Y;
	Z -= rhs.Z;

	return *this;
}

Point3D Point3D::operator *=(const Point3D& rhs) {
	X *= rhs.X;
	Y *= rhs.Y;
	Z *= rhs.Z;

	return *this;
}

Point3D Point3D::operator /=(const Point3D& rhs) {
	X /= rhs.X;
	Y /= rhs.Y;
	Z /= rhs.Z;

	return *this;
}


// Point3D single input operators - BROKEN/BUGGY
template <typename T>
Point3D Point3D::operator +(const T& rhs) {

	X += rhs;
	Y += rhs;
	Z += rhs;

	return *this;
}

template <typename T>
Point3D Point3D::operator -(const T& rhs) {
	X -= rhs;
	Y -= rhs;
	Z -= rhs;

	return *this;
}

template <typename T>
Point3D Point3D::operator *(const T& rhs) {
	X *= rhs;
	Y *= rhs;
	Z *= rhs;

	return *this;
}

template <typename T>
Point3D Point3D::operator /(const T& rhs) {
	X /= rhs;
	Y /= rhs;
	Z /= rhs;

	return *this;
}