#pragma once
//#define _BIN_
#include"graphic.h"
#include"CONTAINER.h"
CONTAINER::~CONTAINER() {
    delete[] Data.explosion.imgs;
}
void CONTAINER::load() {
#ifdef _BIN_
    LoadData();
#else
    SetData();
#endif
    LoadGraphics();
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
void CONTAINER::SetData() {
    Data.game.firstSceneId = GAME::TITLE_ID;
    Data.game.changeSceneKey = KEY_Z;

    Data.titleScene.backColor = COLOR(0, 30, 0);
    Data.titleScene.textColor = COLOR(0, 255, 0);
    Data.titleScene.textSize = 450;
    strcpy_s(Data.titleScene.string, "KUNOICHI");
    Data.titleScene.pos = calcPos(Data.titleScene.string, Data.titleScene.textSize);
    Data.titleScene.transSpeed = 102;

    Data.stageClearScene.backColor = COLOR(50, 50, 50);
    Data.stageClearScene.textColor = COLOR(255, 200, 200);
    Data.stageClearScene.textSize = 120;
    strcpy_s(Data.stageClearScene.string, "ステージクリア");
    Data.stageClearScene.pos = calcPos(Data.stageClearScene.string, Data.stageClearScene.textSize);

    //STAGE独自の追加データ
    Data.stage.stageNum = 8;
    Data.stage.stageCnt = 1;
    strcpy_s(Data.stage.startPreMsg1, "あと");
    strcpy_s(Data.stage.startMsg1, "ステージ");
    strcpy_s(Data.stage.startMsg2, "最後のステージ");
    //STAGE・ SCENE基底クラスのデータ
    Data.stageScene.backColor = COLOR(50, 50, 50);
    Data.stageScene.textColor = COLOR(0, 255, 255, 255);
    Data.stageScene.textSize = 200;
    Data.stageScene.transSpeed = 102;

    Data.gameClearScene.backColor = COLOR(60, 60, 0);
    Data.gameClearScene.textColor = COLOR(255, 255, 0);
    Data.gameClearScene.textSize = 370;
    strcpy_s(Data.gameClearScene.string, "GAME CLEAR");
    Data.gameClearScene.pos = calcPos(Data.gameClearScene.string, Data.gameClearScene.textSize);

    Data.gameOverScene.backColor = COLOR(60, 0, 0);
    Data.gameOverScene.textColor = COLOR(255, 0, 0);
    Data.gameOverScene.textSize = 370;
    strcpy_s(Data.gameOverScene.string, "GAME OVER");
    Data.gameOverScene.pos = calcPos(Data.gameOverScene.string, Data.gameOverScene.textSize);

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
    Data.player.posForTitle.x = 849;
    Data.player.posForTitle.y = 490;
    //for game clear
    Data.player.angSpeed = 12;
    Data.player.standingRestTime = 0;
    Data.player.standingTime = 0.6f;
    Data.player.triggerInterval2 = 0.02f;
    Data.player.launchAngle = 0;
    Data.player.launchAngleSpeed = 3.1415926f/180*25;
    //for game over
    Data.player.fallSpeed = 120;
    Data.player.fallLimmit = 1050;
    Data.player.rollingSpeed = 2.4f;
    Data.player.rollingLimmit = 1.2f;

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

    Data.playerBullet.totalNum = 36;
    Data.playerBullet.curNum = 0;
    Data.playerBullet.advSpeed = 600;
    Data.playerBullet.angSpeed = 0.05f;
    Data.playerBullet.ofstLaunchDist = 100;
    Data.playerBullet.bcRadius = 20;

    Data.enemyBullet.totalNum = 24;
    Data.enemyBullet.curNum = 0;
    Data.enemyBullet.advSpeed = 600;
    Data.enemyBullet.angSpeed = 0;
    Data.enemyBullet.ofstLaunchDist = 90;
    Data.enemyBullet.bcRadius = 30;

    Data.hpGauge.color = COLOR(0, 255, 0);
    Data.hpGauge.danger = COLOR(255, 0, 0);
    Data.hpGauge.coWidth = 30;
    Data.hpGauge.h = 15;

    Data.explosion.totalNum = 4;
    Data.explosion.curNum = 0;
    Data.explosion.interval = 0.048f;
    Data.explosion.numImgs = 48;
    Data.explosion.imgs = new int[Data.explosion.numImgs];
    Data.explosion.startIdx = 24;
    Data.explosion.color = COLOR(255, 255, 255, 210);
    Data.explosion.scale = 10;

Data.stage.stageNum = 8;
Data.stage.stageCnt = 7;
Data.enemy.totalNum = 8;
//Data.enemy.hp = 1;
Data.player.invincibleTime = 5;

    //create binary file
    FILE* fp;
    fopen_s(&fp, "assets\\Data.bin", "wb");
    if (fp) {
        fwrite(&Data, sizeof(ALL_DATA), 1, fp);
        fclose(fp);
    }
}
#endif

void CONTAINER::LoadGraphics() {
    Data.player.img = loadImage("assets\\player.png");
    Data.playerBullet.img = loadImage("assets\\pBullet.png");
    Data.enemy.img = loadImage("assets\\enemy.png");
    Data.enemyBullet.img = loadImage("assets\\eBullet.png");
    char filename[64];
    for (int i = 0; i < Data.explosion.numImgs; i++) {
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        Data.explosion.imgs[i] = loadImage(filename);
    }
}
