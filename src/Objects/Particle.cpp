
#include "Particle.h"
#include "ObjectDatatypes.h"
#include "../Graphics/GraphicsEngine.h"



Particle::Particle(bool stat, float radius) : TRUE_RADIUS(radius), isStatic(stat) {
	position = new Point3D{ 0.,0.,0. };
	velocity = new Point3D{ 0.,0.,0. };

	position->Randomise(500.0);
	velocity->Randomise(5.0);
}


void Particle::Simulate() {

	if (isStatic)
		return;
	
	Vector3D worldCenter{ {0.0, 0.0, 0.0}, {this->position->X, this->position->Y, this->position->Z} };
	worldCenter /= {10000.0, 10000.0, 10000.0};

	*velocity -= worldCenter;
	*position += *velocity;
}


void Particle::Render(GraphicsEngine& graphics) {

	if (graphics.IsPositionBehind(position))
		return;

	float RENDER_RADIUS = TRUE_RADIUS * graphics.pCamera.position->Z / (position->Z - graphics.pCamera.position->Z);

	sf::CircleShape circle;
	circle.setRadius(RENDER_RADIUS);
	circle.setOrigin(RENDER_RADIUS, RENDER_RADIUS);
	circle.setPosition(graphics.WindowTranslation(position));

	graphics.Draw(circle);
}