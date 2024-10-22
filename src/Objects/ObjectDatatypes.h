
#ifndef OBJECT_DATATYPES_CLASS
#define OBJECT_DATATYPES_CLASS


// A point is just that, a 3D position in worldspace. It isn't a vector itself.
struct Point3D {
	double X{ 0 }, Y{ 0 }, Z{ 0 };

	void Randomise(const double WEIGHT);
	void PrintCoordinates();


	Point3D operator +(const Point3D& rhs);
	Point3D operator -(const Point3D& rhs);
	Point3D operator *(const Point3D& rhs);
	Point3D operator /(const Point3D& rhs);

	Point3D operator +=(const Point3D& rhs);
	Point3D operator -=(const Point3D& rhs);
	Point3D operator *=(const Point3D& rhs);
	Point3D operator /=(const Point3D& rhs);

	template <typename T>
	Point3D operator +(const T& rhs);

	template <typename T>
	Point3D operator -(const T& rhs);

	template <typename T>
	Point3D operator *(const T& rhs);

	template <typename T>
	Point3D operator /(const T& rhs);
};


// Vectors are the product of a tail point and head point. This can then be used to calculate things such as magnitudes, dot products, etc.
struct Vector3D : Point3D {

	Vector3D(Point3D head, Point3D tail) {
		X = tail.X - head.X;
		Y = tail.Y - head.Y;
		Z = tail.Z - head.Z;
	}

	double VectorMagnitude();
	double VectorDotProduct(Vector3D input);
	double findAngleBetweenVectors(Vector3D input);
};


#endif