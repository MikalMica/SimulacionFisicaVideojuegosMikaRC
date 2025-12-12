#include "GaussianSolidGen.h"
#include "DynamicSolid.h"

std::vector<DynamicSolid*>
GaussianSolidGen::generateS() {
	std::vector<DynamicSolid*> solids;
	for (int i = 0; i < numSolids; ++i) {
		if (d(mt) >= probGen) continue;

		Vector3 pSource = { position.x + positionVar.x * d(mt), position.y + positionVar.y * d(mt), position.z + positionVar.z * d(mt) };
		Vector3 vSource = { linearVelocity.x + velocityVar.x * d(mt), linearVelocity.y + velocityVar.y * d(mt), linearVelocity.z + velocityVar.z * d(mt) };

		auto s = mScene->addSolid(false, staticFriction, dynamicFriction + dynamicFrictionVar * d(mt), restituition + restituitionVar * d(mt), 
								  rigidSize, density + densityVar * d(mt), pSource, colour);
		auto ds = static_cast<DynamicSolid*>(s);
		ds->setVel(vSource);
		solids.push_back(ds);
	}

	return solids;
}