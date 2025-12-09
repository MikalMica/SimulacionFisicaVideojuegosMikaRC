#include "RealGravityForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"

bool 
RealGravityForceGenerator::checkCondition(Particle* p) {
	if (radius < 0) return true;

	return (p->getPosition() - origin).magnitude() < radius && enabled;
}

Vector3 
RealGravityForceGenerator::forceToApply(Particle* p) {

	auto direction = origin - p->getPosition();
	double distance = direction.magnitude();
	direction = direction.getNormalized();

	double forceMagnitude = G * ((oMass * p->getMass()) / pow(distance, 2));

	return direction * forceMagnitude;
}

bool
RealGravityForceGenerator::checkCondition(DynamicSolid* s) {
	if (radius < 0) return true;

	return (s->getPosition() - origin).magnitude() < radius && enabled;
}

Vector3
RealGravityForceGenerator::forceToApply(DynamicSolid* s) {

	auto direction = origin - s->getPosition();
	double distance = direction.magnitude();
	direction = direction.getNormalized();

	double forceMagnitude = G * ((oMass * s->getMass()) / pow(distance, 2));

	return direction * forceMagnitude;
}