#include <Urho3D/Audio/Audio.h>
#include <Urho3D/Urho2D/AnimatedSprite2D.h>
#include <Urho3D/Urho2D/AnimationSet2D.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Urho2D/CollisionBox2D.h>
#include <Urho3D/Urho2D/CollisionChain2D.h>
#include <Urho3D/Urho2D/CollisionCircle2D.h>
#include <Urho3D/Urho2D/CollisionPolygon2D.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/GraphicsEvents.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Urho2D/PhysicsEvents2D.h>
#include <Urho3D/Urho2D/PhysicsWorld2D.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Urho2D/RigidBody2D.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Core/StringUtils.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/Urho2D/TileMap2D.h>
#include <Urho3D/Urho2D/TileMapLayer2D.h>
#include <Urho3D/Urho2D/TmxFile2D.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/Graphics/Zone.h>

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
	sample2D_->demoFilename_ = "Plat";

	CreateScene();
}

void Plat::CreateScene()
{
	scene_ = new Scene(context_);
	sample2D_->scene_ = scene_;

	scene_->CreateComponent<Octree>();
	scene_->CreateComponent<DebugRenderer>();

	cameraNode_ = scene_->CreateChild("Camera");
	auto* camera = cameraNode_->CreateComponent<Camera>();
	camera->SetOrthographic(true);

	auto* graphics = GetSubsystem<Graphics>();
	camera->SetOrthoSize((float)graphics->GetHeight() * PIXEL_SIZE);
	camera->SetZoom(2.0f * Min((float)graphics->GetWidth() / 1280.0f, (float)graphics->GetHeight() / 800.0f));

	SharedPtr<Viewport> viewport(new Viewport(context_, scene_, camera));
	auto* renderer = GetSubsystem<Renderer>();
	renderer->SetViewport(0, viewport);

	Zone* zone = renderer->GetDefaultZone();
	zone->SetFogColor(Color(0.2f, 0.2f, 0.2f));
}
