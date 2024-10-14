#ifndef WORLDSPACE_PARTICLE_CLASS_H
#define WORLDSPACE_PARTICLE_CLASS_H

#include "../Engine/WorldSpaceDatatypes.h"
#include "SFML/Graphics.hpp"


class WorldSpaceParticle {
public:
	WorldSpaceParticle(float _inputWidth);
	WorldSpaceParticle(float _inputWidth, worldVector3D inputPosition, worldVector3D inputVelocity);

	void Simulate();

	void Render(sf::RenderTarget* window, float cameraDistance, float viewingDistance);

private:
	worldVector3D particlePosition;
	worldVector3D particleVelocity;
	
	float TRUE_RADIUS;
};


class WorldSpaceStatic {
public:
	WorldSpaceStatic(float _inputWidth);
	WorldSpaceStatic(float _inputWidth, worldVector3D inputPosition);

	void Render(sf::RenderTarget* window, float cameraDistance, float viewingDistance);

private:
	worldVector3D staticPosition;

	float TRUE_RADIUS;
};


#endif