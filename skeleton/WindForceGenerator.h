#pragma once
#include "ForceGenerator.h"

class WindForceGenerator : public ForceGenerator
{
protected:
	Vector3 origin;
	float rangeX;
	float rangeY;
	float rangeZ;

	float k1;
	float k2;

public:
	WindForceGenerator(Vector3 windForce, float K1 = 1.0, float K2 = 0.0) : ForceGenerator(windForce), origin({ 0, 0, 0 }), rangeX(0), rangeY(0), rangeZ(0), k1(K1), k2(K2) {
	}

	WindForceGenerator(Vector3 windForce, Vector3 ori, float xRange, float yRange, float zRange, float K1 = 1.0, float K2 = 0.0)
		: ForceGenerator(windForce), origin(ori), rangeX(xRange), rangeY(yRange), rangeZ(zRange), k1(K1), k2(K2) {
	}

	void changeWindForceModule(double nModule);
	bool checkCondition(Particle* p) override;
	Vector3 forceToApply(Particle* p) override;

};