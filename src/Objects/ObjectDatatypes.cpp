
#include "ObjectDatatypes.h"
#include <iostream>
#include <math.h>
#include <random>


double DoubleSquared(double input) {
	return input * input;
}


////////////////////////
// 3D POINT FUNCTIONS //
////////////////////////


// Takes a Weight modifier and calculates a double result with low degrees for fairly minute differences in randomised output.
void Point3D::Randomise(const double WEIGHT) {
	X = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / WEIGHT)) - WEIGHT / 2;
	Y = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / WEIGHT)) - WEIGHT / 2;
	Z = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / WEIGHT)) - WEIGHT / 2;

}


void Point3D::PrintCoordinates() {
	std::cout
	<< "X: " << this->X
	<< ", Y: " << this->Y
	<< ", Z: " << this->Z
	<< std::endl;
}


//////////////////////////
// 3D VECTOR OPERATIONS //
//////////////////////////


// Magnitude of vector |x|
// square root of (x^2 + y^2 + z^2)
double Vector3D::VectorMagnitude() {
	return sqrt(
		DoubleSquared(this->X) +
		DoubleSquared(this->Y) +
		DoubleSquared(this->Z)
	);
}

// Find dot product of a vector: x.y
// (x.x * y.x) + (x.y * y.y) + (x.z * y.z)
double Vector3D::VectorDotProduct(Vector3D input) {
	return (this->X * input.X)
		+ (this->Y * input.Y)
		+ (this->Z * input.Z);
}


//// Angle equation of two Vectors
//// cos0 = cross_product(a,b) divided by |a||b|
double Vector3D::findAngleBetweenVectors(Vector3D input) {
	return cos(
		VectorDotProduct(input) / (this->VectorMagnitude() * input.VectorMagnitude())
	);
}