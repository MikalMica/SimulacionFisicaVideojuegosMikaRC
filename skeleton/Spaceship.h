#pragma once
#include "ParticleSystem.h"
#include "GaussianGen.h"

class Spaceship : public Particle
{
	// ParticleSystem for the propulsor
	ParticleSystem* mPSys;

	// Spaceship's size
	double sizeX;
	double sizeY;
	double sizeZ;

public:
	Spaceship() 
		: Particle({ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 0.9, 100.0, Particle::SI_EULER, { 43.0 / 255, 76.0 / 255, 142.0 / 255, 1.0 })
		, sizeX(5) 
		, sizeY(5)
		, sizeZ(10)
	{
	
		auto geom = PxBoxGeometry(sizeX, sizeY, sizeZ);
		auto shape = CreateShape(geom);
		DeregisterRenderItem(item);
		item = new RenderItem(shape, pos, colour);

		mPSys = new ParticleSystem(1000);
		mPSys->addGen(new GaussianGen(pos->p - Vector3(0, 0, -sizeZ / 2), { 0, 0, -10 }, 2, 5, 0.6, 0.8, Particle::SI_EULER, 10, 1, 2, 0.1, { 0, 0, 0 }, { 0, 0, 10 }, { 1, 0.64, 0, 1 }));
	}

	void Update();
	void keyPress(unsigned char key, const PxTransform& camera);
};

