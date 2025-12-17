#pragma once
#include "Solid.h"
#include "SpaceObjectData.h"

class DynamicSolid : public Solid
{
protected:

	PxRigidDynamic* dBody = nullptr;
	Vector3 originalPos;
	float timeToDie;
	float timer;

public:

	DynamicSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density, Vector3 const& pos, Vector4 const& colour, SpaceObjectType type = SpaceObjectType::DEFAULT)
	: Solid(actor, boxSize, material, colour)
	, originalPos(pos)
		,timeToDie(-1)
		, timer(0)
	{
		
		dBody = static_cast<PxRigidDynamic*>(actor);

		auto data = new SpaceObjectData();
		data->type = type;
		data->object = this;
		dBody->userData = data;

		PxRigidBodyExt::updateMassAndInertia(*dBody, density);
	}

	DynamicSolid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, float density, Vector3 const& pos, Vector4 const& colour, float time, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: Solid(actor, boxSize, material, colour)
		, originalPos(pos)
		, timeToDie(time)
		, timer(0)
	{

		dBody = static_cast<PxRigidDynamic*>(actor);
		
		auto data = new SpaceObjectData();
		data->type = type;
		data->object = this;
		dBody->userData = data;

		PxRigidBodyExt::updateMassAndInertia(*dBody, density);
	}

	DynamicSolid(PxRigidActor* actor, float radius, PxMaterial* material, float density, Vector3 pos, Vector4 const& colour, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: Solid(actor, radius, material, colour)
		, originalPos(pos)
		,timeToDie(-1)
		, timer(0)
	{

		dBody = static_cast<PxRigidDynamic*>(actor);
		
		auto data = new SpaceObjectData();
		data->type = type;
		data->object = this;
		dBody->userData = data;

		PxRigidBodyExt::updateMassAndInertia(*dBody, density);
	}

	DynamicSolid(PxRigidActor* actor, float radius, PxMaterial* material, float density, Vector3 pos, Vector4 const& colour, float time, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: Solid(actor, radius, material, colour)
		, originalPos(pos)
		, timeToDie(time)
		, timer(0)
	{

		dBody = static_cast<PxRigidDynamic*>(actor);

		auto data = new SpaceObjectData();
		data->type = type;
		data->object = this;
		dBody->userData = data;

		PxRigidBodyExt::updateMassAndInertia(*dBody, density);
	}

	inline void addForce(Vector3 const& force) { dBody->addForce(force);}
	inline void clearForceAndVelocity() { dBody->clearForce(); dBody->clearTorque(); dBody->setLinearVelocity({ 0, 0, 0 }); dBody->setAngularVelocity({ 0, 0, 0 }); }
	inline void clearForce() { dBody->clearForce(); dBody->clearTorque(); }
	inline void addTorque(Vector3 const& torque) { dBody->addTorque(torque); }

	inline bool isFarFromOrigin(double distance) { if (((dBody->getGlobalPose().p - originalPos).magnitude() > distance)) { dead = true; return dead; } return false; }

	void setVel(Vector3 const& vel) { dBody->setLinearVelocity(vel); }
	Vector3 getVel() { return dBody->getLinearVelocity(); }

	float getMass() { return dBody->getMass(); }

	PxActor* getActor() override { return dBody;}
	Vector3 getPosition() override { return dBody->getGlobalPose().p; }
	PxQuat getRotation() override { return dBody->getGlobalPose().q; }
	void setRotation(PxQuat const& rot) override { dBody->setGlobalPose(PxTransform(getPosition(), rot));}

	void Update(double t) override {
		
		if (timeToDie > -1) {
			timer += t;
			if (timer >= timeToDie) { dead = true; }
		}
	}
};

