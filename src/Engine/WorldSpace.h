#ifndef WORLDSPACE_CLASS
#define WORLDSPACE_CLASS


#include "SFML/Graphics.hpp"
#include "vector"


struct worldCoordinate3D {
	float positionX, positionY, positionZ;


};



class Camera {
public:
	Camera(int _inputWidth, int _inputHeight, float x, float y, float z);

	void Render();

private:
	sf::RenderWindow window;
	worldCoordinate3D cameraPosition;
	// Position in the Z axis
	float viewingDistance = 100.0f;

};



class WorldSpace {
public:
	WorldSpace();


private:
	Camera worldCamera;
};


// IDEA
// WorldPoints will just render a basic point at the position of wherever they are assigned.


#endif