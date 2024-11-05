#ifndef BUFFERS_CLASS_HPP
#define BUFFERS_CLASS_HPP


// Vertex Array Object
// Holds all data relating to vertices, such as their position, colour, texture coordinates, etc.
// All Buffers and Element Arrays are handled by a parent VAO.
class Buffer {
public:
	unsigned int VAO, VBO, EBO;

	Buffer();

	void BindVertexArray();
	void BindBuffer(float* vertex);

	void Attribute(unsigned int layout, int size, int stride, int offset);
};


#endif
