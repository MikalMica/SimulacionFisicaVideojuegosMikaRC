#pragma once
#include "ForceGenerator.h"

class ExplosionForceGenerator : public ForceGenerator
{

	// radius of the explosion
	float _radius;

	// constant to set the intensity of the explosion
	float _K;

	// time constant. From 4T the explosion is almost inexistent
	float _T;

	// center of the explosion
	Vector3 _origin;

	// time passed since initialitation
	double _time;

	// expansion velocity. Used to know how much does the explosion radius increase each second
	double _eVelocity;

public:

	ExplosionForceGenerator(float r, float k, float t, Vector3 center, double expVel = 343.0) 
		: ForceGenerator({0, 0, 0})
		, _radius(r)
		, _K(k)
		, _T(t)
		, _origin(center)
		, _time(0.0)
		, _eVelocity(expVel)
	{ }

	Vector3 forceToApply(Particle* p) override;
	Vector3 forceToApply(DynamicSolid* s) override;
	bool checkCondition(Particle* p) override;
	bool checkCondition(DynamicSolid* s) override;
	void Update(double t) override;
};

