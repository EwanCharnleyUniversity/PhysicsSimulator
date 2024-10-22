#ifndef QUAD_PLANE_CLASS_HPP
#define QUAD_PLANE_CLASS_HPP

#include "Objects.h"



class QuadPlane : public Objects {
public:
	QuadPlane();

	virtual void Simulate();
	virtual void Render(GraphicsEngine& graphics);

private:
	Point3D* velocity;
	Vector3D* normal;
	Point3D* vertices[4];
};


#endif