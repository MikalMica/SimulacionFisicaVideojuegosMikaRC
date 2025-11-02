#pragma once
#include "ForceGenerator.h"

class RealGravityForceGenerator : public ForceGenerator
{

	// Gravitational constant
	const double G = 6.67408 * pow(10, -11);
	
	// Mass of the object who is going to attract others
	double oMass;

	// Origin of the object
	Vector3 origin;

	// radius of action. Used to make things easier for the player
	double radius;

public:

	RealGravityForceGenerator(double mass, Vector3 ori = {0, 0, 0}, double r = -1)
		: ForceGenerator({0, 0, 0})
		, oMass(mass)
		, origin(ori)
		, radius(r)
	{ }

	bool checkCondition(Particle* p) override;
	Vector3 forceToApply(Particle* p) override;
};

