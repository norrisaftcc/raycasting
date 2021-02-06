#include "player.h"
#include "../global.h"
#include <stdlib.h>

//------------------------------------------------------------------------------------
// Private functions declaration.
//------------------------------------------------------------------------------------
static void initPlayerData(Player_t *const player, Vector2 position);
static void initPlayerRays(Player_t *const player);

//------------------------------------------------------------------------------------
// Public functions implementation.
//------------------------------------------------------------------------------------
Player_t *initPlayer(Vector2 position) {
    Player_t *player = malloc(sizeof(Player_t));
    initPlayerData(player, position);
    return player;
}
void freePlayer(Player_t **ptrPlayer) {
    if (ptrPlayer) {
        freeShape(&(*ptrPlayer)->shapeLine);
        free((*ptrPlayer)->rays);
        (*ptrPlayer)->rays = NULL;
        free(*ptrPlayer);
        *ptrPlayer = NULL;
    }
}

//------------------------------------------------------------------------------------
// Private functions implementation.
//------------------------------------------------------------------------------------
static void initPlayerData(Player_t *const player, Vector2 position) {
    player->position = position;
    player->shapeLine = initShape(SHAPE_LINE);
    player->angle = 0;
    player->angleVel = 0;
    player->velocity = (Vector2){0};
    player->posZ = globalConfig.canvasHeight >> 1;
    initPlayerRays(player);
}
static void initPlayerRays(Player_t *const player) {
    const int32_t nRays = globalConfig.canvasNumRays;
    player->rays = malloc(sizeof(Ray_t) * nRays);
    for (int i=0; i < nRays; ++i) {
        player->rays[i].ptoA = player->position;
        player->rays[i].ptoB = (Vector2){0};
        player->rays[i].angle = 0.0f;
        player->rays[i].angle = 0.0f;
        player->rays[i].color = RAY_COLOR_BASE;
    }
}

