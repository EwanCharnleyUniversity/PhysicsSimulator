
#include <iostream>

#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPoint) {
	graphics = &graphicsPoint;
}


void PhysicsEngine::Simulate() {
	sf::Clock FPS;

	// Main simulation logic
	while (graphics->window.isOpen()) {

		int deltaTime = FPS.getElapsedTime().asMilliseconds();

		if (deltaTime < 16) {
			continue;
		}


		graphics->Render();
		FPS.restart();
	}
}