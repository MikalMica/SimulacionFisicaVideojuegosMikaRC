#pragma once
#include <PxPhysicsAPI.h>
#include "core.hpp"

class Solid;

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

	Solid* addSolid(bool isStatic, float sFriction, float dFriction, float resti, Vector3 const& boxSize, float density, Vector3 const& pos, Vector4 const& colour, double lifeTime = -1);
	Solid* addSolid(bool isStatic, float sFriction, float dFriction, float resti, float radius, float density, Vector3 const& pos, Vector4 const& colour);
	void removeSolid(Solid* solid);
};

