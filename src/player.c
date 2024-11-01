#include "player.h"
#include "raylib.h"

void PlayerUpdate(Player* player) {
    if (player->velocity < 2.0f) {
        player->velocity += 0.2f;
    }

    player->y += (int)player->velocity;

    if (player->y < 0) {
        player->y = 0;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        player->velocity = -2.0f;
    }
}
void PlayerDraw(Player* player) {
    DrawRectangle(player->x, player->y, PLAYER_SIZE, PLAYER_SIZE, YELLOW);
}
