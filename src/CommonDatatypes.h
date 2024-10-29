
#ifndef COMMON_DATATYPES_CLASS
#define COMMON_DATATYPES_CLASS

// Global Variables
static float TIMESPEED = 1.f;		// Modifier that speeds up or slows down worldspace time.



// Vectors are represented in program as both points and geometric vectors, has mathmatics and operators related to translations, dot/cross product, and magnitude.
// NOTATION: Mark variables for positions as points. Nark variables for directions as Vectors.
struct Vector3D {
	double X, Y, Z;


	Vector3D() { X = 0.0; Y= 0.0; Z = 0.0; }
	Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

	// Construct Directional vector from two points.
	Vector3D(Vector3D tail, Vector3D head) {
		X = head.X - tail.X;
		Y = head.Y - tail.Y;
		Z = head.Z - tail.Z;
	}

	// Utility
	void Randomise(const double WEIGHT);
	void PrintCoordinates();

	// Vector calculations
	double Magnitude();
	double DotProduct(Vector3D input);
	double CrossProduct(Vector3D input);


	// Vector to Vector Operators 
	inline Vector3D operator +=(const Vector3D& rhs) {
		X += rhs.X;
		Y += rhs.Y;
		Z += rhs.Z;

		return *this;
	}

	inline Vector3D operator -=(const Vector3D& rhs) {
		X -= rhs.X;
		Y -= rhs.Y;
		Z -= rhs.Z;

		return *this;
	}

	inline Vector3D operator *=(const Vector3D& rhs) {
		X *= rhs.X;
		Y *= rhs.Y;
		Z *= rhs.Z;

		return *this;
	}

	inline Vector3D operator /=(const Vector3D& rhs) {
		X /= rhs.X;
		Y /= rhs.Y;
		Z /= rhs.Z;

		return *this;
	}

	// Single type operator
	template <typename T>
	inline Vector3D operator +=(const T& rhs) {
		X += rhs;
		Y += rhs;
		Z += rhs;

		return *this;
	}

	template <typename T>
	inline Vector3D operator -=(const T& rhs) {
		X -= rhs;
		Y -= rhs;
		Z -= rhs;

		return *this;
	}

	template <typename T>
	inline Vector3D operator *=(const T& rhs) {
		X *= rhs;
		Y *= rhs;
		Z *= rhs;

		return *this;
	}

	template <typename T>
	inline Vector3D operator /=(const T& rhs) {
		X /= rhs;
		Y /= rhs;
		Z /= rhs;

		return *this;
	}
};


// Operators of LHS + RHS
Vector3D operator +(Vector3D& lhs, const Vector3D& rhs) {
	lhs.X += rhs.X;
	lhs.Y += rhs.Y;
	lhs.Z += rhs.Z;

	return lhs;
}

Vector3D operator -(Vector3D& lhs, const Vector3D& rhs) {
	lhs.X -= rhs.X;
	lhs.Y -= rhs.Y;
	lhs.Z -= rhs.Z;

	return lhs;
}

Vector3D operator *(Vector3D& lhs, const Vector3D& rhs) {
	lhs.X *= rhs.X;
	lhs.Y *= rhs.Y;
	lhs.Z *= rhs.Z;

	return lhs;
}

Vector3D operator /(Vector3D& lhs, const Vector3D& rhs) {
	lhs.X /= rhs.X;
	lhs.Y /= rhs.Y;
	lhs.Z /= rhs.Z;

	return lhs;
}

Vector3D operator +(Vector3D& lhs, const double& rhs) {
	lhs.X += rhs;
	lhs.Y += rhs;
	lhs.Z += rhs;

	return lhs;
}

Vector3D operator -(Vector3D& lhs, const double& rhs) {
	lhs.X -= rhs;
	lhs.Y -= rhs;
	lhs.Z -= rhs;

	return lhs;
}

Vector3D operator *(Vector3D& lhs, const double& rhs) {
	lhs.X *= rhs;
	lhs.Y *= rhs;
	lhs.Z *= rhs;

	return lhs;
}

Vector3D operator /(Vector3D& lhs, const double& rhs) {
	lhs.X /= rhs;
	lhs.Y /= rhs;
	lhs.Z /= rhs;

	return lhs;
}


// lhs += rhs
// we want the lhs to be added to the rhs no questions asked
// lhs + rhs we do not want to IMMEDIATELLY override the original lhs with the new value, we are returning a temporary value that can be used for other things.
// Maybe it could be overriding the lhs, maybe its for an original value, who knows, we just dont want to immediatelly assign the lhs to be the product.


#endif