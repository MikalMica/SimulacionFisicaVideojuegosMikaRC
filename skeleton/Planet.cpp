#include "Planet.h"

void
Planet::Update(double t) {

	if (gravity->getEnabled()) gravity->Update(t);
}

void 
Planet::keyPress(unsigned char key, const PxTransform& camera) {

	switch (key) {
	case '1':
		gravity->changeEnabled();
		break;
	default:
		break;
	}
}
