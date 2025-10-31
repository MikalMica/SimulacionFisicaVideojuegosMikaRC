#include "TornadoForceGenerator.h"
#include "Particle.h"

Vector3 
TornadoForceGenerator::forceToApply(Particle* p) {
	auto vel = p->getPosition().cross(origin);
	vel.z *= -1;
	vel.y += 50;
	vel *= k1;

	//Aplicar fuerza
}