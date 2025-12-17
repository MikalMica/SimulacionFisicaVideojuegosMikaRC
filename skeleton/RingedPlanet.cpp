#include "RingedPlanet.h"
#include "ForceManager.h"
#include "GaussianSolidGen.h"
#include "TornadoForceGenerator.h"
#include <iostream>


void 
RingedPlanet::Update(double t) {
	ring->Update(t);
}

void 
RingedPlanet::init() {
	GaussianSolidGen* gen = new GaussianSolidGen(scene, 0.5, 0.5, 0, 0.9, 0.2, { 1, 1, 1 }, 0.8, 0.2, { dBody->getGlobalPose().p.x, dBody->getGlobalPose().p.y, dBody->getGlobalPose().p.z + radius }, { 10, 0, 0 }, 10000, 0, { 0, 0, 0 }, { 30, 10, 10 }, 20, 0.8, {0, 0.5, 1, 1}, 10, 5, SpaceObjectType::ASTEROIDS_RING);
	ring = new SolidPSystem(scene, 1000);
	ring->addGen(gen);

	ForceManager::Instance()->RegisterSolidPSystem(ring, ForceManager::TORNADO_PARTS);
	ForceManager::Instance()->AddForceGenerator(new TornadoForceGenerator({ 0, 1, 0 }, dBody->getGlobalPose().p, 5, forceRadius), ForceManager::PLANET_RING);
}