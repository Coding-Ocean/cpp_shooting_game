#pragma once
#include"DATABASE.h"
#include"ALL_DATA.h"
class CREATE_BIN
{
public:
    struct ALL_DATA data;
    void createBinaryData() {

        DATABASE db("data.txt");

        data.title.backColor.r          = db.data("data.title.backColor.r");
        data.title.backColor.g          = db.data("data.title.backColor.g");
        data.title.backColor.b          = db.data("data.title.backColor.b");
        data.title.textColor.r          = db.data("data.title.textColor.r");
        data.title.textColor.g          = db.data("data.title.textColor.g");
        data.title.textColor.b          = db.data("data.title.textColor.b");
        data.title.px                   = db.data("data.title.px");
        data.title.py                   = db.data("data.title.py");
        data.title.textSize             = db.data("data.title.textSize");
        strcpy_s(data.title.string, db.data("data.title.string"));

        data.stageBackColor.r           = db.data("data.stageBackColor.r");
        data.stageBackColor.g           = db.data("data.stageBackColor.g");
        data.stageBackColor.b           = db.data("data.stageBackColor.b");

        data.player.advSpeed            = db.data("data.player.advSpeed");
        data.player.triggerElapsedTime  = db.data("data.player.triggerElapsedTime");
        data.player.triggerInterval     = db.data("data.player.triggerInterval");
        data.player.bcRadius            = db.data("data.player.bcRadius");
        data.player.invincibleTime      = db.data("data.player.invincibleTime");
        data.player.pos.x               = db.data("data.player.pos.x");
        data.player.pos.y               = db.data("data.player.pos.y");
        data.player.angle               = db.data("data.player.angle");
        data.player.hp                  = db.data("data.player.hp");
        data.player.launchVec.x         = db.data("data.player.launchVec.x");
        data.player.launchVec.y         = db.data("data.player.launchVec.y");
        data.player.collisionColor.r    = db.data("data.player.collisionColor.r");
        data.player.collisionColor.g    = db.data("data.player.collisionColor.g");
        data.player.collisionColor.b    = db.data("data.player.collisionColor.b");
        data.player.normalColor.r       = db.data("data.player.normalColor.r");
        data.player.normalColor.g       = db.data("data.player.normalColor.g");
        data.player.normalColor.b       = db.data("data.player.normalColor.b");
        data.player.hpGaugeOffset.x     = db.data("data.player.hpGaugeOffset.x");
        data.player.hpGaugeOffset.y     = db.data("data.player.hpGaugeOffset.y");
        data.player.titlePos.x          = db.data("data.player.titlePos.x");
        data.player.titlePos.y          = db.data("data.player.titlePos.y");

        data.playerBullet.advSpeed      = db.data("data.playerBullet.advSpeed");
        data.playerBullet.angSpeed      = db.data("data.playerBullet.angSpeed");
        data.playerBullet.ofstLaunchDist= db.data("data.playerBullet.ofstLaunchDist");
        data.playerBullet.bcRadius      = db.data("data.playerBullet.bcRadius");
        data.playerBullet.totalNum      = db.data("data.playerBullet.totalNum");
        data.playerBullet.curNum        = db.data("data.playerBullet.curNum");

        data.enemy.totalNum             = db.data("data.enemy.totalNum");
        data.enemy.triggerInterval      = db.data("data.enemy.triggerInterval");
        data.enemy.majRadius            = db.data("data.enemy.majRadius");
        data.enemy.minRadius            = db.data("data.enemy.minRadius");
        data.enemy.invincibleTime       = db.data("data.enemy.invincibleTime");
        data.enemy.bcRadius             = db.data("data.enemy.bcRadius");
        data.enemy.hp                   = db.data("data.enemy.hp");
        data.enemy.centerPos.x          = db.data("data.enemy.centerX");
        data.enemy.centerPos.y          = db.data("data.enemy.centerY");

        data.enemyBullet.advSpeed       = db.data("data.enemyBullet.advSpeed");
        data.enemyBullet.angSpeed       = db.data("data.enemyBullet.angSpeed");
        data.enemyBullet.ofstLaunchDist = db.data("data.enemyBullet.ofstLaunchDist");
        data.enemyBullet.bcRadius       = db.data("data.enemyBullet.bcRadius");
        data.enemyBullet.totalNum       = db.data("data.enemyBullet.totalNum");
        data.enemyBullet.curNum         = db.data("data.enemyBullet.curNum");

        //create binary file
        FILE* fp;
        fopen_s(&fp, "data.bin", "wb");
        if (fp) {
            fwrite(&data, sizeof(ALL_DATA), 1, fp);
            fclose(fp);
        }
    }
};

