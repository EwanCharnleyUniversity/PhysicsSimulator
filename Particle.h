#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


struct particleVector2D {
	sf::Vector2f positionTail;
	sf::Vector2f velocityHead;
};


class Particle {
public:

	Particle(int id, float _inputWidth, sf::Color _inputColor);
	Particle(int id, float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY);

	void Draw(sf::RenderWindow* window);

	void Simulation(sf::RenderWindow* window, std::vector<Particle>* ballVector);
	
	void DetermineCollision(Particle* ball);
	void calculateCollision();

private:
	int ID;
	bool DEBUG = false;

	sf::CircleShape particleShape;
	particleVector2D particleMovement;

	sf::Color baseColor = sf::Color(255, 255, 255, 255);
};



// Particle Runtime is a struct containg a vector of particles.
// Includes functions to add, draw, and simulate all of its components.
struct particleRuntime {
	
	std::vector<Particle> particleStore;
	float PARTICLESIZE = 250.0f;


	// Window coords and Colour //
	float randomXCoord(sf::RenderWindow* window) {
		return rand() % window->getSize().x;
	}

	float randomYCoord(sf::RenderWindow* window) {
		return rand() % window->getSize().y;
	}

	sf::Color randomColor() {
		return sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
	}


	// Particle Addition to Vector //
	void addParticle(sf::RenderWindow* window) {
		this->particleStore.push_back(Particle(this->particleStore.size() + 1, PARTICLESIZE, randomColor(), randomXCoord(window), randomYCoord(window)));
	}

	void addMultipleParticles(sf::RenderWindow* window, int amount) {
		for (int i = 0; i < amount; i++) {
			this->particleStore.push_back(Particle(this->particleStore.size() + 1, PARTICLESIZE, randomColor(), randomXCoord(window), randomYCoord(window)));
		}
	}


	// Rendering and Simulation //
	void drawParticleRuntime(sf::RenderWindow* window) {
		for (int i = 0; i < particleStore.size(); i++) {
			this->particleStore.at(i).Draw(window);
		}
	}

	void simulateParticleRuntime(sf::RenderWindow* window) {
		for (int i = 0; i < particleStore.size(); i++) {
			this->particleStore.at(i).Simulation(window,&particleStore);
		}
	}
};


#endif