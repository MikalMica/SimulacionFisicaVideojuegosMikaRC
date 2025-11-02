#include "RealGravityForceGenerator.h"
#include "Particle.h"

bool 
RealGravityForceGenerator::checkCondition(Particle* p) {
	if (radius < 0) return true;

	return (p->getPosition() - origin).magnitude() < radius;
}

Vector3 
RealGravityForceGenerator::forceToApply(Particle* p) {

	auto direction = origin - p->getPosition();
	double distance = direction.magnitude();
	direction = direction.getNormalized();

	double forceMagnitude = G * ((oMass * p->getMass()) / pow(distance, 2));

	return direction * forceMagnitude;
}