
#include <cmath>
#include <random>
#include "Ball.h"


Ball::Ball(float _inputWidth, sf::Color _inputColor) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setOrigin(_inputWidth, _inputWidth);
	ballShape.setFillColor(_inputColor);
}

Ball::Ball(float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setFillColor(_inputColor);
	baseColor = _inputColor;

	ballMovement.xPosition = _inputPositionX;
	ballMovement.yPosition = _inputPositionY;
	ballShape.setPosition(ballMovement.xPosition, ballMovement.yPosition);
	ballShape.setOrigin(_inputWidth, _inputWidth);
	
	// DEBUG: Sets random velocity between -5 and 5, gives more dynamic movement.
	ballMovement.xVelocity += rand() % 10 - 5;
	ballMovement.yVelocity += rand() % 10 - 5;
}


void Ball::Draw(sf::RenderWindow* window) {

	window->draw(ballShape);

	if (!DEBUG) {
		return;
	}

	// Draws lines if debug is true.
	sf::Vertex vertices[] = {
		sf::Vertex(sf::Vector2f(ballMovement.xPosition, ballMovement.yPosition), sf::Color(255,255,255)),
		sf::Vertex(sf::Vector2f(ballMovement.xPosition + ballMovement.xVelocity * 5.0f,
			ballMovement.yPosition + ballMovement.yVelocity * 5.0f), sf::Color(0,0,0)),
	};

	window->draw(vertices, 2, sf::Lines);
}


void Ball::Simulation(sf::Vector2u windowSize) {

	float middleWidth = (float)windowSize.x / 2;
	float middleHeight = (float)windowSize.y / 2;

	// Calculates vector x and y to center.
	float widthWeight = ballMovement.xPosition - middleWidth;
	float heightWeight = ballMovement.yPosition - middleHeight;

	// Applies Gravitational Weight
	ballMovement.xVelocity += widthWeight / -1000;
	ballMovement.yVelocity += heightWeight / -1000;

	ballMovement.yPosition += ballMovement.yVelocity;
	ballMovement.xPosition += ballMovement.xVelocity;

	ballShape.setPosition(ballMovement.xPosition, ballMovement.yPosition);
}


template <typename T>
T squaredProduct(T _input) {
	_input *= _input;
	return _input;
}


void Ball::calculateCollision() {
	// Sets ball colour to Red to show it has collided.
	std::cout << "Colour changed!" << std::endl;
	ballShape.setFillColor(sf::Color(255, 0, 0));
}


void Ball::DetermineCollision(Ball* targetBall) {

	// Two Balls (Radius = 100)
	// Ball 1 - x: 100	y: 200
	// Ball 2 - x: 300	y: 200

	// Ball One xDisplacement = 100 - 200 = -100
	// Ball One yDisplacement = 300 - 200 = 100

	// Ball Two xDisplacement = 200 - 100 = 100
	// Ball Two yDisplacement = 200 - 300 = -100

	float xDisplacement = ballMovement.xPosition - targetBall->ballMovement.xPosition;
	float yDisplacement = ballMovement.yPosition - targetBall->ballMovement.yPosition;


	float distance = sqrtf(squaredProduct(abs(xDisplacement)) + squaredProduct(abs(yDisplacement)));

	// The combination of the parent and target ball's radius
	float ballDepth = ballShape.getRadius() + targetBall->ballShape.getRadius();

	if (distance > ballDepth) {
		ballShape.setFillColor(baseColor);
		return;
	}

	calculateCollision();

	// calculate collision.
	// Elastic collisions, no loss of energy
	// Coefficient of restitution is 1
	// we need the center of mass velocity, both balls are considered the same mass, find the direct middle of the collision and apply the sum of both vectors there.
	//
	
}