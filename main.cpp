
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Window.hpp>

#include "Ball.h"
#include "DebugTools.h"


static int RATIO = 92;
static int WIDTH = RATIO * 16;
static int HEIGHT = RATIO * 9;

static float BALLWIDTH = 75.0f;
static int BALLAMOUNT = 10;

// For simulating the balls, I should create a TIME variable that can be modified rather than directly through FPS.
static bool FPSBOOL = true;
static int FPS = 60;


void keyHandler(sf::Event& event, sf::RenderWindow& window) {
	switch (event.key.scancode) {

	case sf::Keyboard::Scan::Escape:
		window.close();
		break;

	case sf::Keyboard::W:
		FPS += 1;
		break;

	case sf::Keyboard::S:
		FPS -= 1;
		break;

	case sf::Keyboard::A:
		FPSBOOL = true;
		FPS = 60;
		break;

	case sf::Keyboard::D:
		FPSBOOL = true;
		FPS = 0;
		break;

	case sf::Keyboard::Scan::LShift:
		FPS = 60;
		FPSBOOL = false;
		break;
	}
}


void eventHandler(sf::Event& event, sf::RenderWindow& window) {
	switch (event.type) {

	case sf::Event::Closed:
		window.close();
		break;

	case sf::Event::KeyPressed:
		keyHandler(event, window);
		break;
	}
}


int main(void)
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Physics SFML Simulator");

	std::vector<Ball> ballVector;
	for (int i = 0; i < BALLAMOUNT; i++) {
		sf::Color randomBallColour = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
		ballVector.push_back(Ball(i, BALLWIDTH, randomBallColour, rand() % WIDTH, rand() % HEIGHT));
	}
	
	sf::Clock deltaTime;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			eventHandler(event, window);
		}

		if (FPS <= 0)
			continue;

		uint32_t timeStep = deltaTime.getElapsedTime().asMilliseconds();
		if (FPSBOOL == true && timeStep < 1000 / FPS) {
			continue;
		}

		window.clear(sf::Color(0,0,15,255));

		// Vector Calls - simulate it's stored entities and draw them.
		for (int _baseBall = 0; _baseBall < ballVector.size(); _baseBall++) {
			ballVector[_baseBall].Simulation(&window, &ballVector);
			ballVector[_baseBall].Draw(&window);
		}

		window.display();
		deltaTime.restart();
	}

	return 0;
}