#ifndef QUAD_PLANE_CLASS_HPP
#define QUAD_PLANE_CLASS_HPP

#include "Objects.h"


struct Point3D;


class QuadPlane : public Objects {
public:
	QuadPlane();

	virtual void Simulate();
	virtual void Render(GraphicsEngine& graphics);

private:
	Point3D* velocity;
	Point3D* vertices[4];
};


#endif