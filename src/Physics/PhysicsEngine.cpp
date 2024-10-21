
#include <iostream>

#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"
#include "../Objects/QuadPlane.h"


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPoint) : graphics(&graphicsPoint) {}


void PhysicsEngine::Simulate() {
	sf::Clock FPS;

	srand(time(NULL));

	QuadPlane testPlane;

	// Main simulation logic
	while (graphics->Window.isOpen()) {

		int deltaTime = FPS.getElapsedTime().asMilliseconds();

		if (deltaTime < 16) {
			continue;
		}

		// Simulate
		testPlane.Simulate();
		graphics->pCamera.Simulate();

		// Start of Rendering
		graphics->PollEvents();
		graphics->ClearWindow();

		// Object Rendering
		testPlane.Render(*graphics);

		// Display everything
		graphics->DisplayWindow();

		FPS.restart();
	}
}