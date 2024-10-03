
#include <cmath>
#include <random>
#include "Particle.h"


int weight = 25 * 100;

float randomWeight() {
	return (rand() % weight - (weight / 2)) / 100;
}


Particle::Particle(int id, float _inputWidth, sf::Color _inputColor) : ID(id) {
	particleShape = sf::CircleShape(_inputWidth);
	particleShape.setOrigin(_inputWidth, _inputWidth);
	particleShape.setFillColor(_inputColor);
}

Particle::Particle(int id, float _inputWidth, sf::Color _inputColor, float _inputPositionX, float _inputPositionY) : ID(id) {
	particleShape = sf::CircleShape(_inputWidth);
	particleShape.setFillColor(_inputColor);
	baseColor = _inputColor;

	particleMovement.positionTail.x = _inputPositionX;
	particleMovement.positionTail.y = _inputPositionY;

	particleShape.setPosition(particleMovement.positionTail.x, particleMovement.positionTail.y);
	particleShape.setOrigin(_inputWidth, _inputWidth);
	
	// DEBUG: Sets A random velocity, gives more dynamic movement.
	particleMovement.velocityHead.x = randomWeight();
	particleMovement.velocityHead.y = randomWeight();
}



/// DRAW FUNCTION ///

void Particle::Draw(sf::RenderWindow* window) {

	window->draw(particleShape);

	if (!DEBUG) {
		return;
	}

	// Draws lines if debug is true.
	sf::Vertex vertices[] = {
		sf::Vertex(particleMovement.positionTail, sf::Color(255,255,255)),
		sf::Vertex(particleMovement.positionTail + particleMovement.velocityHead * sqrt(particleShape.getRadius()), sf::Color(0,0,0)),
	};

	window->draw(vertices, 2, sf::Lines);
}


/// MATH FUNCTIONS ///

template <typename T>
T squaredProduct(T _input) {
	return _input * _input;
}

sf::Vector2f vectorProperty(sf::Vector2f tail, sf::Vector2f head) {
	return head - tail;
}

float vectorMagnitude(sf::Vector2f _firstInput) {
	return sqrt(squaredProduct(_firstInput.x) + squaredProduct(_firstInput.y));
}

float dotProduct2D(sf::Vector2f _firstInput, sf::Vector2f _secondInput) {
	return _firstInput.x * _secondInput.x + _firstInput.y * _secondInput.y;
}

float dotProduct2DAngle(sf::Vector2f _firstInput, sf::Vector2f _secondInput) {	
	return acos(dotProduct2D(_firstInput,_secondInput) / (vectorMagnitude(_firstInput) * vectorMagnitude(_secondInput)));
}



/// BALL SIMULATION ///

void Particle::Simulation(sf::RenderWindow* window, std::vector<Particle>* ballVector) {

	particleShape.setFillColor(baseColor);

	float middleWidth = window->getSize().x / static_cast<float>(2);
	float middleHeight = window->getSize().y / static_cast<float>(2);

	// Calculates vector x and y to center.
	float widthWeight = particleMovement.positionTail.x - middleWidth;
	float heightWeight = particleMovement.positionTail.y - middleHeight;

	// Applies Gravitational Weight
	particleMovement.velocityHead.x += widthWeight / -1000;
	particleMovement.velocityHead.y += heightWeight / -1000;

	particleMovement.positionTail.y += particleMovement.velocityHead.y;
	particleMovement.positionTail.x += particleMovement.velocityHead.x;

	particleShape.setPosition(particleMovement.positionTail);

	// Checks for collisions by searching every other ball stored in the vector. terrible O(n^2) complexity.
	for (int _targetBall = 0; _targetBall < ballVector->size(); _targetBall++) {

		if (this->ID == ballVector->at(_targetBall).ID)
			continue;

		this->DetermineCollision(&ballVector->at(_targetBall));
	}
}


void Particle::calculateCollision() {
	particleShape.setFillColor(sf::Color(255,0,0,255));
	particleMovement.velocityHead.x *= -1;
	particleMovement.velocityHead.y *= -1;
}


void Particle::DetermineCollision(Particle* targetBall) {

	sf::Vector2f distanceVector = vectorProperty(particleMovement.positionTail, targetBall->particleMovement.positionTail);
	//std::cout << distanceVector.x << "||" << distanceVector.y << std::endl;

	sf::Vector2f mainVelocityVector = particleMovement.positionTail + particleMovement.velocityHead;
	sf::Vector2f targetVelocityVector = targetBall->particleMovement.positionTail + targetBall->particleMovement.velocityHead;
	sf::Vector2f relativeDisplacement = mainVelocityVector - targetVelocityVector;
	
	float displacementMagnitude = vectorMagnitude(relativeDisplacement);

	float distanceMagnitude = vectorMagnitude(distanceVector);

	float collisionDistance = particleShape.getRadius() + targetBall->particleShape.getRadius();

	if (distanceMagnitude <= collisionDistance) {
		calculateCollision();
		//targetBall->calculateCollision();
	}
}