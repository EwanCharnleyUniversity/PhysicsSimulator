
#define PI 3.14159265


#include <iostream>
#include <vector>


// Constants
static int MOVING_PARTICLES = 1;
static int STATIC_PARTICLES = 1;

static float PARTICLE_RADIUS = 10.f;
static float PARTICLE_MASS = 25.f;


static float Square(float input) {
	return input * input;
}


struct Vector3D {
	float X, Y, Z;


	// Magnitude is the square root of x^2 + y^2 + z^2 
	float Magnitude() {
		return sqrt(Square(X) + Square(Y) + Square(Z));
	}

	// (x1y1) + (x2y2) + (x3y3)
	float CrossProduct(Vector3D input) {
		return (this->X * input.X) + (this->Y * input.Y) + (this->Z * input.Z);
	}

	// Dot Product is the inverse cosine of the dot product of two vectors divided by their multiplied magnitudes.
	float DotProduct(Vector3D input) {
		return CrossProduct(input) / (Magnitude() * input.Magnitude());
	}

	float DotProductToAngle(Vector3D input) {
		return acosf(CrossProduct(input) / (Magnitude() * input.Magnitude())) * 180 / PI;
	}


	void Print() {
		std::cout << "X: " << this->X << " ";
		std::cout << "Y: " << this->Y << " ";
		std::cout << "Z: " << this->Z << std::endl;
	}


	// Addition
	inline Vector3D operator +(const Vector3D& lhs) const {
		return Vector3D{
			this->X + lhs.X,
			this->Y + lhs.Y,
			this->Z + lhs.Z
		};
	}

	inline Vector3D operator +=(const Vector3D& lhs) {
		this->X += lhs.X;
		this->Y += lhs.Y;
		this->Z += lhs.Z;

		return *this;
	}


	// Subtraction
	inline Vector3D operator -(const Vector3D& lhs) const {
		return Vector3D{
			this->X - lhs.X,
			this->Y - lhs.Y,
			this->Z - lhs.Z
		};
	}

	inline Vector3D operator -=(const Vector3D& lhs) {
		this->X -= lhs.X;
		this->Y -= lhs.Y;
		this->Z -= lhs.Z;

		return *this;
	}


	// Multiplication
	inline Vector3D operator *(const Vector3D& lhs) const {
		return Vector3D{
			this->X * lhs.X,
			this->Y * lhs.Y,
			this->Z * lhs.Z
		};
	}

	inline Vector3D operator *=(const Vector3D& lhs) {
		this->X *= lhs.X;
		this->Y *= lhs.Y;
		this->Z *= lhs.Z;

		return *this;
	}

	inline Vector3D operator *(const float& lhs) const {
		return Vector3D{
			this->X * lhs,
			this->Y * lhs,
			this->Z * lhs
		};
	}

	inline Vector3D operator *=(const float& lhs) {
		this->X *= lhs;
		this->Y *= lhs;
		this->Z *= lhs;

		return *this;
	}


	// Division
	inline Vector3D operator /(const Vector3D& lhs) const {
		return Vector3D{
			this->X / lhs.X,
			this->Y / lhs.Y,
			this->Z / lhs.Z
		};
	}

	inline Vector3D operator /=(const Vector3D& lhs) {
		this->X /= lhs.X;
		this->Y /= lhs.Y;
		this->Z /= lhs.Z;

		return *this;
	}

	inline Vector3D operator /(const float& lhs) const {
		return Vector3D{
			this->X / lhs,
			this->Y / lhs,
			this->Z / lhs
		};
	}

	inline Vector3D operator /=(const float& lhs) {
		this->X /= lhs;
		this->Y /= lhs;
		this->Z /= lhs;

		return *this;
	}
};


class Particle {
public:
	Particle(int id, bool immobile) : STATIC(immobile), ID(id) {
		position = {
			static_cast<float> (rand()) / static_cast<float> (RAND_MAX / 25),
			static_cast<float> (rand()) / static_cast<float> (RAND_MAX / 25),
			static_cast<float> (rand()) / static_cast<float> (RAND_MAX / 25)
		};

		velocity = {
			static_cast<float> (rand()) / static_cast<float> (RAND_MAX),
			static_cast<float> (rand()) / static_cast<float> (RAND_MAX),
			static_cast<float> (rand()) / static_cast<float> (RAND_MAX)
		};
	}


	void DetectPlane() {
		
		Vector3D surfacePosition{ 0,0,0 };
		Vector3D surfaceNormal{ 0,1,0 };

		float angle = surfaceNormal.DotProduct(velocity * -1);

		std::cout << "Angle to plane: " << angle << std::endl;
		std::cout << "In Degrees: " << angle * 180 / PI << std::endl;
		std::cout << std::endl;
	}


