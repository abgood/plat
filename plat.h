#pragma once

#include "Sample.h"
#include "Utilities2D/Sample2D.h"

class Sample2D;

class Plat : public Sample
{
	URHO3D_OBJECT(Plat, Sample);

public:
	explicit Plat(Context* context);
	void Start() override;
	void Setup() override;

private:
	// void CreateScene();

	SharedPtr<Sample2D> sample2D_;
};
