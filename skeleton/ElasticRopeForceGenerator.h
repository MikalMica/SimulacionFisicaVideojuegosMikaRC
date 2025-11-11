#pragma once
#include "SpringForceGenerator.h"

class ElasticRopeForceGenerator : public SpringForceGenerator
{
public:
	ElasticRopeForceGenerator(double l, double k, Particle* a, Particle* b = nullptr)
		: SpringForceGenerator(l, k, a, b)
	{ }

	bool checkCondition(Particle* p) override;
};

