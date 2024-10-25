
#ifndef COMMON_DATATYPES_CLASS
#define COMMON_DATATYPES_CLASS

// Global Variables
static float TIMESPEED = 1.f;		// Modifier that speeds up or slows down worldspace time.



// Vectors are represented in program as both points and geometric vectors, has mathmatics and operators related to translations, dot/cross product, and magnitude.
// NOTATION: Mark variables for positions as points. Nark variables for directions as Vectors.
struct Vector3D {
	double X{ 0 }, Y{ 0 }, Z{ 0 };


	Vector3D() { X = 0.0; Y= 0.0; Z = 0.0; }
	Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

	// Construct Directional vector from two points.
	Vector3D(Vector3D head, Vector3D tail) {
		X = tail.X - head.X;
		Y = tail.Y - head.Y;
		Z = tail.Z - head.Z;
	}

	// Utility
	void Randomise(const double WEIGHT);
	void PrintCoordinates();

	// Vector calculations
	double Magnitude();
	double DotProduct(Vector3D input);
	double CrossProduct(Vector3D input);


	// Vector to Vector Operators 
	inline Vector3D operator +(const Vector3D& rhs) {
		X += rhs.X;
		Y += rhs.Y;
		Z += rhs.Z;

		return *this;
	}

	inline Vector3D operator -(const Vector3D& rhs) {
		X -= rhs.X;
		Y -= rhs.Y;
		Z -= rhs.Z;

		return *this;
	}

	inline Vector3D operator *(const Vector3D& rhs) {
		X *= rhs.X;
		Y *= rhs.Y;
		Z *= rhs.Z;

		return *this;
	}

	inline Vector3D operator /(const Vector3D& rhs) {
		X /= rhs.X;
		Y /= rhs.Y;
		Z /= rhs.Z;

		return *this;
	}

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

	template <typename T>
	inline Vector3D operator +(const T& rhs) {
		X += rhs;
		Y += rhs;
		Z += rhs;
	
		return *this;
	}

	template <typename T>
	inline Vector3D operator -(const T& rhs) {
		X -= rhs;
		Y -= rhs;
		Z -= rhs;
		
		return *this;
	}

	template <typename T>
	inline Vector3D operator *(const T& rhs) {
		X *= rhs;
		Y *= rhs;
		Z *= rhs;

		return *this;
	}

	template <typename T>
	inline Vector3D operator /(const T& rhs) {
		X /= rhs;
		Y /= rhs;
		Z /= rhs;

		return *this;
	}

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



#endif