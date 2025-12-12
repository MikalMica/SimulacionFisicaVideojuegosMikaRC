#pragma once
#include "Planet.h"
#include "ParticleSystem.h"

class RingedPlanet : public Planet
{

	// Ring of the planet
	ParticleSystem* ring = nullptr;

public:

	RingedPlanet(Solid* solid, float r)
		: Planet(solid, r)
	{ }

	void Update(double t) override;
	void init() override;
};

