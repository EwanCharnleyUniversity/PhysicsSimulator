
#include <iostream>

#include "Particle.h"
#include "../Shaders/Buffers.h"
#include "../GlobalStructs.h"



Particle::Particle() {
	position = new Vector3D{ 2.5f , -1.0f , 3.3f };
	velocity = new Vector3D{ 0.0f , 0.0f , 0.0f };
}


void Particle::Simulate() {

	Vector3D distanceToCenter = Vector3D{ 0.0f,0.0f,0.0f } - *position;

	// force = Gravity(mass1 * mass2 / magnitude^2)
	float force = 0.1f * (1 * 1 / (distanceToCenter.Magnitude() * distanceToCenter.Magnitude()));
	*velocity += Vector3D{distanceToCenter.X * force, distanceToCenter.Y * force, distanceToCenter.Z * force};

	*position += *velocity;
	position->Print();
}