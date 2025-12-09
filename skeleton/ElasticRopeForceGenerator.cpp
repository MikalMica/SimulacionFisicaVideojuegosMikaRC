#include "ElasticRopeForceGenerator.h"

bool
ElasticRopeForceGenerator::checkCondition(Particle* p) {
	Vector3 diff;

	if (p == p1)
		diff = p2->getPosition() - p1->getPosition();
	else
		diff = p1->getPosition() - p2->getPosition();

	return diff.magnitude() > length;
}

bool
ElasticRopeForceGenerator::checkCondition(DynamicSolid* s) {
	Vector3 diff;

	if (s == s1)
		diff = p2->getPosition() - s1->getPosition();
	else
		diff = p1->getPosition() - s2->getPosition();

	return diff.magnitude() > length;
}