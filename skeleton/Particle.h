#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

using namespace physx;

class Particle{
public:
	enum Mode {
		EULER,
		SI_EULER,
		VERLET,
		POST_VERLET
	};

private:
	RenderItem* item;
	PxTransform* pos;
	Vector3 v;
	Vector3 a;
	double m;
	double tVida; // in seconds
	double damping;
	Vector3 lasPos;
	Mode mode;

public:
	Particle() : pos(new PxTransform({0, 0, 0})), v(0, 0, 0), a(0, 0, 0), m(1.0), tVida(10), damping(1.0), lasPos(0, 0, 0), mode(EULER){
		auto geom = PxSphereGeometry(1.0f);
		auto shape = CreateShape(geom);
		item = new RenderItem(shape, pos, Vector4(1, 0, 0, 1));
	}

	Particle(Vector3 P, Vector3 V, Vector3 A, double T, double d, Mode m) : pos(new PxTransform(P)), v(V), a(A), m(1.0), tVida(T), damping(d), lasPos(0, 0, 0), mode(m) {
		auto geom = PxSphereGeometry(1.0f);
		auto shape = CreateShape(geom);
		item = new RenderItem(shape, pos, Vector4(1, 0, 0, 1));
	}

	~Particle() { DeregisterRenderItem(item); item = nullptr; pos = nullptr; }


	void Integrate(double t);
	inline void setMode(Mode m) { mode = m; }

	bool hasToDie() { return tVida <= 0.0; }
};

