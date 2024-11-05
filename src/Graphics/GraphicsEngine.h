#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP


struct GLFWwindow;
class ShaderProgram;


// Ghetto quick struct for position of camera.
struct cam3D {
	float X, Y, Z;
};


class GraphicsEngine {
public:
	GLFWwindow*		window	= nullptr;
	ShaderProgram*	shaders = nullptr;

	cam3D cameraPos = { 0.0f, 0.0f, 0.0f };

	GraphicsEngine(int WIDTH, int HEIGHT, const char* name);
	~GraphicsEngine();

	void Render(const float &time);
};

#endif
