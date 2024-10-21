

#include "Graphics/GraphicsEngine.h"
#include "Physics/PhysicsEngine.h"

#include <iostream>



int main(void) {
	GraphicsEngine graphics(1472, 828);
	PhysicsEngine physics(graphics);

	physics.Simulate();


	return 0;
}