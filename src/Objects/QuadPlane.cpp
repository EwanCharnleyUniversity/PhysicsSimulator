
#include "ObjectDatatypes.h"
#include "QuadPlane.h"
#include "../Graphics/GraphicsEngine.h"

#include <iostream>
#include <random>



QuadPlane::QuadPlane() {

	Point3D random3D{ 1,1,1 };
	random3D.Randomise(500);

	velocity = new Point3D{ 0,0,0 };
	normal = new Vector3D{ {0,0,0} , random3D };

	// Assign random vertice positions to the Plane
	for (int i = 0; i < 4; i++) {

		vertices[i] = new Point3D;
		vertices[i]->Randomise(1000);
		vertices[i]->PrintCoordinates();
	}
}

void QuadPlane::Simulate() {
	
	velocity->Z += 0.001;

	for (int i = 0; i < 4; i++) {
		vertices[i]->X += velocity->X;
		vertices[i]->Y += velocity->Y;
		vertices[i]->Z += velocity->Z;
	}
}


void QuadPlane::Render(GraphicsEngine& graphics) {

	// Generates a Quad from the translated positions of each point
	sf::VertexArray Quad(sf::Quads, 4);
	for (int i = 0; i < 4; i++) {
		Quad[i].position = graphics.WindowTranslation(vertices[i]);

		// If the Vertex position is behind the camera
		if (graphics.IsPositionBehind(vertices[i])) {

			Point3D culledPoint{ vertices[i]->X,vertices[i]->Y,vertices[i]->Z };
			Quad[i].position = graphics.WindowCull(&culledPoint);

			continue;
		}
		else {
			Quad[i].color = {0,0,255,255};
		}
	}

	graphics.Draw(Quad);
}