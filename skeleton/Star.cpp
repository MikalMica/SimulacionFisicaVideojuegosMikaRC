#include "Star.h"
#include "ExplosionForceGenerator.h"
#include "BlackHole.h"

void 
Star::Supernova() {

	item->release();

	ForceManager::Instance()->DeleteForceGenerator({gForce, ForceManager::GRAVITY});

	ForceManager::Instance()->AddForceGenerator(new ExplosionForceGenerator(radius, 100, 4, getPosition()), ForceManager::EXPLOSION);
	GaussianGen* gen = new GaussianGen(getPosition(), {0, 0, 0}, -1, radius + 500, 0.6, 0.9, Particle::SI_EULER, 10000, 2, 50, 0.5, {100, 100, 100}, {0, 0, 0}, {0.4, 0.4, 1, 1});
	explosion = new ParticleSystem(1000000);

	explosion->addGen(gen);
	explosion->Update(0.2);
	explosion->ChangeParticleGeneration();

	ForceManager::Instance()->RegisterPSystem(explosion, ForceManager::EXPLOSION_PARTS);

	blackHoleTimer = 0;

}

void
Star::Update(double t) {

	if (explosion != nullptr) {
		explosion->Update(t);
	}

	if (blackHoleTimer >= 0 && !blackHoled) {
		blackHoleTimer += t;

		if (blackHoleTimer >= 5 && !initFlag) {
			ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(5.97 * pow(10, 15), getPosition(), radius + 250), ForceManager::GRAVITY);
			initFlag = true;
		}
		if (blackHoleTimer >= 10) {
			new BlackHole(getPosition());
			blackHoled = true;
		}
	}
}