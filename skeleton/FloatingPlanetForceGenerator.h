#pragma once
#include "ForceGenerator.h"

class FloatingPlanetForceGenerator : public ForceGenerator
{
	// center of the planet
	Vector3 origin;

	// radius of the liquid
	float radius;

	// height of the particle
	float pHeight;

	// volume of the liquid
	float volume;

	// density of the liquid
	float density;

	public:
		FloatingPlanetForceGenerator(double r, double pH, double v, double d, Vector3 const& ori)
			: ForceGenerator({ 0, 0, 0 })
			, radius(r)
			, pHeight(pH)
			, volume(v)
			, density(d)
			, origin(ori)
		{
		}

	Vector3 forceToApply(Particle* p) override;
	Vector3 forceToApply(DynamicSolid* s) override;


};

