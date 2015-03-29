#include "player.h"

Player::Player()
{
	_playerX = 0;
	_playerY = 0;
	_previousX = _playerX;
	_previousY = _playerY;
	_framePosWasStored = 0;
}

Player::Player(signed char playerX, signed char playerY)
{
	_playerX = playerX;
	_playerY = playerY;
	_previousX = _playerX;
	_previousY = _playerY;
	_framePosWasStored = 0;
}

signed char Player::getX()
{
	return _playerX;
}

signed char Player::getY()
{
	return _playerY;
}

void Player::setX(signed char value)
{
	pushPosState();
	_playerX = value;
}

void Player::setY(signed char value)
{
	pushPosState();
	_playerY = value;
}

Rectangle Player::getBoundingBox()
{
	Rectangle boundingBox;
	boundingBox.setLeftEdge(_playerX);
	boundingBox.setRightEdge(_playerX + PLAYER_WIDTH - 1);
	boundingBox.setTopEdge(_playerY);
	boundingBox.setBottomEdge(_playerY + PLAYER_HEIGHT - 1);
	return boundingBox;
}

void Player::move(PlayerAction action)
{
	if(action == LEFT)
	{
		setX(_playerX - 1);
	}
	else if(action == RIGHT)
	{
		setX(_playerX + 1);
	}
	else if(action == UP)
	{
		setY(_playerY - 1);
	}
	else if(action == DOWN)
	{
		setY(_playerY + 1);
	}
}

void Player::pushPosState()
{
	if(gb.frameCount > _framePosWasStored)
	{
		_framePosWasStored = gb.frameCount;
		_previousX = _playerX;
		_previousY = _playerY;
	}
}

void Player::revertMove()
{
	_playerX = _previousX;
	_playerY = _previousY;
}

void Player::render()
{
	gb.display.drawRect(_playerX, _playerY, PLAYER_WIDTH, PLAYER_HEIGHT);
}