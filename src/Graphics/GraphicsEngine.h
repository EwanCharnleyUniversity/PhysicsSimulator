
#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP


#include "SFML/Graphics.hpp"


class GraphicsEngine {
public:
	sf::RenderWindow window;

	GraphicsEngine(int WIDTH, int HEIGHT);

	void Render();

private:

};


#endif
