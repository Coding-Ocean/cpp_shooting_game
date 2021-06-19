#pragma once
class CHARACTER {
private:
    class GAME* Game=0;
public:
    CHARACTER(class GAME* game);
    virtual ~CHARACTER();
    virtual void initOnce() = 0;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    class GAME* game();
};