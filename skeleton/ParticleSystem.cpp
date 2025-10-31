#include "ParticleSystem.h"
#include "ForceGenerator.h"
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

		
		if (!forces.empty()) {
			for (int j = 0; j < forces.size(); ++j) {
				if (forces[j]->checkCondition(p))
					p->addForce(forces[j]->forceToApply(p));

			}
		}
		p->Integrate(t);
		p->isFarFromOrigin(generators[genIndex]->getDistance());

		if (!p->hasToDie()) particles.push(p);
		else {
			delete p;
			p = nullptr;
		}
	}
}

void
ParticleSystem::removeGen(ParticleGen* gen) {
	// remove ParticleGen
}

void 
ParticleSystem::deleteForceGenerator(ForceGenerator* gen) {
	// remove Force generator
}

