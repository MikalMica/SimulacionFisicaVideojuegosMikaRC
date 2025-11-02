#include "Spaceship.h"

void 
Spaceship::Update(double t) {

	Particle::Integrate(t);

	if (showPropulsion) mPSys->Update(t);

	if (propulsionTimer >= propulsionTime && showPropulsion) {

		showPropulsion = false;
		mPSys->DestroyAllParticles();
	}

	mPSys->setCurrPosition(pos->p - Vector3(0, 0, sizeZ));

	propulsionTimer += t;
}

void 
Spaceship::keyPress(unsigned char key, const PxTransform& camera) {

	switch (key) {
	case 'j':
		addForce({ 0, 0, propulsionSpeed });
		showPropulsion = true;
		propulsionTimer = 0;
		break;
	case 'h':
		// rotate left
		break;
	case 'k':
		// rotate right
		break;
	default:
		break;
	}
}
