#pragma once
#include "Planet.h"

class WaterPlanet : public Planet
{
	float waterRadius;
public:
	WaterPlanet(Solid* solid, float r)
		: Planet(solid, r - (r / 3))
		, waterRadius(r)
	{
		auto geom = PxSphereGeometry(waterRadius);
		auto shape = CreateShape(geom);
		item = new RenderItem(shape, new PxTransform(solid->getPosition()), {0, 0, 1, 1});

		auto data = new SpaceObjectData();
		data->type = SpaceObjectType::WATER_PLANET;
		data->object = this;
		dBody->userData = data;
	}

	void init() override;

};

