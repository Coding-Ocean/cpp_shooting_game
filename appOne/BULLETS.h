#pragma once
class BULLETS
{
public:
    virtual void launch(float px, float py, float vx, float vy) = 0;
    virtual void move() = 0;
};

