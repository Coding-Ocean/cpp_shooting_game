#pragma once
#include"ALL_DATA.h"
class CREATE_BIN
{
public:
    struct ALL_DATA data;
    void createBinary() {
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

