#include "Spaceship.h"
#include <math.h>

const float pi = 3.141592653589793f;

void 
Spaceship::Update(double t) {

	Particle::Integrate(t);

	if (showPropulsion) mPSys->Update(t);

	if (propulsionTimer >= propulsionTime && showPropulsion) {

		showPropulsion = false;
		mPSys->DestroyAllParticles();
	}

	mPSys->setCurrPosition(pos->p - Vector3(0, 0, sizeZ));
	mCannon->setPosition(pos->p + Vector3(0, 0, sizeZ));

	mCannon->Update(t);

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
		pos->q += PxQuat(pi / 20.0f, {0, 0, 0});
		if (pos->q.w > 1) pos->q.w -= 1;
		// gestionar y para que no se cague
		break;
	case 'k':
		pos->q += PxQuat(-pi / 20.0f, Vector3(0, 1, 0));
		break;
	case 'z':
		mCannon->Shoot();
		break;
	default:
		break;
	}
}
