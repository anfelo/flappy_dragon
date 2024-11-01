#include "game.h"
#include "raylib.h"
#include "stdlib.h"
#include "time.h"

int main(void) {
    srand(time(NULL));

    int random_num = rand() % (40 - 10 + 1) + 10;
    State state = {
        .mode = MENU,
        .player = {.x = 10, .y = 200, .velocity = 0.0},
        .obstacle = {.x = SCREEN_WIDTH, .size = 200, .gap_y = random_num},
    };
    ObstacleNew(&state.obstacle, state.score);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Dragon");

    SetTargetFPS(60);

    while (!WindowShouldClose() && state.mode != QUIT) {
        UpdateGame(&state);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawGame(&state);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
