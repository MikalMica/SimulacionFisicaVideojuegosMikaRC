#pragma once
#include "Scene.h"

class ParticleSystem;

class TestScene : public Scene
{
	// This scene's particle system
	ParticleSystem* pSys;

public:
	TestScene() : Scene() {}

	void Update(double t) override;
	void keyPress(unsigned char key, const PxTransform& camera) override;

	void loadScene() override;
	void unloadScene() override;
};

