#include "obstacle.h"
#include "game.h"
#include "player.h"
#include "raylib.h"
#include "stdlib.h"

void ObstacleUpdate(Obstacle *obstacle) { obstacle->x -= OBSTACLE_SPEED; }

void ObstacleDraw(Obstacle *obstacle, Player *player) {
    int half_size = obstacle->size / 2;

    DrawRectangle(obstacle->x, 0, OBSTACLE_WIDTH, obstacle->gap_y - half_size,
                  RED);
    DrawRectangle(obstacle->x, obstacle->gap_y + half_size, OBSTACLE_WIDTH,
                  SCREEN_HEIGHT, RED);
}

int ObstacleHit(Obstacle *obstacle, Player *player) {
    int half_size = obstacle->size / 2;
    int does_x_match = player->x == obstacle->x;
    int player_above_gap = player->y < obstacle->gap_y - half_size;
    int player_below_gap = player->y > obstacle->gap_y + half_size;
    return does_x_match && (player_above_gap || player_below_gap);
}

void ObstacleNew(Obstacle *obstacle, int score) {
    int random_num = rand() % (400 - 50 + 1) + 50;
    int size = (10 - score) * 10;

    obstacle->x = SCREEN_WIDTH;
    obstacle->size = size < OBSTACLE_MIN_SIZE ? OBSTACLE_MIN_SIZE : size;
    obstacle->gap_y = random_num;
}
