#pragma once
#include "Particle.h"
#include "ParticleSystem.h"
#include "GaussianGen.h"
#include "RealGravityForceGenerator.h"
#include "ForceManager.h"

class Star : public Particle
{

	float radius;
	int gIndex;
	ParticleSystem* explosion;

	double blackHoleTimer;

	bool initFlag;

public:

	Star(Vector3 const& posi, float rad)
		: Particle(posi, {0, 0, 0}, {0, 0, 0}, -1, 0.9, 1, Particle::SI_EULER, {1, 0.5, 0, 1})
		, radius(rad)
		, explosion(nullptr)
		, blackHoleTimer(-1)
		, initFlag(false)
	{
		item->release();

		auto geom = PxSphereGeometry(rad);
		auto shape = CreateShape(geom);
		pos = new PxTransform(posi);
		item = new RenderItem(shape, pos, colour);

		gIndex = ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(5.97 * pow(10, 15), getPosition(), rad + 250), ForceManager::GRAVITY);
	}

	~Star() {

		if (explosion != nullptr) {
			delete explosion;
			explosion = nullptr;
		}
	}

	void Supernova();
	void Update(double t);
};

