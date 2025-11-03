#pragma once
#include "ForceGenerator.h"

class GravityForceGenerator : public ForceGenerator
{
	float forceMagn;

public:
	GravityForceGenerator(float gravity = 9.8)
		: ForceGenerator({0, -1, 0})
		, forceMagn(gravity)
	{}

	Vector3 forceToApply(Particle* p) override;
};

