#include "GameScene.h"
#include "Spaceship.h"
#include "Cannon.h"
#include "ForceManager.h"
#include "Planet.h"

void 
GameScene::Update(double t) {

	mSpaceship->Update(t);
	mCannon->Update(t);
}

void 
GameScene::keyPress(unsigned char key, const PxTransform& camera) {

	switch (key) {
	case 'x':
		mCannon->setPosition(camera.p);
		mCannon->setVel(camera.q);
		mCannon->Shoot();
		break;
	default:
		break;
	}

	mSpaceship->keyPress(key, camera);
}

void 
GameScene::loadScene() {

	mSpaceship = new Spaceship();
	mCannon = new Cannon({ 0, 0, 0 }, { 100, 0, 0 }, { 0, 0, 0 }, 5, 0.9, Particle::SI_EULER, 0.1, { 1, 0, 0, 1 });

	mCannon->SetSimulatedVel(250);

	auto plan = new Planet({ 400, 0, 400 }, { 1, 1, 0, 1 }, 100);
	planets.push_back(plan);

	// ALL SCENE OBJECTS MUST BE REGISTERED BEFORE ADDING NEW FORCEGENERATORS

	// Register Spaceship's components
	ForceManager::getSingleton()->RegisterParticle(mSpaceship);
	ForceManager::getSingleton()->RegisterCannon(mSpaceship->getCannon());
	ForceManager::getSingleton()->RegisterPSystem(mSpaceship->getPSystem());

	// initialize the forces
	for (auto planet : planets) {
		planet->init();
	}
}

void 
GameScene::unloadScene() {

	delete mSpaceship;
	mSpaceship = nullptr;

	delete mCannon;
	mCannon = nullptr;
}