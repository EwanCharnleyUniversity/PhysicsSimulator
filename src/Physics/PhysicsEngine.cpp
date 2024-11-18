
#include <iostream>

#include "PhysicsEngine.h"
#include "../Graphics/GraphicsEngine.h"

#include "GLFW/glfw3.h"

#include "Particle.h"


PhysicsEngine::PhysicsEngine(GraphicsEngine& graphicsPointer) : Graphics(graphicsPointer) {}


void PhysicsEngine::Simulate() {
	float clock = 0;
	Particle test;

	while (!glfwWindowShouldClose(Graphics.window)) {
		clock += 0.01f;

		test.Simulate();
		Graphics.Render(clock);
	}
}