#include "ParticleSystem.h"
#include "GaussianGen.h"

void
ParticleSystem::Update(double t) {
	auto partics = generators[genIndex]->generateP();

	for (auto p : partics) { 
		if (particles.size() < maxParticles)
			particles.push(p);
		else
			delete p; p = nullptr;
	}

	int size = particles.size();
	for (int i = 0; i < size; ++i) {
		auto p = particles.front();
		particles.pop();

		p->Integrate(t);
		p->isFarFromOrigin(generators[genIndex]->getDistance());

		if (!p->hasToDie()) particles.push(p);
		else {
			delete p;
			p = nullptr;
		}
	}
}