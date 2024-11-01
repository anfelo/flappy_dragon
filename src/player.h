#ifndef PLAYER_H_
#define PLAYER_H_

#define PLAYER_SIZE 20

typedef struct Player {
    int x;
    int y;
    float velocity;
} Player;

void PlayerUpdate(Player* state);
void PlayerDraw(Player* state);

#endif
