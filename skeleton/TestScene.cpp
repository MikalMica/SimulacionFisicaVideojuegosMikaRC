#include "TestScene.h"
#include "ParticleSystem.h"
#include "SolidPSystem.h"
#include "GaussianSolidGen.h"
#include "FloatingForceGenerator.h"
#include "GravityForceGenerator.h"
#include "TornadoForceGenerator.h"
#include "Sea.h"
#include <iostream>

void 
TestScene::Update(double t) {
	ForceManager::Instance()->Update(t);

	testSys->Update(t);
}

void
TestScene::keyPress(unsigned char key, const PxTransform& camera) {

	switch (toupper(key))
	{
	default:
		break;
	}
}

void 
TestScene::loadScene() {
	ForceManager::Init(this);

	addSolid(true, 0.5, 0.5, 0.5, { 100, 2, 100 }, 0.9, { 0, 0, 0 }, {1, 0, 0, 1});
	testSys = new SolidPSystem(this, 1000);
	//testSys->addGen(new GaussianSolidGen(this, 0.5, 0.5, 0, 1, 0, {1, 1, 1}, 0.9, 0, {0, 15, 0}, {5, 5, 5}, 100, 0, {0, 0, 0}, {0, 0, 0}, 10, 0.8));

	ForceManager::Instance()->RegisterSolidPSystem(testSys, ForceManager::TORNADO_PARTS);
	ForceManager::Instance()->AddForceGenerator(new TornadoForceGenerator({ 0, 1, 0 }, { 0, 0, 0 }, 5), ForceManager::PLANET_RING);
}

void 
TestScene::unloadScene() {
}

void 
TestScene::onCollision(physx::PxActor* actor1, physx::PxActor* actor2) {
}
