#pragma once
#include "ForceGenerator.h"

class TorqueForceGenerator : public ForceGenerator
{

	Vector3 mTorque;

public:
	TorqueForceGenerator(Vector3 const& torque)
		: ForceGenerator({ 0, 0, 0 })
		, mTorque(torque)
	{ }

	Vector3 forceToApply(DynamicSolid* p) override;
};