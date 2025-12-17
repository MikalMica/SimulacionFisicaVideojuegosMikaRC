#pragma once
#include "Planet.h"
#include "SolidPSystem.h"

class RingedPlanet : public Planet
{

	// Ring of the planet
	SolidPSystem* ring = nullptr;

	Scene* scene = nullptr;

	int tIndex;
	Vector3 iPos;

public:

	RingedPlanet(Scene* sce, Solid* solid, float r)
		: Planet(solid, r)
		, scene(sce)
		,tIndex(-1)
	{ 
		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::COMET;
		data->object = this;
		dBody->userData = data;
	}

	void Update(double t) override;
	void init() override;
};

