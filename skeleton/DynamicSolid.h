#pragma once
#include "Solid.h"

class DynamicSolid : public Solid
{
public:

	DynamicSolid() {

		// Hacer cosas con lo que rescatamos de Solid especifico para dynamic

		PxRigidBodyExt::updateMassAndInertia(*body, density);

		item = new RenderItem(shape, body, { 1, 0, 0, 1 });
	}
};

