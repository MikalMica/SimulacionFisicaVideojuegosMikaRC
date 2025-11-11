#pragma once
#include "Particle.h"

class Anchor : public Particle
{
public:
	Anchor(Vector3 posi)
		: Particle(posi, {0, 0, 0}, {0, 0, 0}, -1, 0.9, 0, Particle::SI_EULER, {1, 1, 1, 1})
	{
	
		auto geom = PxBoxGeometry(1, 1, 1);
		auto shape = CreateShape(geom);
		item->release();
		item = new RenderItem(shape, pos, colour);
	}
};

