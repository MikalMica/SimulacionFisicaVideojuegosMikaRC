#pragma once
#include "Anchor.h"
#include "ForceGenerator.h"
#include "Scene.h"
#include "DynamicSolid.h"
#include "StaticSolid.h"

class SpringForceGenerator : public ForceGenerator
{
protected:
	// length when no force is applied
	double length;

	// constant of the spring
	double K;

	// pointers to the embed particles
	Particle* p1;
	Particle* p2;

	// pointers to the embed solids
	DynamicSolid* s1;
	Solid* s2;

	// private bool to set if the Spring has an anchor or not
	bool isAnchored;

public:

	SpringForceGenerator(double l, double k, Particle* a, Particle* b = nullptr)
		: ForceGenerator({0, 0, 0})
		, length(l)
		, K(k)
		, p1(a)
		, p2(b)
		, s1(nullptr)
		, s2(nullptr)
	{ 
		if (p2 == nullptr) {
			p2 = new Anchor({ 0, 0, 0 });
		}
	}

	SpringForceGenerator(Scene* scene, double l, double k, DynamicSolid* a, DynamicSolid* b = nullptr)
		: ForceGenerator({ 0, 0, 0 })
		, length(l)
		, K(k)
		, p1(nullptr)
		, p2(nullptr)
		, s1(a)
		, s2(b)
	{
		if (s2 == nullptr) {
			auto s = scene->addSolid(true, 0.5, 0.5, 0.5, { 1, 1, 1 }, 0.9, { 0, 0, 0 }, {1, 0, 0, 1});
			s2 = s;
		}
	}

	SpringForceGenerator(Scene* scene, double l, double k, DynamicSolid* a, StaticSolid* b)
		: ForceGenerator({ 0, 0, 0 })
		, length(l)
		, K(k)
		, p1(nullptr)
		, p2(nullptr)
		, s1(a)
		, s2(b)
	{
	}

	Vector3 forceToApply(Particle* p) override;
	Vector3 forceToApply(DynamicSolid* p) override;
	Vector3 forceToApply(StaticSolid* p) override;
	void setK(double nK) { K = nK; }
};

