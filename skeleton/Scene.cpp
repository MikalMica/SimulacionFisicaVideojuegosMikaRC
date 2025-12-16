#include "Scene.h"
#include "DynamicSolid.h"
#include "StaticSolid.h"

Solid*
Scene::addSolid(bool isStatic, float sFriction, float dFriction, float resti, Vector3 const& boxSize, float density, Vector3 const& pos, Vector4 const& colour, double lifeTime) {

	PxRigidActor* actor = nullptr;
	PxTransform tf = PxTransform(pos);

	auto material = gPhysics->createMaterial(sFriction, dFriction, resti);
	Solid* rigid = nullptr;

	if (isStatic) {
		actor = gPhysics->createRigidStatic(tf);
		rigid = new StaticSolid(actor, boxSize, material, density, colour);
	}
	else {
		actor = gPhysics->createRigidDynamic(tf);
		rigid = new DynamicSolid(actor, boxSize, material, density, pos, colour, lifeTime);
	}

	gScene->addActor(*actor);

	return rigid;
}

Solid*
Scene::addSolid(bool isStatic, float sFriction, float dFriction, float resti, float radius, float density, Vector3 const& pos, Vector4 const& colour) {

	PxRigidActor* actor = nullptr;
	PxTransform tf = PxTransform(pos);

	auto material = gPhysics->createMaterial(sFriction, dFriction, resti);
	Solid* rigid = nullptr;

	if (isStatic) {
		actor = gPhysics->createRigidStatic(tf);
		rigid = new StaticSolid(actor, radius, material, density, colour);
	}
	else {
		actor = gPhysics->createRigidDynamic(tf);
		rigid = new DynamicSolid(actor, radius, material, density, pos, colour);
	}

	gScene->addActor(*actor);

	return rigid;
}

void
Scene::removeSolid(Solid* solid) {

	PxActor* actor = solid->getActor();

	gScene->removeActor(*actor);
}