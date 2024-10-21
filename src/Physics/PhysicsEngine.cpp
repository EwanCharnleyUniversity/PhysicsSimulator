
#include <iostream>

#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPoint) {
	graphics = &graphicsPoint;
}


void PhysicsEngine::Simulate() {

	// Main simulation logic
	while (graphics->window.isOpen()) {


		graphics->Render();
	}
}