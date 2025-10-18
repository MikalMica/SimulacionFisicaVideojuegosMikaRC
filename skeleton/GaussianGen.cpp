#include "GaussianGen.h"

std::vector<Particle*>
GaussianGen::generateP() {
	std::vector<Particle*> particles;
	for (int i = 0; i < numParticles; ++i) {
		if (d(mt) >= probGen) continue;

		Vector3 pSource = { pos.x + posVar.x * d(mt), pos.y + posVar.y * d(mt), pos.z + posVar.z * d(mt) };
		Vector3 vSource = { vel.x + velVar.x * d(mt), vel.y + velVar.y * d(mt), vel.z + velVar.z * d(mt) };

		Particle* p = new Particle(pSource, vSource, ac, dur + lifeVar * d(mt), damping, mode, colour);
		particles.push_back(p);
	}

	return particles;
}