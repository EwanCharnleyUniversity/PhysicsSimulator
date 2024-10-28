
#include <SFML/Graphics.hpp>

#include "GraphicDatatypes.h"
#include "GraphicsEngine.h"
#include "vector"

#include <iostream>


Model::Model() {
	// Hard coded Cube (for now)
	vertices.insert(vertices.end(), {
		{-250,-250,-250},
		{ 250,-250,-250},
		{ 250, 250,-250},
		{-250, 250,-250},
		{-250,-250, 250},
		{ 250,-250, 250},
		{ 250, 250, 250},
		{-250, 250, 250}
	});


	// Elements of a cube
	elements.insert(elements.end(),{
		0,1,2,0,2,3,	// Front Face
		0,1,5,0,5,4,	// Bottom Face
		0,4,7,0,7,3,	// Left Face
		1,5,2,5,6,2,	// Right Face
		4,5,7,5,6,7,	// Back Face
		3,2,5,5,7,3		// Top Face
	});
}


// Displays the model in worldspace
void Model::Display(GraphicsEngine& graphics) {
	sf::VertexArray points(sf::Points);
	sf::VertexArray tris(sf::Triangles);

	// Vertex Points
	for (int i = 0; i < vertices.size(); i++) {
		Vector3D newPosition = vertices[i] + originPoint;

		points.append(graphics.WindowTranslation(&newPosition));
		points[i].color = { 0,255,0,255 };
	}

	// Element Triangles
	for (int i = 0; i < elements.size(); i++) {
		Vector3D elementRef = vertices[elements[i]] + originPoint;
		tris.append(graphics.WindowTranslation(&elementRef));
		tris[i].color = { 255,255,255,255 };
	}

	graphics.Draw(points);
	graphics.Draw(tris);
}