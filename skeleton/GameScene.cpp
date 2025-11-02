#include "GameScene.h"
#include "Spaceship.h"

void 
GameScene::Update(double t) {

	mSpaceship->Update(t);
}

void 
GameScene::keyPress(unsigned char key, const PxTransform& camera) {

	mSpaceship->keyPress(key, camera);
}

void 
GameScene::loadScene() {

	mSpaceship = new Spaceship();
}

void 
GameScene::unloadScene() {

	delete mSpaceship;
	mSpaceship = nullptr;
}