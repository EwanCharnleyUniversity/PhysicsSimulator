

#include <random>
#include <iostream>
#include "WorldSpaceParticle.h"

int WEIGHT = 500;

WorldSpaceParticle::WorldSpaceParticle(float _inputWidth) : TRUE_RADIUS(_inputWidth) {
	particlePosition.X = rand() % 1000 - 500;
	particlePosition.Y = rand() % 1000 - 500;
	particlePosition.Z = rand() % 1000 - 500;

	particleVelocity = worldVector3D{
		(float)(rand() % WEIGHT - (WEIGHT / 2)) / 10000,
		(float)(rand() % WEIGHT - (WEIGHT / 2)) / 10000,
		(float)(rand() % WEIGHT - (WEIGHT / 2)) / 10000
	};
}

WorldSpaceParticle::WorldSpaceParticle(float _inputWidth, worldVector3D inputPosition, worldVector3D inputVelocity)
	: TRUE_RADIUS(_inputWidth), particlePosition(inputPosition), particleVelocity(inputVelocity) { }


void WorldSpaceParticle::Simulate() {

	// Find world center and put the results into a vector.
	worldVector3D worldCenter{
		0 - particlePosition.X,
		0 - particlePosition.Y,
		0 - particlePosition.Z
	};

	particleVelocity.X += worldCenter.X / 10000000.0f;
	particleVelocity.Y += worldCenter.Y / 10000000.0f;
	particleVelocity.Z += worldCenter.Z / 10000000.0f;

	particlePosition.VectorAdd(particleVelocity);
}


void WorldSpaceParticle::Render(sf::RenderTarget* window, float cameraDistance, float viewingDistance) {
	float particleDistance = (particlePosition.Z - cameraDistance) - viewingDistance;

	if (particleDistance <= 0)
		return;

	// WorldSpace Transformations
	float adjustedX = particlePosition.X * viewingDistance / particleDistance;
	float adjustedY = particlePosition.Y * viewingDistance / particleDistance;
	float RENDER_RADIUS = TRUE_RADIUS * viewingDistance / particleDistance;

	// Particle circle parameters
	sf::CircleShape circle(RENDER_RADIUS, 100);
	circle.setOrigin(RENDER_RADIUS, RENDER_RADIUS);

	circle.setPosition(
		adjustedX + window->getSize().x / 2,
		adjustedY * -1 + window->getSize().y / 2
	);

	circle.setFillColor(sf::Color(255, 255, 255, 255));

	window->draw(circle);
}



// STATIC PARTICLE //

WorldSpaceStatic::WorldSpaceStatic(float _inputWidth) : TRUE_RADIUS(_inputWidth) {
	staticPosition.X = rand() % 1000 - 500;
	staticPosition.Y = rand() % 1000 - 500;
	staticPosition.Z = rand() % 1000 - 500;
}

WorldSpaceStatic::WorldSpaceStatic(float _inputWidth, worldVector3D inputPosition)
	: TRUE_RADIUS(_inputWidth), staticPosition(inputPosition) {}


void WorldSpaceStatic::Render(sf::RenderTarget* window, float cameraDistance, float viewingDistance) {
	float staticDistance = (staticPosition.Z - cameraDistance) - viewingDistance;

	if (staticDistance <= 0)
		return;

	// WorldSpace Transformations
	float adjustedX = staticPosition.X * viewingDistance / staticDistance;
	float adjustedY = staticPosition.Y * viewingDistance / staticDistance;
	float RENDER_RADIUS = TRUE_RADIUS * viewingDistance / staticDistance;

	// Particle circle parameters
	sf::CircleShape circle(RENDER_RADIUS, 100);
	circle.setOrigin(RENDER_RADIUS, RENDER_RADIUS);

	circle.setPosition(
		adjustedX + window->getSize().x / 2,
		adjustedY * -1 + window->getSize().y / 2
	);

	circle.setFillColor(sf::Color(255, 255, 255, 255));

	window->draw(circle);
}

