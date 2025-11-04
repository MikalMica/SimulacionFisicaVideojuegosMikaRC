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
	std::queue<Particle*> particles;
	std::vector<ParticleSystem*> systems;
	std::vector<Cannon*> cannons;

	
	
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
		PLANET_EXPLOSION
	};

	// returns the index in the generators vector
	int AddForceGenerator(ForceGenerator* gen, FORCE_GRP group);
	bool DeleteForceGenerator(std::pair<ForceGenerator*, int> gen);
	void Update(double t);

	inline void RegisterParticle(Particle* p) { particles.push(p); }
	void RegisterPSystem(ParticleSystem* sys);
	void RegisterCannon(Cannon* can);

	inline std::pair<ForceGenerator*, int> getGeneratorAt(int i) { return forces[i]; }
	std::vector<ForceGenerator*> getGeneratorGroup(FORCE_GRP group);
};

