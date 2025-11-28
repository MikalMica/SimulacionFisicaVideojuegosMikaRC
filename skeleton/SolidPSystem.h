#pragma once
#include <queue>
#include "DynamicSolid.h"
#include "Scene.h"

class SolidPSystem
{
	std::queue<Solid*> solids;
	Scene* mScene = nullptr;
	
	int maxSolids;
	int genIndex = 0;
	int forceIndex = 0;
	bool generate = true;

public:
	//Terminar esta cosa

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
};

