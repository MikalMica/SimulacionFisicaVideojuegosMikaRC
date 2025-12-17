#pragma once
#include "Scene.h"
#include "ElasticRopeForceGenerator.h"
#include "ForceManager.h"

class SolidPSystem;

class TestScene : public Scene
{
	SolidPSystem* testSys = nullptr;

	int springIndex = 0;
public:
	TestScene(PxPhysics* gPh, PxScene* sc) : Scene(gPh, sc) {}

	void Update(double t) override;
	void keyPress(unsigned char key, const PxTransform& camera) override;

	void loadScene() override;
	void unloadScene() override;

	void onCollision(physx::PxActor* actor1, physx::PxActor* actor2) override;
};

