#include "SpringForceGenerator.h"

Vector3
SpringForceGenerator::forceToApply(Particle* p)
{
	Vector3 diff;

	if(p == p1)
		diff = p2->getPosition() - p1->getPosition();
	else
		diff = p1->getPosition() - p2->getPosition();

	float currLen = diff.normalize();
	float delta_x = currLen - length;

	Vector3 force = diff * delta_x * K;

	return force;
}