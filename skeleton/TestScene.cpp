#include "TestScene.h"
#include "ParticleSystem.h"
#include "FloatingForceGenerator.h"
#include "GravityForceGenerator.h"
#include "Sea.h"
#include <iostream>

void 
TestScene::Update(double t) {
	ForceManager::Instance()->Update(t);
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
	ForceManager::Init();

	addSolid(false, 0.5, 0.5, 0.5, { 10, 10, 10 }, 0.9, { 0, 30, 0 });
	addSolid(true, 0.5, 0.5, 0.5, { 100, 2, 100 }, 0.9, { 0, 0, 0 });
	
}

void 
TestScene::unloadScene() {
}