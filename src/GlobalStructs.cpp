
#include <iostream>

#include "GlobalStructs.h"


static float Square(float input) {
	return input * input;
}

const void Vector3D::Print() {
	std::cout << "X: " << X << " Y: " << Y << " Z: " << Z << std::endl;
}

// Calculate Vector Magnitude
// Square root of (x^2 + y^2 + z^2)
float Vector3D::Magnitude() {
	return sqrt(Square(X) + Square(Y) + Square(Z));
}