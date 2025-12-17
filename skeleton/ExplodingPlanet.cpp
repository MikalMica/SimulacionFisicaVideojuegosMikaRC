#include "ExplodingPlanet.h"
#include "ForceManager.h"
#include "GaussianGen.h"
#include "Scene.h"
#include <random>

void 
ExplodingPlanet::_Explode() {

	item->release();

	mScene->removeSolid(this);

	ForceManager::Instance()->DeleteForceGenerator(ForceManager::Instance()->getGeneratorAt(gIndex));

	ForceManager::Instance()->AddForceGenerator(new ExplosionForceGenerator(radius, _K, 2, dBody->getGlobalPose().p), ForceManager::EXPLOSION);
	GaussianGen* gen = new GaussianGen(dBody->getGlobalPose().p, { 0, 0, 0 }, 5, radius + 100, 0.6, 0.9, Particle::SI_EULER, 500, 2, 50, 0.5, { 0, 0, 0 }, { 50, 50, 50 }, { 1, 0.5, 0, 1 });
	explosion = new ParticleSystem(1500);

	explosion->addGen(gen);
	explosion->Update(0.2);
	explosion->ChangeParticleGeneration();
	
	ForceManager::Instance()->RegisterPSystem(explosion, ForceManager::EXPLOSION_PARTS);
}

void 
ExplodingPlanet::init() {
	gIndex = ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(getMass(), getPosition(), forceRadius + 50), ForceManager::GRAVITY);
	ForceManager::Instance()->RegisterSolid(this, ForceManager::PLANET);
}

void 
ExplodingPlanet::Update(double t) {

	if (hasToExplode) {
		if (!hasExploded) {
			_Explode();
			hasExploded = true;
		}
	}

	if (explosion != nullptr) {
		explosion->Update(t);

		destroyTimer += t;

		if (destroyTimer >= 7) {
			dead = true;
		}
	}
}
