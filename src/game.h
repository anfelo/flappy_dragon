#ifndef GAME_H_
#define GAME_H_

#include "obstacle.h"
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

typedef enum GameMode {
    MENU,
    PLAYING,
    DEAD,
    QUIT,
} GameMode;

typedef struct State {
    GameMode mode;
    Player player;
    Obstacle obstacle;
    int score;
} State;

void UpdateGame(State* state);
void DrawGame(State* state);
void UpdateGameMode(State* state, GameMode new_mode);

#endif
