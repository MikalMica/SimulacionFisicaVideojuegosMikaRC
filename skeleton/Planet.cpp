#include "Planet.h"
#include "ForceManager.h"
#include "RealGravityForceGenerator.h"

void 
Planet::keyPress(unsigned char key, const PxTransform& camera) {

	if (key == '1') {
		auto aux = ForceManager::getSingleton()->getGeneratorGroup(ForceManager::PLANET_GRAVITY);
		for (auto force : aux) {
			force->changeEnabled();
		}
	}
}

void 
Planet::init() {

	ForceManager::getSingleton()->AddForceGenerator(new RealGravityForceGenerator(getMass(), getPosition(), radius + 20), ForceManager::PLANET_GRAVITY);
}