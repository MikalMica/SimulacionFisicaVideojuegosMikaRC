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
ForceManager::RegisterPSystem(ParticleSystem* sys) {

	for (auto force : forces) {
		sys->applyForceGenerator(force.first);
	}

	systems.push_back(sys);
}

void 
ForceManager::RegisterCannon(Cannon* can) {
	
	for (auto force : forces) {
		can->applyForceGenerator(force.first);
	}
	
	cannons.push_back(can); 
}

void 
ForceManager::Update(double t) {

	for (auto force : forces) {

		int size = particles.size();
		for (int i = 0; i < size; ++i) {
			auto p = particles.front();
			particles.pop();

			if (p->hasToDie()) {
				delete p;
				p = nullptr;
			}
			else {
				if (force.first->checkCondition(p))
					p->addForce(force.first->forceToApply(p));
				particles.push(p);
			}
		}

		force.first->Update(t);
	}
}

std::vector<ForceGenerator*> 
ForceManager::getGeneratorGroup(FORCE_GRP group) {
	std::vector<ForceGenerator*> aux;

	for (auto force : forces) {
		if (force.second == group) aux.push_back(force.first);
	}

	return aux;
}

bool
ForceManager::init() {
	return true;
}

bool
ForceManager::DeleteForceGenerator(std::pair<ForceGenerator*, int> gen) {

	auto it = std::find(forces.begin(), forces.end(), gen);

	if (it == forces.end()) return false;
		
	auto aux = *it;

	for (auto pSys : systems) {
		pSys->deregisterForceGenerator(aux.first);
	}

	for (auto cannon : cannons) {
		cannon->deleteForceGenerator(aux.first);
	}

	forces.erase(it);
		
	delete aux.first;
	aux.first = nullptr;

	return true;
}