	void DetectParticle(std::vector<Particle>& targets) {
		for (auto& target : targets) {

			// Check if the target is itself
			if (target.ID == this->ID) {
				continue;
			}

			// Distance Magnitude between target and parent
			Vector3D distance = target.position - this->position;
			Vector3D velocityVector = velocity - position;
			float angle = velocityVector.DotProduct(distance);


			// Print data on distance and angle.
			std::cout << this->ID << " -> " << target.ID << std::endl;
			std::cout << "Distance to Target || "; distance.Print();
			std::cout << "Angle: " << sin(angle) << std::endl;
			std::cout << "Closest Approach: " << sin(angle) * distance.Magnitude() << std::endl;


			// Check angle to the combined radius.
			float combinedRadius = this->RADIUS + target.RADIUS;
			float closest = sin(angle) * distance.Magnitude();

			if (closest <= combinedRadius) {
				std::cout << "collision is possible!" << std::endl;

				// Calculate the point of collision
				// offset from closest approach	(e)  :  Square root of combined radius squared, minus the closest approach squared
				// Length of Collision Point	(Vc) :  cosine of the angle times the magnitude of distance minus the point of collision.
				float collisionOffset = sqrt(Square(combinedRadius) - Square(closest));
				float collisionPointMagnitude = cos(angle) * distance.Magnitude() - collisionOffset;

				// Find length of collision point (aka it's vector)
				// Vc * V / |V|
				Vector3D vcVector = velocity * collisionPointMagnitude / velocity.Magnitude();

				std::cout << "Collision Point || "; vcVector.Print();
			}
		}
	}


	void Simulate(std::vector<Particle>& targets) {

		std::cout << "Particle: " << this->ID << std::endl;
		std::cout << "Position || "; this->position.Print();

		if (STATIC) {
			std::cout << "Particle is static and will not move.\n" << std::endl;
			return;
		}

		std::cout << "Velocity || "; this->velocity.Print();

		DetectPlane();
		DetectParticle(targets);

		position += velocity;
		std::cout << std::endl;
	}

private:
	bool STATIC = false;
	int ID;
	float RADIUS{ PARTICLE_RADIUS }, MASS{ PARTICLE_MASS };
	Vector3D position, velocity;
};



void ParticleToStaticParticle() {
	std::vector<Particle> particles;
	for (int i = 0; i < MOVING_PARTICLES; i++) {
		particles.push_back(Particle(particles.size(), false));
	}

	for (int i = 0; i < STATIC_PARTICLES; i++) {
		particles.push_back(Particle(particles.size(), true));
	}

	while (1) {
		for (auto& i : particles) {
			i.Simulate(particles);
		}
	}
}



void ParticleToPlane() {
	std::vector<Particle> particles;
	for (int i = 0; i < MOVING_PARTICLES; i++) {
		particles.push_back(Particle(particles.size(), false));
	}

	while (1) {
		for (auto& i : particles) {
			i.Simulate(particles);
		}
	}
}



int main(void) {
	srand(time(NULL));


	// Raw maths check both on paper (or doc) and in program.
	Vector3D particlePosition{ 13.131, 14.72, -18.32 };
	Vector3D particleVelocity{ 3.3, -4, 2 };

	Vector3D planePoint{ 0, -2.5, 0 };
	Vector3D planeNormal{ 0, 1, 0 };
	
	std::cout << "magnitude of Normal is: " << planeNormal.Magnitude() << std::endl;
	std::cout << "magnitude of Velocity is: " << particleVelocity.Magnitude() << std::endl;
	std::cout << planeNormal.Magnitude() << " * " <<  particleVelocity.Magnitude() << " = " << planeNormal.Magnitude() * particleVelocity.Magnitude() << std::endl;

	std::cout << "Cross Product of Normal and the inverse of Velocity: " << planeNormal.CrossProduct(particleVelocity * -1) << std::endl;
	std::cout << "Dot Product between Normal and inverse of Velocity is: " << planeNormal.DotProduct(particleVelocity * -1) << std::endl;
	std::cout << "Angle between Normal and inverse of Velocity is: " << planeNormal.DotProductToAngle(particleVelocity * -1) << std::endl;

	if (planeNormal.DotProductToAngle(particleVelocity * -1) >= 90.f) {
		std::cout << "\nParticle will not collide.\n";
	}

	std::cout << "\nParticle will collide!\n";



	//ParticleToStaticParticle();

	return 0;
}