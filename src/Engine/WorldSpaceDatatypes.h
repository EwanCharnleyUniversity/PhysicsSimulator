#ifndef WORLDSPACE_DATATYPES_CLASS
#define WORLDSPACE_DATATYPES_CLASS


#include <math.h>


struct worldVector3D {
	float X, Y, Z;

	void VectorAdd(worldVector3D _input) {
		this->X += _input.X;
		this->Y += _input.Y;
		this->Z += _input.Z;
	}

	void VectorMultiplication(float input) {
		this->X *= input;
		this->Y *= input;
		this->Z *= input;
	}

	void VectorDivision(float input) {
		this->X /= input;
		this->Y /= input;
		this->Z /= input;
	}

	float squared(float input) {
		return input * input;
	}


	float VectorMagnitude() {
		float product = sqrtf(squared(this->X) + squared(this->Y) + squared(this->Z));

		return product;
	}
};


#endif