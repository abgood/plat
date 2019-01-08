#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/ProcessUtils.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/UI.h>

#include <Urho3D/DebugNew.h>

#include "Utilities2D/Sample2D.h"
#include "Plat.h"

URHO3D_DEFINE_APPLICATION_MAIN(Plat)

Plat::Plat(Context* context) :
	Sample(context)
{
}

void Plat::Setup()
{
	Sample::Setup();
	engineParameters_[EP_SOUND] = true;
}

void Plat::Start()
{
	Sample::Start();

	sample2D_ = new Sample2D(context_);
}
