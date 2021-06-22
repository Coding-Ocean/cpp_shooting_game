#pragma once
class GAME
{
//�R���e�i
private:
    class CONTAINER* Container = 0;
public:
    class CONTAINER* container();
//�V�[�P���X�J��
public:
    enum STATE_ID{ 
        STATE_TITLE,
        STATE_STAGE,
        STATE_GAME_CLEAR,
        STATE_GAME_OVER,
        STATE_NUM
    };
private:
    class GAME_STATE* GameStates[STATE_NUM];
    STATE_ID CurStateId = STATE_TITLE;
public:
    void changeGameState(STATE_ID state);
//�L�����N�^
private:
    class PLAYER* Player = 0;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMIES* Enemies = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
public:
    void draw();
    class PLAYER* player();
    class PLAYER_BULLETS* playerBullets();
    class ENEMIES* enemies();
    class ENEMY_BULLETS* enemyBullets();
//�Q�[���}�l�[�W���[
public:
    GAME();
    ~GAME();
    void run();
};
