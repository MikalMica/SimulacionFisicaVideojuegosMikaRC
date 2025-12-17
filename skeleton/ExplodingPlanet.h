#pragma once
#include "Planet.h"
#include "ParticleSystem.h"
#include "SpaceObjectData.h"

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

	// flag to explode the planet out of physics time
	bool hasToExplode;

	// flag to see if the planet has exploded
	bool hasExploded;

	Scene* mScene;

	void _Explode();

public:

	ExplodingPlanet(Solid* solid, float r, float k, Scene* scene)
		: Planet(solid, r)
		, _K(k)
		, gIndex(-1)
		, mScene(scene)
		, hasToExplode(false)
		, hasExploded(false)
	{
		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::EXPLODING_PLANET;
		data->object = this;
		dBody->userData = data;
	}

	void Explode() { hasToExplode = true; }
	void init() override;
	bool hasPlanetExploded() { return hasExploded; }
	void Update(double t) override;
};

