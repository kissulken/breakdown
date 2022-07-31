#include "Console_Navigation.h"

void Console_Navigation::sayIt(const std::string& s, Points p, Constants::Color text_color, Constants::Color bvackground_color)
{
    setColor(text_color, bvackground_color);
    textThrower(p, s);
    Sleep(2000);
    setColor(Constants::Black);
    textThrower(p, s);
}

void Console_Navigation::SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Console_Navigation::removeCursor()
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void Console_Navigation::WindowInit()
{
    SetConsoleSize(Constants::SCREEN_CONSOLE_WIDTH, Constants::SCREEN_CONSOLE_HEIGHT);
    removeCursor();
}

void Console_Navigation::setColor(Constants::Color text, Constants::Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void Console_Navigation::setColor(Constants::Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4)));
}

void Console_Navigation::SetCursor(const Points p)
{
    COORD myCoords = { static_cast<short>(p.x),  static_cast<short>(p.y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoords);
}

void Console_Navigation::textThrower(const Points p, const std::string& phrase)
{
    SetCursor(p);
    std::cout << phrase << std::endl;
}

void Console_Navigation::textThrower(const Points p, const char ch)
{
    SetCursor(p);
    std::cout << ch << std::endl;
}


void Console_Navigation::Do_Sleep(const int time)
{
    Sleep(time);
}

bool Console_Navigation::buttonPressed()
{
    return _kbhit();
}

Constants::Directions Console_Navigation::whichButtonIsPressed()
{
    int key = _getch();
    if (key == 0 || key == 0xE0)
    {
        key = whichButtonIsPressed();
    }
    switch (key)
    {
        case Constants::Buttons::A_BUTTON:
            return Constants::Directions::LeftB;
        case Constants::Buttons::D_BUTTON:
            return Constants::Directions::RightB;
        case Constants::Buttons::ENTER_BUTTON:
            return Constants::Directions::ENTER_B;
    }
}
