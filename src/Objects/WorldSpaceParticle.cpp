

#include <random>
#include <iostream>
#include "WorldSpaceParticle.h"


int WEIGHT = 500;
sf::Color BASE_COLOUR = { 255,255,255,255 };
sf::Color COLLISION_COLOUR = { 255,0,0,255 };


// Base Particle Shape Constructor
sf::CircleShape baseParticle(float RADIUS) {
	sf::CircleShape base;

	base.setRadius(RADIUS);
	base.setPointCount(64);
	base.setOrigin(RADIUS, RADIUS);
	base.setPosition({ 0,0 });
	base.setFillColor(BASE_COLOUR);

	return base;
}


// Only Width Input, random position, non static
WorldSpaceParticle::WorldSpaceParticle(int _id, float _inputWidth, bool staticVal)
	: ID(_id), TRUE_RADIUS(_inputWidth), isStatic(staticVal)
{

	particlePosition.X = (float)(rand() % 1000 - 500);
	particlePosition.Y = (float)(rand() % 1000 - 500);
	particlePosition.Z = (float)(rand() % 1000 - 500);

	particleVelocity = Vector3D{
		(float)(rand() % WEIGHT - (WEIGHT / 2)) / 10000,
		(float)(rand() % WEIGHT - (WEIGHT / 2)) / 10000,
		(float)(rand() % WEIGHT - (WEIGHT / 2)) / 10000
	};

	particleShape = baseParticle(5.0f);
}

WorldSpaceParticle::WorldSpaceParticle(int _id, float _inputWidth, Vector3D inputPosition, Vector3D inputVelocity, bool staticVal)
	: ID(_id), TRUE_RADIUS(_inputWidth), particlePosition(inputPosition), particleVelocity(inputVelocity), isStatic(staticVal)
{
	particleShape = baseParticle(5.0f);
}


void WorldSpaceParticle::Render(sf::RenderTarget* window, Vector3D cameraPosition, float viewingDistance) {
	
	float distance = particlePosition.Z - cameraPosition.Z;

	if (distance <= 0)
		return;
	

	float RENDER_RADIUS = TRUE_RADIUS * viewingDistance / distance;

	particleShape.setRadius(RENDER_RADIUS);
	particleShape.setOrigin(RENDER_RADIUS, RENDER_RADIUS);

	particleShape.setPosition(
		((particlePosition.X - cameraPosition.X) * viewingDistance / distance) + window->getSize().x / 2,
		((particlePosition.Y - cameraPosition.Y) * viewingDistance / distance) * -1 + window->getSize().y / 2
	);

	window->draw(particleShape);
}



void WorldSpaceParticle::Simulate(std::vector<WorldSpaceParticle>* objects) {
	bool hasCollided = false;

	if (isStatic)
		return;

	// Calculation for collision O(n)
	for (int i = 0; i < objects->size(); i++) {

		WorldSpaceParticle& target = objects->at(i);

		// Skip if the Target is the Parent.
		if (target.ID == ID)
			continue;

		Vector3D toTargetVector = target.particlePosition;
		toTargetVector.VectorSubtraction(particlePosition);

		// Calculate the distance between particles by taking the angle between the velocity of the parent and the Target Vector, then multiply it by the magnitude of the Target Vector.
		float distanceBetweenParticles = sin(particleVelocity.findAngleBetweenVectors(toTargetVector)) * toTargetVector.VectorMagnitude();
		float collisionDistance = TRUE_RADIUS / 2 + target.TRUE_RADIUS / 2;

		if (distanceBetweenParticles <= collisionDistance)
		{
			hasCollided = true;
		}
	}

	if (hasCollided == true) {
		particleShape.setFillColor(COLLISION_COLOUR);
	}
	else {
		particleShape.setFillColor(BASE_COLOUR);
	}

	// Find world center and put the results into a vector.
	Vector3D worldCenter{
		0 - particlePosition.X,
		0 - particlePosition.Y,
		0 - particlePosition.Z
	};

	// Create Gravitational Weight.
	particleVelocity.X += worldCenter.X / 10000000.0f;
	particleVelocity.Y += worldCenter.Y / 10000000.0f;
	particleVelocity.Z += worldCenter.Z / 10000000.0f;

	// Add Gravity
	particlePosition.VectorAdd(particleVelocity);

}