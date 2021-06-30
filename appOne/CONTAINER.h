#pragma once
//#define _BIN_
#include"graphic.h"
#include"ALL_DATA.h"
class CONTAINER {
    struct ALL_DATA Data;
public:
    const ALL_DATA* data()const { return &Data; }
    void load() {
#ifdef _BIN_
        loadData();
#else
        setData();
#endif
        loadGraphics();
    }
private:
#ifdef _BIN_
    void loadData() {
        FILE* fp;
        fopen_s(&fp,"assets\\data.bin","rb");
        if (fp) {
            fread(&Data, sizeof(struct ALL_DATA), 1, fp);
            fclose(fp);
        }
    }
#else
    void setData() {
        Data.title.backColor.r = 20;
        Data.title.backColor.g = 20;
        Data.title.backColor.b = 20;
        Data.title.textColor.r = 0;
        Data.title.textColor.g = 255;
        Data.title.textColor.b = 0;
        Data.title.px = 0;
        Data.title.py = 700;
        Data.title.textSize = 490;
        strcpy_s(Data.title.string, "KUNOICHI");

        Data.stageBackColor.r = 50;
        Data.stageBackColor.g = 50;
        Data.stageBackColor.b = 50;

        Data.player.pos.x = 960;
        Data.player.pos.y = 975;
        Data.player.angle = 0;
        Data.player.advSpeed = 300;
        Data.player.launchVec.x = 0;
        Data.player.launchVec.y = -1;
        Data.player.triggerElapsedTime = 0.1f;
        Data.player.triggerInterval = 0.1f;
        Data.player.bcRadius = 40;
        Data.player.invincibleTime = 0.05f;
        Data.player.collisionColor.r = 255;
        Data.player.collisionColor.g = 0;
        Data.player.collisionColor.b = 0;
        Data.player.normalColor.r = 255;
        Data.player.normalColor.g = 255;
        Data.player.normalColor.b = 255;
        Data.player.hp = 5;
        Data.player.hpGaugeOffset.x = 0;
        Data.player.hpGaugeOffset.y = -120;
        Data.player.posForTitle.x = 859;
        Data.player.posForTitle.y = 520;

        Data.enemy.totalNum = 8;
        Data.enemy.triggerInterval = 0.72f;
        Data.enemy.centerPos.x = 960;
        Data.enemy.centerPos.y = -300;
        Data.enemy.majRadius = 800;
        Data.enemy.minRadius = 100;
        Data.enemy.fallSpeedY = 60;
        Data.enemy.arrivalY = 300;
        Data.enemy.refTheta = 0;
        Data.enemy.refThetaSpeed = 0.6f;
        Data.enemy.invincibleTime = 0.05f;
        Data.enemy.bcRadius = 90;
        Data.enemy.hp = 5;
        Data.enemy.hpGaugeOffset.x = -10;
        Data.enemy.hpGaugeOffset.y = -120;
        Data.enemy.collisionColor.r = 255;
        Data.enemy.collisionColor.g = 0;
        Data.enemy.collisionColor.b = 0;
        Data.enemy.normalColor.r = 255;
        Data.enemy.normalColor.g = 255;
        Data.enemy.normalColor.b = 255;
        Data.enemy.normalColor.a = 200;

        Data.playerBullet.advSpeed = 600;
        Data.playerBullet.angSpeed = 0.05f;
        Data.playerBullet.ofstLaunchDist = 100;
        Data.playerBullet.bcRadius = 20;
        Data.playerBullet.totalNum = 20;
        Data.playerBullet.curNum = 0;

        Data.enemyBullet.advSpeed = 600;
        Data.enemyBullet.angSpeed = 0;
        Data.enemyBullet.ofstLaunchDist = 90;
        Data.enemyBullet.bcRadius = 30;
        Data.enemyBullet.totalNum = 20;
        Data.enemyBullet.curNum = 0;

        //create binary file
        FILE* fp;
        fopen_s(&fp, "assets\\Data.bin", "wb");
        if (fp) {
            fwrite(&Data, sizeof(ALL_DATA), 1, fp);
            fclose(fp);
        }
    }
#endif
    void loadGraphics() {
        Data.player.img = loadImage("assets\\player.png");
        Data.playerBullet.img = loadImage("assets\\pBullet.png");
        Data.enemy.img = loadImage("assets\\enemy.png");
        Data.enemyBullet.img = loadImage("assets\\eBullet.png");
    }
};