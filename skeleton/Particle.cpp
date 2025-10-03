#include "Particle.h"
#include <iostream>

void
Particle::Integrate(double t) {


	switch (mode) {
	case(Mode::EULER):
		lasPos = pos->p;
		pos->p = pos->p + t * v;
		v = v + t * a;
		v = v * pow(damping, t);
		break;
	case(Mode::SI_EULER):
		lasPos = pos->p;
		v = v + t * a;
		pos->p = pos->p + t * v;
		v = v * pow(damping, t);
		break;
	case(Mode::VERLET):
		lasPos = pos->p;
		pos->p = pos->p + t * v;
		v = v + t * a;
		v = v * pow(damping, t);
		mode = Mode::POST_VERLET;
		break;
	case(Mode::POST_VERLET):
		auto nPos = 2 * pos->p - lasPos + pow(t, 2)*a;
		lasPos = pos->p;
		pos->p = nPos;
		break;
	}

	tVida -= t;
	//std::cout << tVida << "\n";
}