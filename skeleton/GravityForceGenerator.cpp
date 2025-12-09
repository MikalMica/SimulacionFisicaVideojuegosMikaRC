#include "GravityForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"

Vector3 
GravityForceGenerator::forceToApply(Particle* p) {
	auto ac = force * forceMagn;

	return ac * p->getMass();
}

Vector3
GravityForceGenerator::forceToApply(DynamicSolid* s) {
	auto ac = force * forceMagn;

	return ac * s->getMass();
}