#pragma once

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