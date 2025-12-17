#include "GameScene.h"
#include "Spaceship.h"
#include "Cannon.h"
#include "ForceManager.h"
#include "Planet.h"
#include "ExplodingPlanet.h"
#include "RingedPlanet.h"
#include "WaterPlanet.h"
#include "Nebula.h"
#include "Comet.h"
#include "AlienLifeForm.h"
#include "Star.h"

void 
GameScene::Update(double t) {

	mSpaceship->Update(t);
	mCannon->Update(t);
	mNebula->Update(t);
	mComet->Update(t);
	mAlien->Update(t);
	mStar->Update(t);
	
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
		forces = ForceManager::Instance()->getGeneratorGroup(ForceManager::GRAVITY);
		for (auto force : forces) {
			force->changeEnabled();
		}
		break;
	case '2':
		for (auto planet : ePlanets) {
			if(!planet->hasPlanetExploded())
				planet->Explode();
		}
		break;
	case '3':
		forces = ForceManager::Instance()->getGeneratorGroup(ForceManager::PLANET_RING);
		for (auto force : forces) {
			force->changeEnabled();
		}
		break;
	case '4':
		mAlien->Die();
		break;
	case '5':
		mStar->Supernova();
		break;
	default:
		break;
	}

	mSpaceship->keyPress(key, camera);
}

void 
GameScene::loadScene() {

	ForceManager::Init(this);

	mSpaceship = new Spaceship(addSolid(false, 0.5, 0.5, 0.8, {5, 5, 10}, 0.9, {0, 0, 0}, {0, 0.3, 0.62, 1}), this);
	mCannon = new Cannon({ 0, 0, 0 }, { 100, 0, 0 }, { 0, 0, 0 }, 5, 0.9, Particle::SI_EULER, 0.1, { 1, 0, 0, 1 });
	mNebula = new Nebula({ 400, 0, 400 });
	mComet = new Comet(addSolid(false, 0.5, 0.2, 0.3, { 5, 5, 5 }, 0.9, { 1500, 0, 0 }, { 0.2, 0.1, 0, 1 }), {0, 0, 0}, 1600);
	mAlien = new AlienLifeForm({ 0, 0, 50 }, { -10, 0, 0 }, { 15, 15, 15 }, this, 30);
	mStar = new Star({ -2000, 0, 2000 }, 1000);

	mCannon->SetSimulatedVel(250);

	// Create the planets
	planets.push_back(new Planet(addSolid(false, 0.5, 0.5, 0.8, 100, 0.9, { 1200, 0, 500 }, { 1, 0, 1, 1 }), 150));
	planets.push_back(new Planet(addSolid(false, 0.3, 0.3, 0.6, 100, 0.8, { 0, 200, 500 }, { 1, 0.5, 0.5, 1 }), 150));
	planets.push_back(new Planet(addSolid(false, 0.2, 0.2, 0.8, 100, 0.5, { -800, -400, 0 }, { 1, 0.7, 0.7, 1 }), 150));
	planets.push_back(new Planet(addSolid(false, 0.9, 0.9, 0.2, 100, 0.3, { -300, 0, -500 }, { 1, 1, 1, 1 }), 150));;
	planets.push_back(new RingedPlanet(this, addSolid(false, 0.5, 0.5, 0.9, 100, 0.9, { 500, 0, 200 }, { 0, 0, 0, 1 }), 150));
	planets.push_back(new WaterPlanet(addSolid(false, 0.5, 0.5, 0.9, 50, 0.9, { 600, 0, -600 }, { 1, 1, 1, 1 }), 150));

	// Create aside the Exploding planets
	auto exp = new ExplodingPlanet(addSolid(false, 0.5, 0.5, 0.8, 100, 0.9, { 300, 0, 700 }, { 1, 0, 0, 1 }), 150, 100, this);
	planets.push_back(exp);
	ePlanets.push_back(exp);

	// Register Spaceship's components
	ForceManager::Instance()->RegisterSolid(mSpaceship, ForceManager::SPACESHIP);
	ForceManager::Instance()->RegisterSolidCannon(mSpaceship->getCannon(), ForceManager::SPACESHIP);
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

	delete mComet;
	mComet = nullptr;

	delete mAlien;
	mAlien = nullptr;

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

void 
GameScene::onCollision(physx::PxActor* actor1, physx::PxActor* actor2) {

	auto data1 = reinterpret_cast<SpaceObjectData*>(actor1->userData);
	auto data2 = reinterpret_cast<SpaceObjectData*>(actor2->userData);

	// if bullet hits planet, planet kabooms
	if ((data1->type == SpaceObjectType::BULLET || data1->type == SpaceObjectType::EXPLODING_PLANET) &&
		(data2->type == SpaceObjectType::BULLET || data2->type == SpaceObjectType::EXPLODING_PLANET))
	{
		auto explodingPlanet = data1->type == SpaceObjectType::EXPLODING_PLANET ? data1->object : data2->object;
		static_cast<ExplodingPlanet*>(explodingPlanet)->Explode();
	}
}

