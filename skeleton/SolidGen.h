#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <random>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Scene.h"

class SolidGen
{
	const Vector4 colour;
	Scene* mScene = nullptr;
	float staticFriction;
	float dynamicFriction;
	float restituition;
	Vector3 rigidSize;
	float density;
	Vector3 position;
	// Terminar esta cosa
public:

	SolidGen(Scene* scene, float sFriction, float dFriction, float resti, Vector3 const& boxSize, float den, Vector3 const& pos)
		: mScene(scene)
		, staticFriction(sFriction)
		, dynamicFriction(dFriction)
		, restituition(resti)
		, rigidSize(boxSize)
		, density(den)
		, position(pos)
	{}

};

