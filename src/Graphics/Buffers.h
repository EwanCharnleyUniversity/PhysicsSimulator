#ifndef BUFFERS_CLASS_HPP
#define BUFFERS_CLASS_HPP


// Vertex Array
class VAO {
	unsigned int ID;

	VAO();
	~VAO();

	void Unbind();
};

// Vertex Buffer
class Buffer {
	unsigned int ID;

	Buffer();
	~Buffer();

	virtual void Bind();
	virtual void Unbind();
};

#endif
