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
void CONTAINER::LoadData() {
    FILE* fp;
    fopen_s(&fp, "assets\\data.bin", "rb");
    if (fp) {
        fread(&Data, sizeof(struct ALL_DATA), 1, fp);
        fclose(fp);
    }
}
#else
void CONTAINER::SetData() {
    Data.game.firstSceneId = GAME::TITLE_ID;
    Data.game.changeSceneKey = KEY_Z;

    Data.titleScene.backColor = COLOR(0, 50, 0);
    Data.titleScene.message.setColor( COLOR(0, 255, 0));
    Data.titleScene.message.setSize(450);
    Data.titleScene.message.setString("KUNOICHI");
    Data.titleScene.message.calcPosDispCenter();
    Data.titleScene.message.setFadeInSpeed(102);

    //STAGEì∆é©ÇÃí«â¡ÉfÅ[É^
    Data.stage.num = 8;
    Data.stage.no = 1;
    //STAGEÇÃSCENEäÓíÍÉNÉâÉXÇÃÉfÅ[É^
    Data.stageScene.backColor = COLOR(0, 0, 50);
    Data.stageScene.message.setColor(COLOR(0, 255, 255, 255));
    Data.stageScene.message.setSize(200);
    Data.stageScene.message.setFadeInSpeed(204);
    Data.stageScene.message.setFadeOutSpeed(102);
    Data.stageScene.message.setPreMsg("îCñ±ÇÕÇ†Ç∆");
    Data.stageScene.message.setSufMsg("Ç¬");
    Data.stageScene.message.setLastMsg("ç≈å„ÇÃîCñ±");

    Data.stageClearScene.backColor = COLOR(0, 0, 50);
    Data.stageClearScene.message.setColor(COLOR(255, 200, 200));
    Data.stageClearScene.message.setSize(120);
    Data.stageClearScene.message.calcPosDispCenter();
    Data.stageClearScene.message.setFadeInSpeed(500);
    Data.stageClearScene.message.setPreMsg("Åuë¥Ém");
    Data.stageClearScene.message.setSufMsg("ÅväÆ");

    Data.gameClearScene.backColor = COLOR(60, 60, 0);
    Data.gameClearScene.message.setColor(COLOR(255, 255, 0));
    Data.gameClearScene.message.setSize(370);
    Data.gameClearScene.message.setString("îCñ±äÆóπ");
    Data.gameClearScene.message.calcPosDispCenter();
    Data.gameClearScene.message.setInitPosY(height);
    Data.gameClearScene.message.setVecY(-300);

    Data.gameOverScene.backColor = COLOR(60, 0, 0);
    Data.gameOverScene.message.setColor(COLOR(255, 0, 0));
    Data.gameOverScene.message.setSize(500);
    Data.gameOverScene.message.setString("é∏îs");
    Data.gameOverScene.message.calcPosDispCenter();
    Data.gameOverScene.message.setFadeInSpeed(102);

    Data.player.pos = VECTOR2(960, 975);
    Data.player.angle = 0;
    Data.player.advSpeed = 300;
    Data.player.limmitRange = 100;
    Data.player.launchVec = VECTOR2(0,-1);
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
    Data.player.triggerInterval2 = 0.03f;
    Data.player.launchAngle = 0;
    Data.player.launchAngleSpeed = 3.1415926f/180*25;
    //for game over
    Data.player.fallSpeed = 120;
    Data.player.fallLimmit = 1050;
    Data.player.rollingSpeed = 2.4f;
    Data.player.rollingLimmit = 1.2f;
    Data.player.changeRedColorSpeed = -255;
    Data.player.changeGreenColorSpeed = 255;

    Data.enemy.totalNum = 8;
    Data.enemy.triggerInterval = 0.7f;
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

    Data.playerBullet.totalNum = 40;
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

    Data.hpGauge.hp = 0;
    Data.hpGauge.green = COLOR(0, 255, 0);
    Data.hpGauge.yellow = COLOR(255, 255, 0);
    Data.hpGauge.red = COLOR(255, 0, 0);
    Data.hpGauge.coWidth = 30;
    Data.hpGauge.hi = 15;
    Data.hpGauge.warningHp = 2;
    Data.hpGauge.dangerHp = 1;

    Data.explosion.totalNum = 4;
    Data.explosion.curNum = 0;
    Data.explosion.interval = 0.048f;
    Data.explosion.numImgs = 48;
    Data.explosion.imgs = 0;
    Data.explosion.startIdx = 24;
    Data.explosion.color = COLOR(255, 255, 255, 255);
    Data.explosion.scale = 10;

    //create binary file
    FILE* fp;
    fopen_s(&fp, "assets\\data.bin", "wb");
    if (fp) {
        fwrite(&Data, sizeof(ALL_DATA), 1, fp);
        fclose(fp);
    }

//Data.game.changeSceneKey = KEY_J;
//Data.stage.stageNum = 10;
//Data.stage.stageNo = 8;
//Data.enemy.totalNum = 10;
//Data.enemy.hp = 1;
//Data.player.hp = 1;
//Data.player.invincibleTime = 5;
}
#endif

void CONTAINER::LoadGraphics() {
    Data.player.img = loadImage("assets\\player.png");
    Data.playerBullet.img = loadImage("assets\\pBullet.png");
    Data.enemy.img = loadImage("assets\\enemy.png");
    Data.enemyBullet.img = loadImage("assets\\eBullet.png");

    Data.explosion.imgs = new int[Data.explosion.numImgs];
    char filename[64];
    for (int i = 0; i < Data.explosion.numImgs; i++) {
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        Data.explosion.imgs[i] = loadImage(filename);
    }
}
