
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


// Shader Source Code (Vertex and Fragment)
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
"}\0";


// Hard coded vertices - normalised (center of screen is 0,0)
float vertices[] = {
	-0.5, -0.5f, 0.0f,
	0.5, -0.5f, 0.0f,
	0.5, 0.5f, 0.0f
};


// https://learnopengl.com/Getting-started/Hello-Triangle
int main(void) {

	// Initialises glfw.
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(1472, 828, "3D Physics Engine", NULL, NULL);

	// Checks if window has loaded.
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialises GLAD and checks if it fails to load.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Make the window our current context.
	glfwMakeContextCurrent(window);

	// Buffers
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	// Vertex Shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int  success;
	char infoLog[512];

	// Vertex Link Debug
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	// Fragment Shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


	// Shader Program
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);


	// Shader debug
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Attributes of Vertexes and enable them.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glClearColor(0.025, 0.025, 0.05, 0.0);

	// Program Runtime
	while (!glfwWindowShouldClose(window)) {
		vertices[0] += 0.001f;

		// Buffer inside runtime 1*
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// 1* This is necessary if we want to refresh the draw call per frame.
		// People will mention this is BAD for performance. But I do not care, as my program needs to grab data pertaining to vertex position and what not within worldspace.
		// Using matrix transformations, while plausible and the standard for displaying in OpenGL, needs to be parsed in shader files. Instead, I want to seperate the actual physics, position, etc of the Vertices
		// and Objects within worldspace from the actual renderer engine.
		
		// This has a hit on performance but, as mentioned, I do not care - PHYSICS ACCURACY is more important, and I do not want to deal with OpenGL in any way when it comes to calculated if two things have collided or not.
		// OpenGL is merely a visualisation tool, not the dictator of the entire project.

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	// Delete everything
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glfwTerminate();

	return 0;
}