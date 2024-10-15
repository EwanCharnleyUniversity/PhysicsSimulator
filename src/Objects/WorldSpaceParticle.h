#ifndef WORLDSPACE_PARTICLE_CLASS_H
#define WORLDSPACE_PARTICLE_CLASS_H

#include "ObjectDatatypes.h"
#include "SFML/Graphics.hpp"

using namespace ObjectDatatype;


class WorldSpaceParticle {
public:
	WorldSpaceParticle(int _id, float _inputWidth, bool staticVal);
	WorldSpaceParticle(int _id, float _inputWidth, Vector3D inputPosition, Vector3D inputVelocity, bool staticVal);

	void Simulate(std::vector<WorldSpaceParticle>* _input);

	void Render(sf::RenderTarget* window, Vector3D cameraPosition, float viewingDistance);

private:
	int ID;
	float TRUE_RADIUS;
	bool isStatic = true;

	Vector3D particlePosition;
	Vector3D particleVelocity;

	sf::CircleShape particleShape;
};


#endif