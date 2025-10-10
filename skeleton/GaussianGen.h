#pragma once
#include "ParticleGen.h"

class GaussianGen : public ParticleGen
{
	std::normal_distribution<double >d{ 0, 1 };

public:
	void generateP() override;
};

