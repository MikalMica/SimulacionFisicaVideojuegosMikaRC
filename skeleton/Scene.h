#pragma once
#include <PxPhysicsAPI.h>

using namespace physx;

class Scene
{
public:

	Scene() {}

	virtual void Update(double t) {}
	virtual void keyPress(unsigned char key, const PxTransform& camera) {}

	virtual void loadScene() = 0;
	virtual void unloadScene() = 0;
};

