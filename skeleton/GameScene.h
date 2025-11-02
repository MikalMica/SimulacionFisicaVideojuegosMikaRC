#pragma once
#include "Scene.h"

class Spaceship;

class GameScene : public Scene
{
	// The player
	Spaceship* mSpaceship;

public:

	GameScene()
		: Scene()
		, mSpaceship(nullptr)
	{}

	void Update(double t) override;
	void keyPress(unsigned char key, const PxTransform& camera) override;

	void loadScene() override;
	void unloadScene() override;
};
