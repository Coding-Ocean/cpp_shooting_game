#pragma once
#include"graphic.h"
#include"TITLE.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
struct ALL_DATA {
    TITLE::DATA title;
    PLAYER::DATA player;
    ENEMIES::DATA enemy;
    BULLETS::DATA playerBullet;
    BULLETS::DATA enemyBullet;
    COLOR stageBackColor;
};
