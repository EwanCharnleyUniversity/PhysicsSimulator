
#include <cmath>
#include <random>
#include "Ball.h"



int randomWeight() {
	return (rand() % 10 - (10 / 2));
}


Ball::Ball(int id, float _inputWidth, sf::Color _inputColor) : ID(id) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setOrigin(_inputWidth, _inputWidth);
	ballShape.setFillColor(_inputColor);
}

Ball::Ball(int id, float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY) : ID(id) {
	ballShape = sf::CircleShape(_inputWidth);
	ballShape.setFillColor(_inputColor);
	baseColor = _inputColor;

	ballMovement.position.x = _inputPositionX;
	ballMovement.position.y = _inputPositionY;

	ballShape.setPosition(ballMovement.position.x, ballMovement.position.y);
	ballShape.setOrigin(_inputWidth, _inputWidth);
	
	// DEBUG: Sets random velocity between -5 and 5, gives more dynamic movement.
	ballMovement.velocity.x = randomWeight();
	ballMovement.velocity.y = randomWeight();
}



/// DRAW FUNCTION ///

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

// REMEMBER: Vectors a lines between TWO POINTS, you need four values with a 2D vector, six values for a 3D vector, etc.
// 
// |x| is vector magnitude. Pythagorean lenght of side c.
// x.y is a vector dot product.
// the standard formula for a dot product is a.b = |a||b|cos0
// 
// In this case we have two vectors, the distance to target and our velocity.
// d.v = |d||v|cos0

float vectorMagnitude(sf::Vector2f _firstInput) {
	return sqrt((squaredProduct(_firstInput.x)) + (squaredProduct(_firstInput.y)));
}

float dotProduct2D(sf::Vector2f _firstInput, sf::Vector2f _secondInput) {
	return _firstInput.x * _secondInput.x + _firstInput.y * _secondInput.y;
}

float dotProduct2DAngle(sf::Vector2f _firstInput, sf::Vector2f _secondInput) {	
	return acos(dotProduct2D(_firstInput,_secondInput) / (vectorMagnitude(_firstInput) * vectorMagnitude(_secondInput)));
}



/// BALL SIMULATION ///

void Ball::Simulation(sf::RenderWindow* window, std::vector<Ball>* ballVector) {

	//float middleWidth = (float)windowSize.x / 2;
	//float middleHeight = (float)windowSize.y / 2;
	float middleWidth = window->getSize().x / static_cast<float>(2);
	float middleHeight = window->getSize().y / static_cast<float>(2);

	// Calculates vector x and y to center.
	float widthWeight = ballMovement.position.x - middleWidth;
	float heightWeight = ballMovement.position.y - middleHeight;

	// Applies Gravitational Weight
	ballMovement.velocity.x += widthWeight / -1000;
	ballMovement.velocity.y += heightWeight / -1000;

	ballMovement.position.y += ballMovement.velocity.y;
	ballMovement.position.x += ballMovement.velocity.x;

	ballShape.setPosition(ballMovement.position);

	// Checks for collisions by searching every other ball stored in the vector. terrible O(n^2) complexity.
	for (int _targetBall = 0; _targetBall < ballVector->size(); _targetBall++) {

		if (this->ID == ballVector->at(_targetBall).ID)
			continue;

		this->DetermineCollision(&ballVector->at(_targetBall));
	}
}


void Ball::calculateCollision() {
	ballMovement.velocity.x = randomWeight();
	ballMovement.velocity.y = randomWeight();
}


void Ball::DetermineCollision(Ball* targetBall) {

	float displacementValue = dotProduct2D(ballMovement.position, targetBall->ballMovement.position);
	float ballDepth = ballShape.getRadius() + targetBall->ballShape.getRadius();
	
	//std::cout << displacementValue << std::endl;
	if (displacementValue >= ballDepth)
		return;

	calculateCollision();
}