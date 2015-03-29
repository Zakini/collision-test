#include "debug.h"

#if DEBUG

void drawDebugInfo(Player player)
{
	#if SHOW_PLAYER_BOX_COORDS

	Rectangle playerBoundingBox = player.getBoundingBox();
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

void showDebugMessage(char* message)
{
	gb.display.println(message);
}

#endif