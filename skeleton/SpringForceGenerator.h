#pragma once
#include "Anchor.h"
#include "ForceGenerator.h"

class SpringForceGenerator : public ForceGenerator
{
protected:
	// length when no force is applied
	double length;

	// constant of the spring
	double K;

	// pointers to the embed particles
	Particle* p1;
	Particle* p2;

	// private bool to set if the Spring has an anchor or not
	bool isAnchored;

public:

	SpringForceGenerator(double l, double k, Particle* a, Particle* b = nullptr)
		: ForceGenerator({0, 0, 0})
		, length(l)
		, K(k)
		, p1(a)
		, p2(b)
	{ 
		if (p2 == nullptr) {
			p2 = new Anchor({ 0, 0, 0 });
		}
	}

	Vector3 forceToApply(Particle* p);
	void setK(double nK) { K = nK; }
};

