
#include <iostream>
#include "WorldSpace.h"


Camera::Camera(int _inputWidth, int _inputHeight, float x, float y, float z) {
	window.create(sf::VideoMode(_inputWidth, _inputHeight), "Worldspace Renderer");

	cameraPosition.X = x;
	cameraPosition.Y = y;
	cameraPosition.Z = z;
}


void Camera::Render(worldContainers* Objects) {
	window.clear(sf::Color(0, 0, 0));

	// Render World Objects
	for (int i = 0; i < Objects->worldParticles.size(); i++) {
		Objects->worldParticles.at(i).Simulate(&Objects->worldParticles);
		//Objects->worldParticles.at(i).Render(&window, cameraPosition, viewingDistance);
		Objects->worldParticles.at(i).Render(&window, cameraPosition, viewingDistance);
	}

	window.display();
}