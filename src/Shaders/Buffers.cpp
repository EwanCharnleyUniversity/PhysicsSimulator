
#include <glad/glad.h>
#include "Buffers.h"


//* VAO *//

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::Bind() {
	glBindVertexArray(ID);
}


void VAO::VertexAttribute()  {
	// Hardcoded with ID { 0 } and { 3 } vertex pointers for position for now.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

VAO::~VAO() {
	glDeleteVertexArrays(1, &ID);
}


//* VBO *//

VBO::VBO() {
	glGenBuffers(1, &ID);
}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Buffer(float vertices[]) {
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

VBO::~VBO() {
	glDeleteBuffers(1, &ID);
}



//* EBO *//

EBO::EBO() {
	glGenBuffers(1, &ID);
}

void EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Buffer(int indices[]) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

EBO::~EBO() {
	glDeleteBuffers(1, &ID);
}