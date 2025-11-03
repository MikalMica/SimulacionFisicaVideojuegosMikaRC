#include "Cannon.h"
#include <iostream>

void
Cannon::Update(double t) {
	int size = bullets.size();

	for (int i = 0; i < size; ++i) {
		auto aux = bullets.front();
		bullets.pop();

		if (aux->hasToDie()) {
			delete aux;
			aux = nullptr;
		}
		else {
			for (auto force : forces) {
				if (force->checkCondition(aux))
					force->forceToApply(aux);
			}
			aux->Integrate(t);
			bullets.push(aux);
		}
	}
}

void
Cannon::Shoot() {
	if (bullets.size() >= MAX_BULLETS) return;
	auto part = new Particle(iPos, Svel, a, tVida, damping, Smass, mode, col);
	bullets.push(part);
}

/// <summary>
/// sets the simulated velocity and mass to mantain the cinetic energy
/// </summary>
/// <param name="simulatedVel"></param> the simulated energy wanted
/// <returns></returns> the simulated mass
double
Cannon::SetSimulatedVel(double simulatedVel) {

	auto direction = Rvel.getNormalized();
	Svel = Vector3(direction * simulatedVel);

	double realVel = Rvel.magnitude();
	Smass = Rmass * pow(realVel / simulatedVel, 2);

	return Smass;
}

void 
Cannon::applyForceGenerator(ForceGenerator* force) {

	forces.push_back(force);
}

void 
Cannon::deleteForceGenerator(ForceGenerator* force) {
	// delete force
}