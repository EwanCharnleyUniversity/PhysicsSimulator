#ifndef OBJECTS_CLASS_HPP
#define OBJECTS_CLASS_HPP


class GraphicsEngine;

struct Vector3D;
struct Model;


class Objects {
public:
	virtual void Simulate() {}
	virtual void Render(GraphicsEngine& graphics) {}
};


#endif
