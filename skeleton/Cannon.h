#pragma once
#include <queue>
#include "Particle.h"

class Cannon
{
public:
	enum Type {
		Bullet,
		Bowling_ball,
		Balloon
	};

private:
	int const MAX_BULLETS = 20;

	struct particleType {
		Vector3 Vel;
		Vector3 ac;
		Vector4 colour;
	};

	Type pType;
	std::vector<particleType> particles;
	Vector3 iPos;
	Vector3 Rvel;
	Vector3 a;
	double Rmass;
	double tVida; // in seconds
	double damping;
	Particle::Mode mode;
	Vector3 Svel;
	double Smass;

	std::queue<Particle*> bullets;

public:
	Cannon(Vector3 P, Vector3 V, Vector3 A, double T, double d, Particle::Mode m, double M)
		: iPos(P), Rvel(V), a(A), Rmass(M), tVida(T), damping(d), mode(m), Svel(V), Smass(M) {
		bullets = std::queue<Particle*>();
		particles = { {{ -20, 0, -20 }, { 0, -9.8, 0 }, {1, 0, 0, 1}}, { {-10, 0, -10}, {0, -20, 0}, {0, 1, 0, 1} }, { {-20, 0, -20}, {0, 9.8, 0}, {0, 0, 1, 1} } };
	};

	~Cannon() { int size = bullets.size(); for (int i = 0; i < size; ++i) { auto aux = bullets.front(); bullets.pop(); delete aux; aux = nullptr; } }

	void Shoot();
	void Update(double t);
	double SetSimulatedVel(double simulatedVel);

	inline void setType(Type nType) { pType = nType; }
	inline void setPosition(Vector3 const& nPos) { iPos = nPos; };
	inline void setSpeed(Vector3 const& nVel) { Rvel = nVel; };
	inline void setVel(PxQuat const& nVel) { Svel = nVel.rotate({0, 0, -particles[pType].Vel.magnitude()}); };

	inline Vector3 getVel() { return Rvel; }
};

