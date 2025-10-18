#pragma once

#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <random>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Particle.h"

class ParticleGen
{
protected:
	const Vector3 GRAVITY = {0, -10.0, 0};

	const Vector4 colour;
	Vector3 pos;
	Vector3 vel;
	Vector3 ac;
	double dur;
	double probGen;
	double damping;
	double distance;
	Particle::Mode mode;
	int numParticles; // Máximo de particulas generadas por generate

	Vector3 posVar;
	Vector3 velVar;
	double lifeVar;
	double distanceVar;

	std::mt19937 mt;
	std::uniform_real_distribution<double> u{ 0, 1 };

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
	/// <param name="pVar">variation of initial position</param>
	/// <param name="vVar">variation of initial velocity</param>
	/// <param name="col">colour</param>
	ParticleGen(Vector3 p, Vector3 v, double lifeT, double dist, double prob, double damp, Particle::Mode m, 
		int maxParticles, double lVar, double dVar, Vector3 pVar, Vector3 vVar, Vector4 col) 
		: pos(p), vel(v), dur(lifeT), probGen(prob), numParticles(maxParticles), damping(damp), mode(m),
		distance(dist), posVar(pVar), velVar(vVar), lifeVar(lVar), distanceVar(dVar), colour(col), ac(GRAVITY) {}

	virtual std::vector<Particle*> generateP() = 0;

	virtual inline double getDistance() { return distance + distanceVar * u(mt); }
	virtual inline void changeAc(Vector3 acel) { ac = acel; }
};

