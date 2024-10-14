#ifndef WORLDSPACE_CLASS
#define WORLDSPACE_CLASS


#include "SFML/Graphics.hpp"
#include "vector"

#include "WorldSpaceDatatypes.h"
#include "../Objects/WorldSpaceParticle.h"


struct worldContainers {
	std::vector<WorldSpaceParticle> worldParticles;
};


class Camera {
public:
	Camera() {}
	Camera(int _inputWidth, int _inputHeight, float x, float y, float z);

	void Render(worldContainers Objects);

private:
	sf::RenderWindow window;
	worldVector3D cameraPosition;

	float viewingDistance = 100.0f;

};


class WorldSpace {
public:
	WorldSpace();


private:
	Camera worldCamera;
	worldContainers worldObjects;
};



#endif