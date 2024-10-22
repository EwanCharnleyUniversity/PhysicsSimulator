
#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP

#include "SFML/Graphics.hpp"


struct Point3D;


class Camera {
public:
	Camera();
	void Simulate();

	double viewingDistance = 100.0;
	Point3D* position;
};


class GraphicsEngine {
public:
	sf::RenderWindow Window;
	Camera pCamera;

	GraphicsEngine(int WIDTH, int HEIGHT);
	
	// Event Polling
	void PollEvents();

	// Window Functions
	void ClearWindow();
	void Draw(const sf::Drawable& drawable);
	void DisplayWindow();

	// Transformations
	bool IsPositionBehind(double point);
	sf::Vector2f WindowTranslation(Point3D* point);
};


#endif
