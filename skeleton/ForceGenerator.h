#pragma once

#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

class Particle;

using namespace physx;

class ForceGenerator
{
protected:
	Vector3 force;
public:
	ForceGenerator(Vector3 f) : force(f) {}

	virtual bool checkCondition(Particle* p) { return true; }
	virtual inline Vector3 forceToApply(Particle* p) { return force; }
};