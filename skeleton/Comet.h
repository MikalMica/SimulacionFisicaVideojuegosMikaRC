#pragma once
#include "DynamicSolid.h"
#include "ParticleSystem.h"
#include "GaussianGen.h"
#include "ForceManager.h"
#include "TorqueForceGenerator.h"
#include "TornadoForceGenerator.h"
#include "SpaceObjectData.h"

class Comet : public DynamicSolid
{
	ParticleSystem* trail;

public:
	Comet(Solid* solid, Vector3 const& orbitOrigin, float radius)
		: DynamicSolid(*static_cast<DynamicSolid*>(solid))
	{
		trail = new ParticleSystem(300);
		auto gen = new GaussianGen(getPosition(), getRotation().rotate({ 1, 0, 0 }) * 50, 5, 200, 0.5, 0.9, Particle::SI_EULER, 4, 2, 100, 1, { 0, 0, 0 }, { 0, 5, 5 }, { 0, 1, 1, 1 });
		trail->addGen(gen);

		ForceManager::Instance()->RegisterPSystem(trail, ForceManager::COMET_PARTS);
		ForceManager::Instance()->AddForceGenerator(new TorqueForceGenerator({ 10000, 0, 100000 }), ForceManager::SPIN);
		ForceManager::Instance()->RegisterSolid(this, ForceManager::COMET);
		ForceManager::Instance()->AddForceGenerator(new TornadoForceGenerator(Vector3(0, 1, 0), orbitOrigin, 100, radius), ForceManager::ORBIT);

		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::COMET;
		data->object = this;
		dBody->userData = data;
	}

	void Update(double t);
};

