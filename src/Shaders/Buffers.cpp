
#include <glad/glad.h>
#include "Buffers.h"


// Hard coded vertices for testing, six total floats per vertex
// XYZ coordinates    [ -1 to 1 ]
// RGB colour values [  0 to 1  ]
float vertices[] = {
	-0.5, -0.5f, -0.5f,		 1.0f,	0.0f,  0.0f,
	 0.5, -0.5f, -0.5f,		0.66f,	0.0f, 0.33f,
	 0.5,  0.5f, -0.5f,		 0.0f,  0.0f,  1.0f,
	-0.5,  0.5f, -0.5f,		0.33f, 0.66f,  0.0f,

	-0.5, -0.5f,  0.5f,		0.33f, 0.33f, 0.33f,
	 0.5, -0.5f,  0.5f,		 0.0f, 0.33f, 0.66f,
	 0.5,  0.5f,  0.5f,		 0.0f, 0.66f, 0.33f,
	-0.5,  0.5f,  0.5f,		 0.0f,  1.0f,  0.0f
};

// Element indices
unsigned int indices[] = {
	0,1,2,	0,2,3,
	5,6,2,	5,2,1,
	4,0,3,	4,3,7,
	5,4,6,	4,7,6,
	3,2,6,	3,6,7,
	4,5,1,	4,1,0,
};


Buffer::Buffer() {
	// Gen Data
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	BindVertexArray();

	BindBuffer(vertices);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}


void Buffer::BindBuffer(float* vertex) {

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Attribute VBO data (coordinate and RGB values)
	Attribute(0, 3, 6, 0);
	Attribute(1, 3, 6, 3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}



void Buffer::BindVertexArray() {
	glBindVertexArray(VAO);
}


/* 
# Layout	- ID from which a shader can parse in and use.
|[ example: ID 0 is texture coordinates, Fragment Shader gets it through layout 0 ]|
# Size	- The amount of data per Attribute.
|[ example: assigning three size could represent three floats which represent the attribute for coordinates. ]|
# Stride	- After reading Size, the rest of the vertex is skipped for the next in the array (if applicable).
|[ example: Vertex contains nine values but we only need three, after reading three we skip the other six for the next vertex. ]|
# Offset	- How much of the data is skipped from the beginning of the Vertex.
|[ example: Using the Vertex example from Stide, we need to parse two values from the start of it's fifth value. This means we have an Offset of five ]|
*/
void Buffer::Attribute(unsigned int layout, int size, int stride, int offset) {
	glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
	glEnableVertexAttribArray(layout);
}




/* How does the Cube work ?
	- We have a class Buffer Object that holds a VAO, VBO, and EBO.
	- currently, it hardcodes values based on the dimensions of a cube (8 vertexes, 36 indices)
	- These values are then dumped into their respective VBO and EBO before being attributed to the VAO.
	- Then after all that, we bind the Array Buffer and Vertex Array.

TO ABSTRACT THIS :
	- The Buffer Object will still need to contain the VAO, VBO, and EBO.
		- However, we can seperate the bind functions of the Buffer and Elements into their own functions.
		- Attributes can then be called from the Buffer focused functions. Probably do it in it's own function so it's abstracted.
	- We need to simply parse data from vertices and elements, WE SHOULD NOT HARD CODE IT!

*/