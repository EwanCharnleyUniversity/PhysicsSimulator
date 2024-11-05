#ifndef PARTICLE_CLASS_HPP
#define PARTICLE_CLASS_HPP


// A structure that handles three worldspace coordinates.
// This could represent either a point or a geometric vector.
struct Vector3D {
	float X, Y, Z;
};


// A 3D sphere in worldspace, with a defined radius and physics to determine collision.
class Particle {
public:
	float		Radius = 2.5f;
	Vector3D	position, velocity;

	Particle();

	void Simulate();
	void Render();
};


#endif
