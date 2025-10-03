#pragma once
#include <queue>
#include "Particle.h"

class Cannon
{
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
	};

	~Cannon() { int size = bullets.size(); for (int i = 0; i < size; ++i) { auto aux = bullets.front(); bullets.pop(); delete aux; aux = nullptr; } }

	void Shoot();
	void Update(double t);
	double SetSimulatedVel(double simulatedVel);
};

