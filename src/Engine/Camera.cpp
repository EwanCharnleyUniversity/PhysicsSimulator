
#include <iostream>
#include "WorldSpace.h"


Camera::Camera(int _inputWidth, int _inputHeight, float z) {
	window.create(sf::VideoMode(_inputWidth, _inputHeight), "Worldspace Renderer");

	cameraZ = z;
}


void Camera::Render(worldContainers* Objects) {
	window.clear(sf::Color(0, 0, 0));

	// Render World Objects
	for (int i = 0; i < Objects->worldParticles.size(); i++) {
		Objects->worldParticles.at(i).Render(&window, cameraZ, viewingDistance);
		Objects->worldParticles.at(i).Simulate(&window, cameraZ, viewingDistance, &Objects->worldParticles);
		//Objects->worldParticles.at(i).Render(&window, cameraPosition, viewingDistance);
	}

	window.display();
}