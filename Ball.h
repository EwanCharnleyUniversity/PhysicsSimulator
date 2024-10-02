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
	//int ID;

	Ball(int id, float _inputWidth, sf::Color _inputColor);
	Ball(int id, float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY);

	void Draw(sf::RenderWindow* window);

	void Simulation(sf::RenderWindow* window, std::vector<Ball>* ballVector);
	
	void DetermineCollision(Ball* ball);
	void calculateCollision();

private:
	int ID;
	bool DEBUG = false;

	sf::CircleShape ballShape;
	WorldMovement ballMovement;

	sf::Color baseColor = sf::Color(255, 255, 255, 255);
	sf::Vector2f vectorPath;
};

#endif