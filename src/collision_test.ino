// TODO - turn this file into a .cpp and call it from a main .ino
// TODO - move collision detection into another file. collision detection/handler class?

#include "collision_test.h"

Gamebuino gb;

// Player variables
Player player1;
//PlayerAction XInput = NONE;
//PlayerAction YInput = NONE;

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
	/*getInput();

	handleXInput();
	handleWorldCollisions();
	handleScreenEdgeCollisions();
	
	handleYInput();
	handleWorldCollisions();
	handleScreenEdgeCollisions();*/

	handleInput();
	handleWorldCollisions();
	handleScreenEdgeCollisions();
}

void drawGame()
{
	drawPlayer();
	drawWorld();

	#if DEBUG

	drawDebugInfo();

	#endif
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

/*void getInput()
{
	XInput = NONE;

	if(gb.buttons.repeat(BTN_LEFT, 1))
	{
		XInput = LEFT;
	}
	else if(gb.buttons.repeat(BTN_RIGHT, 1))
	{
		XInput = RIGHT;
	}

	YInput = NONE;

	if(gb.buttons.repeat(BTN_UP, 1))
	{
		YInput = UP;
	}
	else if(gb.buttons.repeat(BTN_DOWN, 1))
	{
		YInput = DOWN;
	}
}

void handleXInput()
{
	player1.move(XInput);
}

void handleYInput()
{
	player1.move(YInput);
}*/

void handleWorldCollisions()
{
	Rectangle playerBoundingBox = player1.getBoundingBox();

	// TODO Seriously, this revert move idea is rubbish.
	//		You need to figure out a valid location to move the player.
	
	if(testChunk.collideWithRectangle(playerBoundingBox))
	{
		player1.revertMove();

		#if DEBUG && SHOW_WHEN_COLLIDED

		gb.display.println("collided");

		#endif
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

#if DEBUG

void drawDebugInfo()
{
	#if SHOW_PLAYER_BOX_COORDS

	Rectangle playerBoundingBox = player1.getBoundingBox();
	signed char top = playerBoundingBox.getTopEdge();
	signed char bottom = playerBoundingBox.getBottomEdge();
	signed char left = playerBoundingBox.getLeftEdge();
	signed char right = playerBoundingBox.getRightEdge();

	gb.display.print(top);
	gb.display.print(" ");
	gb.display.print(bottom);
	gb.display.print(" ");
	gb.display.print(left);
	gb.display.print(" ");
	gb.display.println(right);

	#endif

	#if SHOW_FRAME_COUNT
	
	gb.display.println(gb.frameCount);
	
	#endif
}

#endif