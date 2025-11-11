#pragma once
#include "Particle.h"

class Sea : public Particle
{
public:
	Sea(Vector3 posi)
		: Particle(posi, { 0, 0, 0 }, { 0, 0, 0 }, -1, 0.9, 0.5, Particle::SI_EULER, { 0, 0, 1, 1 })
	{
		auto geom = PxBoxGeometry(1000, 0.1, 1000);
		auto shape = CreateShape(geom);
		item->release();
		item = new RenderItem(shape, pos, colour);
	}
};

