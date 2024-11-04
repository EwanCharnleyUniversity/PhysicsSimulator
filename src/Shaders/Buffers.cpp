
#include <glad/glad.h>
#include "Buffers.h"


// Hard coded vertices for testing, six total floats per vertex
// XYZ coordinates  ( -1 to 1 )
// RGB colour values ( 0 to 1 )
float vertices[] = {
	-0.5, -0.5f, .0f,	1.0f, 0.0f,  .0f,
	 0.5, -0.5f, .0f,	 .0f, 1.0f, 0.0f,
	 0.5,  0.5f, .0f,	0.0f,  .0f, 1.0f,
	-0.5,  0.5f, .0f,	0.5f, 0.0f, 0.5f
};

// Element indices
unsigned int indices[] = {
	0,1,2,
	0,2,3
};


VAO::VAO() {
	// Gen Data
	glGenVertexArrays(1, &ID);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	Bind();

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Element Array
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Attribute VBO data (coordinate and RGB values)
	Attribute(0, 3, 6, 0);
	Attribute(1, 3, 6, 3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	Bind();
}

void VAO::Bind() {
	glBindVertexArray(ID);
}

/* 
Layout	- ID from which a shader can parse in and use.
|[ example: ID 0 is texture coordinates, Fragment Shader gets it through layout 0 ]|

Size	- The amount of data per Attribute.
|[ example: 3 floats constitute the attribute for coordinates. ]|

Stride	- After reading Size, the rest of the vertex is skipped for the next in the array (if applicable).
|[ example: Vertex contains nine values but we only need three, after reading three we skip the other six for the next vertex. ]|

Offset	- How much of the data is skipped from the beginning of the Vertex.
|[ example: Using the Vertex example from Stide, we need to parse two values from the start of it's fifth value. This means we have an Offset of five ]|
*/
void VAO::Attribute(unsigned int layout, int size, int stride, int offset) {
	glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
	glEnableVertexAttribArray(layout);
}
