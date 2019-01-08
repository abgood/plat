#pragma once

#include <Urho3D/Core/Object.h>

namespace Urho3D
{
	class Node;
	class Scene;
}

using namespace Urho3D;

class Sample2D : public Object
{
	URHO3D_OBJECT(Sample2D, Object);

public:
	explicit Sample2D(Context* context);
	~Sample2D() override = default;
};
