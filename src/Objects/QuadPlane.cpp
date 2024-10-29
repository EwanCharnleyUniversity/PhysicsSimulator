
#include "../CommonDatatypes.h"
#include "../Graphics/GraphicDatatypes.h"
#include "QuadPlane.h"
#include "../Graphics/GraphicsEngine.h"

#include <iostream>
#include <random>



QuadPlane::QuadPlane() {
	position = new Vector3D{ 0,0,0 };
	baseModel = new Model();

	velocity = new Vector3D{ 0,0,0 };
	normal = new Vector3D{ { 0, 0, 0} , { 0, 100, 0} };
}

void QuadPlane::Simulate(float time) {

	baseModel->originPoint->Z = cos(time);
}


void QuadPlane::Render(GraphicsEngine& graphics) {

	baseModel->Display(graphics);
}