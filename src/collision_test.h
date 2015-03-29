#ifndef COLLISION_TEST_H
#define COLLISION_TEST_H

#include "collision_test_globals.h"
#include "player.h"
#include "chunk.h"
#include "debug.h"

// Player variables
const byte INITIAL_PLAYER_X = 0;
const byte INITIAL_PLAYER_Y = 0;
extern Player player1;
//extern PlayerAction XInput;
//extern PlayerAction YInput;

// World variables
extern byte world[9];
extern Chunk testChunk;

void initialise();
void showTitleScreen();
void updateGame();
void drawGame();
/*void getInput();
void handleXInput();
void handleYInput();*/
void handleInput();
void handleWorldCollisions();
void handleScreenEdgeCollisions();
void drawPlayer();
void drawWorld();

#endif