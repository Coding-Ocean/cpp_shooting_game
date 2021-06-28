#pragma once
#include"DATABASE.h"
#include"ALL_DATA.h"
class CREATE_BIN
{
public:
    struct ALL_DATA data;
    void createBinary() {
        DATABASE db("data.txt");
        data.title.backColor.r = db.data("data.title.backColor.r");
        data.title.backColor.g = db.data("data.title.backColor.g");
        data.title.backColor.b = db.data("data.title.backColor.b");
        data.title.textColor.r = db.data("data.title.textColor.r");
        data.title.textColor.g = db.data("data.title.textColor.g");
        data.title.textColor.b = db.data("data.title.textColor.b");
        data.title.px = db.data("data.title.px");
        data.title.py = db.data("data.title.py");
        data.title.textSize = db.data("data.title.textSize");
        strcpy_s(data.title.string, db.data("data.title.string"));
        data.stageBackColor.r = db.data("data.stageBackColor.r");
        data.stageBackColor.g = db.data("data.stageBackColor.g");
        data.stageBackColor.b = db.data("data.stageBackColor.b");
        data.playerHp = db.data("data.playerHp");
        data.numEnemies = db.data("data.numEnemies");

        data.title.backColor.r = 20;
        data.title.backColor.g = 20;
        data.title.backColor.b = 20;
        data.title.textColor.r = 0;
        data.title.textColor.g = 255;
        data.title.textColor.b = 0;
        data.title.px = 0;
        data.title.py = 700;
        data.title.textSize = 490;
        data.stageBackColor.r = 60;
        data.stageBackColor.g = 60;
        data.stageBackColor.b = 60;
        //create binary file
        FILE* fp;
        fopen_s(&fp, "data.bin", "wb");
        if (fp) {
            fwrite(&data, sizeof(ALL_DATA), 1, fp);
            fclose(fp);
        }
    }
};

