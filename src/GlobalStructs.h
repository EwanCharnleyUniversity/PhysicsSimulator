#ifndef GLOBAL_STRUCTS_CLASS_HPP
#define GLOBAL_STRUCTS_CLASS_HPP



// Three Coordinates denoting a Vector in 3D space
// Can also represent static Points.
struct Vector3D {
	float X, Y, Z;

	float Magnitude();

	const void Print();


	// Addition
	inline Vector3D operator +(const Vector3D& lhs) {
		this->X += lhs.X;
		this->Y += lhs.Y;
		this->Z += lhs.Z;

		return *this;
	}

	inline Vector3D operator +=(const Vector3D& lhs) {
		return operator+(lhs);
	}

	// Subtraction
	inline Vector3D operator -(const Vector3D& lhs) {
		this->X -= lhs.X;
		this->Y -= lhs.Y;
		this->Z -= lhs.Z;

		return *this;
	}

	inline Vector3D operator -=(const Vector3D& lhs) {
		return operator-(lhs);
	}

	// Multiplication
	inline Vector3D operator *(const Vector3D& lhs) {
		this->X *= lhs.X;
		this->Y *= lhs.Y;
		this->Z *= lhs.Z;

		return *this;
	}

	inline Vector3D operator *=(const Vector3D& lhs) {
		return operator*(lhs);
	}

	// Division
	inline Vector3D operator /(const Vector3D& lhs) {
		this->X /= lhs.X;
		this->Y /= lhs.Y;
		this->Z /= lhs.Z;

		return *this;
	}

	inline Vector3D operator /=(const Vector3D& lhs) {
		return operator/(lhs);
	}
};


#endif
