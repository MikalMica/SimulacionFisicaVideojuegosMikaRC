#pragma once
#include "SolidGen.h"

class DynamicSolid;

class GaussianSolidGen : public SolidGen
{
	std::normal_distribution<float>d{ 0, 1 };

public:

	GaussianSolidGen(Scene* scene, float sFriction, float dFriction, float dFrictionVar, float resti, float restiVar, Vector3 const& boxSize, float den, float denVar, Vector3 const& pos, Vector3 const& posVar,
		double dist, double distVar, Vector3 const& vel, Vector3 const& velVar, int nSolids, double probability, Vector4 const& col, double lTime, double lTimeVar, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: SolidGen(scene, sFriction, dFriction, dFrictionVar, resti, restiVar, boxSize, den, denVar, pos, posVar, dist, distVar, vel, velVar, nSolids, probability, col, lTime, lTimeVar, type)
	{ }

	std::vector<DynamicSolid*> generateS() override;
	inline double getDistance() override { return distance + distanceVar * d(mt); }
};

