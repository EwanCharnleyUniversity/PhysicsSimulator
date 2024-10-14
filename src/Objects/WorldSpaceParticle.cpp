

#include "random"
#include "SFML/Graphics.hpp"
#include "WorldSpaceParticle.h"


WorldSpaceParticle::WorldSpaceParticle(float _inputWidth) : TRUE_RADIUS(_inputWidth) {
	particlePosition.X = rand() % 1000 - 500;
	particlePosition.Y = rand() % 1000 - 500;
	particlePosition.Z = rand() % 1000 - 500;

	particleVelocity.X = (rand() % 10 - 5) / 1000.0f;
	particleVelocity.Y = (rand() % 10 - 5) / 1000.0f;
	particleVelocity.Z = (rand() % 10 - 5) / 1000.0f;
}


void WorldSpaceParticle::Simulate() {
	particlePosition.VectorAdd(particleVelocity);
}


void WorldSpaceParticle::Render(sf::RenderTarget* window, float cameraDistance, float viewingDistance) {
	float particleDistance = (particlePosition.Z - cameraDistance) - viewingDistance;

	if (particleDistance <= 0)
		return;

	float adjustedX = particlePosition.X * viewingDistance / particleDistance;
	float adjustedY = particlePosition.Y * viewingDistance / particleDistance;

	float RENDER_RADIUS = TRUE_RADIUS * viewingDistance / particleDistance;

	sf::CircleShape circle(RENDER_RADIUS);

	circle.setOrigin(RENDER_RADIUS / 2, RENDER_RADIUS / 2);
	circle.setPosition(
		adjustedX + window->getSize().x / 2,
		adjustedY + window->getSize().y / 2
	);

	int COLOR = 255;

	circle.setFillColor(sf::Color(COLOR, COLOR, COLOR, 255));

	window->draw(circle);
}


