#include "game.h"
#include "obstacle.h"
#include "player.h"
#include "raylib.h"
#include <stdio.h>

void UpdateGame(State *state) {
    switch (state->mode) {
    case MENU:
        if (IsKeyDown(KEY_P)) {
            UpdateGameMode(state, PLAYING);
        } else if (IsKeyDown(KEY_Q)) {
            UpdateGameMode(state, QUIT);
        }
        break;
    case PLAYING:
        PlayerUpdate(&state->player);
        ObstacleUpdate(&state->obstacle);

        if (state->player.y > SCREEN_HEIGHT ||
            ObstacleHit(&state->obstacle, &state->player) == 1) {
            UpdateGameMode(state, DEAD);
        }

        if (state->player.x > state->obstacle.x) {
            state->score += 1;
            ObstacleNew(&state->obstacle, state->score);
        }
        break;
    case DEAD:
        if (IsKeyDown(KEY_P)) {
            state->player.x = 10;
            state->player.y = 200;
            state->score = 0;
            ObstacleNew(&state->obstacle, state->score);

            UpdateGameMode(state, PLAYING);
        } else if (IsKeyDown(KEY_Q)) {
            UpdateGameMode(state, QUIT);
        }
        break;
    case QUIT:
        // INFO: Nothing to see here
        break;
    }
}

void UpdateGameMode(State *state, GameMode new_mode) { state->mode = new_mode; }

void DrawGame(State *state) {
    switch (state->mode) {
    case MENU:
        DrawText("Welcome to Flappy Dragon", 260, 160, 20, LIGHTGRAY);
        DrawText("(P) Play Game", 320, 180, 20, LIGHTGRAY);
        DrawText("(Q) Quit Game", 320, 200, 20, LIGHTGRAY);
        break;
    case PLAYING:
        DrawText("Press SPACE to flap.", 10, 10, 14, LIGHTGRAY);
        char score_txt[20];
        sprintf(score_txt, "Score: %d", state->score);
        DrawText(score_txt, 10, 25, 14, LIGHTGRAY);

        PlayerDraw(&state->player);
        ObstacleDraw(&state->obstacle, &state->player);
        break;
    case DEAD:
        DrawText("You are dead!", 320, 160, 20, LIGHTGRAY);

        DrawText("(P) Play Again", 320, 180, 20, LIGHTGRAY);
        DrawText("(Q) Quit Game", 320, 200, 20, LIGHTGRAY);
        break;
    case QUIT:
        // INFO: Nothing to see here
        break;
    }
}
