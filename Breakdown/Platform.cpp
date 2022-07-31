#include "Platform.h"

void Platform::Reset()
{
	x = start_x;
	y = start_y;
}

void Platform::clearPreviousPosition()
{
	nav->setColor(Constants::Black);
	for (int i = 1; i <= Constants::CONSOLE_WIDTH - 1; i++)
	{
		nav->textThrower({i, y }, ' ');
	}
}

void Platform::moveLeft()
{
	if (x > Constants::PLATFORM_STEP)
	{
		x-=Constants::PLATFORM_STEP;
		clearPreviousPosition();
		draw_player();
	}	
}

void Platform::moveRight()
{
	if (x < Constants::CONSOLE_WIDTH - Constants::PLATFORM_STEP - Constants::PLATFORM_SIZE - 1)
	{
		x+= Constants::PLATFORM_STEP;
		clearPreviousPosition();
		draw_player();
	}
}

void Platform::draw_player()
{
	nav->setColor(Constants::Red);
	for (int i = 0; i <= Constants::PLATFORM_SIZE; i++)
	{
		nav->textThrower({ x + i, y }, Constants::PLAYER_MATERIAL);
	}
}