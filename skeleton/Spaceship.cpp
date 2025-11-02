#include "Spaceship.h"

void 
Spaceship::Update(double t) {

	force += forceToAdd;

	Particle::Integrate(t);

	if (showPropulsion) mPSys->Update(t);
	mPSys->setCurrPosition(pos->p - Vector3(0, 0, sizeZ));
}

void 
Spaceship::keyPress(unsigned char key, const PxTransform& camera) {

	switch (key) {
	case '1':
		forceToAdd = { 0, 0, propulsionSpeed };
		showPropulsion = true;
		break;
	case '0':
		forceToAdd = { 0, 0, 0 };
		showPropulsion = false;
		mPSys->DestroyAllParticles();
	default:
		break;
	}
}
