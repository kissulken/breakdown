#include "Block.h"

Block::Block(int _type, std::shared_ptr<INavigation> _nav, int _x, int _y) : type(_type), nav(_nav), x(_x), y(_y) 
{
	switch (type)
	{
		case 0:
			color = Constants::Green;
			HP = 1;
			break;
		case 1:
			color = Constants::Blue;
			HP = 2;
			break;
		case 2:
			color = Constants::Red;
			HP = 3;
			break;
	}
};

void Block::unSpawn()
{
	for (int i = x; i < x + Constants::BLOCK_WIDTH; i++)
	{
		nav->setColor(Constants::Black);
		nav->textThrower({ i, y }, ' ');
	}
}

void Block::spawn()
{
	for (int i = x; i < x + Constants::BLOCK_WIDTH; i++)
	{
		nav->setColor(color);
		nav->textThrower({ i, y }, ' ');
	}
}

void Block::minusHP()
{
	HP--;
	if (HP < 0)
	{
		HP = 0;
	}
	switchColor();
}

void Block::switchColor()
{
	switch (HP)
	{
		case 1:
			color = Constants::Green;
			break;
		case 2:
			color = Constants::Blue;
			break;
	}
	unSpawn();
	spawn();
}