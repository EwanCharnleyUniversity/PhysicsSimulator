
#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP

#include "SFML/Graphics.hpp"


struct Point3D;


class Camera {
public:
	Camera();
	void Simulate();

	Point3D* position;
	double viewingDistance = 0;
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
	bool IsPositionBehind(Point3D* point);
	sf::Vector2f WindowTranslation(Point3D* point);
	sf::Vector2f WindowCull(Point3D* point);
};


#endif
