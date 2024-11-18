
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/matrix.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shaders.h"


static float FOV = 90.0f;


// Outputs the contents of a shader file via an inputted filepath.
std::string AccessShaderFile(const char* filepath) {
	std::ifstream source(filepath);
	std::string line, stream;

	if (!source.is_open()) {
		std::cout << "ERROR :: INCORRECT FILEPATH" << std::endl;
		return "";
	}

	while (std::getline(source, line)) {
		stream += line + "\n";
	}

	return stream;
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

	// Scuffed container
	std::string output = AccessShaderFile(filePath);
	const char* source = output.c_str();

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

	// Scuffed container
	std::string output = AccessShaderFile(filePath);
	const char* source = output.c_str();

	glShaderSource(ID, 1, &source, GL_FALSE);
	glCompileShader(ID);

	CheckShader(ID);
}

FragmentShader::~FragmentShader() {
	glDeleteShader(ID);
}



//* Shader Program *//

ShaderProgram::ShaderProgram(const char* vertexFilePath, const char* fragmentFilePath) {
	// Load up the Vertex and Fragment Shaders for the Shader Program
	Vertex	  =	new VertexShader(vertexFilePath);
	Fragment  =	new FragmentShader(fragmentFilePath);

	ID = glCreateProgram();

	// Attatch shaders and link them
	glAttachShader(ID, Vertex->ID);
	glAttachShader(ID, Fragment->ID);

	glLinkProgram(ID);
}


void ShaderProgram::Use() {
	glUseProgram(ID);
}


// Camera Perspective, we only need one camera so it's no big deal to make it hard-coded
// Parses in model, view, and projection matrices for the vertex shaders.
void ShaderProgram::cameraPerspective(GLFWwindow& window, const float &time) {
	
	// Grab the Windows width and height for later perspective calculation.
	int width, height;
	glfwGetWindowSize(&window, &width, &height);

	// Model matrix
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(time * 100), glm::vec3(0.0f, 1.0f, 0.0f));

	unsigned int modelproj = glGetUniformLocation(ID, "model");
	glUniformMatrix4fv(modelproj, 1, GL_FALSE, glm::value_ptr(model));
	

	// Viewing and Projection matrices
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	proj = glm::perspective(glm::radians(FOV), (float)width / (float)height, 0.1f, 100.0f);
	view = glm::translate(view, glm::vec3(cos(time), sin(time), -1.5f - sin(time / 3)));

	// Parse Camera projection matrix and viewing matrix into the shaders
	unsigned int viewing = glGetUniformLocation(ID, "view");
	glUniformMatrix4fv(viewing, 1, GL_FALSE, glm::value_ptr(view));

	unsigned int projection = glGetUniformLocation(ID, "proj");
	glUniformMatrix4fv(projection, 1, GL_FALSE, glm::value_ptr(proj));
}


ShaderProgram::~ShaderProgram() {
	Vertex->~VertexShader();
	Fragment->~FragmentShader();
}
