#include "FloatingForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"
#include <iostream>

Vector3 
FloatingForceGenerator::forceToApply(Particle* p) {

	float immersed = 0.0;
	if (p->getPosition().y - height > pHeight * 0.5) immersed = 0.0;
	else if (height - p->getPosition().y > pHeight * 0.5) immersed = 1.0;
	else immersed = (height - p->getPosition().y) / pHeight + 0.5;

	return { 0, density * volume * immersed * 9.8f, 0 };
}

Vector3
FloatingForceGenerator::forceToApply(DynamicSolid* s) {

	float immersed = 0.0;
	if (s->getPosition().y - height > pHeight * 0.5) immersed = 0.0;
	else if (height - s->getPosition().y > pHeight * 0.5) immersed = 1.0;
	else immersed = (height - s->getPosition().y) / pHeight + 0.5;

	return { 0, density * volume * immersed * 9.8f, 0 };
}