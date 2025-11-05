#pragma once
#include <queue>
#include <functional>
#include "Particle.h"
#include "ParticleGen.h"
class ForceGenerator;

class ParticleSystem
{
	std::queue<Particle*> particles;
	std::vector<ParticleGen*> generators;
	std::vector<ForceGenerator*> forces;
	int maxParticles;
	int genIndex = 0;
	int forceIndex = 0;
	bool generate = true;
public:
	ParticleSystem(int max) : maxParticles(max) {}
	ParticleSystem(std::vector<ParticleGen*> gens, int max) : maxParticles(max), generators(gens) {}

	~ParticleSystem() {
		int size = particles.size(); for (int i = 0; i < size; ++i) { auto aux = particles.front(); particles.pop(); delete aux; aux = nullptr; }
		size = generators.size(); for (int i = 0; i < size; ++i) { delete generators[i]; generators[i] = nullptr; };
	}

	void Update(double t);

	inline void addGen(ParticleGen* gen) { generators.push_back(gen); }
	void removeGen(ParticleGen* gen);
	inline void setGenerator(int index) { genIndex = index; }

	inline void applyForceGenerator(ForceGenerator* gen) { forces.push_back(gen); }
	void deregisterForceGenerator(ForceGenerator* gen);

	inline void setCurrPosition(Vector3 nPos) { generators[genIndex]->setPosition(nPos); }
	inline Vector3 getCurrPosition() { return generators[genIndex]->getPosition(); }

	void DestroyAllParticles();
	inline void ChangeParticleGeneration() { generate = !generate; }

};

// Viento: F_v = K_1 (O_v - O) + K_2 (v_v - v) |v_v - v|