#include "TestScene.h"
#include "ParticleSystem.h"
#include "GaussianGen.h"
#include "TornadoForceGenerator.h"
#include "GravityForceGenerator.h"
#include "ExplosionForceGenerator.h"

void 
TestScene::Update(double t) {

	pSys->Update(t);
}

void
TestScene::keyPress(unsigned char key, const PxTransform& camera) {

	auto explosion = new ExplosionForceGenerator(10, 100, 1, { 0, 0, 0 });
	switch (toupper(key))
	{
	case '1':
		pSys->applyForceGenerator(explosion);
		break;
	default:
		delete explosion;
		break;
	}
}


void 
TestScene::loadScene() {

	pSys = new ParticleSystem(1000);
	GaussianGen* water = new GaussianGen({ 0, 0, 0 }, { 0, 0, 0 }, 7, 500, 0.6, 0.9, Particle::SI_EULER, 5, 1, 1, 1.0, { 0.5, 0.5, 0.5 }, { 2.5, 0, 2.5 }, { 0, 0, 1, 1 });
	wind = new WindForceGenerator({ 10.0, 0.0, 0.0 });
	gravity = new GravityForceGenerator();
	tornado = new TornadoForceGenerator({ 0, 1, 0 }, { 0, 0, 0 }, 10);

	pSys->addGen(water);
	//pSys->applyForceGenerator(tornado);
	//pSys->applyForceGenerator(gravity);
	//pSys->applyForceGenerator(wind);
}

void 
TestScene::unloadScene() {

	delete pSys;
	pSys = nullptr;
}