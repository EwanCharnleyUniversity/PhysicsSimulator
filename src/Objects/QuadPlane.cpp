
#include "../CommonDatatypes.h"
#include "../Graphics/GraphicDatatypes.h"
#include "QuadPlane.h"
#include "../Graphics/GraphicsEngine.h"

#include <iostream>
#include <random>



QuadPlane::QuadPlane() {
	baseModel = new Model();

	velocity = new Vector3D{ 0,0,0 };
	normal = new Vector3D{ { 0, 0, 0} , { 0, 100, 0} };
}

void QuadPlane::Simulate(float time) {

	baseModel->originPoint.Z = 5 * cos(time) - 5;
}


void QuadPlane::Render(GraphicsEngine& graphics) {

	baseModel->Display(graphics);
}