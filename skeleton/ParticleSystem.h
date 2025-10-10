#pragma once
#include <queue>
#include "Particle.h"
class ParticleGen;

class ParticleSystem
{
	std::queue<Particle*> particles;
	std::vector<ParticleGen*> generators;
	Vector3 iPos;
public:
	ParticleSystem(Vector3 P, Vector3 V, Vector3 A, double T, double d, Particle::Mode m, double M)
		: iPos(P) {
		particles = std::queue<Particle*>();
	};

	~ParticleSystem() { int size = particles.size(); for (int i = 0; i < size; ++i) { auto aux = particles.front(); particles.pop(); delete aux; aux = nullptr; }
	
	void Update(double t);
};

