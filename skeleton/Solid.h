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

	RenderItem* item = nullptr;

protected:
	bool dead = false;

	Solid(PxRigidActor* actor, Vector3 const& boxSize, PxMaterial* material)
	{
		auto geo = PxBoxGeometry(boxSize.x, boxSize.y, boxSize.z);
		auto shape = CreateShape(geo, material);
		actor->attachShape(*shape);

		item = new RenderItem(shape, actor, { 0.4, 0.1, 0.9, 1 });
	}

public:

	~Solid() { item->release(); }

	void Update(double t) {}
	bool hasToDie() { return dead; }
	virtual Vector3 getPosition() = 0;
	virtual PxActor* getActor() = 0;
};

