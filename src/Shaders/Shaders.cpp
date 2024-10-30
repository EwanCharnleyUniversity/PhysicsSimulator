
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>

#include <glad/glad.h>
#include "Shaders.h"


// Outputs the contents of a shader file via an inputted filepath.
const char* AccessShaderFile(const char* filepath) {
	std::ifstream source(filepath, std::ios::in | std::ios::binary);
	std::string stream{ "" }, line{ "" };

	if (!source.is_open()) {
		throw std::runtime_error("INCORRECT SHADER FILEPATH");
	}

	while (std::getline(source, line)) {
		stream += line + "\n";
	}

	source.close();

	const char* output = "#version 330 core";
	return stream.c_str();
}


// Checks Shader Compilation and prints out an error if the file has incorrect syntax.
void CheckShader(unsigned int &ID) {
	int success;
	char infoLog[512];

	glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
}


//* Vertex Shader *//

VertexShader::VertexShader(const char* filePath) {
	ID = glCreateShader(GL_VERTEX_SHADER);

	const char* source = AccessShaderFile(filePath);
	std::cout << source;

	glShaderSource(ID, 1, &source, GL_FALSE);
	glCompileShader(ID);

	CheckShader(ID);
}

VertexShader::~VertexShader() {
	glDeleteShader(ID);
}



//* Fragment Shader *//

FragmentShader::FragmentShader(const char* filePath) {
	ID = glCreateShader(GL_FRAGMENT_SHADER);
}

FragmentShader::~FragmentShader() {
	glDeleteShader(ID);
}



//* Shader Program *//

ShaderProgram::ShaderProgram(const char* vertexFilePath, const char* fragmentFilePath) {
	// Load up the Vertex and Fragment Shaders for the Shader Program
	Vertex	  =	new VertexShader(vertexFilePath);
	Fragment  =	new FragmentShader(fragmentFilePath);
}