#include "RingedPlanet.h"
#include "ForceManager.h"
#include "GaussianGen.h"
#include "TornadoForceGenerator.h"
#include <iostream>


void 
RingedPlanet::Update(double t) {
	ring->Update(t);
}

void 
RingedPlanet::init() {
	GaussianGen* gen = new GaussianGen({ dBody->getGlobalPose().p.x, dBody->getGlobalPose().p.y, dBody->getGlobalPose().p.z + radius }, { 0, 0, 0 }, 8, 275, 0.6, 0.9, Particle::SI_EULER, 20, 2, 50, 0.1, { 30, 10, 10 }, { 10, 0, 0 }, { 0, 0.5, 1, 0 });
	ring = new ParticleSystem(1000);
	ring->addGen(gen);

	ForceManager::Instance()->RegisterPSystem(ring, ForceManager::TORNADO_PARTS);
	ForceManager::Instance()->AddForceGenerator(new TornadoForceGenerator({ 0, 1, 0 }, dBody->getGlobalPose().p, 5, forceRadius), ForceManager::PLANET_RING);
}