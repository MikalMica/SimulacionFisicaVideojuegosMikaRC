#include "WaterPlanet.h"
#include "ForceManager.h"
#include "FloatingPlanetForceGenerator.h"

void
WaterPlanet::init() {
	ForceManager::Instance()->AddForceGenerator(new FloatingPlanetForceGenerator(waterRadius, 7.5, 1, 1000, getPosition()), ForceManager::LIQUID);
	ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(5 * pow(10, 14), getPosition(), waterRadius + 100), ForceManager::PLANET_GRAVITY);

}