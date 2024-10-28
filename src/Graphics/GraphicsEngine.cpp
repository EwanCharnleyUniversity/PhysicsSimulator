
#include "GraphicsEngine.h"
#include "SFML/Graphics.hpp"
#include "../CommonDatatypes.h"

#include <iostream>


// Camera //

Camera::Camera() {
	position = new Vector3D{ 0, 0, -500 };
	viewingDistance = 250;
}

// Rocks Camera back and forth
void Camera::Simulate(float time) {
	//position->Z = -500 + ( - 250 * (sin(time) - sin(time) / 2));
}




// Graphics Engine //

GraphicsEngine::GraphicsEngine(int WIDTH, int HEIGHT) {
	Window.create(sf::VideoMode(WIDTH, HEIGHT), "Yggdrasil Engine");
}


// Checks if the vertex is behind the camera.
bool GraphicsEngine::IsPositionBehind(Vector3D* point) {
	if (point->Z - pCamera.position->Z <= 0)
		return true;

	return false;
}


// Takes the distance from the camera and the Point and translates it to 3D rendering
sf::Vector2f GraphicsEngine::WindowTranslation(Vector3D* point) {
	
	double distance = point->Z - pCamera.position->Z;

	// PointPos = P * vD / P
	sf::Vector2f translation{
		(float)((point->X - pCamera.position->X) * pCamera.viewingDistance / distance) + Window.getSize().x / 2,
		(float)((point->Y - pCamera.position->Y) * pCamera.viewingDistance / distance) * - 1 + Window.getSize().y / 2
	};

	return translation;
}


// Clips Vertices that shouldn't be rendered yet are connected to visible points, thus they still need to represent solid surfaces.
sf::Vector2f GraphicsEngine::WindowClip(Vector3D* point) {
	
	sf::Vector2f culled{
		(float)point->X,
		(float)point->Y
	};

	return culled;
}



void GraphicsEngine::PollEvents() {
	sf::Event events;

	while (Window.pollEvent(events)) {
		if (events.type == sf::Event::Closed) {
			Window.close();
		}
	}
}


void GraphicsEngine::ClearWindow() {
	Window.clear({ 0, 0, 0 });
}

void GraphicsEngine::Draw(const sf::Drawable &drawable) {
	Window.draw(drawable);
}

void GraphicsEngine::DisplayWindow() {
	Window.display();
}