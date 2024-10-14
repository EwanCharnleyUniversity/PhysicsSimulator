#ifndef WORLDSPACE_DATATYPES_CLASS
#define WORLDSPACE_DATATYPES_CLASS

#include "vector"


struct worldVector3D {
	float X, Y, Z;

	void VectorAdd(worldVector3D _input) {
		this->X += _input.X;
		this->Y += _input.Y;
		this->Z += _input.Z;
	}
};


#endif