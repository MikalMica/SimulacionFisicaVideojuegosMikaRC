#include "ForceManager.h"

int 
ForceManager::AddForceGenerator(ForceGenerator* gen, FORCE_GRP group) {

	forces.push_back({ gen, group });

	for (auto cannon : cannons) {
		if (collides[cannon.second][group])
			cannon.first->applyForceGenerator(gen);
	}

	for (auto system : systems) {
		if (collides[system.second][group])
			system.first->applyForceGenerator(gen);
	}

	return forces.size() - 1;
}

void 
ForceManager::RegisterPSystem(ParticleSystem* sys, INTER_GRP grp) {

	for (auto force : forces) {
		if(collides[grp][force.second])
			sys->applyForceGenerator(force.first);
	}

	systems.push_back({ sys, grp });
}

void 
ForceManager::RegisterCannon(Cannon* can, INTER_GRP grp) {
	
	for (auto force : forces) {
		if(collides[grp][force.second])
			can->applyForceGenerator(force.first);
	}
	
	cannons.push_back({ can, grp });
}

void 
ForceManager::Update(double t) {

	for (auto force : forces) {

		int size = particles.size();
		for (int i = 0; i < size; ++i) {
			auto p = particles.front();
			particles.pop();

			if (p.first->hasToDie()) {
				delete p.first;
				p.first = nullptr;
			}
			else {
				if (collides[p.second][force.second] && force.first->checkCondition(p.first))
					p.first->addForce(force.first->forceToApply(p.first));
				p.first->Integrate(t);
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
		if (collides[pSys.second][gen.second])
			pSys.first->deregisterForceGenerator(aux.first);
	}

	for (auto cannon : cannons) {
		if (collides[cannon.second][gen.second])
			cannon.first->deleteForceGenerator(aux.first);
	}

	forces.erase(it);
		
	delete aux.first;
	aux.first = nullptr;

	return true;
}
