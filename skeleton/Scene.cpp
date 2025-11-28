#include "Scene.h"
#include "DynamicSolid.h"
#include "StaticSolid.h"

void 
Scene::addSolid(bool isStatic, float sFriction, float dFriction, float resti, Vector3 const& boxSize, float density, Vector3 const& pos) {

	PxRigidActor* actor = nullptr;
	PxTransform tf = PxTransform(pos);

	auto material = gPhysics->createMaterial(sFriction, dFriction, resti);
	StaticSolid* sRigid = nullptr;
	DynamicSolid* dRigid = nullptr;

	if (isStatic) {
		actor = gPhysics->createRigidStatic(tf);
		sRigid = new StaticSolid(actor, boxSize, material, density);
	}
	else {
		actor = gPhysics->createRigidDynamic(tf);
		dRigid = new DynamicSolid(actor, boxSize, material, density);
	}

	// Hacer cosas con el solido rigido creado (como cargarmelo y eso)

	gScene->addActor(*actor);
}
