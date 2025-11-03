#include "ForceManager.h"

int 
ForceManager::AddForceGenerator(ForceGenerator* gen, FORCE_GRP group) {

	forces.push_back({ gen, group });

	for (auto cannon : cannons) {
		cannon->applyForceGenerator(gen);
	}

	for (auto system : systems) {
		system->applyForceGenerator(gen);
	}

	return forces.size() - 1;
}

void 
ForceManager::Update(double t) {

	for (auto force : forces) {
		for (auto p : particles) {
			if (force.first->checkCondition(p))
				force.first->forceToApply(p);
		}

		force.first->Update(t);
	}
}

ForceManager* 
ForceManager::getSingleton() {

	if (singleton == nullptr)
		singleton = new ForceManager();
	
	return singleton;
}

std::vector<ForceGenerator*> 
ForceManager::getGeneratorGroup(FORCE_GRP group) {
	std::vector<ForceGenerator*> aux;

	for (auto force : forces) {
		if (force.second == group) aux.push_back(force.first);
	}

	return aux;
}
