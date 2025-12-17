#include "SolidPSystem.h"

#include "ForceGenerator.h"
#include "GaussianGen.h"
#include "ParticleSystem.h"

void
SolidPSystem::Update(double t) {

	if (generate) {
		auto sols = generators[genIndex]->generateS();
		for (auto s : sols) {
			if (solids.size() < maxSolids)
				solids.push(s);
			else {
				mScene->removeSolid(s);
				delete s; s = nullptr;
			}
		}
	}

	int size = solids.size();
	for (int i = 0; i < size; ++i) {
		auto s = solids.front();
		solids.pop();

		s->clearForceAndVelocity();
		s->Update(t);

		if (!forces.empty()) {
			for (int j = 0; j < forces.size(); ++j) {
				if (forces[j]->checkCondition(s)) // Sobrecargar
					s->addForce(forces[j]->forceToApply(s)); // Sobrecargar

			}
		}
		s->isFarFromOrigin(generators[genIndex]->getDistance());

		if (!s->hasToDie()) solids.push(s);
		else {
			mScene->removeSolid(s);
			delete s;
			s = nullptr;
		}
	}
}

void
SolidPSystem::removeGen(SolidGen* gen) {
	auto it = std::find(generators.begin(), generators.end(), gen);

	if (it == generators.end()) return;

	generators.erase(it);

	delete gen;
	gen = nullptr;

	return;
}

void
SolidPSystem::deregisterForceGenerator(ForceGenerator* gen) {
	auto it = std::find(forces.begin(), forces.end(), gen);

	if (it == forces.end()) return;

	forces.erase(it);

	return;
}

void
SolidPSystem::DestroyAllParticles() {

	int size = solids.size();

	for (int i = 0; i < size; ++i) {
		auto s = solids.front();
		solids.pop();

		mScene->removeSolid(s);
		delete s;
		s = nullptr;
	}
}