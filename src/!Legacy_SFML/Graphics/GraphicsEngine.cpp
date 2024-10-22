
#include "GraphicsEngine.h"
#include "SFML/Graphics.hpp"
#include "../Objects/ObjectDatatypes.h"

#include <iostream>


Camera::Camera() {
	position = new Point3D{ 0,0,-250.0 };
}

void Camera::Simulate() {
	//position->Z += -1;
}


bool GraphicsEngine::IsPositionBehind(double pointZ) {
	if (pCamera.position->Z - pointZ <= 0)
		return false;

	return true;
}


sf::Vector2f GraphicsEngine::WindowTranslation(Point3D* point) {
	float distance = pCamera.position->Z - point->Z;

	sf::Vector2f translation{
		(float)((point->X - pCamera.position->X) * pCamera.viewingDistance / distance) + Window.getSize().x / 2,
		(float)((point->Y - pCamera.position->Y) * pCamera.viewingDistance / distance) + Window.getSize().y / 2
	};

	return translation;
}



GraphicsEngine::GraphicsEngine(int WIDTH, int HEIGHT) {
	Window.create(sf::VideoMode(WIDTH, HEIGHT), "Yggdrasil Engine");
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