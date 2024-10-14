

#include <iostream>
#include "WorldSpace.h"


Camera::Camera(int _inputWidth, int _inputHeight, float x, float y, float z) {
	window.create(sf::VideoMode(_inputWidth, _inputHeight), "Worldspace Renderer");

	cameraPosition.X = x;
	cameraPosition.Y = y;
	cameraPosition.Z = z;
}


void Camera::Render(worldContainers* Objects) {
	float zVelocity = 0;

	while (window.isOpen()) {
		cameraPosition.Z += zVelocity;

		sf::Event event;
		while (window.pollEvent(event)) {
			// Swap this to event handler function

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.scancode == sf::Keyboard::Scan::W || event.key.scancode == sf::Keyboard::Scan::Up) {
					zVelocity += 0.001f;
				}
				else if (event.key.scancode == sf::Keyboard::Scan::S || event.key.scancode == sf::Keyboard::Scan::Down) {
					zVelocity += -0.001f;
				}
				else if (event.key.scancode == sf::Keyboard::Scan::Space) {
					zVelocity = 0;
				}
			}
			else if (event.type == sf::Event::MouseWheelScrolled) {
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					zVelocity *= 1.0f + event.mouseWheelScroll.delta / 10;
				}
			}
		}

		window.clear(sf::Color(0, 0, 0));

		// World Objects to the Render
		for (int i = 0; i < Objects->worldStatics.size(); i++) {
			Objects->worldStatics.at(i).Render(&window, cameraPosition.Z, viewingDistance);
		}

		for (int i = 0; i < Objects->worldParticles.size(); i++) {
			Objects->worldParticles.at(i).Simulate();
			Objects->worldParticles.at(i).Render(&window, cameraPosition.Z, viewingDistance);
		}

		window.display();
	}
}