#include "SolidCannon.h"
#include "Scene.h"
#include <iostream>

void
SolidCannon::Update(double t) {
	int size = bullets.size();

	for (int i = 0; i < size; ++i) {
		auto aux = bullets.front();
		bullets.pop();

		if (aux->hasToDie()) {
			delete aux;
			aux = nullptr;
		}
		else {
			aux->clearForce();
			aux->Update(t);
			for (auto force : forces) {
				if (force->checkCondition(aux))
					aux->addForce(force->forceToApply(aux));
			}
			bullets.push(aux);
		}
	}
}

void
SolidCannon::Shoot() {
	if (bullets.size() >= MAX_BULLETS) return;
	auto solid = static_cast<DynamicSolid*>(mScene->addSolid(false, staticFriction, dynamicFriction, restituition, radius, density, initPos, colour, lifeTime, mType));
	solid->setVel(velocity);
	bullets.push(solid);
}

void
SolidCannon::applyForceGenerator(ForceGenerator* force) {

	forces.push_back(force);
}

void
SolidCannon::deleteForceGenerator(ForceGenerator* force) {

	auto it = std::find(forces.begin(), forces.end(), force);

	if (it == forces.end()) return;

	forces.erase(it);

	return;
}
