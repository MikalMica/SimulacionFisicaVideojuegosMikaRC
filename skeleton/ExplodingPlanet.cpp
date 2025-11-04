#include "ExplodingPlanet.h"
#include "ForceManager.h"

void 
ExplodingPlanet::Explode() {

	DeregisterRenderItem(item);
	ForceManager::Instance()->DeleteForceGenerator(ForceManager::Instance()->getGeneratorAt(gIndex));

	ForceManager::Instance()->AddForceGenerator(new ExplosionForceGenerator(radius, _K, 2, pos->p), ForceManager::PLANET_EXPLOSION);
	// Start Updating the particle system
}

void 
ExplodingPlanet::init() {
	gIndex = ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(getMass(), getPosition(), radius + 50), ForceManager::PLANET_GRAVITY);
}
