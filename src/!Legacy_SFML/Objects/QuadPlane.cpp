
#include "ObjectDatatypes.h"
#include "QuadPlane.h"
#include "../Graphics/GraphicsEngine.h"

#include <iostream>
#include <random>



QuadPlane::QuadPlane() {

	velocity = new Point3D{ 0,0,0 };

	// Assign random vertice positions to the Plane
	for (int i = 0; i < 4; i++) {

		vertices[i] = new Point3D;
		vertices[i]->randomPosition();
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

	sf::VertexArray Quad(sf::Quads, 4);

	for (int i = 0; i < 4; i++) {
		Quad[i].position = graphics.WindowTranslation(vertices[i]);

		// If the Vertex position is behind the camera, we set its position to 0 and alpha to 0
		if (graphics.IsPositionBehind(vertices[i]->Z)) {
			
			Point3D TempPoint{ vertices[i]->X,vertices[i]->Y,vertices[i]->Z };
			TempPoint.Z = graphics.pCamera.position->Z + graphics.pCamera.viewingDistance;

			Quad[i].position = graphics.WindowTranslation(&TempPoint);
			Quad[i].color.a = 0;
			continue;
		}
		else {
			Quad[i].color = {0,0,255,255};
		}
	}

	graphics.Draw(Quad);
}