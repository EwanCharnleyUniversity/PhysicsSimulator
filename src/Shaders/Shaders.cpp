
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <glad/glad.h>
#include "Shaders.h"


// Outputs the contents of a shader file via an inputted filepath.
void AccessShaderFile(std::string filepath) {

}



VertexShader::VertexShader() {
	ID = glCreateShader(GL_VERTEX_SHADER);

	// Compiles Vertex Shader from .vert File
}

VertexShader::~VertexShader() {
	glDeleteShader(ID);
}



FragmentShader::FragmentShader() {
	ID = glCreateShader(GL_FRAGMENT_SHADER);
}

FragmentShader::~FragmentShader() {
	glDeleteShader(ID);
}