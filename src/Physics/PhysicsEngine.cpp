
#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"

#include "GLFW/glfw3.h"


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPointer) : Graphics(graphicsPointer) {}


void PhysicsEngine::Simulate() {
	while (!glfwWindowShouldClose(Graphics.window)) {
		Graphics.Render();
	}
}