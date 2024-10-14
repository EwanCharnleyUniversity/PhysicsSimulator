
#include <iostream>
#include "WorldSpace.h"


int particleAmount = 100;
float particleRadius = 50.0f;

int WIDTH{ 1536 }, HEIGHT{ 864 };


WorldSpace::WorldSpace() {

	//for (int i = 0; i < particleAmount; i++) {
	//	worldObjects.worldParticles.push_back(particleRadius);
	//}

	worldVector3D nullVector = { 0.0f, 0.0f, 0.0f };
	worldVector3D firstParticlePosition = { 500.0f, 0.0f, 0.0f };

	worldObjects.worldParticles.push_back({particleRadius, firstParticlePosition, nullVector });

	worldObjects.worldStatics.push_back({125.0f, nullVector});


	Camera camera(WIDTH, HEIGHT, 0, 0, -250.0f);
	camera.Render(&worldObjects);
}