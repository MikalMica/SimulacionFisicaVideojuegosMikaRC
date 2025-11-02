#pragma once
#include "ParticleGen.h"

class GaussianGen : public ParticleGen
{

	std::normal_distribution<float>d{ 0, 1 };

public:

	/// <summary>
	/// Acceleration by default is GRAVITY. To change it use "changeAc"
	/// </summary>
	/// <param name="p">initial position</param>
	/// <param name="v">initial velocity</param>
	/// <param name="lifeT">life time of the particles</param>
	/// <param name="dist">distance from the origin at which the particles will destroy themselves</param>
	/// <param name="prob">percentage of the distribution that sets de probability of a particle to spawn</param>
	/// <param name="damp">damping</param>
	/// <param name="m">mode of integration</param>
	/// <param name="maxParticles">maximum number of particles that will be created each generateP</param>
	/// <param name="lVar">variation of lifetime</param>
	/// <param name="dVar">variation of distance</param>
	/// <param name="ma">mass of the particle</param>
	/// <param name="pVar">variation of initial position</param>
	/// <param name="vVar">variation of initial velocity</param>
	/// <param name="col">colour</param>
	GaussianGen(Vector3 p, Vector3 v, double lifeT, double dist, double prob, double damp, Particle::Mode m,
		int maxParticles, double lVar, double dVar, double ma, Vector3 pVar, Vector3 vVar, Vector4 colour)
		: ParticleGen(p, v, lifeT, dist, prob, damp, m, maxParticles, lVar, dVar, ma, pVar, vVar, colour) {
	}

	std::vector<Particle*> generateP() override;
	inline double getDistance() override { return distance + distanceVar * d(mt); }
};

