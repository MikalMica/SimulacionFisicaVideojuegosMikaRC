#pragma once

#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

class Particle;
class DynamicSolid;
class StaticSolid;

using namespace physx;

class ForceGenerator
{
protected:
	Vector3 force;
	bool enabled;
public:
	ForceGenerator(Vector3 f) : force(f), enabled(true) {}

	virtual bool checkCondition(Particle* p) { return enabled; }
	virtual bool checkCondition(DynamicSolid* s) { return enabled; }
	virtual inline Vector3 forceToApply(Particle* p) { return force; }
	virtual inline Vector3 forceToApply(DynamicSolid* s) { return force; }
	virtual inline Vector3 forceToApply(StaticSolid* s) { return force; }
	virtual inline void Update(double t) {}
	inline bool getEnabled() { return enabled; }
	inline void changeEnabled() { enabled = !enabled; }
};