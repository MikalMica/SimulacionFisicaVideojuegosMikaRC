#pragma once
#include "Scene.h"

class ParticleSystem;
class TornadoForceGenerator;
class GravityForceGenerator;
class ExplosionForceGenerator;

class TestScene : public Scene
{
	// This scene's particle system
	ParticleSystem* pSys;

	// Scene's force generators
	TornadoForceGenerator* tornado;
	GravityForceGenerator* gravity;
	WindForceGenerator* wind;

public:
	TestScene() : Scene() {}

	void Update(double t) override;
	void keyPress(unsigned char key, const PxTransform& camera) override;

	void loadScene() override;
	void unloadScene() override;
};

