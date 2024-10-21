
#ifndef PHYSICS_ENGINE_CLASS_HPP
#define PHYSICS_ENGINE_CLASS_HPP


class GraphicsEngine;


class PhysicsEngine {
public:
	PhysicsEngine(GraphicsEngine& graphics);

	void Simulate();


private:
	GraphicsEngine* graphics;
	double TIME;

};


#endif
