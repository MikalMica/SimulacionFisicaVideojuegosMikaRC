#include "TornadoForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"
#include <iostream>

Vector3 
TornadoForceGenerator::forceToApply(Particle* p) {

	auto k = force.getNormalized() * Kt;
	auto vel = k.cross(p->getPosition() - origin);

	auto diff = vel - p->getVelocity();
	auto force = k1 * diff + k2 * abs(diff.magnitude()) * diff;

	std::cout << p->getVelocity().x << " " << p->getVelocity().y << " " << p->getVelocity().z << "\n";
	return  k1 * diff + k2 * abs(diff.magnitude()) * diff;
}

bool
TornadoForceGenerator::checkCondition(Particle* p) {

	if (r == 0.0f) return true && enabled;

	return (p->getPosition() - origin).magnitude() < r && enabled;
}

Vector3
TornadoForceGenerator::forceToApply(DynamicSolid* s) {

	auto k = force.getNormalized() * Kt;
	auto vel = k.cross(s->getPosition() - origin);

	auto diff = vel - s->getVel();
	return  k1 * diff + k2 * abs(diff.magnitude()) * diff;
}

bool
TornadoForceGenerator::checkCondition(DynamicSolid* s) {

	if (r == 0.0f) return true && enabled;

	return (s->getPosition() - origin).magnitude() < r && enabled;
}