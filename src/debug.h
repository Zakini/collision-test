#ifndef DEBUG_H
#define DEBUG_H

#include "collision_test_globals.h"
#include "rectangle.h"
#include "player.h"

#if DEBUG

#define SHOW_PLAYER_BOX_COORDS true
#define SHOW_FRAME_COUNT true
#define SHOW_WHEN_COLLIDED true

void drawDebugInfo(Player player);
void showDebugMessage(char* message);

#else

// If DEBUG == false, replace with blank
#define drawDebugInfo(x)
#define showDebugMessage(x)

#endif

#endif