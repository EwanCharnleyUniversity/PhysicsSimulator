
#include <iostream>
#include <vector>

#include "PhysicsEngine.h"
#include "../CommonDatatypes.h"
#include "../Graphics/GraphicsEngine.h"
#include "../Objects/QuadPlane.h"
#include "../Objects/Particle.h"


static int ParticleCount = 2500;


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPoint) : graphics(&graphicsPoint) {}


void PhysicsEngine::Simulate() {

	sf::Clock FPS;
	float clock = 0.f;
	srand(time(NULL));

	QuadPlane testPlane;

	// Particle vector for storing particles
	std::vector<Particle> particleVector;
	for (int i = 0; i < ParticleCount; i++) {
		particleVector.push_back({ false, 1.0f });
	}


	// Main simulation loop
	while (graphics->Window.isOpen()) {

		// Sixty Frames Per Second
		int deltaTime = FPS.getElapsedTime().asMilliseconds();
		if (deltaTime < 16) {
			continue;
		}

		clock += 0.025f;


		// Simulate things
		//for (int i = 0; i < particleVector.size(); i++) {
		//	particleVector[i].Simulate();
		//}

		testPlane.Simulate(clock);
		graphics->pCamera.Simulate(clock);

		// Polling and Clearing
		graphics->PollEvents();
		graphics->ClearWindow();

		// Object Rendering
		testPlane.Render(*graphics);
		
		//for (int i = 0; i < particleVector.size(); i++) {
		//	particleVector[i].Render(*graphics);
		//}

		// Display everything
		graphics->DisplayWindow();

		FPS.restart();
	}
}