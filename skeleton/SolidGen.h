#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <random>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Scene.h"

class DynamicSolid;

class SolidGen
{
protected:
	const Vector4 colour;
	Scene* mScene = nullptr;
	float staticFriction;
	float dynamicFriction;
	float dynamicFrictionVar;
	float restituition;
	float restituitionVar;
	Vector3 rigidSize;
	float density;
	float densityVar;
	Vector3 position;
	Vector3 positionVar;
	double distance;
	double distanceVar;
	Vector3 linearVelocity;
	Vector3 velocityVar;
	int numSolids;
	double probGen;
	double lifeTime;
	double lifeTimeVar;
	
	std::mt19937 mt;
	std::uniform_real_distribution<double> u{ 0, 1 };

public:

	SolidGen(Scene* scene, float sFriction, float dFriction, float dFrictionVar, float resti, float restiVar, Vector3 const& boxSize, float den, float denVar, Vector3 const& pos, Vector3 const& posVar, 
		double dist, double distVar, Vector3 const& vel, Vector3 const& velVar, int nSolids, double probability, Vector4 const& col, double lTime, double lTimeVar)
		: mScene(scene)
		, staticFriction(sFriction)
		, dynamicFriction(dFriction)
		, dynamicFrictionVar(dFrictionVar)
		, restituition(resti)
		, restituitionVar(restiVar)
		, rigidSize(boxSize)
		, density(den)
		, densityVar(denVar)
		, position(pos)
		, positionVar(posVar)
		, distance(dist)
		, distanceVar(distVar)
		, linearVelocity(vel)
		, velocityVar(velVar)
		, numSolids(nSolids)
		, probGen(probability)
		, colour(col)
		, lifeTime(lTime)
		, lifeTimeVar(lTimeVar)
	{}

	virtual std::vector<DynamicSolid*> generateS() = 0;

	virtual inline double getDistance() { return distance + distanceVar * u(mt); }

	inline void setPosition(Vector3 nPos) { position = nPos; }
	inline Vector3 getPosition() { return position; }

	inline void setVelocity(Vector3 nVel) { linearVelocity = nVel; }
	inline Vector3 getVelocity() { return linearVelocity; }
};

