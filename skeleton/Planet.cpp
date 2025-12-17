#include "Planet.h"
#include "ForceManager.h"
#include "RealGravityForceGenerator.h"

void 
Planet::keyPress(unsigned char key, const PxTransform& camera) {
	
}

void 
Planet::init() {

	ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(5.97 * pow(10, 15), getPosition(), forceRadius + 50), ForceManager::GRAVITY);
	ForceManager::Instance()->RegisterSolid(this, ForceManager::PLANET);
}

void
Planet::Update(double t) {
	// gira
}
