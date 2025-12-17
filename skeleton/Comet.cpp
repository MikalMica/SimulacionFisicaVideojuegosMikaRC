#include "Comet.h"

void
Comet::Update(double t) {
	DynamicSolid::clearForceAndVelocity();
	DynamicSolid::Update(t);
	trail->Update(t);
	trail->setCurrPosition(getPosition());
}