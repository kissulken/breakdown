#include "Ball.h"

Ball::Ball(int posX, int posY, std::shared_ptr<INavigation> _nav) : x(posX), y(posY), direction(Constants::DOWNRIGHT), nav(_nav)
{
	originalX = posX;
	originalY = posY;
}

void Ball::Reset()
{
	redraw_ball();
	x = originalX;
	y = originalY;
}


void Ball::Move()
{	
	redraw_ball();
	switch (direction) 
	{
	case Constants::STOP:
		break;

	case Constants::UP:
		y --;
		break;

	case Constants::UPLEFT:
		y--;
		x-=speed;
		break;

	case Constants::UPRIGHT:
		y --;
		x+= speed;
		break;

	case Constants::DOWN:
		y ++;
		break;

	case Constants::DOWNLEFT:
		y ++;
		x-=speed;
		break;

	case Constants::DOWNRIGHT:
		y ++;
		x += speed;
		break;

	default:
		break;
	}
	draw_ball();
}

void Ball::draw_ball()
{
	nav->setColor(Constants::White, Constants::Black);
	nav->textThrower({ x, y }, Constants::BALL_MATERIAL);
	nav->Do_Sleep(40);
}

void Ball::redraw_ball()
{
	nav->setColor(Constants::Black);
	nav->textThrower({ x, y }, ' ');
}

void Ball::check_border_touch(std::shared_ptr<HPbar> hpbar, std::shared_ptr<CountdownBar> countdown)
{
	if (x < 2 || x > Constants::CONSOLE_WIDTH - 3) 
	{
		switch (direction)
		{
			case Constants::UPRIGHT:
				direction = Constants::UPLEFT;
				break;
			case Constants::UPLEFT:
				direction = Constants::UPRIGHT;
				break;
			case Constants::DOWNRIGHT:
				direction = Constants::DOWNLEFT;
				break;
			case Constants::DOWNLEFT:
				direction = Constants::DOWNRIGHT;
				break;
		}
	}
	if (y > Constants::CONSOLE_HEIGHT - 2)
	{
		hpbar->updateValue();
		Reset();
		countdown->countDown();
	}
	if (y < 2)
	{
		switch (direction)
		{
			case Constants::UPRIGHT:
				direction = Constants::DOWNRIGHT;
				break;
			case Constants::UPLEFT:
				direction = Constants::DOWNLEFT;
				break;
		}
	}
}

void Ball::check_player_touch(std::shared_ptr<Platform> player)
{
	if (player->getY() == y + 1)
	{
		for (int i = 0; i < Constants::PLATFORM_SIZE / 2 + 1; i++)
		{
			if (player->getX() + i - 1 == x)
				direction = Constants::UPLEFT;
		}
		for (int i = 0; i < Constants::PLATFORM_SIZE / 2 + 1; i++)
		{
			if (player->getX() + i + Constants::PLATFORM_SIZE / 2 + 1 == x)
				direction = Constants::UPRIGHT;
		}
	}
}

void Ball::check_block_touch(std::vector<std::shared_ptr<Block>> & blocks, std::shared_ptr<PointBar> points)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks[i]->getY() == y - 1)
		{
			for (int j = 0; j < Constants::BLOCK_WIDTH; j++)
			{
				if (blocks[i]->getX() + j == x)
				{
					blocks[i]->minusHP();
					points->updateValue();
					if (blocks[i]->getHP() == 0)
					{
						blocks.erase(blocks.begin() + i);
					}
					if (direction == Constants::UPRIGHT)
					{
						direction = Constants::DOWNRIGHT;
					}
					else
					{
						direction = Constants::DOWNLEFT;
					}
				}
			}
		}
	}
}
