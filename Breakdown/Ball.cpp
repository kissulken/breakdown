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

void Ball::changeDirectionLogically(bool clockwise) 
{
		if (clockwise)
		{
			switch (direction)
			{
			case Constants::UPRIGHT:
				direction = Constants::UPLEFT;
				break;
			case Constants::UPLEFT:
				direction = Constants::DOWNLEFT;
				break;
			case Constants::DOWNLEFT:
				direction = Constants::DOWNRIGHT;
				break;
			case Constants::DOWNRIGHT:
				direction = Constants::UPRIGHT;
				break;
			}
		}
		else
		{
			switch (direction)
			{
			case Constants::UPRIGHT:
				direction = Constants::DOWNRIGHT;
				break;
			case Constants::DOWNRIGHT:
				direction = Constants::DOWNLEFT;
				break;
			case Constants::DOWNLEFT:
				direction = Constants::UPLEFT;
				break;
			case Constants::UPLEFT:
				direction = Constants::UPRIGHT;
				break;
			}
		}
}

void Ball::randomUpDirection()
{
	direction = (Constants::BallDir)((rand() % 3) + 4);
	
}

void Ball::randomDownDirection()
{
	direction = (Constants::BallDir)((rand() % 3) + 1);
}

void Ball::randomDirection()
{
	direction = (Constants::BallDir)((rand() % 6) + 1);
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
		x--;
		break;

	case Constants::UPRIGHT:
		y --;
		x++;
		break;

	case Constants::DOWN:
		y ++;
		break;

	case Constants::DOWNLEFT:
		y ++;
		x--;
		break;

	case Constants::DOWNRIGHT:
		y ++;
		x ++;
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

void Ball::check_border_touch()
{
	if (x < 2 || x > Constants::CONSOLE_WIDTH - 1) 
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
		Reset();
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
	if (player->getX() + 7 == x && player->getY() == y + 1)
		direction = Constants::UPLEFT;
	else if (player->getX() + 8 == x && player->getY() == y + 1)
		direction = Constants::UPRIGHT;
	else if (player->getX() + 9 == x && player->getY() == y + 1)
		direction = Constants::UPRIGHT;
}

void Ball::check_block_touch(std::vector<std::shared_ptr<Block>> & blocks)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		if ((blocks[i]->getX() == x || blocks[i]->getX() + 1 == x) && blocks[i]->getY() == y - 2)
		{
			blocks[i]->minusHP();
			direction = Constants::DOWNLEFT;
			if (blocks[i]->getHP() == 0)
				blocks.erase(blocks.begin() + i);
		}
		if ((blocks[i]->getX() + 1 == x || blocks[i]->getX() + 1 == x) && blocks[i]->getY() == y - 2)
		{
			blocks[i]->minusHP();
			direction = Constants::DOWNRIGHT;
			if(blocks[i]->getHP() == 0)
				blocks.erase(blocks.begin() + i);
		}
	}
}
