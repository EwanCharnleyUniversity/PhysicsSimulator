
#include "../CommonDatatypes.h"
#include "QuadPlane.h"
#include "../Graphics/GraphicsEngine.h"

#include <iostream>
#include <random>



QuadPlane::QuadPlane() {
	// Hard coded positions, will change later.
	vertices[0] = new Vector3D{	-250,	-250,	-250 };
	vertices[1] = new Vector3D{ 250,	-250,	-250 };
	vertices[2] = new Vector3D{ 250,	-250,	250 };
	vertices[3] = new Vector3D{ -250,	-250,	250 };

	velocity = new Vector3D{ 0,0,0 };
	normal = new Vector3D{ { 0, 0, 0} , { 0, 100, 0} };
}

void QuadPlane::Simulate() {
	for (int i = 0; i < 4; i++) {
		*vertices[i] += *velocity;
	}
}


void QuadPlane::Render(GraphicsEngine& graphics) {

	// Generates a Quad from the translated positions of each point
	sf::VertexArray Quad(sf::Quads, 4);
	for (int i = 0; i < 4; i++) {

		Quad[i].position = graphics.WindowTranslation(vertices[i]);

		// If the Vertex position is behind the camera
		if (graphics.IsPositionBehind(vertices[i])) {

			Vector3D culledPoint{ vertices[i]->X,vertices[i]->Y,vertices[i]->Z };
			Quad[i].position = graphics.WindowClip(&culledPoint);

			continue;
		}
		else {
			Quad[i].color = { 0, 0, 255, 255};
		}
	}

	Quad[0].color = { 255,0,0,255 };
	Quad[1].color = { 0,255,0,255 };
	Quad[2].color = { 0,0,255,255 };
	Quad[3].color = { 255,0,255,255 };

	graphics.Draw(Quad);
}