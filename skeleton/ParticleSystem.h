#pragma once
#include <queue>
#include "Particle.h"
class ParticleGen;

class ParticleSystem
{
	std::queue<Particle*> particles;
	std::vector<ParticleGen*> generators;
	int maxParticles;
	int genIndex = 0;
public:
	ParticleSystem(int max) : maxParticles(max) {}
	ParticleSystem(std::vector<ParticleGen*> gens, int max) : maxParticles(max), generators(gens) {}

	~ParticleSystem() {
		int size = particles.size(); for (int i = 0; i < size; ++i) { auto aux = particles.front(); particles.pop(); delete aux; aux = nullptr; }
		size = generators.size(); for (int i = 0; i < size; ++i) { delete generators[i]; generators[i] = nullptr; };
	}

	void Update(double t);

	inline void addGen(ParticleGen* gen) { generators.push_back(gen); }
	inline void setGenerator(int index) { genIndex = index; }
};