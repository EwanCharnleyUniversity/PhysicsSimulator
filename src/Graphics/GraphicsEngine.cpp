
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicsEngine.h"
#include "../Shaders/Shaders.h"
#include "../Shaders/Buffers.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}



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

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Initialises GLAD and checks if it fails to load.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	// Create Shaders
	shaders = new ShaderProgram("resources/vertex.vert", "resources/fragment.frag");

	glEnable(GL_DEPTH_TEST);
}


// Performs one Frame Call for Rendering to the Shaders
void GraphicsEngine::Render(const float &time) {
	glfwPollEvents();

	// Clear background and cull depth hidden faces.
	glClearColor(0.033f, 0.033f, 0.066f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Buffer buffer;

	shaders->Use();
	shaders->cameraPerspective(*window, time);

	buffer.BindVertexArray();

	// Find buffer size for drawing
	int nBufferSize = 0;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &nBufferSize);
	int size = (nBufferSize / sizeof(int));

	glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
}


GraphicsEngine::~GraphicsEngine() {
	glfwTerminate();
}