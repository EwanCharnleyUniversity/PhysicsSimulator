#ifndef BUFFERS_CLASS_HPP
#define BUFFERS_CLASS_HPP


// Vertex Array Object (VAO), contains all data pertaining to Vertices.
// All Buffers bind to the VAO.
class VAO {
public:
	unsigned int ID;

	VAO();
	~VAO();

	void Bind();
	void VertexAttribute();
};


// Vertex Buffer Object, contains data pertaining to an attribute of a vertex.
// Ie, a VBO could serve as a container for vertex position, vertex colour, vertex texture coordinate, etc.
class VBO {
public:
	unsigned int ID;

	VBO();
	~VBO();

	void Bind();
	void Buffer(float vertices[]);
};


// Element Buffer Object, contains data pertaining to the binding of vertices (aka elements).
// It tells the engine how elements link together. This prevents us from needing duplicate vertices for repeated connections.
class EBO {
public:
	unsigned int ID;

	EBO();
	~EBO();

	void Bind();
	void Buffer(int indices[]);
};


#endif
