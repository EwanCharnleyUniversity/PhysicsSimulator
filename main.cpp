

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
			std::cout << this->ID << " -> " << target.ID << std::endl;
			Vector3D distance = target.position - this->position;
			std::cout << distance.Magnitude() << std::endl;



		}
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
		for (auto i : particles) {
			i.Simulate(particles);
		}
	}

	return 0;
}