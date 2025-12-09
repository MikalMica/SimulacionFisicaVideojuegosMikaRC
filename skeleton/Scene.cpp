#include "Scene.h"
#include "DynamicSolid.h"
#include "StaticSolid.h"

Solid*
Scene::addSolid(bool isStatic, float sFriction, float dFriction, float resti, Vector3 const& boxSize, float density, Vector3 const& pos) {

	PxRigidActor* actor = nullptr;
	PxTransform tf = PxTransform(pos);

	auto material = gPhysics->createMaterial(sFriction, dFriction, resti);
	Solid* rigid = nullptr;

	if (isStatic) {
		actor = gPhysics->createRigidStatic(tf);
		rigid = new StaticSolid(actor, boxSize, material, density);
	}
	else {
		actor = gPhysics->createRigidDynamic(tf);
		rigid = new DynamicSolid(actor, boxSize, material, density, pos);
	}

	gScene->addActor(*actor);

	return rigid;
}

void
Scene::removeSolid(Solid* solid) {

	PxActor* actor = solid->getActor();

	gScene->removeActor(*actor);
}