#pragma once
#include "WindForceGenerator.h"

class TornadoForceGenerator : public WindForceGenerator
{
public:
	TornadoForceGenerator(Vector3 windForce, Vector3 ori, float K1 = 5.0, float K2 = 0.0) : WindForceGenerator(windForce, K1, K2){
		origin = ori;
	}

	Vector3 forceToApply(Particle* p) override;
};