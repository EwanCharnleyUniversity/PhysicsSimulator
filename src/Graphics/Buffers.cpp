
#include <glad/glad.h>
#include "Buffers.h"

//### VAO ###//

// Vao Binding
VAO::VAO() {
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
}

void VAO::Bind() {
	glBindVertexArray(ID);
}

void VAO::Attribute(unsigned int index, unsigned int size) {
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, size * sizeof(float), (void*)0);
	glEnableVertexAttribArray(index);
}



//### BUFFERS ###//

// Buffers
Buffer::Buffer(unsigned int index) {
	glGenBuffers(index, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void Buffer::Bind(float vertices[]) {
	//glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}