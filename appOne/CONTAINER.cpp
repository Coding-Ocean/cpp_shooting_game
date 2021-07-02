#pragma once
//#define _BIN_
#include"graphic.h"
#include"CONTAINER.h"

void CONTAINER::load() {
#ifdef _BIN_
    loadData();
#else
    setData();
#endif
    loadGraphics();
}

#ifdef _BIN_
void CONTAINER::loadData() {
    FILE* fp;
    fopen_s(&fp, "assets\\data.bin", "rb");
    if (fp) {
        fread(&Data, sizeof(struct ALL_DATA), 1, fp);
        fclose(fp);
    }
}
#else
VECTOR2 CONTAINER::calcPos(const char* str, float size) {
    size_t len = strlen(str);
    float px = (width - size / 2 * len) / 2;
    float py = (height - size) / 2 - 100;
    return VECTOR2(px, py);
}
void CONTAINER::setData() {

    Data.title.backColor = COLOR(0, 30, 0);
    Data.title.textColor = COLOR(0, 255, 0);
    Data.title.textSize = 400;
    strcpy_s(Data.title.string, "KUNOICHI");
    Data.title.pos = calcPos(Data.title.string, Data.title.textSize);

    Data.stageClear.backColor = COLOR(50, 50, 50);
    Data.stageClear.textColor = COLOR(255, 200, 200);
    Data.stageClear.textSize = 200;
    strcpy_s(Data.stageClear.string, "ステージクリア");
    Data.stageClear.pos = calcPos(Data.stageClear.string, Data.stageClear.textSize);

    Data.stage.stageNum = 8;
    Data.stage.stageCnt = 7;
    Data.stageScene.backColor = COLOR(50, 50, 50);
    Data.stageScene.textColor = COLOR(0, 255, 255, 255);
    Data.stageScene.textSize = 200;
    Data.stageScene.transSpeed = 102;

    Data.gameClear.backColor = COLOR(60, 60, 0);
    Data.gameClear.textColor = COLOR(255, 255, 0);
    Data.gameClear.textSize = 370;
    strcpy_s(Data.gameClear.string, "GAME CLEAR");
    Data.gameClear.pos = calcPos(Data.gameClear.string, Data.gameClear.textSize);

    Data.gameOver.backColor = COLOR(60, 0, 0);
    Data.gameOver.textColor = COLOR(255, 0, 0);
    Data.gameOver.textSize = 370;
    strcpy_s(Data.gameOver.string, "GAME OVER");
    Data.gameOver.pos = calcPos(Data.gameOver.string, Data.gameOver.textSize);

    Data.player.pos.x = 960;
    Data.player.pos.y = 975;
    Data.player.angle = 0;
    Data.player.advSpeed = 300;
    Data.player.limmitRange = 100;
    Data.player.launchVec.x = 0;
    Data.player.launchVec.y = -1;
    Data.player.triggerElapsedTime = 0.1f;
    Data.player.triggerInterval = 0.1f;
    Data.player.bcRadius = 40;
    Data.player.invincibleTime = 0.05f;
    Data.player.collisionColor = COLOR(255, 0, 0);
    Data.player.normalColor = COLOR(255, 255, 255);
    Data.player.hp = 5;
    Data.player.hpGaugeOffset.x = 0;
    Data.player.hpGaugeOffset.y = -120;
    Data.player.posForTitle.x = 859;
    Data.player.posForTitle.y = 520;

    Data.hpGauge.color = COLOR(0, 255, 0);
    Data.hpGauge.danger = COLOR(255, 0, 0);
    Data.hpGauge.coWidth = 30;
    Data.hpGauge.h = 15;

    Data.enemy.totalNum = 8;
    Data.enemy.triggerInterval = 0.72f;
    Data.enemy.centerPos.x = 960;
    Data.enemy.centerPos.y = -300;
    Data.enemy.majRadius = 800;
    Data.enemy.minRadius = 100;
    Data.enemy.fallSpeedY = 120;
    Data.enemy.arrivalY = 300;
    Data.enemy.refTheta = 0;
    Data.enemy.refThetaSpeed = 0.6f;
    Data.enemy.invincibleTime = 0.05f;
    Data.enemy.bcRadius = 90;
    Data.enemy.hp = 5;
    Data.enemy.hpGaugeOffset.x = -10;
    Data.enemy.hpGaugeOffset.y = -120;
    Data.enemy.collisionColor = COLOR(255, 0, 0, 200);
    Data.enemy.normalColor = COLOR(255, 255, 255, 200);

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

void CONTAINER::loadGraphics() {
    Data.player.img = loadImage("assets\\player.png");
    Data.playerBullet.img = loadImage("assets\\pBullet.png");
    Data.enemy.img = loadImage("assets\\enemy.png");
    Data.enemyBullet.img = loadImage("assets\\eBullet.png");
}
