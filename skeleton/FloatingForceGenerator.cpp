#include "FloatingForceGenerator.h"
#include "Particle.h"

Vector3 
FloatingForceGenerator::forceToApply(Particle* p) {

	float immersed = 0.0;
	if (p->getPosition().y - height > pHeight * 0.5) immersed = 0.0;
	else if (height - p->getPosition().y > pHeight * 0.5) immersed = 1.0;
	else immersed = (height - p->getPosition().y) / pHeight + 0.5;

	return { 0, density * volume * immersed * 9.8f, 0 };
}
