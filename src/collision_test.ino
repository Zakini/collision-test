// TODO - turn this file into a .cpp and call it from a main .ino
// TODO - move collision detection into another file. collision detection/handler class?

#include "collision_test.h"

Gamebuino gb;

// Player variables
Player player1;

// World variables
byte world[9] = {
	B00000010
,	B00000000
,	B00010000
,	B00011000
,	B00010000
,	B00000000
,	B00000000
,	B00000000
,	B00000000
};
Chunk testChunk = 0;

void setup()
{
	gb.begin();
	initialise();
	showTitleScreen();
}

void loop()
{
	if(gb.update())
	{
		updateGame();
		drawGame();
	}
}

void initialise()
{
	player1 = Player(INITIAL_PLAYER_X, INITIAL_PLAYER_Y);
	testChunk = Chunk(world);
	gb.display.setColor(BLACK);
}

void showTitleScreen()
{
	gb.titleScreen(F("Collision Test"));
}

void updateGame()
{
	handleInput();
	handleWorldCollisions();
	handleScreenEdgeCollisions();
}

void drawGame()
{
	drawPlayer();
	drawWorld();

	drawDebugInfo(player1);
}

void handleInput()
{
	if(gb.buttons.repeat(BTN_LEFT, 1))
	{
		player1.move(LEFT);
	}
	else if(gb.buttons.repeat(BTN_RIGHT, 1))
	{
		player1.move(RIGHT);
	}

	if(gb.buttons.repeat(BTN_UP, 1))
	{
		player1.move(UP);
	}
	else if(gb.buttons.repeat(BTN_DOWN, 1))
	{
		player1.move(DOWN);
	}
}

void handleWorldCollisions()
{
	Rectangle playerBoundingBox = player1.getBoundingBox();

	// TODO Seriously, this revert move idea is rubbish.
	//		You need to figure out a valid location to move the player.
	
	if(testChunk.collideWithRectangle(playerBoundingBox))
	{
		player1.revertMove();
		
		showDebugMessage("collided");
	}
}

void handleScreenEdgeCollisions()
{
	signed char currentPlayerX = player1.getX();
	signed char currentPlayerY = player1.getY();

	if(currentPlayerX < 0)
	{
		player1.setX(0);
	}
	else if((currentPlayerX + PLAYER_WIDTH) > LCDWIDTH)
	{
		player1.setX(LCDWIDTH - PLAYER_WIDTH);
	}

	if(currentPlayerY < 0)
	{
		player1.setY(0);
	}
	else if((currentPlayerY + PLAYER_HEIGHT) > LCDHEIGHT)
	{
		player1.setY(LCDHEIGHT - PLAYER_HEIGHT);
	}
}

void drawPlayer()
{
	player1.render();
}

void drawWorld()
{
	testChunk.render();
}