#ifndef WORLDSPACE_PARTICLE_CLASS_H
#define WORLDSPACE_PARTICLE_CLASS_H


#include "../Engine/WorldSpaceDatatypes.h"


class WorldSpaceParticle {
public:
	WorldSpaceParticle(float _inputWidth);

	void Simulate();

	void Render(sf::RenderTarget* window, float cameraDistance, float viewingDistance);

private:
	worldVector3D particlePosition;
	worldVector3D particleVelocity;
	
	float TRUE_RADIUS;
};


#endif