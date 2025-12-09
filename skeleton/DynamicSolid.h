#pragma once
#include "Solid.h"

class DynamicSolid : public Solid
{

	PxRigidDynamic* dBody = nullptr;
	Vector3 originalPos;

public:

	DynamicSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density, Vector3 pos)
	: Solid(actor, boxSize, material)
	, originalPos(pos)
	{

		dBody = static_cast<PxRigidDynamic*>(actor);

		PxRigidBodyExt::updateMassAndInertia(*dBody, density);
	}

	inline void addForce(Vector3 const& force) { dBody->addForce(force);}

	inline bool isFarFromOrigin(double distance) { if (((dBody->getGlobalPose().p - originalPos).magnitude() > distance)) { dead = true; return dead; } return false; }

	void setVel(Vector3 const& vel) { dBody->setLinearVelocity(vel); }
	Vector3 getVel() { return dBody->getLinearVelocity(); }

	float getMass() { return dBody->getMass(); }

	PxActor* getActor() override { return dBody; }
	Vector3 getPosition() override { return dBody->getGlobalPose().p; }

};

