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
    enum STATE { STATE_TITLE, STATE_PLAY, STATE_NUM };
    void changeGameState(STATE state);
private:
    class GAME_STATE* GameStates[STATE_NUM];
    STATE CurState = STATE_TITLE;
//�L�����N�^
private:
    class CHARACTER* Player = 0;
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
