
#include <iostream>
#include "WorldSpace.h"


WorldSpace::WorldSpace() {
	for (int i = 0; i < 250; i++) {
		worldObjects.worldParticles.push_back(50.0f);
	}

	Camera camera(1000, 1000, 0, 0, -250);
	camera.Render(worldObjects);
}