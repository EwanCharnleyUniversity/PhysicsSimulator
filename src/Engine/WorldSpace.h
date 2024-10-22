#ifndef WORLDSPACE_CLASS
#define WORLDSPACE_CLASS


#include "SFML/Graphics.hpp"

#include "WorldSpaceDatatypes.h"


// Camera contains the display window.
class Camera {
public:
	sf::RenderWindow window;
	float cameraZ = 0;

	Camera() {}
	Camera(int _inputWidth, int _inputHeight, float z);

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