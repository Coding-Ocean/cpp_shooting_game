#pragma once
class CHARACTER {
private:
    class GAME* Game=0;
public:
    CHARACTER(class GAME* game);
    virtual ~CHARACTER();
    class GAME* game();
    virtual void prepare() = 0;
    virtual void start() = 0;
    virtual void move() = 0;
    virtual void isDrawn() = 0;
};