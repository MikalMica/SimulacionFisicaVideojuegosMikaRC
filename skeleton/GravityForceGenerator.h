#pragma once
#include "ForceGenerator.h"

class GravityForceGenerator : public ForceGenerator
{
public:
	GravityForceGenerator(float gravity = 9.8) : ForceGenerator({0, -gravity, 0}){}
};

