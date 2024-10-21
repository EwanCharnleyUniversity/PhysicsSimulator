
#ifndef OBJECT_DATATYPES_CLASS
#define OBJECT_DATATYPES_CLASS


struct Vector3D {
	double X, Y, Z;

	// Basic Operators
	// Vector3D o=   this .o. Vector3D
	Vector3D operator +=(const Vector3D& rhs) {
		X += rhs.X;
		Y += rhs.Y;
		Z += rhs.Z;

		return *this;
	}

	Vector3D operator -=(const Vector3D& rhs) {
		X -= rhs.X;
		Y -= rhs.Y;
		Z -= rhs.Z;

		return *this;
	}

	Vector3D operator *=(const Vector3D& rhs) {
		X *= rhs.X;
		Y *= rhs.Y;
		Z *= rhs.Z;

		return *this;
	}

	Vector3D operator /=(const Vector3D& rhs) {
		X /= rhs.X;
		Y /= rhs.Y;
		Z /= rhs.Z;

		return *this;
	}
};

// Vector3D operator overload functions for: x o= y
//Vector3D operator +=(const Vector3D& rhs)
//{
//	X += rhs.X;
//	Y += rhs.Y;
//	Z += rhs.Z;

//	return { X, Y, Z };
//}

//Vector3D operator +=(const float rhs)
//{
//	X += rhs;
//	Y += rhs;
//	Z += rhs;

//	return { X, Y, Z };
//}

//Vector3D operator -=(const Vector3D& rhs)
//{
//	X -= rhs.X;
//	Y -= rhs.Y;
//	Z -= rhs.Z;

//	return { X, Y, Z };
//}

//Vector3D operator -=(const float rhs)
//{
//	X -= rhs;
//	Y -= rhs;
//	Z -= rhs;

//	return { X, Y, Z };
//}

//Vector3D operator *=(const Vector3D& rhs)
//{
//	X *= rhs.X;
//	Y *= rhs.Y;
//	Z *= rhs.Z;

//	return { X, Y, Z };
//}

//Vector3D operator *=(const float rhs)
//{
//	X *= rhs;
//	Y *= rhs;
//	Z *= rhs;

//	return { X, Y, Z };
//}

//Vector3D operator /=(const Vector3D& rhs)
//{
//	X /= rhs.X;
//	Y /= rhs.Y;
//	Z /= rhs.Z;

//	return { X, Y, Z };
//}

//Vector3D operator /=(const float rhs)
//{
//	X /= rhs;
//	Y /= rhs;
//	Z /= rhs;

//	return { X, Y, Z };
//}


//float squared(float input) {
//	return input * input;
//}

//// Magnitude calculation (Pythagorean product)
//float VectorMagnitude() {
//	return sqrtf(squared(this->X) + squared(this->Y) + squared(this->Z));
//}

//// Dot Product of two vectors
//float VectorDotProduct(Vector3D input) {
//	return (this->X * input.X) + (this->Y * input.Y) + (this->Z * input.Z);
//}

//// Angle equation of two Vectors
//// cos0 = cross_product(a,b) divided by |a||b|
//float findAngleBetweenVectors(Vector3D input) {
//	return cosf( VectorDotProduct(input)   /   (VectorMagnitude() * input.VectorMagnitude()) );
//}


//void printVector() {
//	std::cout
//		<< "X: "	<< this->X
//		<< ", Y: "	<< this->Y
//		<< ", Z: "	<< this->Z
//	<< std::endl;
//}

// Vector3D operator overloads for: x = x + y
//Vector3D operator+(Vector3D lhs, const Vector3D& rhs)
//{
//	lhs.X += rhs.X;
//	lhs.Y += rhs.Y;
//	lhs.Z += rhs.Z;

//	return lhs;
//}

//Vector3D operator+(Vector3D lhs, const float& rhs)
//{
//	lhs.X += rhs;
//	lhs.Y += rhs;
//	lhs.Z += rhs;

//	return lhs;
//}

//Vector3D operator-(Vector3D lhs, const Vector3D& rhs)
//{
//	lhs.X -= rhs.X;
//	lhs.Y -= rhs.Y;
//	lhs.Z -= rhs.Z;

//	return lhs;
//}

//Vector3D operator-(Vector3D lhs, const float& rhs)
//{
//	lhs.X -= rhs;
//	lhs.Y -= rhs;
//	lhs.Z -= rhs;

//	return lhs;
//}

//Vector3D operator*(Vector3D lhs, const Vector3D& rhs)
//{
//	lhs.X *= rhs.X;
//	lhs.Y *= rhs.Y;
//	lhs.Z *= rhs.Z;

//	return lhs;
//}

//Vector3D operator*(Vector3D lhs, const float& rhs)
//{
//	lhs.X *= rhs;
//	lhs.Y *= rhs;
//	lhs.Z *= rhs;

//	return lhs;
//}

//Vector3D operator/(Vector3D lhs, const Vector3D& rhs)
//{
//	lhs.X /= rhs.X;
//	lhs.Y /= rhs.Y;
//	lhs.Z /= rhs.Z;

//	return lhs;
//}

//Vector3D operator/(Vector3D lhs, const float& rhs)
//{
//	lhs.X /= rhs;
//	lhs.Y /= rhs;
//	lhs.Z /= rhs;

//	return lhs;
//}


#endif
