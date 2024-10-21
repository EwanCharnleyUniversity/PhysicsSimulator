
#include "ObjectDatatypes.h"
#include "QuadPlane.h"

#include <iostream>


QuadPlane::QuadPlane() {

	// Testing out Vector3D maths.
	Vector3D a{1, 1, 1};
	a += {1, 1, 1};
	std::cout << a.X << " " << a.Y << " " << a.Z << std::endl;

	a -= {0.25, -1, 1.5};
	std::cout << a.X << " " << a.Y << " " << a.Z << std::endl;

	a *= {4, 1, 1};
	std::cout << a.X << " " << a.Y << " " << a.Z << std::endl;

	a /= {0.5, 0.25, 1.5};
	std::cout << a.X << " " << a.Y << " " << a.Z << std::endl;
}