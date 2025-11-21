#pragma once
#include "Scene.h"
#include "ElasticRopeForceGenerator.h"
#include "ForceManager.h"

class Sea;

class TestScene : public Scene
{
	Particle* pTest;
	Particle* pTest2;
	Sea* sea;

	int springIndex = 0;
public:
	TestScene(PxPhysics* gPh, PxScene* sc) : Scene(gPh, sc) {}

	void Update(double t) override;
	void keyPress(unsigned char key, const PxTransform& camera) override;

	void loadScene() override;
	void unloadScene() override;
};

