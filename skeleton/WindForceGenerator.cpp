#include "WindForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"

void 
WindForceGenerator::changeWindForceModule(double nModule) {
	force = force.getNormalized() * nModule;
}

bool 
WindForceGenerator::checkCondition(Particle* p) {
	if (!(rangeX || rangeY || rangeZ)) return true;
	auto pos = p->getPosition();
	return pos.x > origin.x && pos.x < (origin.x + rangeX) && pos.y > origin.y && pos.y < (origin.y + rangeY) && pos.z > origin.z && pos.z < (origin.z + rangeZ) && enabled;
}

Vector3 
WindForceGenerator::forceToApply(Particle* p) {
	Vector3 diff = force - p->getVelocity();
	return k1 * diff + k2 * abs(diff.magnitude()) * diff;
}

bool
WindForceGenerator::checkCondition(DynamicSolid* s) {
	if (!(rangeX || rangeY || rangeZ)) return true;
	auto pos = s->getPosition();
	return pos.x > origin.x && pos.x < (origin.x + rangeX) && pos.y > origin.y && pos.y < (origin.y + rangeY) && pos.z > origin.z && pos.z < (origin.z + rangeZ) && enabled;
}

Vector3
WindForceGenerator::forceToApply(DynamicSolid* s) {
	Vector3 diff = force - s->getVel();
	return k1 * diff + k2 * abs(diff.magnitude()) * diff;
}