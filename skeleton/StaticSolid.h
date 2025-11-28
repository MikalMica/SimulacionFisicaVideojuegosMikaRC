#pragma once
#include "Solid.h"

class StaticSolid : public Solid
{

	PxRigidStatic* sBody = nullptr;
public:

	StaticSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density)
		: Solid(actor, boxSize, material)
	{
		sBody = static_cast<PxRigidStatic*>(actor);
	}


};

