#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include "player.h"

#define OBSTACLE_SPEED 2
#define OBSTACLE_WIDTH 30
#define OBSTACLE_MAX_SIZE 200
#define OBSTACLE_MIN_SIZE 30

typedef struct Obstacle {
    int x;
    int gap_y;
    int size;
} Obstacle;

void ObstacleUpdate(Obstacle* obstacle);
void ObstacleDraw(Obstacle* obstacle, Player* player);
int ObstacleHit(Obstacle* obstacle, Player* player);
void ObstacleNew(Obstacle* obstacle, int score);

#endif
