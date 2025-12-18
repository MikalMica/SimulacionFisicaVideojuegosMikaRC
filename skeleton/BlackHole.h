#pragma once
#include "Particle.h"
#include "ForceManager.h"
#include "RealGravityForceGenerator.h"

class BlackHole : public Particle
{
public:
	BlackHole(Vector3 const& posi)
		: Particle(posi, { 0, 0, 0 }, { 0, 0, 0 }, -1, 0.9, 1000000000, Particle::SI_EULER, { 0, 0, 0, 1 })
	{
		item->release();

		auto geom = PxSphereGeometry(100);
		auto shape = CreateShape(geom);
		pos = new PxTransform(posi);
		item = new RenderItem(shape, pos, colour);

		ForceManager::Instance()->AddForceGenerator(new RealGravityForceGenerator(5.97 * pow(10, 17), getPosition(), -1), ForceManager::BLACK_HOLE);
	}
};

