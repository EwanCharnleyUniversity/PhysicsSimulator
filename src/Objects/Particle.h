
#ifndef PARTICLE_CLASS_HPP
#define PARTICLE_CLASS_HPP

#include "Objects.h"


class Particle : Objects {
public:
	Particle(bool stat, float radius);

	virtual void Simulate();
	virtual void Render(GraphicsEngine& graphics);

private:
	bool isStatic;
	float TRUE_RADIUS = 0.f;
	Point3D* position;
	Point3D* velocity;
};


#endif
