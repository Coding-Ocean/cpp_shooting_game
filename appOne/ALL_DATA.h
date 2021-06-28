#pragma once
#include"graphic.h"
#include"TITLE.h"
#include"PLAYER.h"
struct ALL_DATA {
    struct TITLE::DATA title;
    struct PLAYER::DATA player;
    COLOR stageBackColor;
};
