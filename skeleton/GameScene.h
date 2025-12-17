#pragma once
#include "Scene.h"
#include <vector>

class Spaceship;
class Cannon;
class Planet;
class ExplodingPlanet;
class Nebula;
class Comet;

class GameScene : public Scene
{
	// The player
	Spaceship* mSpaceship;

	// UI Cannon
	Cannon* mCannon;

	// Planets
	std::vector<Planet*> planets;

	// Exploding Planets (also referenced in planets)
	std::vector<ExplodingPlanet*> ePlanets;

	// Nebula
	Nebula* mNebula;

	// Comet
	Comet* mComet;

	// method to remove dead planets
	bool killPlanet(Planet* planet);

public:

	GameScene(PxPhysics* gPh, PxScene* sc)
		: Scene(gPh, sc)
		, mSpaceship(nullptr)
		, mCannon(nullptr)
		, mNebula(nullptr)
		, mComet(nullptr)
	{}

	void Update(double t) override;
	void keyPress(unsigned char key, const PxTransform& camera) override;

	void loadScene() override;
	void unloadScene() override;

	void onCollision(physx::PxActor* actor1, physx::PxActor* actor2) override;

};
