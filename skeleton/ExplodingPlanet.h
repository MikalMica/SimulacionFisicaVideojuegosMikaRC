#pragma once
#include "Planet.h"
#include "ParticleSystem.h"

class ExplodingPlanet : public Planet
{

	// Explosion constant
	float _K;

	// index of the RealGravityForceGenerator of this planet to deactivate it once it exploded
	int gIndex = -1;

	// Particle system only updated when the planet explode
	ParticleSystem* explosion = nullptr;

	// timer to delete this after it exploded
	double destroyTimer = 0;

public:

	ExplodingPlanet(Vector3 posi, Vector4 col, float r, double mass, float k)
		: Planet(posi, col, r, mass)
		, _K(k)
	{ }

	void Explode();
	void init() override;
	void Update(double t) override;
};

