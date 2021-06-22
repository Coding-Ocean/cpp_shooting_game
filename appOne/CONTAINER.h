#pragma once
#include"graphic.h"
#include"ALL_DATA.h"
class CONTAINER {
public:
    //Graphics
    int playerImg = 0;
    int playerBulletImg = 0;
    int enemyImg = 0;
    int enemyBulletImg = 0;
    void loadGraphics() {
        playerImg = loadImage("assets\\player.png");
        playerBulletImg = loadImage("assets\\pBullet.png");
        enemyImg = loadImage("assets\\enemy.png");
        enemyBulletImg = loadImage("assets\\eBullet.png");
    }

    //Data
    struct ALL_DATA data;
    void loadData() {
        FILE* fp;
        fopen_s(&fp,"data.bin","rb");
        if (fp) {
            fread(&data, sizeof(struct ALL_DATA), 1, fp);
            fclose(fp);
        }
    }

    //Strings
    std::string titleString = "KUNOICHI";
};