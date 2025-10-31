#pragma once
#include "ParticleGen.h"

class GaussianGen : public ParticleGen
{

	std::normal_distribution<float>d{ 0, 1 };

public:
	GaussianGen(Vector3 p, Vector3 v, double lifeT, double dist, double prob, double damp, Particle::Mode m,
		int maxParticles, double lVar, double dVar, double ma, Vector3 pVar, Vector3 vVar, Vector4 colour)
		: ParticleGen(p, v, lifeT, dist, prob, damp, m, maxParticles, lVar, dVar, ma, pVar, vVar, colour) {
	}

	std::vector<Particle*> generateP() override;
	inline double getDistance() override { return distance + distanceVar * d(mt); }
};

