#ifndef BUFFERS_CLASS_HPP
#define BUFFERS_CLASS_HPP


// Vertex Array Object - stores the vertex data of a model, such as the vertex positions, colour, texture coords, normals, etc.
class VAO {
public:
	unsigned int ID;

	VAO();

	void Bind();
	void Attribute(unsigned int index, unsigned int size);
};


// A Buffer, contains specific data such as position. Binds into the VAO.
class Buffer {
public:
	unsigned int ID;

	Buffer(unsigned int index);

	void Bind(float vertices[]);
};

#endif
