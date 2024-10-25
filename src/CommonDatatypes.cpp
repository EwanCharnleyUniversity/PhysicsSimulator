
#include "CommonDatatypes.h"
#include <iostream>
#include <math.h>
#include <random>


// Simple Squared Product equation, x^2
template <typename T>
double Squared(T input) {
	return input * input;
}



// Takes a Weight modifier and calculates a result with precision for minute differences in randomised output.
void Vector3D::Randomise(const double WEIGHT) {
	X = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / WEIGHT)) - WEIGHT / 2;
	Y = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / WEIGHT)) - WEIGHT / 2;
	Z = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / WEIGHT)) - WEIGHT / 2;

}

// Just prints the coordinates of the Vector
void Vector3D::PrintCoordinates() {
	std::cout
	<< "X: " << this->X
	<< ", Y: " << this->Y
	<< ", Z: " << this->Z
	<< std::endl;
}

// Magnitude of vector |x|
// square root of (x^2 + y^2 + z^2)
double Vector3D::Magnitude() {
	return sqrt(
		Squared(this->X) +
		Squared(this->Y) +
		Squared(this->Z)
	);
}

// Find dot product of a vector
// (x.x * y.x) + (x.y * y.y) + (x.z * y.z)
double Vector3D::DotProduct(Vector3D input) {
	return (this->X * input.X)
		+ (this->Y * input.Y)
		+ (this->Z * input.Z);
}


//// Cross Product equation of two Vectors, useful for finding the angle between them.
//// cos0 = Dot_Product(a,b) divided by |a||b|
double Vector3D::CrossProduct(Vector3D input) {
	return cos(
		DotProduct(input) / (this->Magnitude() * input.Magnitude())
	);
}