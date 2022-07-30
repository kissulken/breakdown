#pragma once
#include <Windows.h>
#include "Navigation.h"
#include "Platform.h"
#include <memory>
#include <vector>
#include "Block.h"

class Ball
{
	private:
		int x, y, originalX, originalY, step_x = 1, step_y = 1;
		Constants::BallDir direction, prev_direction;
		std::shared_ptr<INavigation> nav;
public:
	Ball(int posX, int posY, std::shared_ptr<INavigation> _nav);
	void Reset();
	void changeDirectionLogically(bool clockwise);
	void randomUpDirection();
	void randomDownDirection();
	void randomDirection();
	void draw_ball();
	void redraw_ball();
	void check_border_touch();
	void check_player_touch(std::shared_ptr<Platform> player);
	void check_block_touch(std::vector<std::shared_ptr<Block>> & blocks);
	int getX() { return x; };
	int getY() { return y; };
	Constants::BallDir getDirection() { return direction; };
	void Move();
};