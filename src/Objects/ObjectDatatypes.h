
#ifndef OBJECT_DATATYPES_CLASS
#define OBJECT_DATATYPES_CLASS

#include <vector>
#include <iostream>


namespace ObjectDatatype {

	struct Vector3D {
		float X, Y, Z;

		// Operators for inputting other Vectors
		void VectorAdd(Vector3D _input) {
			this->X += _input.X;
			this->Y += _input.Y;
			this->Z += _input.Z;
		}

		void VectorSubtraction(Vector3D input) {
			this->X -= input.X;
			this->Y -= input.Y;
			this->Z -= input.Z;
		}

		void VectorMultiplication(Vector3D input) {
			this->X *= input.X;
			this->Y *= input.Y;
			this->Z *= input.Z;
		}

		void VectorDivision(Vector3D input) {
			this->X /= input.X;
			this->Y /= input.Y;
			this->Z /= input.Z;
		}


		float squared(float input) {
			return input * input;
		}

		// Magnitude calculation (Pythagorean product)
		float VectorMagnitude() {
			return sqrtf(squared(this->X) + squared(this->Y) + squared(this->Z));
		}

		// Dot Product of two vectors
		float VectorDotProduct(Vector3D input) {
			return (this->X * input.X) + (this->Y * input.Y) + (this->Z * input.Z);
		}

		// Angle equation of two Vectors
		// cos0 = cross_product(a,b) divided by |a||b|
		float findAngleBetweenVectors(Vector3D input) {
			return cosf( VectorDotProduct(input)   /   (VectorMagnitude() * input.VectorMagnitude()) );
		}


		void printVector() {
			std::cout
				<< "X: "	<< this->X
				<< ", Y: "	<< this->Y
				<< ", Z: "	<< this->Z
			<< std::endl;
		}
	};
}


#endif
