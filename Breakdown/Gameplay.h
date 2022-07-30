#pragma once
#include "Navigation.h"
#include "Console_Navigation.h"
#include "Ball.h"
#include "Block.h"
#include "Platform.h"
#include <memory>
#include <vector>
#include "StartScreen.h"
#include "IngameUI.h"


class Gameplay
{
	private:
		bool quit;
		std::shared_ptr<Platform> player;
		std::shared_ptr<INavigation> nav;
		std::vector<std::shared_ptr<Block>> blocks;
		std::unique_ptr<Ball> ball;
		std::unique_ptr<NewGameContainer> newGame;
		std::unique_ptr<ExitContainer> exitGame;
		std::unique_ptr<HPbar> hpbar;
		std::unique_ptr<PointBar> pointbar;
		std::unique_ptr<CountdownBar> countdown;
	public:
		Gameplay();
		void createStartMenu();
		void Restart();
		void checkControls();
		void DrawBorder();
		void printUI();
		void Run();
};