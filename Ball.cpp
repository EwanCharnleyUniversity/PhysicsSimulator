
#include <cmath>
#include <random>
#include "Ball.h"

template <typename T>
T randomWeight(T weight) {
	return rand() % weight - (weight / 2);
}


Ball::Ball(float _inputWidth, sf::Color _inputColor) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setOrigin(_inputWidth, _inputWidth);
	ballShape.setFillColor(_inputColor);
}

Ball::Ball(float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setFillColor(_inputColor);
	baseColor = _inputColor;

	ballMovement.position.x = _inputPositionX;
	ballMovement.position.y = _inputPositionY;

	ballShape.setPosition(ballMovement.position.x, ballMovement.position.y);
	ballShape.setOrigin(_inputWidth, _inputWidth);
	
	// DEBUG: Sets random velocity between -5 and 5, gives more dynamic movement.
	ballMovement.velocity.x = randomWeight(25);
	ballMovement.velocity.y = randomWeight(25);
}


void Ball::Draw(sf::RenderWindow* window) {

	window->draw(ballShape);

	if (!DEBUG) {
		return;
	}

	// Draws lines if debug is true.
	sf::Vertex vertices[] = {
		sf::Vertex(ballMovement.position, sf::Color(255,255,255)),
		sf::Vertex(ballMovement.position + ballMovement.velocity * sqrt(ballShape.getRadius()), sf::Color(0,0,0)),
	};

	window->draw(vertices, 2, sf::Lines);
}



/// MATH FUNCTIONS ///

template <typename T>
T squaredProduct(T _input) {
	_input *= _input;
	return _input;
}

// we have two inputs representing the vector between our balls position
// we know the vector, we do not know the angle.
// the standard formula is a.b = |a||b|cos0
// but we can rewrite it to cos0 = a.b / |a||b|

float vectorMagnitude(sf::Vector2f _firstInput) {
	return sqrt((squaredProduct(_firstInput.x)) + (squaredProduct(_firstInput.y)));
}

float dotProduct2D(sf::Vector2f _firstInput, sf::Vector2f _secondInput) {
	return _firstInput.x * _secondInput.x + _firstInput.y * _secondInput.y;
}

float dotProduct2DAngle(sf::Vector2f _firstInput, sf::Vector2f _secondInput) {	
	return acos(dotProduct2D(_firstInput,_secondInput) / (vectorMagnitude(_firstInput) * vectorMagnitude(_secondInput)));
}



/// SIMULATION CALCULATIONS ///

void Ball::Simulation(sf::Vector2u windowSize) {

	float middleWidth = (float)windowSize.x / 2;
	float middleHeight = (float)windowSize.y / 2;

	// Calculates vector x and y to center.
	float widthWeight = ballMovement.position.x - middleWidth;
	float heightWeight = ballMovement.position.y - middleHeight;

	// Applies Gravitational Weight
	ballMovement.velocity.x += widthWeight / -1000;
	ballMovement.velocity.y += heightWeight / -1000;

	ballMovement.position.y += ballMovement.velocity.y;
	ballMovement.position.x += ballMovement.velocity.x;

	// Probably could just calculate the collision in here.

	ballShape.setPosition(ballMovement.position);
}

void Ball::calculateCollision() {
	ballMovement.velocity.x = randomWeight(25);
	ballMovement.velocity.y = randomWeight(25);
}


void Ball::DetermineCollision(Ball* targetBall) {
	// Dot product for angle requires the vector between the two ball points and our velocity vector of the main ball.
	// We can then calculate the closest distance of the two and predict whether it will collide or not.

	float displacementValue = dotProduct2D(ballMovement.position, targetBall->ballMovement.position);

	float ballDepth = ballShape.getRadius() + targetBall->ballShape.getRadius();
	
	//std::cout << displacementValue << std::endl;
	if (displacementValue >= ballDepth) {
		return;
	}

	calculateCollision();
	
}