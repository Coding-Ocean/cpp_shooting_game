#pragma once
class ENEMIES
{
private:
    struct DATA {
        float px = 0, py = 0, angle = 0;
    };
    struct DATA* Data=0;
    float Theta = 0;
    int Img = 0;
    int Num = 0;

    //launch bullet
    int TriggerCnt;
    int TriggerInterval;

public:
    ENEMIES();
    ~ENEMIES();
    void create(int img);
    void destroy();
    void init(class GAME* game);
    void move(class GAME* game);
    void launch(class BULLETS* bullets, class CHARACTER* target);
    void draw();
    int num() { return Num; }
    float px(int i) { return Data[i].px; }
    float py(int i) { return Data[i].py; }
};

