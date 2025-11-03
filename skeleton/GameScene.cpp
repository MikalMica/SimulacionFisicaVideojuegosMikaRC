#include "GameScene.h"
#include "Spaceship.h"
#include "Cannon.h"

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

}

void 
GameScene::unloadScene() {

	delete mSpaceship;
	mSpaceship = nullptr;

	delete mCannon;
	mCannon = nullptr;
}