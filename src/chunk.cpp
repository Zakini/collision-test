#include "chunk.h"

Chunk::Chunk(byte* blocks)
{
	_chunkX = 0;
	_chunkY = 0;
	_blocks = blocks;
}

Chunk::Chunk(byte chunkX, byte chunkY, byte* blocks)
{
	_chunkX = chunkX;
	_chunkY = chunkY;
	_blocks = blocks;
}

byte Chunk::collide(Rectangle rect, Vector* collisionResults)
{
	// Get blocks that could be colliding
	Rectangle chunkFootprint;
	chunkFootprint.setLeftEdge(rect.getLeftEdge() / BLOCK_WIDTH);
	chunkFootprint.setRightEdge(rect.getRightEdge() / BLOCK_WIDTH);
	chunkFootprint.setTopEdge(rect.getTopEdge() / BLOCK_HEIGHT);
	chunkFootprint.setBottomEdge(rect.getBottomEdge() / BLOCK_HEIGHT);

	Point footprintSize = chunkFootprint.getSize();
	Vector _results[footprintSize.getX() * footprintSize.getY()];
	collisionResults = _results;
	byte resultIndex = 0;

	for(byte y = chunkFootprint.getTopEdge(); y <= chunkFootprint.getBottomEdge(); y++)
	{
		for(byte x = chunkFootprint.getLeftEdge(); x <= chunkFootprint.getRightEdge(); x++)
		{
			Vector* currentResult = 0/* collision test */;

			if(currentResult)
			{
				collisionResults[resultIndex++] = *currentResult;
			}
		}
	}

	return resultIndex - 1;
}

boolean Chunk::collideWithPoint(byte pointX, byte pointY)
{
	byte blockXToCheck = pointX / BLOCK_WIDTH;
	byte blockYToCheck = pointY / BLOCK_HEIGHT;
	byte blockYMask = ORIGINAL_CHUNK_MASK << blockYToCheck;

	if(_blocks[blockXToCheck] & blockYMask)
	{
		return true;
	}

	return false;
}

// TODO - this is only any good for rectangles of equal or greater size than the chunk's blocks
boolean Chunk::collideWithRectangle(Rectangle rect)
{
	boolean didCollideNE = collideWithPoint(rect.getLeftEdge(), rect.getTopEdge());
	boolean didCollideNW = collideWithPoint(rect.getRightEdge(), rect.getTopEdge());
	boolean didCollideSE = collideWithPoint(rect.getLeftEdge(), rect.getBottomEdge());
	boolean didCollideSW = collideWithPoint(rect.getRightEdge(), rect.getBottomEdge());

	return didCollideNE || didCollideNW || didCollideSE || didCollideSW;
}

Rectangle Chunk::getBoundingBoxForBlock(byte posX, byte posY)
{
	Rectangle boundingBox;
	boundingBox.setLeftEdge(posX * BLOCK_WIDTH);
	boundingBox.setRightEdge(posX * BLOCK_WIDTH + BLOCK_WIDTH - 1);
	boundingBox.setTopEdge(posY * BLOCK_HEIGHT);
	boundingBox.setBottomEdge(posY * BLOCK_HEIGHT + BLOCK_HEIGHT - 1);
	return boundingBox;
}

void Chunk::render()
{
	byte chunkMask = ORIGINAL_CHUNK_MASK;
	byte currentX = _chunkX;
	byte currentY = _chunkY;

	for(byte i = 0; i < CHUNK_WIDTH; i++)
	{
		for(byte j = 0; j < CHUNK_HEIGHT; j++)
		{
			if(_blocks[i] & chunkMask)
			{
				gb.display.drawRect(currentX, currentY, BLOCK_WIDTH, BLOCK_HEIGHT);
			}

			currentY += BLOCK_HEIGHT;
			chunkMask <<= 1;

			if(!chunkMask)
			{
				chunkMask = ORIGINAL_CHUNK_MASK;
			}
		}

		currentY = _chunkY;
		currentX += BLOCK_WIDTH;
	}
}