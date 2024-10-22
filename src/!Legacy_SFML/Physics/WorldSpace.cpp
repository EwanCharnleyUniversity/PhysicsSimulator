
#include <iostream>
#include "WorldSpace.h"


int particleAmount = 16;
float particleRadius = 25.0f;

int WIDTH{ 1536 }, HEIGHT{ 864 };


// Initialises Worldspace by adding particles
WorldSpace::WorldSpace() {

	int objectID = 0;

	worldObjects.worldParticles.push_back({ objectID++, 128.0f, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f}, true});

	for (int i = 0; i < particleAmount; i++) {
		worldObjects.worldParticles.push_back({ objectID++, particleRadius, false });
	}

	// moving Particle MANUAL ADDITION
	worldObjects.worldParticles.push_back({ objectID++, 25.0f, { 500.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f}, false });


	Camera camera(WIDTH, HEIGHT, 0, 0, -250.0f);
	
	float CLOCK = 0;
	int FPS = 0;
	sf::Clock delta;

	while (camera.window.isOpen()) {

		// Sixty Frames Per Second.
		FPS = delta.getElapsedTime().asMilliseconds();
		if (FPS <= 16)
			continue;

		CLOCK += 0.01f;

		sf::Event event;

		while (camera.window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				camera.window.close();
			}
		}

		//camera.cameraPosition.X = sin(CLOCK) * 750;
		//camera.cameraPosition.Y = cos(CLOCK * 3.14159265359) * 300;

		camera.Render(&worldObjects);

		delta.restart();
		FPS = 0;
	}
}