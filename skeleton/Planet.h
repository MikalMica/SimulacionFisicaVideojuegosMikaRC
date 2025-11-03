#pragma once
#include "Particle.h"
#include "ExplosionForceGenerator.h"
#include "RealGravityForceGenerator.h"

class Planet : public Particle
{

public:

	Planet(Vector3 posi, Vector4 col, float r) 
		: Particle(posi, { 0, 0, 0 }, { 0, 0, 0 }, -1, 0.0, 1000, Particle::SI_EULER, col)
	{

		auto geom = PxSphereGeometry(r);
		auto shape = CreateShape(geom);
		item = new RenderItem(shape, pos, colour);
	}

	void Update(double t);
	void keyPress(unsigned char key, const PxTransform& camera);
};

