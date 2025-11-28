#pragma once
#include "Solid.h"

class DynamicSolid : public Solid
{

	PxRigidDynamic* dBody = nullptr;

public:

	DynamicSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density)
	: Solid(actor, boxSize, material){

		dBody = static_cast<PxRigidDynamic*>(actor);

		PxRigidBodyExt::updateMassAndInertia(*dBody, density);
	}
};

