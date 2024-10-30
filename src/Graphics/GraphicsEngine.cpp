
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicsEngine.h"
#include "../Shaders/Shaders.h"


// Hard coded vertices - normalised (center of screen is 0,0)
float vertices[] = {
	-0.5, -0.5f, 0.0f,
	0.5, -0.5f, 0.0f,
	0.5, 0.5f, 0.0f
};


GraphicsEngine::GraphicsEngine(int WIDTH, int HEIGHT, const char* TITLE) {

	// Initialises glfw.
	if (!glfwInit())
		return;

	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

	// Checks if window has loaded.
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	// Initialises GLAD and checks if it fails to load.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	ShaderProgram Shaders("src/Shaders/vertex.vert", "src/Shaders/fragment.frag");
}

// Performs one Frame Call for Rendering
void GraphicsEngine::Render() {
	glfwPollEvents();

	glClearColor(0.033f, 0.033f, 0.066f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
}

// Terminate
GraphicsEngine::~GraphicsEngine() {
	glfwTerminate();
}
