#include "TornadoForceGenerator.h"
#include "Particle.h"

Vector3 
TornadoForceGenerator::forceToApply(Particle* p) {

	auto k = force.getNormalized() * Kt;
	auto vel = k.cross(p->getPosition() - origin);

	auto diff = vel - p->getVelocity();
	return  k1 * diff + k2 * abs(diff.magnitude()) * diff;
}

bool
TornadoForceGenerator::checkCondition(Particle* p) {

	if (r == 0.0f) return true && enabled;

	return (p->getPosition() - origin).magnitude() < r && enabled;
}