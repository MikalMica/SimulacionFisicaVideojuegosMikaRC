#pragma once
#include "Particle.h"
#include "ExplosionForceGenerator.h"
#include "RealGravityForceGenerator.h"

class Planet : public Particle
{
protected:

	// Radius of the planet
	double radius;

public:

	Planet(Vector3 posi, Vector4 col, float r, double mass) 
		: Particle(posi, { 0, 0, 0 }, { 0, 0, 0 }, -1, 0.0, mass, Particle::SI_EULER, col)
		, radius(r)
	{

		item->release();

		auto geom = PxSphereGeometry(r);
		auto shape = CreateShape(geom);
		item = new RenderItem(shape, pos, colour);
	}

	virtual void Update(double t);
	void keyPress(unsigned char key, const PxTransform& camera);

	virtual void init();
};

