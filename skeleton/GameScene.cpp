#include "GameScene.h"
#include "Spaceship.h"
#include "Cannon.h"
#include "ForceManager.h"
#include "ExplodingPlanet.h"

void 
GameScene::Update(double t) {

	mSpaceship->Update(t);
	mCannon->Update(t);

	ForceManager::Instance()->Update(t);
}

void 
GameScene::keyPress(unsigned char key, const PxTransform& camera) {

	std::vector<ForceGenerator*> forces;

	switch (key) {
	case 'x':
		mCannon->setPosition(camera.p);
		mCannon->setVel(camera.q);
		mCannon->Shoot();
		break;
	case '1':
		forces = ForceManager::Instance()->getGeneratorGroup(ForceManager::PLANET_GRAVITY);
		for (auto force : forces) {
			force->changeEnabled();
		}
		break;
	case '2':
		for (auto planet : planets) {
			auto pl = static_cast<ExplodingPlanet*>(planet);
			if (pl != nullptr) pl->Explode();
		}
	default:
		break;
	}

	mSpaceship->keyPress(key, camera);
}

void 
GameScene::loadScene() {

	ForceManager::Init();

	mSpaceship = new Spaceship();
	mCannon = new Cannon({ 0, 0, 0 }, { 100, 0, 0 }, { 0, 0, 0 }, 5, 0.9, Particle::SI_EULER, 0.1, { 1, 0, 0, 1 });

	mCannon->SetSimulatedVel(250);

	// Create the planets
	//planets.push_back(new Planet({ 120, 0, 120 }, { 1, 1, 0, 1 }, 100, 6 * pow(10, 16)));
	planets.push_back(new ExplodingPlanet({ 120, 0, 120 }, { 1, 1, 0, 1 }, 100, 6 * pow(10, 16), 100));

	// Register Spaceship's components
	ForceManager::Instance()->RegisterParticle(mSpaceship);
	ForceManager::Instance()->RegisterCannon(mSpaceship->getCannon());
	ForceManager::Instance()->RegisterPSystem(mSpaceship->getPSystem());

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

	for (auto planet : planets) {
		delete planet;
		planet = nullptr;
	}
}