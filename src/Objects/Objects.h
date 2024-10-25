#ifndef OBJECTS_CLASS_HPP
#define OBJECTS_CLASS_HPP


class GraphicsEngine;

struct Vector3D;
struct Vector3D;


class Objects {
public:
	virtual void Simulate() {}
	virtual void Render(GraphicsEngine& graphics) {}
};


#endif
