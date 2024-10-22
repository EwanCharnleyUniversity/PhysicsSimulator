#ifndef OBJECTS_CLASS_HPP
#define OBJECTS_CLASS_HPP


class GraphicsEngine;

struct Point3D;
struct Vector3D;


class Objects {
public:
	virtual void Render(GraphicsEngine& graphics) {}
	virtual void Simulate() {}
};


#endif
