#ifndef PLAYER_H
#define PLAYER_H

#include "collision_test_globals.h"
#include "rectangle.h"

const byte PLAYER_WIDTH = 8;
const byte PLAYER_HEIGHT = 8;

// TODO - make this an enum
typedef char PlayerAction;
const PlayerAction LEFT = 'L';
const PlayerAction RIGHT = 'R';
const PlayerAction UP = 'U';
const PlayerAction DOWN = 'D';
//const PlayerAction NONE = 'N';

class Player
{
private:
	// TODO - use points
	signed char _playerX;
	signed char _playerY;
	signed char _previousX;
	signed char _previousY;
	unsigned long _framePosWasStored;

public:
	Player();
	Player(signed char playerX, signed char playerY);
	signed char getX();
	signed char getY();
	Rectangle getBoundingBox();
	void setX(signed char value);
	void setY(signed char value);
	void move(PlayerAction action);
	void pushPosState();
	void revertMove();
	void render();
};

#endif