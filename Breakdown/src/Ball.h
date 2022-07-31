#pragma once
#include <Windows.h>
#include "Navigation.h"
#include "Platform.h"
#include "IngameUI.h"
#include <memory>
#include <vector>
#include "Block.h"

class Ball
{
	private:
		int x, y, originalX, originalY, step_x = 1, step_y = 1, speed = 1;
		Constants::BallDir direction;
		std::shared_ptr<INavigation> nav;
		std::shared_ptr<HPbar> hpbar;
		std::shared_ptr<PointBar> points;
		std::shared_ptr<CountdownBar> countdown;
public:
	Ball(int posX, int posY, std::shared_ptr<INavigation> _nav);
	void Reset();
	void draw_ball();
	void redraw_ball();
	void check_border_touch(std::shared_ptr<HPbar> hpbar, std::shared_ptr<CountdownBar> countdown);
	void check_player_touch(std::shared_ptr<Platform> player);
	void check_block_touch(std::vector<std::shared_ptr<Block>> & blocks, std::shared_ptr<PointBar> points);
	int getX() const { return x; };
	int getY() const { return y; };
	Constants::BallDir getDirection() { return direction; };
	void Move();
};