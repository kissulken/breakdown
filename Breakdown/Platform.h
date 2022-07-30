#pragma once
#include "Constants.h"
#include "Console_Navigation.h"
#include "Navigation.h"

class Platform
{
	private:
		int start_x, start_y, x, y, HP, score;
		std::shared_ptr<INavigation> nav;
	public:
		Platform(int _x, int _y, std::shared_ptr<INavigation> _nav) : start_x(_x), start_y(_y), HP(Constants::BASIC_HP), score(Constants::BASIC_POINTS), nav(_nav)
		{
			x = start_x;
			y = start_y;
		};
		int getX() { return x; };
		int getY() { return y; };
		void moveRight();
		void moveLeft();
		void Reset();
		void clearPreviousPosition();
		void draw_player();
		void scoreUp();
		void lifeLost();
};