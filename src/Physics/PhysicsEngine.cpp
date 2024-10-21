
#include <iostream>

#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"
#include "../Objects/QuadPlane.h"


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPoint) : graphics(&graphicsPoint) {}


void PhysicsEngine::Simulate() {
	sf::Clock FPS;

	// For future plane rendering, but for now it's just used to test Point3D and Vector3D.
	QuadPlane testPlane;

	// Main simulation logic
	while (graphics->window.isOpen()) {

		int deltaTime = FPS.getElapsedTime().asMilliseconds();

		if (deltaTime < 16) {
			continue;
		}

		testPlane.Simulate();
		
		graphics->Render();
		FPS.restart();
	}
}