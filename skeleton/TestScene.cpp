#include "TestScene.h"
#include "ParticleSystem.h"
#include "FloatingForceGenerator.h"
#include "GravityForceGenerator.h"
#include "Sea.h"
#include <iostream>

void 
TestScene::Update(double t) {
	ForceManager::Instance()->Update(t);
}

void
TestScene::keyPress(unsigned char key, const PxTransform& camera) {

	switch (toupper(key))
	{
	case '1':
		pTest->addForce({ 0, -5, 0 });
		break;
	case '2':
		pTest->setMass(1);
		//static_cast<SpringForceGenerator*>(ForceManager::Instance()->getGeneratorAt(springIndex).first)->setK(1);
		break;
	case '3':
		pTest->setMass(15);
		//static_cast<SpringForceGenerator*>(ForceManager::Instance()->getGeneratorAt(springIndex).first)->setK(5);
		break;
	case '4':
		pTest->setMass(100);
		//static_cast<SpringForceGenerator*>(ForceManager::Instance()->getGeneratorAt(springIndex).first)->setK(10);
		break;
	default:
		break;
	}
}

void 
TestScene::loadScene() {
	ForceManager::Init();
	sea = new Sea({ 0, -10, 0 });
	ForceManager::Instance()->AddForceGenerator(new FloatingForceGenerator(-10, 2, 10, 10), ForceManager::LIQUID);
	ForceManager::Instance()->AddForceGenerator(new GravityForceGenerator(), ForceManager::LIQUID);

	pTest = new Particle({ 0, -5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 0.9, 20, Particle::SI_EULER, { 1, 0, 0, 1 });
	/*pTest2 = new Particle({0, 0, 0}, {0, 0, 0}, {0, 0, 0}, -1, 0.9, 0.5, Particle::SI_EULER, {1, 0, 0, 1});
	springIndex = ForceManager::Instance()->AddForceGenerator(new ElasticRopeForceGenerator(10, 5, pTest, pTest2), ForceManager::SPRING);*/
	ForceManager::Instance()->RegisterParticle(pTest, ForceManager::TORNADO_PARTS);
	/*ForceManager::Instance()->RegisterParticle(pTest2, ForceManager::TORNADO_PARTS); */
}

void 
TestScene::unloadScene() {
	delete pTest; pTest = nullptr;
	/*delete pTest2; pTest2 = nullptr; */
}