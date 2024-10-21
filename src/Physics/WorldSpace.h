#ifndef WORLDSPACE_CLASS
#define WORLDSPACE_CLASS


#include "SFML/Graphics.hpp"

#include "../Objects/ObjectDatatypes.h"
#include "WorldSpaceDatatypes.h"


// Camera contains the display window.
class Camera {
public:
	sf::RenderWindow window;
	ObjectDatatype::Vector3D cameraPosition;

	Camera() {}
	Camera(int _inputWidth, int _inputHeight, float x, float y, float z);

	void Render(worldContainers* Objects);

private:
	float viewingDistance = 100.0f;

};


// The physical space of the Engine
class WorldSpace {
public:
	WorldSpace();

private:
	worldContainers worldObjects;
};



// TODO - move the Simulation and tick loop into Worldspace

#endif