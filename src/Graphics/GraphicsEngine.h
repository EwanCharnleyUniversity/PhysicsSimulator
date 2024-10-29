
#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP


struct GLFWwindow;


class GraphicsEngine {
public:
	GLFWwindow* window = nullptr;

	GraphicsEngine(int WIDTH, int HEIGHT, const char* name);
	~GraphicsEngine();

	void Render();
};


#endif
