/*
 * Copyright (c) 2018 Isetta
 */
#include "Custom/AILevel/AITestLevel.h"
#include "AITestComponent.h"
#include "Components/Editor/EditorComponent.h"
#include "Components/FlyController.h"
#include "Custom/EscapeExit.h"
#include "Custom/IsettaCore.h"
#include "Custom/KeyTransform.h"
#include "Graphics/ParticleSystemComponent.h"

void Isetta::AITestLevel::OnLevelLoad() {
  Entity *camera = Entity::CreateEntity("Camera");
  camera->SetTransform(Math::Vector3{5, 5, 16}, Math::Vector3{-20, 0, 0},
                       Math::Vector3::one);
  camera->AddComponent<CameraComponent>();
  Entity *lightEntity{Entity::CreateEntity("Light")};
  lightEntity->AddComponent<LightComponent>(
      "materials/light.material.xml", "LIGHT_1");
  lightEntity->SetTransform(Math::Vector3{0, 200, 600}, Math::Vector3::zero,
                            Math::Vector3::one);

  camera->AddComponent<EscapeExit>();
  // camera->AddComponent<EditorComponent>();

  Entity *moveCube{Entity::CreateEntity("Move")};
  moveCube->SetTransform(Math::Vector3{5, 0, 5}, Math::Vector3::zero,
                         Math::Vector3::one * 0.2);
  moveCube->AddComponent<MeshComponent>("primitive/Cube.scene.xml");
  auto p = moveCube->AddComponent<ParticleSystemComponent>(
      "particles/particleSys1/particleSys1.scene.xml");
  Input::RegisterKeyPressCallback(KeyCode::L, [p]() { p->SetActive(false); });
  Input::RegisterKeyPressCallback(KeyCode::O, [p]() { p->SetActive(true); });

  moveCube->AddComponent<KeyTransform>();

  auto ai = camera->AddComponent<AITestComponent>(
      Math::Rect{0, 0, 10, 10}, Math::Vector2Int{20, 20}, moveCube->transform);
}
