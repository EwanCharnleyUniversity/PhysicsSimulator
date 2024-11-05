
#ifndef PHYSICS_ENGINE_CLASS_HPP
#define PHYSICS_ENGINE_CLASS_HPP


class GraphicsEngine;


class PhysicsEngine {
public:
	GraphicsEngine& Graphics;

	PhysicsEngine(GraphicsEngine& graphicsPointer);
	void Simulate();

};


#endif