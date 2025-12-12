#pragma once
#include "Solid.h"

class StaticSolid : public Solid
{

	PxRigidStatic* sBody = nullptr;
public:

	StaticSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density, Vector4 const& colour)
		: Solid(actor, boxSize, material, colour)
	{
		sBody = static_cast<PxRigidStatic*>(actor);
	}

	StaticSolid(PxRigidActor* actor, float radius, PxMaterial* material, float density, Vector4 const& colour)
		: Solid(actor, radius, material, colour)
	{
		sBody = static_cast<PxRigidStatic*>(actor);
	}

	PxActor* getActor() override { return sBody; }
	Vector3 getPosition() override { return sBody->getGlobalPose().p; }


};

