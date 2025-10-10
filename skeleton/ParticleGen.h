#pragma once

#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <random>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

class ParticleGen
{
	Vector3 pos;
	Vector3 vel;
	Vector3 dur;
	double probGen;

	std::mt19937 mt;
	std::uniform_real_distribution<double> u{ 0, 1 };

public:
	virtual void generateP() = 0;
};

