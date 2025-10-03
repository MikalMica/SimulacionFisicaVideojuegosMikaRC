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
			aux->Integrate(t);
			bullets.push(aux);
		}
	}
}

void
Cannon::Shoot() {
	auto part = new Particle(iPos, Svel, a, tVida, damping, mode);
	bullets.push(part);
}

/// <summary>
/// sets the simulated velocity and mass to mantain the cinetic energy
/// </summary>
/// <param name="simulatedVel"></param> the simulated energy wanted
/// <returns></returns> the simulated mass
double
Cannon::SetSimulatedVel(double simulatedVel) {

	auto direction = Rvel.normalize();
	Svel = Vector3(direction * simulatedVel);

	double realVel = Rvel.magnitude();
	Smass = Rmass * pow(realVel / simulatedVel, 2);

	return Smass;
}