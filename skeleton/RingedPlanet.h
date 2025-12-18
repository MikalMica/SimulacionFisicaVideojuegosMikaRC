#pragma once
#include "Planet.h"
#include "SolidPSystem.h"

class TornadoForceGenerator;

class RingedPlanet : public Planet
{

	// Ring of the planet
	SolidPSystem* ring = nullptr;

	Scene* scene = nullptr;

	TornadoForceGenerator* tForce;
	Vector3 iPos;

public:

	RingedPlanet(Scene* sce, Solid* solid, float r)
		: Planet(solid, r)
		, scene(sce)
		, tForce(nullptr)
	{ 
		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::COMET;
		data->object = this;
		dBody->userData = data;
	}

	void Update(double t) override;
	void init() override;
};

