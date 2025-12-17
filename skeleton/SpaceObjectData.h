#pragma once

// Cualquier parecido entre este archivo y el de otros compis de clase es pura coincidencia

enum class SpaceObjectType {
	PLANET,
	EXPLODING_PLANET,
	RINGED_PLANET,
	ASTEROIDS_RING,
	WATER_PLANET,
	COMET,
	SPACESHIP,
	BULLET,
	DEFAULT
};

struct SpaceObjectData {
public:
	SpaceObjectType type;
	void* object;
};