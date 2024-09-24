
#include <iostream>
#include <SFML/Window.hpp>

#include "Ball.h"


static int WIDTH = 784;
static int HEIGHT = 441;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(784,441), "Physics SFML Simulator");

	Ball firstBall(100, sf::Color(25,25,255,255), 25, 25);
	Ball secondBall(100, sf::Color(25,255,0,255), WIDTH - 225, 25);

	// DEBUG :: Center of screen
	Ball centerMark(2, sf::Color(255,255,255,255), WIDTH / 2, HEIGHT / 2);


	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0,0,15,255));

		// Simulate and draw everything.
		firstBall.Simulation(window.getSize());
		secondBall.Simulation(window.getSize());

		firstBall.Draw(&window);
		secondBall.Draw(&window);
		centerMark.Draw(&window);

		window.display();
	}

	return 0;
}