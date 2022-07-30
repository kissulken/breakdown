#pragma once
#include <memory>
#include "Constants.h"
#include "Navigation.h"
#include "Console_Navigation.h"

class Block
{
	private:
		Constants::Color color;
		int type;
		int HP, x, y;
		std::shared_ptr<INavigation> nav;
		void switchColor();
	public:
		Block(int _type, std::shared_ptr<INavigation> _nav, int _x, int _y);
		int getX() { return x; };
		int getY() { return y; };
		int getHP() { return HP; };
		void spawn();
		void minusHP();
};