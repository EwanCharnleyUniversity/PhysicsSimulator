
#include "GraphicsEngine.h"
#include "SFML/Graphics.hpp"



GraphicsEngine::GraphicsEngine(int WIDTH, int HEIGHT) {
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Meridian Engine");
}


void GraphicsEngine::Render() {

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	window.clear({ 0,0,0 });

	// Seeing how vertices work and how I could use them to draw in-scene over using sf::Shapes
	sf::VertexArray triangle(sf::Triangles, 3);
	triangle[0].position = sf::Vector2f(200, 500);
	triangle[0].color = sf::Color::Red;

	triangle[1].position = sf::Vector2f(500, 500);
	triangle[1].color = sf::Color::Green;

	triangle[2].position = sf::Vector2f(700, 700);
	triangle[2].color = sf::Color::Blue;

	window.draw(triangle);

	window.display();
}