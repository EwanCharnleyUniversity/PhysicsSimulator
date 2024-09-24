
#include <math.h>
#include "Ball.h"


Ball::Ball(int _inputWidth, sf::Color _inputColor) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setFillColor(_inputColor);
}


Ball::Ball(int _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setFillColor(_inputColor);

	ballMovement.xPosition = _inputPositionX;
	ballMovement.yPosition = _inputPositionY;
	ballShape.setPosition(ballMovement.xPosition, ballMovement.yPosition);
}


void Ball::Draw(sf::RenderWindow* window) {
	window->draw(ballShape);
}


template <typename T>
T squaredProduct(T _input) {
	_input *= _input;
	return _input;
}


void Ball::Simulation(sf::Vector2u windowSize) {
	// TODO - change to gravity being at the center of the screen
	sf::Vector2u ballPosition(ballMovement.xPosition, ballMovement.yPosition);

	// a squared + b squred = c squared
	// a and b are points, our ball and the center.
	// c is the distance between the two.
	
	float distance = squaredProduct(ballPosition.x - ballPosition.y) + squaredProduct((windowSize.x / 2) - (windowSize.y / 2));
	distance = abs(sqrt(distance));


	ballMovement.yVelocity += 0.00000025f;
	ballMovement.xPosition += ballMovement.xVelocity;
	ballMovement.yPosition += ballMovement.yVelocity;

	ballShape.setPosition(ballMovement.xPosition, ballMovement.yPosition);
}