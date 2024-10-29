
#include <iostream>
#include <fstream>
#include <string>

#include <glad/glad.h>
#include "Shaders.h"


// Outputs the contents of a shader file via an inputted filepath.
const char* AccessShaderFile(std::string filepath) {
	std::ifstream ShaderFileSource(filepath, std::ios::binary);
	
	if (!ShaderFileSource.is_open())
		throw std::runtime_error("ERROR:: INCORRECT SHADER FILEPATH");

	std::string contents, line;
	while (std::getline(ShaderFileSource, line)) {
		contents += line;
	}

	std::cout << contents.c_str() << std::endl;
	std::cout << contents << std::endl;

	const char* a = "#version 330";
	return a;
}



VertexShader::VertexShader() {
	ID = glCreateShader(GL_VERTEX_SHADER);

	const char* source = AccessShaderFile("src/Shaders/vertex.vert");
	glShaderSource(ID, 1, &source, GL_FALSE);
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