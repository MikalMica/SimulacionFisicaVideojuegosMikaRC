#include "ExplodingPlanet.h"
#include "ForceManager.h"
#include "GaussianGen.h"
#include "Scene.h"
#include <random>

void 
ExplodingPlanet::Explode() {

	//item->release();
	//auto geom = PxSphereGeometry(0.01);
	//auto shape = CreateShape(geom);
	//item = new RenderItem(shape, pos, colour);

	mScene->removeSolid(this);

	ForceManager::Instance()->DeleteForceGenerator(ForceManager::Instance()->getGeneratorAt(gIndex));

	ForceManager::Instance()->AddForceGenerator(new ExplosionForceGenerator(radius, _K, 2, dBody->getGlobalPose().p), ForceManager::PLANET_EXPLOSION);
	GaussianGen* gen = new GaussianGen(dBody->getGlobalPose().p, { 0, 0, 0 }, 5, radius + 100, 0.6, 0.9, Particle::SI_EULER, 500, 2, 50, 0.5, { 0, 0, 0 }, { 50, 50, 50 }, { 1, 0.5, 0, 1 });
	explosion = new ParticleSystem(1500);

	explosion->addGen(gen);
	explosion->Update(0.2);
	explosion->ChangeParticleGeneration();
	
	ForceManager::Instance()->RegisterPSystem(explosion, ForceManager::EXPLOSION_PARTS);
}

void 
ExplodingPlanet::init() {
	gIndex = ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(getMass(), getPosition(), radius + 50), ForceManager::PLANET_GRAVITY);
}

void 
ExplodingPlanet::Update(double t) {

	if (explosion != nullptr) {
		explosion->Update(t);

		destroyTimer += t;

		if (destroyTimer >= 7) {
			dead = true;
		}
	}
}
