
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicsEngine.h"
#include "../Shaders/Shaders.h"
#include "../Shaders/Buffers.h"



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

	/* Working Triangle Code
	// Works with Vertex Array, Buffer, and Element Array.
	unsigned int VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	vertices[0] += 0.001f;

	// Render
	shaders->Use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//*/

	VAO vao;

	shaders->Use();
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
}

// Terminate
GraphicsEngine::~GraphicsEngine() {
	glfwTerminate();
}
