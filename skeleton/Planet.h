#pragma once
#include "DynamicSolid.h"
#include "ExplosionForceGenerator.h"
#include "RealGravityForceGenerator.h"

class Planet : public DynamicSolid
{
protected:

	// Radius of the planet
	float forceRadius;

public:

	Planet(Solid *solid, float r) 
		: DynamicSolid(*static_cast<DynamicSolid*>(solid))
		, forceRadius(r)
	{
		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::PLANET;
		data->object = this;
		dBody->userData = data;
	}

	virtual void Update(double t);
	void keyPress(unsigned char key, const PxTransform& camera);

	virtual void init();
};

