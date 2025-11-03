#pragma once
#include <vector>
#include "ForceGenerator.h"
#include "ParticleSystem.h"
#include "Cannon.h"

class ForceManager
{

	// Vector of all the forceGenerators in scene
	std::vector<std::pair<ForceGenerator*, int>> forces;

	// Vectors containing everything that needs to be affected by the forces
	std::vector<Particle*> particles;
	std::vector<ParticleSystem*> systems;
	std::vector<Cannon*> cannons;
	
	// Singleton
	static ForceManager* singleton;

public:

	enum FORCE_GRP {
		PLANET_GRAVITY,
		EXPLOSION
	};

	ForceManager()
	{}

	// returns the index in the generators vector
	int AddForceGenerator(ForceGenerator* gen, FORCE_GRP group);
	void Update(double t);

	inline void RegisterParticle(Particle* p) { particles.push_back(p); }
	inline void RegisterPSystem(ParticleSystem* sys) { systems.push_back(sys); }
	inline void RegisterCannon(Cannon* can) { cannons.push_back(can); }

	inline ForceGenerator* getGeneratorAt(int i) { return forces[i].first; }
	std::vector<ForceGenerator*> getGeneratorGroup(FORCE_GRP group);

	static ForceManager* getSingleton();
};

