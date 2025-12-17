#pragma once
#include <queue>
#include "ForceGenerator.h"
#include "DynamicSolid.h"

// TENGO QUE REFACTORIZAR TODO ESTO PERO QUIERO DORMIR
class Scene;

class SolidCannon
{
private:
	int const MAX_BULLETS = 20;

	std::queue<DynamicSolid*> bullets;
	std::vector<ForceGenerator*> forces;

	Scene* mScene;
	float staticFriction;
	float dynamicFriction;
	float restituition;
	float radius;
	float density;
	Vector3 initPos;
	Vector3 velocity;
	Vector4 colour;
	double lifeTime;
	SpaceObjectType mType;

public:
	SolidCannon(Scene* scene, float sFriction, float dFriction, float resti, float rad, float den, Vector3 const& pos, Vector3 const& vel, Vector4 const& col, double lTime, SpaceObjectType type = SpaceObjectType::DEFAULT)
		: mScene(scene), staticFriction(sFriction), dynamicFriction(dFriction), restituition(resti), radius(rad), density(den), initPos(pos), velocity(vel), colour(col), lifeTime(lTime), mType(type)
	{
		bullets = std::queue<DynamicSolid*>();
	};

	~SolidCannon() { int size = bullets.size(); for (int i = 0; i < size; ++i) { auto aux = bullets.front(); bullets.pop(); delete aux; aux = nullptr; } }

	void Shoot();
	void Update(double t);

	inline void setPosition(Vector3 const& nPos) { initPos = nPos; };
	inline Vector3 getPosition() { return initPos; }
	inline void setSpeed(Vector3 const& nVel) { velocity = nVel; };
	inline void setVel(PxQuat const& nVel, bool inverse = false) { int inv = inverse ? -1 : 1; velocity = nVel.rotate({ 0, 0, velocity.magnitude() * inv }); };

	inline Vector3 getVel() { return velocity; }

	void applyForceGenerator(ForceGenerator* force);
	void deleteForceGenerator(ForceGenerator* force);
	
};