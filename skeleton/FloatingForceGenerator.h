#pragma once
#include "ForceGenerator.h"

class FloatingForceGenerator : public ForceGenerator
{
	// height of the liquid
	float height;

	// height of the particle
	float pHeight;

	// volume of the liquid
	float volume;

	// density of the liquid
	float density;

public:
	FloatingForceGenerator(double h, double pH, double v, double d)
		: ForceGenerator({0, 0, 0})
		, height(h)
		, pHeight(pH)
		, volume(v)
		, density(d)
	{ }

	Vector3 forceToApply(Particle* p) override;
	Vector3 forceToApply(DynamicSolid* s) override;
};

