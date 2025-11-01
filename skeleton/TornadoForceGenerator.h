#pragma once
#include "WindForceGenerator.h"

class TornadoForceGenerator : public WindForceGenerator
{
	float Kt;
	float r;
public:
	TornadoForceGenerator(Vector3 windForce, Vector3 ori, float KT, float radius = 0.0, float K1 = 5.0, float K2 = 0.0) : WindForceGenerator(windForce, K1, K2), Kt(KT), r(radius) {
		origin = ori;
	}

	Vector3 forceToApply(Particle* p) override;
	bool checkCondition(Particle* p) override;

};