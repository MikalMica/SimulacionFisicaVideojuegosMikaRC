#include "Spaceship.h"
#include <math.h>

const float pi = 3.141592653589793f;

void 
Spaceship::Update(double t) {

	if (showPropulsion) {
		mPSys->Update(t);
	}

	if (propulsionTimer >= propulsionTime && showPropulsion) {

		showPropulsion = false;
		mPSys->DestroyAllParticles();
	}

	mPSys->setCurrPosition(getPosition() - Vector3(sizeZ * std::sin(hAngle), 0, sizeZ * std::cos(hAngle)));
	mCannon->setPosition(getPosition() + Vector3(sizeZ * std::sin(hAngle),0 , sizeZ * std::cos(hAngle)));

	GetCamera()->setPosition(
		getPosition() - Vector3(
			sizeZ * std::sin(hAngle) + zOffset * std::sin(hAngle), 
			-yOffset, 
			sizeZ * std::cos(hAngle) + zOffset * std::cos(hAngle)));

	GetCamera()->setDirection(getPosition() - GetCamera()->getTransform().p + Vector3(0, 30, 0));

	mCannon->Update(t);

	propulsionTimer += t;
}

void 
Spaceship::keyPress(unsigned char key, const PxTransform& camera) {

	switch (key) {
	case 'j':
		addForce(Vector3(getRotation().rotate({ 0, 0, propulsionSpeed })));
		showPropulsion = true;
		propulsionTimer = 0;
		break;
	case 'h':
		clearForceAndVelocity();
		hAngle += pi / 2 * 0.2;
		if (hAngle >= 2 * pi) hAngle = 0.0;
		setRotation(PxQuat(hAngle, {0, 1, 0}));
		mCannon->setVel(getRotation());
		mPSys->setCurrVelocity(getRotation().rotate(oVel));
		GetCamera()->getTransform().q = getRotation();
		break;
	case 'k':
		clearForceAndVelocity();
		hAngle -= pi / 2 * 0.2;
		if (hAngle <= 0.0) hAngle = 2 * pi;
		setRotation(PxQuat(hAngle, { 0, 1, 0 }));
		mCannon->setVel(getRotation());
		mPSys->setCurrVelocity(getRotation().rotate(oVel));
		GetCamera()->getTransform().q = getRotation();
		break;
	case 'z':
		mCannon->Shoot();
		break;
	default:
		break;
	}
}
