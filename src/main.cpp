

#include "Graphics/GraphicsEngine.h"
#include "Physics/PhysicsEngine.h"


// https://learnopengl.com/Getting-started/Hello-Triangle
int main(void) {

	GraphicsEngine Graphics(1472, 828, "OpenGL Worldspace Renderer");
	PhysicsEngine Physics(Graphics);
	Physics.Simulate();

	return 0;
}