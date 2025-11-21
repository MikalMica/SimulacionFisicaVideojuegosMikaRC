#pragma once
#include <PxPhysicsAPI.h>
#include "core.hpp"


using namespace physx;

class Scene
{
	PxPhysics* gPhysics;
	PxScene* gScene;
public:

	Scene(PxPhysics* gPh, PxScene* sc)
	: gPhysics(gPh)
	, gScene(sc)
	{}

	virtual void Update(double t) {}
	virtual void keyPress(unsigned char key, const PxTransform& camera) {}

	virtual void loadScene() = 0;
	virtual void unloadScene() = 0;

	void addSolid(bool isStatic, float sFriction, float dFriction, float resti, Vector3 const& boxSize, float density, Vector3 const& pos);
};

