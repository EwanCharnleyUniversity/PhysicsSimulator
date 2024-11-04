
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicsEngine.h"
#include "../Shaders/Shaders.h"
#include "../Shaders/Buffers.h"


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

	// Create Shaders
	shaders = new ShaderProgram("src/Shaders/vertex.vert", "src/Shaders/fragment.frag");

}

// Performs one Frame Call for Rendering
void GraphicsEngine::Render() {
	glfwPollEvents();

	glClearColor(0.033f, 0.033f, 0.066f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	shaders->Use();

	VAO vao;
	vao.Bind();

	VBO vbo;
	vbo.Bind();

	vbo.Buffer(vertices);
	vao.VertexAttribute();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glfwSwapBuffers(window);
}

// Terminate
GraphicsEngine::~GraphicsEngine() {
	glfwTerminate();
}
