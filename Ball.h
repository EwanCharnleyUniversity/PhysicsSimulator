#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include <iostream>
#include <SFML/Graphics.hpp>


struct WorldMovement {
	float xPosition = 0;
	float yPosition = 0;
	float xVelocity = 0;
	float yVelocity = 0;
};


class Ball {
public:
	Ball(int _inputWidth, sf::Color _inputColor);
	Ball(int _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY);

	void Simulation(sf::Vector2u windowSize);
	void Draw(sf::RenderWindow* window);

private:
	sf::CircleShape ballShape;
	WorldMovement ballMovement;
};

#endif