#include "TorqueForceGenerator.h"
#include "DynamicSolid.h"

Vector3
TorqueForceGenerator::forceToApply(DynamicSolid* s) {

	s->addTorque(mTorque);

	return { 0, 0, 0 };
}