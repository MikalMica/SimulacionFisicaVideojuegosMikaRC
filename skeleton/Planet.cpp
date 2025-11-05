#include "Planet.h"
#include "ForceManager.h"
#include "RealGravityForceGenerator.h"

void 
Planet::keyPress(unsigned char key, const PxTransform& camera) {
	
}

void 
Planet::init() {

	ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(getMass(), getPosition(), radius + 50), ForceManager::PLANET_GRAVITY);
}

void
Planet::Update(double t) {
	// gira
}
