
#include "GraphicsEngine.h"
#include "SFML/Graphics.hpp"
#include "../Objects/ObjectDatatypes.h"

#include <iostream>


Camera::Camera() {
	position = new Point3D{ 0, 0, -500 };
	viewingDistance = 250;
}


void Camera::Simulate() {}



/////////////////////
// GRAPHICS ENGINE //
/////////////////////

GraphicsEngine::GraphicsEngine(int WIDTH, int HEIGHT) {
	Window.create(sf::VideoMode(WIDTH, HEIGHT), "Yggdrasil Engine");
}


// Checks if the point is behind the camera.
bool GraphicsEngine::IsPositionBehind(Point3D* point) {
	if (point->Z - pCamera.position->Z <= 0)
		return true;

	return false;
}


// Takes the distance from the camer and the position point and translates it to 3D rendering
sf::Vector2f GraphicsEngine::WindowTranslation(Point3D* point) {
	
	float distance = point->Z - pCamera.position->Z;

	// PointPos = P * vD / P
	sf::Vector2f translation{
		(float)((point->X - pCamera.position->X) * pCamera.viewingDistance / distance) + Window.getSize().x / 2,
		(float)((point->Y - pCamera.position->Y) * pCamera.viewingDistance / distance) + Window.getSize().y / 2
	};

	return translation;
}


// Culls points that shouldn't be rendered, but are connected to visible points and thus still need to represent solid surfaces.
// Currently isn't functional.
sf::Vector2f GraphicsEngine::WindowCull(Point3D* point) {
	

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