#pragma once
#include "Planet.h"
#include "ParticleSystem.h"

class RingedPlanet : public Planet
{

	// Ring of the planet
	ParticleSystem* ring = nullptr;

public:

	RingedPlanet(Vector3 posi, Vector4 col, float r, double mass)
		: Planet(posi, col, r, mass)
	{ }

	void Update(double t) override;
	void init() override;
};

