
#include "GraphicsEngine.h"


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


	window.display();
}