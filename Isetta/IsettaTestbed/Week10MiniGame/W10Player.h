/*
 * Copyright (c) 2018 Isetta
 */
#pragma once
#include "Scene/Component.h"

BEGIN_COMPONENT(W10Player, Isetta::Component, true)
public:
W10Player(bool isRight);
void Awake() override;
void Start() override;
void Update() override;

private:
bool isOnRight;

float horizontalSpeed;

Isetta::Entity* swordEntity;
int swordPos;
float swordTargetX;
float swordXProgress;
float stabSpeed;
int swordStabStatus;  // 0 for init, 1 for atack, 2 for revoke, 3 for not on
                      // hand

float gravity;
float flyDuration;
float totalFlyDuration;
float targetX;
float targetY;
float originY;
float v0x;
float v0y;
bool isSwordFlying;

void ChangeSwordVerticlePosition(int direction);
void ChangeSwordHorizontalPosition(float deltaTime);
void SwordBlocked();

END_COMPONENT(W10Player, Isetta::Component)