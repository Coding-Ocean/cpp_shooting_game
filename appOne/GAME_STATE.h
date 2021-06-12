#pragma once
class GAME_STATE
{
public:
    enum ID { TITLE, PLAY, OVER, CLEAR, NUM };
    virtual void init(class GAME* game) = 0;
    virtual void proc(class GAME* game) = 0;
};

