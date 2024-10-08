
#include <cmath>
#include <random>
#include "Particle.h"


int weight = 25 * 100;

float randomWeight() {
	return (rand() % weight - (weight / 2)) / 100;
}


Particle::Particle(int id, float _inputRadius, sf::Color _inputColor) : ID(id) {
	Radius = _inputRadius;
	particleShape = sf::CircleShape(_inputRadius);
	particleShape.setOrigin(_inputRadius, _inputRadius);
	particleShape.setFillColor(_inputColor);
}

Particle::Particle(int id, float _inputRadius, sf::Color _inputColor, float _inputPositionX, float _inputPositionY, float _inputPositionZ) : ID(id) {
	Radius = _inputRadius;
	particleShape = sf::CircleShape(_inputRadius);
	particleShape.setFillColor(_inputColor);
	baseColor = _inputColor;

	particleMovement.position.x = _inputPositionX;
	particleMovement.position.y = _inputPositionY;
	particleMovement.position.z = _inputPositionZ;

	// Basic "perspective", no transformation.
	particleShape.setRadius(_inputRadius / log(_inputPositionZ));

	particleShape.setPosition(particleMovement.position.x, particleMovement.position.y);
	particleShape.setOrigin(_inputRadius, _inputRadius);
	

	particleMovement.position.x = randomWeight();
	particleMovement.position.y = randomWeight();
	particleMovement.position.z = randomWeight();
}



/// DRAW FUNCTION ///

void Particle::Draw(sf::RenderWindow* window) {

	particleShape.setRadius(Radius / log(particleMovement.position.z));

	window->draw(particleShape);

	if (!DEBUG) {
		return;
	}


	// Draws lines if debug is true.
	//sf::Vertex vertices[] = {
	//	sf::Vertex(particleMovement.position, sf::Color(255,255,255)),
	//	sf::Vertex(particleMovement.position + particleMovement.velocityHead * sqrt(particleShape.getRadius()), sf::Color(0,0,0)),
	//};

	//window->draw(vertices, 2, sf::Lines);
}


/// MATH FUNCTIONS ///

template <typename T>
T squaredProduct(T _input) {
	return _input * _input;
}

sf::Vector3f vectorProperty(sf::Vector3f tail, sf::Vector3f head) {
	return head - tail;
}

float vectorMagnitude(sf::Vector3f _firstInput) {
	return sqrt(squaredProduct(_firstInput.x) + squaredProduct(_firstInput.y));
}

float dotProduct2D(sf::Vector3f _firstInput, sf::Vector3f _secondInput) {
	return _firstInput.x * _secondInput.x + _firstInput.y * _secondInput.y;
}

float dotProduct2DAngle(sf::Vector3f _firstInput, sf::Vector3f _secondInput) {	
	return acos(dotProduct2D(_firstInput,_secondInput) / (vectorMagnitude(_firstInput) * vectorMagnitude(_secondInput)));
}



/// BALL SIMULATION ///

void Particle::Simulation(sf::RenderWindow* window, std::vector<Particle>* ballVector) {

	particleShape.setFillColor(baseColor);

	float middleWidth = window->getSize().x / static_cast<float>(2);
	float middleHeight = window->getSize().y / static_cast<float>(2);

	// Calculates vector x and y to center.
	float widthWeight = particleMovement.position.x - middleWidth;
	float heightWeight = particleMovement.position.y - middleHeight;

	// Applies Gravitational Weight
	particleMovement.velocity.x += widthWeight / -1000;
	particleMovement.velocity.y += heightWeight / -1000;

	particleMovement.position.y += particleMovement.velocity.y;
	particleMovement.position.x += particleMovement.velocity.x;
	particleMovement.position.x += particleMovement.velocity.z;

	particleShape.setPosition(particleMovement.position.x, particleMovement.position.y);

	// Checks for collisions by searching every other ball stored in the vector. terrible O(n^2) complexity.
	for (int _targetBall = 0; _targetBall < ballVector->size(); _targetBall++) {

		if (this->ID == ballVector->at(_targetBall).ID)
			continue;

		this->DetermineCollision(&ballVector->at(_targetBall));
	}
}


void Particle::calculateCollision() {
	particleShape.setFillColor(sf::Color(255,0,0,255));
	particleMovement.velocity.x *= -1;
	particleMovement.velocity.y *= -1;
	particleMovement.velocity.z *= -1;
}


void Particle::DetermineCollision(Particle* targetBall) {

	sf::Vector3f distanceVector = vectorProperty(particleMovement.position, targetBall->particleMovement.position);

	sf::Vector3f mainVelocityVector = particleMovement.position + particleMovement.velocity;
	sf::Vector3f targetVelocityVector = targetBall->particleMovement.position + targetBall->particleMovement.velocity;
	sf::Vector3f relativeDisplacement = mainVelocityVector - targetVelocityVector;
	
	float displacementMagnitude = vectorMagnitude(relativeDisplacement);

	float distanceMagnitude = vectorMagnitude(distanceVector);

	float collisionDistance = particleShape.getRadius() + targetBall->particleShape.getRadius();

	if (distanceMagnitude <= collisionDistance) {
		calculateCollision();
		//targetBall->calculateCollision();
	}
}