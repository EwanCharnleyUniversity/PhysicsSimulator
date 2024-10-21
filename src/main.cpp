
#include "Graphics/GraphicsEngine.h"
#include "Physics/PhysicsEngine.h"
#include "Objects/QuadPlane.h"

#include <iostream>


int main(void) {
	GraphicsEngine graphics(1472, 828);
	PhysicsEngine physics(graphics);

	// For future plane rendering, but for now it's just used to test Vector3D.
	QuadPlane testPlane;

	physics.Simulate();


	return 0;
}