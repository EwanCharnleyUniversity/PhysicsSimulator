
#ifndef GRAPHICS_DATATYPES_CLASS
#define GRAPHICS_DATATYPES_CLASS

#include "../CommonDatatypes.h"


// Contains three vertices to make a whole triangle.
struct Triangle {
	Vector3D vertices[3];
};


// four by four matrix
struct mat4 {
	double m[4][4];

	inline mat4 operator *() {
		


		return *this;
	}
};


#endif 