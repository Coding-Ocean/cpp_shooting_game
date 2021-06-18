#pragma once
#include"graphic.h"
class CONTAINER {
public:
    void loadGraphics() {
        playerImg = loadImage("assets\\player.png");
        playerBulletImg = loadImage("assets\\pBullet.png");
        enemyImg = loadImage("assets\\enemy.png");
        enemyBulletImg = loadImage("assets\\eBullet.png");
    }
    int playerImg = 0;
    int playerBulletImg = 0;
    int enemyImg = 0;
    int enemyBulletImg = 0;
};