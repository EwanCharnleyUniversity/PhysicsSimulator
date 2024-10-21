
#include "ObjectDatatypes.h"
#include "QuadPlane.h"

#include <iostream>


QuadPlane::QuadPlane() {

	// Vector Structures
	Vector3D vector( { 0,0,0 }, {0,500,-100} );
	Vector3D origin( {0,0,0}, {100,100,100} );

	std::cout << "Vector parameters for test vector and origin are: " << std::endl;
	vector.PrintVector();
	origin.PrintVector();

	std::cout << "Magnitude of test vector is: " << vector.VectorMagnitude() << std::endl;
	std::cout << "Magnitude of origin vector is: " << origin.VectorMagnitude() << std::endl;
	std::cout << "Dot product of test vector to origin vector is: " << vector.VectorDotProduct(origin) << std::endl;
	std::cout << "Angle betwee test vector and origin vector is: " << vector.findAngleBetweenVectors(origin) << std::endl;
	
}

void QuadPlane::Simulate() {
	std::cout << "Simulated!" << std::endl;
}