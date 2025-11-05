#pragma once
#include "ParticleSystem.h"
#include "GaussianGen.h"

class Nebula : public ParticleSystem
{
public:
	Nebula(Vector3 pos)
		: ParticleSystem(1000)
	{
		GaussianGen* gen = new GaussianGen(pos, { 0, 0, 0 }, 5, 500, 0.7, 0.9, Particle::SI_EULER, 20, 5, 50, 0.5, { 400, 400, 400 }, { 5, 5, 5 }, { 61 / 255, 10 / 255, 138 / 255, 1 });
		addGen(gen);
	}
};