#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include <iostream>
#include <SFML/Graphics.hpp>


struct WorldMovement {
	sf::Vector2f position;
	sf::Vector2f velocity;
};


class Ball {
public:
	Ball(float _inputWidth, sf::Color _inputColor);
	Ball(float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY);

	void Simulation(sf::Vector2u windowSize);
	void Draw(sf::RenderWindow* window);

	void DetermineCollision(Ball* ball);
	void calculateCollision();

private:
	bool DEBUG = true;

	sf::CircleShape ballShape;
	WorldMovement ballMovement;

	sf::Color baseColor = sf::Color(255, 255, 255, 255);
	sf::Vector2f vectorPath;
};

#endif