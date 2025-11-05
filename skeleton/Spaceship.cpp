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

	mPSys->setCurrPosition(pos->p - Vector3(sizeZ * std::sin(angle), 0, sizeZ * std::cos(angle)));
	mCannon->setPosition(pos->p + Vector3(sizeZ * std::sin(angle), 0, sizeZ * std::cos(angle)));

	GetCamera()->setPosition(
		pos->p - Vector3(
			sizeZ * std::sin(angle) + zOffset * std::sin(angle), 
			-yOffset, 
			sizeZ * std::cos(angle) + zOffset * std::cos(angle)));

	GetCamera()->setDirection(pos->p - GetCamera()->getTransform().p + Vector3(0, 30, 0));

	mCannon->Update(t);

	propulsionTimer += t;
}

void 
Spaceship::keyPress(unsigned char key, const PxTransform& camera) {

	switch (key) {
	case 'j':
		addForce(Vector3(pos->q.rotate({ 0, 0, propulsionSpeed })));
		showPropulsion = true;
		propulsionTimer = 0;
		break;
	case 'h':
		angle += pi / 2 * 0.2;
		if (angle >= 2 * pi) angle = 0.0;
		pos->q = PxQuat(angle, {0, 1, 0});
		mCannon->setVel(pos->q);
		mPSys->setCurrVelocity(pos->q.rotate(oVel));
		GetCamera()->getTransform().q = pos->q;
		break;
	case 'k':
		angle -= pi / 2 * 0.2;
		if (angle <= 0.0) angle = 2 * pi;
		pos->q = PxQuat(angle, { 0, 1, 0 });
		mCannon->setVel(pos->q);
		mPSys->setCurrVelocity(pos->q.rotate(oVel));
		GetCamera()->getTransform().q = pos->q;
		break;
	case 'z':
		mCannon->Shoot();
		break;
	default:
		break;
	}
}
