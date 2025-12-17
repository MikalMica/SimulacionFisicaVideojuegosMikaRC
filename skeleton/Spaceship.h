#pragma once
#include "DynamicSolid.h"
#include "GaussianGen.h"
#include "ParticleSystem.h"
#include "SolidCannon.h"

class Scene;

class Spaceship : public DynamicSolid
{
	// ParticleSystem for the propulsor
	ParticleSystem* mPSys;

	// Spaceship's Z size
	double sizeZ;

	// Propulsion speed
	float propulsionSpeed;

	// force to add each frame. Changes depending on the propulsor
	Vector3 forceToAdd;

	// Boolean to set is neccesary to spawn particles of propulsor
	bool showPropulsion;

	// Timer to stop going forward 
	double propulsionTimer;

	// Time until propulsor stops
	double propulsionTime;

	// Camera offset
	double ZOffset;
	double YOffset;

	// Cannon of the Spaceship
	SolidCannon* mCannon;

	// Angles of the spaceship
	double hAngle;
	double vAngle;

	// Original velocity of the pSystem
	Vector3 oVel;

	// Offset of the camera
	float zOffset;
	float yOffset;

public:
	Spaceship(Solid* solid, Scene* scene)
		: DynamicSolid(*static_cast<DynamicSolid*>(solid))
		, sizeZ(10)
		, propulsionSpeed(10000.0)
		, showPropulsion(false)
		, forceToAdd({ 0, 0, 0 })
		, propulsionTime(0.5)
		, propulsionTimer(0)
		, ZOffset(10.0)
		, YOffset(10.0)
		, hAngle(0.0)
		, vAngle(0.0)
		, zOffset(70.0)
		, yOffset(50.0)
		, mCannon(new SolidCannon(scene, 0.5, 0.5, 0.8, 1, 0.9, getPosition() + Vector3(0, 0, sizeZ + 1), {0, 0, 100}, {1, 0, 1, 1}, 5, SpaceObjectType::BULLET))
	{

		mPSys = new ParticleSystem(1000);
		mPSys->addGen(new GaussianGen(getPosition() - Vector3(0, 0, sizeZ), {0, 0, -20}, 2, 5, 0.6, 0.8, Particle::SI_EULER, 10, 1, 2, 0.1, {0, 0, 0}, {10, 10, 10}, {1, 0.64, 0, 1}));
		oVel = mPSys->getCurrVelocity();

		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::SPACESHIP;
		data->object = this;
		dBody->userData = data;
	}

	~Spaceship() 
	{

		delete mPSys;
		mPSys = nullptr;

		delete mCannon;
		mCannon = nullptr;
	}

	void Update(double t);
	void keyPress(unsigned char key, const PxTransform& camera);

	inline SolidCannon* getCannon() { return mCannon; }
	inline ParticleSystem* getPSystem() { return mPSys; }
};

