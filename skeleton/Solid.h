#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

using namespace physx;

class Solid
{
protected:

	RenderItem* item = nullptr;
	Vector4 colour;
	float radius;

protected:
	bool dead = false;

	Solid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material, Vector4 const& col)
		: colour(col)
		, radius(boxSize.z/2)
	{
		auto geo = PxBoxGeometry(boxSize.x, boxSize.y, boxSize.z);
		auto shape = CreateShape(geo, material);
		actor->attachShape(*shape);

		item = new RenderItem(shape, actor, colour);
	}

	Solid(PxRigidActor* actor, float r, PxMaterial* material, Vector4 const& col)
		:colour(col)
		, radius(r)
	{
		auto geo = PxSphereGeometry(radius);
		auto shape = CreateShape(geo, material);
		actor->attachShape(*shape);

		item = new RenderItem(shape, actor, colour);
	}

public:

	~Solid() { item->release(); }

	virtual void Update(double t) {}
	bool hasToDie() { return dead; }
	virtual Vector3 getPosition() = 0;
	virtual PxQuat getRotation() = 0;
	virtual void setRotation(PxQuat const& rot) = 0;
	virtual PxActor* getActor() = 0;
};

