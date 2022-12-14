#include "Gameplay.h"

Gameplay::Gameplay() : quit(false), wincondition(Constants::LOGO)
{
	nav = std::make_shared<Console_Navigation>();
	countdown = std::make_unique<CountdownBar>(Constants::CONSOLE_WIDTH + Constants::MARGIN_FOR_UI_RIGHT, Constants::MARGIN_FOR_UI_BOTTOM, Constants::COUNTDOWN_TIME, "PREPARE YOURSELF FOR BATTLE:", nav);
	hpbar = std::make_shared<HPbar>(1, Constants::MARGIN_FOR_UI_BOTTOM + Constants::CONSOLE_HEIGHT, Constants::BASIC_HP, "HP:", nav);
	pointbar = std::make_shared<PointBar>(Constants::CONSOLE_WIDTH, Constants::MARGIN_FOR_UI_BOTTOM + Constants::CONSOLE_HEIGHT, Constants::BASIC_POINTS, "POINTS:", nav);
	timer = std::make_unique<TimerBar>(Constants::CONSOLE_WIDTH + Constants::MARGIN_FOR_UI_RIGHT, Constants::MARGIN_FOR_UI_BOTTOM * 2, Constants::COUNTDOWN_TIME, "TIMER:", nav);
	nav->WindowInit();
	player = std::make_shared<Platform>(Constants::CONSOLE_WIDTH / 2, Constants::CONSOLE_HEIGHT - 3, nav);
	ball = std::make_unique<Ball>(Constants::CONSOLE_WIDTH / 2, Constants::CONSOLE_HEIGHT / 2, nav);
}

void Gameplay::Run()
{
	createBlocks();
	createStartMenu();
	DrawBorder();
	player->draw_player();
	ball->draw_ball();
	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->spawn();
	}
	printUI();
	while (true)
	{
		timer->updateValue();
		checkControls();
		ball->check_border_touch(hpbar, countdown);
		ball->check_player_touch(player);
		ball->check_block_touch(blocks, pointbar);
		ball->Move();
		if (hpbar->getValue() == 0)
		{
			wincondition = Constants::LOSE;
			Restart();
			Run();
		}
		if (blocks.size() == 0)
		{
			wincondition = Constants::WIN;
			Restart();
			Run();
		}
	}
}

void Gameplay::createBlocks()
{
	blocks.clear();
	for (int i = 1; i < Constants::NUMBER_OF_BLOCKS / (Constants::CONSOLE_WIDTH / Constants::BLOCK_WIDTH); i++)
	{
		for (int j = 1; j < Constants::CONSOLE_WIDTH; j += Constants::BLOCK_WIDTH)
		{
			blocks.push_back(std::make_shared<Block>(rand() % 3, nav, j, i));
		}
	}
}

void Gameplay::createStartMenu()
{
	system("cls");
	newGame = std::make_unique<NewGameContainer>(Constants::CONSOLE_WIDTH / 2, Constants::CONSOLE_HEIGHT, nav, "NEW GAME");
	exitGame = std::make_unique<ExitContainer>(Constants::CONSOLE_WIDTH, Constants::CONSOLE_HEIGHT, nav, "EXIT GAME");
	newGame->create();
	exitGame->create();
	newGame->lightUp();
	switch (wincondition)
	{
		case Constants::LOGO:
			nav->sayIt("BREAKDOWN", { Constants::CONSOLE_WIDTH - 15, Constants::CONSOLE_HEIGHT / 2 }, Constants::White, Constants::Blue);
				break;
		case Constants::WIN:
			nav->sayIt("YOU WIN!", { Constants::CONSOLE_WIDTH - 15, Constants::CONSOLE_HEIGHT / 2 }, Constants::White, Constants::Green);
				break;
		case Constants::LOSE:
			nav->sayIt("YOU LOSE", { Constants::CONSOLE_WIDTH - 15, Constants::CONSOLE_HEIGHT / 2 }, Constants::White, Constants::Red);
				break;
	}
	bool condition = true, currentButton = true;
	while (condition)
	{
		if (nav->buttonPressed())
		{
			switch (nav->whichButtonIsPressed())
			{
				case Constants::LeftB:
					newGame->lightUp();
					exitGame->unLightUp();
					currentButton = true;
				break;
				case Constants::RightB:
					exitGame->lightUp();
					newGame->unLightUp();
					currentButton = false;
				break;
				case Constants::ENTER_B:
					condition = false;
				break;
			}
		}
	}
	if (currentButton)
	{
		exitGame->unCreate();
		newGame->buttonAction();
	}
	else
	{
		newGame->unCreate();
		exitGame->buttonAction();
	}
}

void Gameplay::Restart()
{
	player->Reset();
	ball->Reset();
	hpbar->resetValue();
	pointbar->resetValue();
	timer->resetValue();
}

void Gameplay::DrawBorder()
{
	nav->SetCursor({ 0, 0 });
	nav->setColor(Constants::White);
	for (int i = 0; i < Constants::CONSOLE_WIDTH; ++i)
	{
		nav->textThrower({ i, 0 }, Constants::BORDER_MATERIAL);
		nav->textThrower({ i, Constants::CONSOLE_HEIGHT }, Constants::BORDER_MATERIAL);
	}
	for (int i = 0; i <= Constants::CONSOLE_HEIGHT; ++i)
	{
		nav->textThrower({ 0, i }, Constants::BORDER_MATERIAL);
		nav->textThrower({ Constants::CONSOLE_WIDTH, i }, Constants::BORDER_MATERIAL);
	}
}

void Gameplay::printUI()
{
	hpbar->spawn();
	pointbar->spawn();
	countdown->countDown();
	timer->spawn();
}

void Gameplay::checkControls()
{
	if (nav->buttonPressed())
	{
		switch (nav->whichButtonIsPressed())
		{
		case Constants::LeftB:
			player->moveLeft();
			break;
		case Constants::RightB:
			player->moveRight();
			break;
		}
	}
}


