#include "AlienLifeForm.h"
#include "ExplosionForceGenerator.h"

void 
AlienLifeForm::Update(double t) {

	for (int i = 0; i < fleshModules.size(); ++i) {
		fleshModules[i]->addForce(Vector3(var.x * d(mt), var.y * d(mt), var.z * d(mt)));
	}

	if(heart != nullptr) heart->addForce(velocity);
}

AlienLifeForm::~AlienLifeForm() {

	if (heart != nullptr) {
		delete heart;
		heart = nullptr;
	}

	for (auto flesh : fleshModules) {
		delete flesh;
		flesh = nullptr;
	}
}


void 
AlienLifeForm::Die() {

	for (auto force : springForces) {
		ForceManager::Instance()->DeleteForceGenerator({ force, ForceManager::SPRING });
		force = nullptr;
	}

	ForceManager::Instance()->AddForceGenerator(new ExplosionForceGenerator(10, 5, 3, heart->getPosition()), ForceManager::EXPLOSION);

	heart->setDead();
	heart = nullptr;
}