#pragma once
#include "Planet.h"
#include "ParticleSystem.h"

class Scene;

class ExplodingPlanet : public Planet
{

	// Explosion constant
	float _K;

	// index of the RealGravityForceGenerator of this planet to deactivate it once it exploded
	int gIndex;

	// Particle system only updated when the planet explode
	ParticleSystem* explosion = nullptr;

	// timer to delete this after it exploded
	double destroyTimer = 0;

	Scene* mScene;

public:

	ExplodingPlanet(Solid* solid, float r, float k, Scene* scene)
		: Planet(solid, r)
		, _K(k)
		, gIndex(-1)
		, mScene(scene)
	{ }

	void Explode();
	void init() override;
	void Update(double t) override;
};

