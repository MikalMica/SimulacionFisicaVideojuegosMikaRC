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
	PxRigidActor* mBody = nullptr;

public:
	Solid(PxRigidActor* body, Vector3 const& boxSize, PxMaterial* material, float density)
		: mBody(body)
	{
		auto geo = PxBoxGeometry(boxSize.x, boxSize.y, boxSize.z);
		auto shape = CreateShape(geo, material);
		body->attachShape(*shape);

		// Arreglarlo para hacer todo lo posible antes de tener q cargar otra cosa
	}
	~Solid() { item->release(); mBody = nullptr; }

	//PxRigidBody* getBody() { return mBody; }
};

