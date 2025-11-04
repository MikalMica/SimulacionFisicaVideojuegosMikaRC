#pragma once
#include "Planet.h"

class ExplodingPlanet : public Planet
{

	// Explosion constant
	float _K;

	// index of the RealGravityForceGenerator of this planet to deactivate it once it exploded
	int gIndex = -1;

	// Add a Particle system which only updates once the planet exploded

public:

	ExplodingPlanet(Vector3 posi, Vector4 col, float r, double mass, float k)
		: Planet(posi, col, r, mass)
		, _K(k)
	{ }

	void Explode();
	void init() override;
};

