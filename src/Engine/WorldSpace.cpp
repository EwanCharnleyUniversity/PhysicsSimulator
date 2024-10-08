
#include <iostream>
#include "WorldSpace.h"


// DEBUG: Point coordinates of a cube (or cuboid)
worldCoordinate3D points[] = {
	{  250.0, -250.0, 150.0},
	{  250.0,  250.0, 150.0},
	{ -250.0, -250.0, 150.0},
	{ -250.0,  250.0, 150.0},

	{  250.0, -250.0, 650.0},
	{  250.0,  250.0, 650.0},
	{ -250.0, -250.0, 650.0},
	{ -250.0,  250.0, 650.0}
};



Camera::Camera(int _inputWidth, int _inputHeight, float x, float y, float z) {
	window.create(sf::VideoMode(_inputWidth, _inputHeight), "Worldspace Renderer");

	cameraPosition.positionX = x;
	cameraPosition.positionY = y;
	cameraPosition.positionZ = z;
}


void Camera::Render() {
	// Probably just need to place the render into a engine class or something.
	float clock = 0;

	while (window.isOpen()) {
		clock += 0.0001f;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color(0,0,0));

		// Do worldspace translation
		std::vector<sf::CircleShape> circles;
		for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++) {

			// Only grabs the distance in the Z direction.
			float particleDistance = points[i].positionZ - viewingDistance;

			if (particleDistance <= 0)
				continue;

			float adjustedY = points[i].positionY * (viewingDistance / particleDistance);
			float adjustedX = points[i].positionX * (viewingDistance / particleDistance);


			// Very dirty points
			circles.push_back(sf::CircleShape(5.0f));
			circles.back().setOrigin(5.0f, 5.0f);
			circles.back().setFillColor(sf::Color(255, 255, 255, 255));

			circles.back().setPosition(
				adjustedX + window.getSize().x / 2,
				adjustedY + window.getSize().y / 2
			);

			window.draw(circles.back());
		}

		window.display();
	}
}