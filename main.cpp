#include <iostream>
#include <vector>
#include <iomanip>

#define PI 3.14159265


#ifdef NDEBUG
static bool debug = false;
#else
static bool debug = true;
static int TERMINAL_LENGTH = 16;

/**
 * @brief A Logger structure that allows tidier terminal readings.
 * @tparam std::string ID which denotes the name to the loggers instantiated function, class, etc. Useful for marking the code focus in runtime.
 * @returns std::ostream* pointer to std::cout, automatically prints out the stored stream.
 */
class Logger {
private:
	std::ostream* stream = &std::cout;
	std::string ID = "NaN";

public:
	Logger(std::string id) : ID(id) {
		*stream << ID << "\t ||";

		if (TERMINAL_LENGTH - ID.size() > 0) {
			stream->width(TERMINAL_LENGTH - ID.size());
		}
	}

	template <typename T>
	Logger& operator <<(const T& msg) {
		*stream << msg;
		return *this;
	}
};

#endif


// Constants
static int MOVING_PARTICLES = 1;
static int STATIC_PARTICLES = 1;

static float PARTICLE_RADIUS = 10.f;
static float PARTICLE_MASS = 25.f;


static float Square(float input) {
	return input * input;
}

static float Degrees(float input) {
	return acos(input) * 180 / PI;
}


/**
* @brief adasd
* @param floats: X, Y, Z for 3D coordination
*/
struct Vector3D {
	float X, Y, Z;

	// Magnitude is the square root of x^2 + y^2 + z^2 
	float Magnitude() {
		float result = Square(X) + Square(Y) + Square(Z);

		if (debug) {
			Logger logger("Magnitude");
			logger << "(" << this->X << " * " << this->X << ") + (" << this->Y << " * " << this->Y << ") + (" << this->Z << " * " << this->Z << ") = " << Square(X) + Square(Y) + Square(Z);
			logger << "sqrt(" << result << ") = " << sqrt(result);
		}
		
		return sqrt(Square(X) + Square(Y) + Square(Z));
	}

	// Dot Product is x1x2 + y1y2 + z1z2
	float DotProduct(Vector3D input) {
		float result = this->X * input.X + this->Y * input.Y + this->Z * input.Z;
		std::cout << "Dot Product|| " << "(" << this->X << " * " << input.X << ") + (" << this->Y << " * " << input.Y << ") + (" << this->Z << " * " << input.Z << ") = " << result << std::endl;
		return result;
	}

	// Angle is cosine of the dot product divided by the magnitude.
	// Returned as cosine result between -1 and 1.
	float Angle(Vector3D input) {
		float dot = DotProduct(input);
		float magnitude = Magnitude() * input.Magnitude();
		float result = dot / magnitude;
		std::cout << "Angle||" << dot << " / " << magnitude << " = " << result << std::endl;

		std::cout << "Degrees||" << Degrees(result) << "" << std::endl;
		return result;
	}


	void Print() {
		std::cout << "Vector|| X: " << this->X << "	Y: " << this->Y << "	Z: " << this->Z << std::endl;
	}

	void Print(std::string name) {
		std::cout << name << "|| X: " << this->X << "	Y: " << this->Y << "	Z: " << this->Z << std::endl;
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

		float headingAngle = surfaceNormal.DotProduct(velocity * -1);

		Vector3D positionToPlane = surfacePosition - position;
		float planeAngle = positionToPlane.DotProduct(surfaceNormal);

		std::cout << "Angle to plane: " << headingAngle << std::endl;
		std::cout << "In Degrees: " << headingAngle * 180 / PI << std::endl;
		std::cout << std::endl;


		float d = cos(planeAngle) * positionToPlane.Magnitude();
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
	float radius = 2.0f;

	Vector3D planePoint{ 0, -2.5, 0 };
	Vector3D planeNormal{ 0, 1, 0 };

	planePoint.Print("Plane Point");
	planeNormal.Print("Plane Normal");
	particlePosition.Print("Particle Position");
	particleVelocity.Print("Particle Velocity");

	float angleVtoN = planeNormal.Angle(particleVelocity * -1);

	if (angleVtoN >= 90.f) {
		std::cout << "\nParticle will not collide.\n";
		return 0;
	}

	std::cout << "\nParticle will collide!" << std::endl;

	Vector3D P = planePoint - particlePosition;

	planeNormal.Print("Plane Normal");
	P.Print("Plane to Particle");
	float q = planeNormal.Angle(P);
	float d = cos(q) * P.Magnitude();
	std::cout << "D	|| " << d << std::endl;

	float VcMag = (d - radius) / cos(angleVtoN);
	Vector3D Vc = (particleVelocity * VcMag) / particleVelocity.Magnitude();
	Vc.Print("Vc");

	//ParticleToStaticParticle();

	return 0;
}