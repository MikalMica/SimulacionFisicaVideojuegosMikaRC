#pragma once
#include <vector>
#include "ForceGenerator.h"

class ForceManager
{

	// Vector of all the forceGenerators in scene
	std::vector<ForceGenerator*> forces;

	// Singleton
	static ForceManager* singleton;

public:

	ForceManager()
	{
		if (singleton == nullptr) singleton = this;
		else delete this;
	}
};

