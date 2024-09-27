
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Window.hpp>

#include "Ball.h"
#include "DebugTools.h"


static int RATIO = 92;
static int WIDTH = RATIO * 16;
static int HEIGHT = RATIO * 9;
static float FPS = 60;


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Physics SFML Simulator");
	sf::Clock deltaTime;

	// Ball Vector
	std::vector<Ball> ballVector;
	float ballWidth = 100.0f;
	for (int i = 0; i < 2; i++) {
		sf::Color randomBallColour = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
		ballVector.push_back(Ball(ballWidth, randomBallColour, rand() % WIDTH, rand() % HEIGHT));
	}


	while (window.isOpen()) {

		// Delta Time
		uint32_t timeStep = deltaTime.getElapsedTime().asMilliseconds();
		if (timeStep < 1000 / FPS) {
			continue;
		}

		// Window Events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0,0,15,255));

		// Vector draw and Simulation.
		for (int _baseBall = 0; _baseBall < ballVector.size(); _baseBall++) {
			ballVector[_baseBall].Simulation(window.getSize());

			for (int _targetBall = 0; _targetBall < ballVector.size(); _targetBall++) {

				if (_targetBall == _baseBall) {
					continue;
				}

				std::cout << "Base ball: " << _baseBall << " to Target ball: " << _targetBall << std::endl;
				ballVector[_baseBall].DetermineCollision(&ballVector[_targetBall]);
			}

			ballVector[_baseBall].Draw(&window);
		}

		window.display();
		deltaTime.restart();
	}

	return 0;
}