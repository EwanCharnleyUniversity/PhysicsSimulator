
#include <iostream>
#include <vector>

#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"
#include "../Objects/QuadPlane.h"
#include "../Objects/Particle.h"

static int ParticleCount = 2500;


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPoint) : graphics(&graphicsPoint) {}


void PhysicsEngine::Simulate() {
	sf::Clock FPS;
	srand(time(NULL));

	// Particle vector for storing particles
	std::vector<Particle> particleVector;
	for (int i = 0; i < ParticleCount; i++) {
		particleVector.push_back({ false, 1.0f });
	}


	// Main simulation logic
	while (graphics->Window.isOpen()) {

		// Sixty Frames Per Second
		int deltaTime = FPS.getElapsedTime().asMilliseconds();
		if (deltaTime < 16) {
			continue;
		}

		// Simulate things
		for (int i = 0; i < particleVector.size(); i++) {
			particleVector[i].Simulate();
		}
		graphics->pCamera.Simulate();


		// Start of Rendering
		graphics->PollEvents();
		graphics->ClearWindow();

		// Object Rendering
		for (int i = 0; i < particleVector.size(); i++) {
			particleVector[i].Render(*graphics);
		}

		// Display everything
		graphics->DisplayWindow();

		FPS.restart();
	}
}