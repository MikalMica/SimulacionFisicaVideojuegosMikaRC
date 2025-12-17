#pragma once
#include "Solid.h"
#include "SpaceObjectData.h"

class StaticSolid : public Solid
{

	PxRigidStatic* sBody = nullptr;
public:

	StaticSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density, Vector4 const& colour, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: Solid(actor, boxSize, material, colour)
	{
		sBody = static_cast<PxRigidStatic*>(actor);

		auto data = new SpaceObjectData();
		data->type = type;
		data->object = this;
		sBody->userData = data;
	}

	StaticSolid(PxRigidActor* actor, float radius, PxMaterial* material, float density, Vector4 const& colour, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: Solid(actor, radius, material, colour)
	{
		sBody = static_cast<PxRigidStatic*>(actor);

		auto data = new SpaceObjectData();
		data->type = type;
		data->object = this;
		sBody->userData = data;
	}

	PxActor* getActor() override { return sBody; }
	Vector3 getPosition() override { return sBody->getGlobalPose().p; }
	PxQuat getRotation() override { return sBody->getGlobalPose().q; }
	void setRotation(PxQuat const& rot) override { sBody->setGlobalPose(PxTransform(getPosition(), rot)); }


};

