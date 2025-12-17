#pragma once
#include "Particle.h"
#include "StaticSolid.h"
#include "SpringForceGenerator.h"
#include "ForceManager.h"
#include "math.h"
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;

class AlienLifeForm
{
protected:

	Scene* mScene;

	Particle* heart;
	vector<Particle*> fleshModules;
	vector<SpringForceGenerator*> springForces;

	std::normal_distribution<float>d{ 0, 1 };
	std::mt19937 mt;

	Vector3 var;
	Vector3 velocity;

	bool isDead;

public:
	AlienLifeForm(Vector3 const& iPos, Vector3 const& vel, Vector3 const& waveVar, Scene* scene, int nModules)
		: mScene(scene)
		, var(waveVar)
		, velocity(vel)
		, isDead(false)
	{
		heart = new Particle(iPos, {0, 0, 0}, {0, 0, 0}, -1, 0.9, 100, Particle::SI_EULER, {0.5, 0, 0, 1});
		ForceManager::Instance()->RegisterParticle(heart, ForceManager::ALIEN_HEART);

		for (int i = 0; i < nModules; ++i) {
			fleshModules.push_back(new Particle(iPos + Vector3(5 * d(mt), 5 * d(mt), 5 * d(mt)), Vector3(10 * d(mt), 10 * d(mt), 10 * d(mt)), {0, 0, 0}, -1, 0.9, 1, Particle::SI_EULER, {0, 1, 0.7, 1}));
			SpringForceGenerator* force = new SpringForceGenerator(10, 10, fleshModules[i], heart);
			springForces.push_back(force);
			ForceManager::Instance()->AddForceGenerator(force, ForceManager::SPRING);
			ForceManager::Instance()->RegisterParticle(fleshModules[i], ForceManager::ALIEN);
		}
	}

	~AlienLifeForm();

	void Update(double t);
	void Die();
};

