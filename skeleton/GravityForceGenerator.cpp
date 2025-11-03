#include "GravityForceGenerator.h"
#include "Particle.h"

Vector3 
GravityForceGenerator::forceToApply(Particle* p) {
	auto ac = force * forceMagn;

	return ac * p->getMass();
}
