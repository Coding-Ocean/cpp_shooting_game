#pragma once
class CHARACTER {
private:
    class GAME* Game=0;
public:
    CHARACTER(class GAME* game);
    virtual ~CHARACTER();
    class GAME* game();
};