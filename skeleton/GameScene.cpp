#include "GameScene.h"
#include "Spaceship.h"

void 
GameScene::Update(double t) {

}

void 
GameScene::keyPress(unsigned char key, const PxTransform& camera) {

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