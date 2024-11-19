

#include <iostream>
#include <vector>


// Constants
int PARTICLE_AMOUNT = 2;


static float Square(float input) {
	return input * input;
}


struct Vector3D {
	float X, Y, Z;

	// Vector Magnitude
	float Magnitude() {
		return sqrt(Square(X) + Square(Y) + Square(Z));
	}

	float Dot(Vector3D input) {
		return (this->X * input.X) + (this->Y * input.Y) + (this->Z * input.Z);
	}

	float Angle(Vector3D input) {
		return acosf(
			Dot(input) / (Magnitude() * input.Magnitude())
		);
	}

	void Print() {
		std::cout << "X: " << this->X << " ";
		std::cout << "Y: " << this->Y << " ";
		std::cout << "Z: " << this->Z << std::endl;
	}


	// Addition
	inline Vector3D operator +(const Vector3D& lhs) {
		this->X += lhs.X;
		this->Y += lhs.Y;
		this->Z += lhs.Z;

		return *this;
	}

	inline Vector3D operator +=(const Vector3D& lhs) {
		return operator+(lhs);
	}


	// Subtraction
	inline Vector3D operator -(const Vector3D& lhs) {
		this->X -= lhs.X;
		this->Y -= lhs.Y;
		this->Z -= lhs.Z;

		return *this;
	}

	inline Vector3D operator -=(const Vector3D& lhs) {
		return operator-(lhs);
	}


	// Multiplication
	inline Vector3D operator *(const Vector3D& lhs) {
		this->X *= lhs.X;
		this->Y *= lhs.Y;
		this->Z *= lhs.Z;

		return *this;
	}

	inline Vector3D operator *=(const Vector3D& lhs) {
		return operator*(lhs);
	}

	// Division
	inline Vector3D operator /(const Vector3D& lhs) {
		this->X /= lhs.X;
		this->Y /= lhs.Y;
		this->Z /= lhs.Z;

		return *this;
	}

	inline Vector3D operator /=(const Vector3D& lhs) {
		return operator/(lhs);
	}

};


// Particle
class Particle {
public:
	Particle(int id) {
		ID = id;
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

		RADIUS = 10.f;
		MASS = 2.5f;
	}


	void Simulate(std::vector<Particle>& targets) {
		
		for (auto target : targets) {

			// Check if the target is itself
			if (target.ID == this->ID) {
				continue;
			}
			
			// Distance Magnitude between target and parent
			Vector3D distance = target.position; distance -= this->position;
			Vector3D velocityVector = velocity; velocityVector -= position;
			float angle = velocityVector.Angle(distance);
			

			// Print everything out
			std::cout << this->ID << " -> " << target.ID << std::endl;
			std::cout << "Position || "; this->position.Print();
			std::cout << "Velocity || "; this->velocity.Print();
			std::cout << "Distance to Target || "; distance.Print();
			std::cout << "Angle: " << sin(angle) << std::endl;
			std::cout << sin(angle) * distance.Magnitude() << std::endl;


			// Check angle to the combined radius.
			if (sin(angle) * distance.Magnitude() <= this->RADIUS + target.RADIUS) {
				std::cout << "collision is possible" << std::endl;
			}


		}

		//position += velocity;
	}

private:
	int ID;
	float RADIUS, MASS;
	Vector3D position, velocity;
};




int main(void) {
	srand(time(NULL));


	// Generate Vector of Particles
	std::vector<Particle> particles;
	for (int i = 0; i < PARTICLE_AMOUNT; i++) {
		particles.push_back(Particle(i));
	}


	while (1) {
		// Loop through every particle for simulation
		for (auto& i : particles) {
			i.Simulate(particles);
		}
	}

	return 0;
}