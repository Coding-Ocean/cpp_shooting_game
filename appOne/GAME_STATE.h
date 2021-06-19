#pragma once
class GAME_STATE
{
private:
    class GAME* Game = 0;
public:
    GAME_STATE(class GAME* game);
    virtual ~GAME_STATE();
    virtual void init() = 0;
    virtual void proc() = 0;
    //getter
    class GAME* game();
};

