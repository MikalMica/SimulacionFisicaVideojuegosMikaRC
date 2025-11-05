#pragma once
#include <vector>
#include <queue>
#include "ForceGenerator.h"
#include "ParticleSystem.h"
#include "Cannon.h"
#include "Singleton.h"

class ForceManager : public Singleton<ForceManager>
{

	friend Singleton<ForceManager>; // this way Singleton can call the constructor of A

	// Vector of all the forceGenerators in scene
	std::vector<std::pair<ForceGenerator*, int>> forces;

	// Vectors containing everything that needs to be affected by the forces
	std::queue<std::pair<Particle*, int>> particles;
	std::vector<std::pair<ParticleSystem*, int>> systems;
	std::vector<std::pair<Cannon*, int>> cannons;

	
	
private:
	
	ForceManager()
	{
	}
	
	bool init();
	
	virtual ~ForceManager() {
	
		for (auto force : forces) {
			delete force.first;
			force.first = nullptr;
		}
	}

public:

	enum FORCE_GRP {
		PLANET_GRAVITY,
		PLANET_EXPLOSION,
		PLANET_RING,
		FORCE_SIZE // C++ truco
	};

	enum INTER_GRP {
		SPACESHIP,
		EXPLOSION_PARTS,
		TORNADO_PARTS,
		UI,
		INTER_SIZE // C++ truco
	};

	// returns the index in the generators vector
	int AddForceGenerator(ForceGenerator* gen, FORCE_GRP group);
	bool DeleteForceGenerator(std::pair<ForceGenerator*, int> gen);
	void Update(double t);

	inline void RegisterParticle(Particle* p, INTER_GRP grp) { particles.push({ p, grp }); }
	void RegisterPSystem(ParticleSystem* sys, INTER_GRP grp);
	void RegisterCannon(Cannon* can, INTER_GRP grp);

	inline std::pair<ForceGenerator*, int> getGeneratorAt(int i) { return forces[i]; }
	std::vector<ForceGenerator*> getGeneratorGroup(FORCE_GRP group);

private:

	// Matrix to set whic systems collide with each force

			
	std::vector<std::vector<bool>> collides = { 
		// GRAVITY, EXPLOSION, RING
		{ true, true, false }, // SPACESHIP
		{ true, true, false }, // EXPLOSION PARTICLES
		{ true, true, true }, // TORNADO PARTS
		{ false, false, false } // UI
	};
};

