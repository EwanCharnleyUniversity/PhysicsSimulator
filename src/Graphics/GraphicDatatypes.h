
#ifndef GRAPHICS_DATATYPES_CLASS
#define GRAPHICS_DATATYPES_CLASS

#include <vector>

struct Vector3D;
class GraphicsEngine;


// A simple Four by Four matrix.
struct mat4 {
	double m[4][4];
};


// A Model is a visual representation of an object in worldspace, constructed from a multitude of vertices and their elements.
struct Model {
	// Origin of the Model in Worldspace, all vertices are linked to it.
	Vector3D* originPoint;
	
	std::vector<Vector3D*>	vertices;	// Vertex Buffer Object (VBO), contains all model Vertices
	std::vector<int>		elements;	// Element Buffer Object (EBO), contains all elements - aka vertex connections.
	
	Model();
	void Display(GraphicsEngine& graphics);
	
};


#endif 