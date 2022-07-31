#pragma once

class Constants
{
public:
	enum WinConditions {LOGO, WIN, LOSE};
	enum Directions {LeftB, RightB, D_B, Q_B, ENTER_B};
	enum BlockSegregator { WhiteBlock, YellowBlock, RedBlock };
	enum Buttons {A_BUTTON = 'a', D_BUTTON = 'd', Q_BUTTON = 'q', R_BUTTON = 'r', ENTER_BUTTON = '\r' };
	enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
	enum BallDir { STOP, DOWN, DOWNLEFT, DOWNRIGHT, UP,  UPLEFT, UPRIGHT  };
	static const int MARGIN_FOR_UI_RIGHT = 5;
	static const int MARGIN_FOR_UI_BOTTOM = 5;
	static const int COUNTDOWN_TIME = 5;
	static const int SCREEN_CONSOLE_WIDTH = 800;
	static const int SCREEN_CONSOLE_HEIGHT = 600;
	static const int CONSOLE_WIDTH = 61;
	static const int NUMBER_OF_BLOCKS = 120;
	static const int CONSOLE_HEIGHT = 21;
	static const int BLOCK_WIDTH = 2;
	static const int BLOCK_HEIGHT = 1;
	static const int BORDER_SIZE = 1;
	static const char BORDER_MATERIAL = ' ';
	static const char PLAYER_MATERIAL = ' ';
	static const char BALL_MATERIAL = 'o';
	static const int PLATFORM_SIZE = 6;
	static const int BASIC_HP = 3;
	static const int BASIC_POINTS = 0;
	static const int PLATFORM_STEP = 3;
};