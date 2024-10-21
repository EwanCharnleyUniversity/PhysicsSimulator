
#include "ObjectDatatypes.h"
#include <iostream>
#include <math.h>

double DoubleSquared(double input) {
	return input * input;
}



// VECTOR OPERATIONS //
///////////////////////


// Magnitude of vector |x|
// square root of  x^2  +  y^2  +  z^2
double Vector3D::VectorMagnitude() {
	return sqrt(
		DoubleSquared(this->Vector.X) +
		DoubleSquared(this->Vector.Y) +
		DoubleSquared(this->Vector.Z)
	);
}

// Find dot product of a vector: x.y
// (x.x * y.x) + (x.y * y.y) + (x.z * y.z)
double Vector3D::VectorDotProduct(Vector3D input) {
	return (this->Vector.X * input.Vector.X)
		+ (this->Vector.Y * input.Vector.Y)
		+ (this->Vector.Z * input.Vector.Z);
}


//// Angle equation of two Vectors
//// cos0 = cross_product(a,b) divided by |a||b|
double Vector3D::findAngleBetweenVectors(Vector3D input) {
	return cos(
		VectorDotProduct(input) / (this->VectorMagnitude() * input.VectorMagnitude())
	);
}


void Vector3D::PrintVector() {
	std::cout
		<< "X: "	<< this->Vector.X
		<< ", Y: "	<< this->Vector.Y
		<< ", Z: "	<< this->Vector.Z
	<< std::endl;
}