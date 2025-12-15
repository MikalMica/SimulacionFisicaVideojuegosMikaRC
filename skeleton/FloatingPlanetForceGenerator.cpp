#include "FloatingPlanetForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"
#include <iostream>

Vector3
FloatingPlanetForceGenerator::forceToApply(Particle* p) {

	float immersed = 0.0;
	if ((origin - p->getPosition()).magnitude() > (radius + pHeight)) immersed = 0.0;
	else if ((origin - p->getPosition()).magnitude() < (radius - pHeight)) immersed = 1.0;
	else immersed = (radius - (origin - p->getPosition()).magnitude()) / pHeight;

	return (p->getPosition() - origin).getNormalized() * (density * volume * immersed * 9.8f);
}

Vector3
FloatingPlanetForceGenerator::forceToApply(DynamicSolid* s) {

	float immersed = 0.0;
	if ((origin - s->getPosition()).magnitude() > (radius + pHeight)) immersed = 0.0;
	else if ((origin - s->getPosition()).magnitude() < (radius - pHeight)) immersed = 1.0;
	else immersed = (radius - (origin - s->getPosition()).magnitude()) / pHeight;

	return (s->getPosition() - origin).getNormalized() * (density * volume * immersed * 9.8f);
}