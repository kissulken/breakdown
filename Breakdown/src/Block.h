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
		~Block() { unSpawn(); };
		int getX() const { return x; };
		int getY() const { return y; };
		int getHP() const { return HP; };
		void spawn();
		void unSpawn();
		void minusHP();
};