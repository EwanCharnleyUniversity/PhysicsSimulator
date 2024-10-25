
#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP

#include "SFML/Graphics.hpp"


struct Vector3D;


class Camera {
public:
	Camera();
	void Simulate(float time);

	Vector3D* position;
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
	bool IsPositionBehind(Vector3D* point);
	sf::Vector2f WindowTranslation(Vector3D* point);
	sf::Vector2f WindowClip(Vector3D* point);
};


#endif
