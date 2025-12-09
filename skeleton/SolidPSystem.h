#pragma once
#include <queue>
#include "DynamicSolid.h"
#include "Scene.h"
#include "SolidGen.h";

class ForceGenerator;

class SolidPSystem
{
	std::queue<DynamicSolid*> solids;
	Scene* mScene = nullptr;

	std::vector<SolidGen*> generators;
	int genIndex = 0;

	std::vector<ForceGenerator*> forces;
	
	int maxSolids;
	int forceIndex = 0;
	bool generate = true;

public:

	SolidPSystem(Scene* scene, int maxSols)
		: solids()
		, maxSolids(maxSols)
		, mScene(scene)
	{}

	~SolidPSystem()
	{
		int size = solids.size();

		for (int i = 0; i < size; ++i) {
			auto solid = solids.front();
			solids.pop();

			delete solid;
			solid = nullptr;
		}
	}

	void Update(double t);

	inline void addGen(SolidGen* gen) { generators.push_back(gen); }
	void removeGen(SolidGen* gen);
	inline void setGenerator(int index) { genIndex = index; }

	inline void applyForceGenerator(ForceGenerator* gen) { forces.push_back(gen); }
	void deregisterForceGenerator(ForceGenerator* gen);

	inline void setCurrPosition(Vector3 nPos) { generators[genIndex]->setPosition(nPos); }
	inline Vector3 getCurrPosition() { return generators[genIndex]->getPosition(); }

	inline void setCurrVelocity(Vector3 nVel) { generators[genIndex]->setVelocity(nVel); }
	inline Vector3 getCurrVelocity() { return generators[genIndex]->getVelocity(); }

	void DestroyAllParticles();
	inline void ChangeParticleGeneration() { generate = !generate; }
};

