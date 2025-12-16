#pragma once
#include "Planet.h"
#include "SolidPSystem.h"

class RingedPlanet : public Planet
{

	// Ring of the planet
	SolidPSystem* ring = nullptr;

	Scene* scene = nullptr;

public:

	RingedPlanet(Scene* sce, Solid* solid, float r)
		: Planet(solid, r)
		, scene(sce)
	{ }

	void Update(double t) override;
	void init() override;
};

