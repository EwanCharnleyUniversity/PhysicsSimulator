#ifndef PARTICLE_CLASS_HPP
#define PARTICLE_CLASS_HPP


struct Vector3D;


// A 3D sphere in worldspace, with a defined radius and physics to determine collision.
class Particle {
public:
	float		Radius = 2.5f;
	Vector3D*	position;
	Vector3D*	velocity;

	Particle();

	void Simulate();
};


#endif
