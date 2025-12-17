#include "ExplosionForceGenerator.h"
#include "Particle.h"
#include "DynamicSolid.h"
#include "ForceManager.h"
#include <cmath>

Vector3 
ExplosionForceGenerator::forceToApply(Particle* p) {

	auto diff = p->getPosition() - _origin;
	auto eForce = (_K / pow(diff.magnitude(), 2)) * diff * pow(std::exp(1.0), -(_time / _T));
	return eForce;
}

bool 
ExplosionForceGenerator::checkCondition(Particle* p) {

	return (p->getPosition() - _origin).magnitude() < _radius && enabled;
}

Vector3
ExplosionForceGenerator::forceToApply(DynamicSolid* s) {

	auto diff = s->getPosition() - _origin;
	auto eForce = (_K / pow(diff.magnitude(), 2)) * diff * pow(std::exp(1.0), -(_time / _T));
	return eForce;
}

bool
ExplosionForceGenerator::checkCondition(DynamicSolid* s) {

	return (s->getPosition() - _origin).magnitude() < _radius && enabled;
}

void 
ExplosionForceGenerator::Update(double t) {

	_time += t;
	_radius += _eVelocity * t;

	if (_time >= 4 * _T) ForceManager::Instance()->DeleteForceGenerator({ this, ForceManager::EXPLOSION });
}
