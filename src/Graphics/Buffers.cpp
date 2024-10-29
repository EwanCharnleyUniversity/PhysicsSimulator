
#include <glad/glad.h>
#include "Buffers.h"



// Vao
VAO::VAO() {
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
}

VAO::~VAO() {

}


// Buffers
Buffer::Buffer() {}
Buffer::~Buffer() {}

void Buffer::Bind() {}
void Buffer::Unbind() {}