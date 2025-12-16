#pragma once
#include <queue>
#include "ForceGenerator.h"
#include "DynamicSolid.h"

// TENGO QUE REFACTORIZAR TODO ESTO PERO QUIERO DORMIR

//class SolidCannon
//{
//private:
//	int const MAX_BULLETS = 20;
//
//	std::queue<DynamicSolid*> bullets;
//	std::vector<ForceGenerator*> forces;
//
//public:
//	Cannon(Vector3 P, Vector3 V, Vector3 A, double T, double d, Particle::Mode m, double M, Vector4 colour)
//		: iPos(P), Rvel(V), a(A), Rmass(M), tVida(T), damping(d), mode(m), Svel(V), Smass(M), col(colour), copy(nullptr) {
//		bullets = std::queue<Particle*>();
//		particles = { {{ -20, 0, -20 }, { 0, -9.8, 0 }, {1, 0, 0, 1}}, { {-10, 0, -10}, {0, -20, 0}, {0, 1, 0, 1} }, { {-20, 0, -20}, {0, 9.8, 0}, {0, 0, 1, 1} } };
//	};
//
//	~Cannon() { int size = bullets.size(); for (int i = 0; i < size; ++i) { auto aux = bullets.front(); bullets.pop(); delete aux; aux = nullptr; } }
//
//	void Shoot();
//	void Update(double t);
//	double SetSimulatedVel(double simulatedVel);
//
//	inline void setType(Type nType) { pType = nType; }
//	inline void setPosition(Vector3 const& nPos) { iPos = nPos; };
//	inline Vector3 getPosition() { return iPos; }
//	inline void setSpeed(Vector3 const& nVel) { Rvel = nVel; };
//	inline void setVel(PxQuat const& nVel, bool inverse = false) { int inv = inverse ? -1 : 1; Svel = nVel.rotate({ 0, 0, Svel.magnitude() * inv }); };
//
//	inline Vector3 getVel() { return Rvel; }
//
//	void applyForceGenerator(ForceGenerator* force);
//	void deleteForceGenerator(ForceGenerator* force);
//	
//};