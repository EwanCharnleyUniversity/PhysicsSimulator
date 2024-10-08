
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Window.hpp>

#include "Particle.h"
#include "DebugTools.h"


static int RATIO = 92;
static int WIDTH = RATIO * 16;
static int HEIGHT = RATIO * 9;

// For simulating the balls, I should create a TIME variable that can be modified rather than directly through FPS.
static int FPS = 60;
static bool FPSBOOL = true;


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
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Particle SFML Simulator");

	// Contains all particles in the projects run-time.
	particleRuntime particles;

	particles.addParticle(&window);
	particles.addParticle(&window);

	
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

		particles.simulateParticleRuntime(&window);
		particles.drawParticleRuntime(&window);

		window.display();
		deltaTime.restart();
	}

	return 0;
}