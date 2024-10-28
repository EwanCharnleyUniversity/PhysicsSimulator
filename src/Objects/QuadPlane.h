#ifndef QUAD_PLANE_CLASS_HPP
#define QUAD_PLANE_CLASS_HPP

#include "Objects.h"



class QuadPlane : public Objects {
public:
	QuadPlane();

	virtual void Simulate(float time);
	virtual void Render(GraphicsEngine& graphics);

private:
	Model* baseModel;

	Vector3D* velocity;
	Vector3D* normal;
};


#endif