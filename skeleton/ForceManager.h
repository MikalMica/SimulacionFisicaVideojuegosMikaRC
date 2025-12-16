#pragma once
#include <vector>
#include <queue>
#include "ForceGenerator.h"
#include "ParticleSystem.h"
#include "Cannon.h"
#include "Singleton.h"
#include "SolidPSystem.h"

class ForceManager : public Singleton<ForceManager>
{

	friend Singleton<ForceManager>; // this way Singleton can call the constructor of A

	// Scene to remove solids
	Scene* mScene = nullptr;

	// Vector of all the forceGenerators in scene
	std::vector<std::pair<ForceGenerator*, int>> forces;

	// Vectors containing everything that needs to be affected by the forces
	std::queue<std::pair<Particle*, int>> particles;
	std::vector<std::pair<ParticleSystem*, int>> systems;
	std::vector<std::pair<Cannon*, int>> cannons;

	std::queue<std::pair<DynamicSolid*, int>> solids;
	std::vector<std::pair<SolidPSystem*, int>> solidSystems;
	
private:
	
	ForceManager()
	{
	}
	
	bool init(Scene* scene);
	
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
		SPRING,
		LIQUID,
		ORBIT,
		SPIN,
		FORCE_SIZE // C++ truco
	};

	enum INTER_GRP {
		SPACESHIP,
		EXPLOSION_PARTS,
		TORNADO_PARTS,
		UI,
		COMET_PARTS,
		COMET,
		INTER_SIZE // C++ truco
	};

	// returns the index in the generators vector
	int AddForceGenerator(ForceGenerator* gen, FORCE_GRP group);
	bool DeleteForceGenerator(std::pair<ForceGenerator*, int> gen);
	void Update(double t);

	inline void RegisterParticle(Particle* p, INTER_GRP grp) { particles.push({ p, grp }); }
	void RegisterPSystem(ParticleSystem* sys, INTER_GRP grp);
	void RegisterCannon(Cannon* can, INTER_GRP grp);

	inline void RegisterSolid(DynamicSolid* s, INTER_GRP grp) { solids.push({ s, grp }); }
	void RegisterSolidPSystem(SolidPSystem* sys, INTER_GRP grp);

	inline std::pair<ForceGenerator*, int> getGeneratorAt(int i) { return forces[i]; }
	std::vector<ForceGenerator*> getGeneratorGroup(FORCE_GRP group);

private:

	// Matrix to set which systems collide with each force

	std::vector<std::vector<bool>> collides = { 
		// ROWS = PARTICLES/SOLIDS, COLUMNS = FORCES

		// GRAVITY, EXPLOSION, RING, SPRING, LIQUID, ORBIT, SPIN
		{ true, true, true, true, true, false, false }, // SPACESHIP
		{ true, true, false, true, false, false, false }, // EXPLOSION PARTICLES
		{ false, false, true, false, false, false, false }, // TORNADO PARTS
		{ false, false, false, false, false, false, false }, // UI
		{ false, false, false, false, false, false, false }, // COMET_PARTS
		{ false, false, false, false, false, true, true } // COMET
	};
};

