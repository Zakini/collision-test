#ifndef CHUNK_H
#define CHUNK_H

#include "collision_test_globals.h"
#include "rectangle.h"
#include "vector.h"
#include "point.h"

// TODO - make these static?
const byte BLOCK_WIDTH = 8;
const byte BLOCK_HEIGHT = 8;
const byte CHUNK_WIDTH = 9;
const byte CHUNK_HEIGHT = 8;
const byte ORIGINAL_CHUNK_MASK = B00000001;

class Chunk
{
private:
	byte _chunkX;
	byte _chunkY;
	byte* _blocks;

public:
	Chunk(byte* blocks);
	Chunk(byte chunkX, byte chunkY, byte* blocks);
	byte collide(Rectangle rect, Vector* results);
	// TODO - remove these old collision methods
	boolean collideWithPoint(byte pointX, byte pointY);
	boolean collideWithRectangle(Rectangle rect);
	Rectangle getBoundingBoxForBlock(byte posX, byte posY);
	void render();
};

#endif