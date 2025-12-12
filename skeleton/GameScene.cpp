#include "GameScene.h"
#include "Spaceship.h"
#include "Cannon.h"
#include "ForceManager.h"
#include "Planet.h"
#include "ExplodingPlanet.h"
#include "RingedPlanet.h"
#include "Nebula.h"

void 
GameScene::Update(double t) {

	mSpaceship->Update(t);
	mCannon->Update(t);
	mNebula->Update(t);
	
	for (auto planet : planets) {
		if (planet->hasToDie()) {
			killPlanet(planet);
		}
		else planet->Update(t);
	}

	ForceManager::Instance()->Update(t);
}

void 
GameScene::keyPress(unsigned char key, const PxTransform& camera) {

	std::vector<ForceGenerator*> forces;

	switch (key) {
	case 'x':
		mCannon->setPosition(camera.p);
		mCannon->setVel(camera.q, true);
		mCannon->Shoot();
		break;
	case '1':
		forces = ForceManager::Instance()->getGeneratorGroup(ForceManager::PLANET_GRAVITY);
		for (auto force : forces) {
			force->changeEnabled();
		}
		break;
	case '2':
		for (auto planet : ePlanets) {
			planet->Explode();
		}
		break;
	case '3':
		forces = ForceManager::Instance()->getGeneratorGroup(ForceManager::PLANET_RING);
		for (auto force : forces) {
			force->changeEnabled();
		}
	default:
		break;
	}

	mSpaceship->keyPress(key, camera);
}

void 
GameScene::loadScene() {

	ForceManager::Init(this);

	mSpaceship = new Spaceship();
	mCannon = new Cannon({ 0, 0, 0 }, { 100, 0, 0 }, { 0, 0, 0 }, 5, 0.9, Particle::SI_EULER, 0.1, { 1, 0, 0, 1 });
	mNebula = new Nebula({ 400, 0, 400 });

	mCannon->SetSimulatedVel(250);

	// Create the planets
	planets.push_back(new Planet(addSolid(false, 0.5, 0.5, 0.8, 100, 0.9, { 1200, 0, 500 }, { 1, 0, 1, 1 }), 6 * pow(10, 16)));
	planets.push_back(new Planet(addSolid(false, 0.3, 0.3, 0.6, 100, 0.8, { 0, 200, 500 }, { 1, 0.5, 0.5, 1 }), 6 * pow(10, 16)));
	planets.push_back(new Planet(addSolid(false, 0.2, 0.2, 0.8, 100, 0.5, { -800, -400, 0 }, { 1, 0.7, 0.7, 1 }), 6 * pow(10, 16)));
	planets.push_back(new Planet(addSolid(false, 0.9, 0.9, 0.2, 100, 0.3, { -300, 0, -500 }, { 1, 1, 1, 1 }), 6 * pow(10, 16)));;
	planets.push_back(new RingedPlanet(addSolid(false, 0.5, 0.5, 0.9, 100, 0.9, { 500, 0, 200 }, { 0, 0, 0, 1 }), 6 * pow(10, 16)));

	// Create aside the Exploding planets
	auto exp = new ExplodingPlanet(addSolid(false, 0.5, 0.5, 0.8, 100, 0.9, { 300, 0, 700 }, { 1, 0, 0, 1 }), 6 * pow(10, 16), 100, this);
	planets.push_back(exp);
	ePlanets.push_back(exp);

	// Register Spaceship's components
	ForceManager::Instance()->RegisterParticle(mSpaceship, ForceManager::SPACESHIP);
	ForceManager::Instance()->RegisterCannon(mSpaceship->getCannon(), ForceManager::SPACESHIP);
	ForceManager::Instance()->RegisterPSystem(mSpaceship->getPSystem(), ForceManager::SPACESHIP);

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

	delete mNebula;
	mNebula = nullptr;

	ePlanets.clear();

	for (auto planet : planets) {
		delete planet;
		planet = nullptr;
	}
}

bool
GameScene::killPlanet(Planet* planet) {
	auto it = std::find(planets.begin(), planets.end(), planet);

	if (it == planets.end()) return false;

	auto aux = *it;

	planets.erase(it);

	delete planet;
	planet = nullptr;

	return true;
}
