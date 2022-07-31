#include "IngameUI.h"

void UIObject::spawn()
{
	nav->setColor(Constants::White, Constants::Black);
	nav->textThrower({ x, y }, text + ' ' + std::to_string(value));
}

void UIObject::unSpawn()
{
	nav->setColor( Constants::Black);
	nav->textThrower({ x, y }, text + ' ' + std::to_string(value));
}

void HPbar::updateValue()
{
	value--;
	spawn();
}

void PointBar::updateValue()
{
	value++;
	spawn();
}

void CountdownBar::updateValue()
{
	value--;
}

void CountdownBar::countDown()
{
	value = Constants::COUNTDOWN_TIME;
	int tempValue = value;
	for (int i = 0; i < tempValue; i++)
	{
		spawn();
		nav->Do_Sleep(1000);
		unSpawn();
		updateValue();
	}
	unSpawn();
}

void TimerBar::updateValue()
{
	nav->Do_Sleep(10);
	millis += 10;
	if (millis == 100)
	{
		millis = 0;
		seconds++;
		if (seconds == 60)
		{
			minutes++;
			seconds = 0;
		}
	}
	spawn();
}

void TimerBar::spawn()
{
	unSpawn();
	nav->setColor(Constants::White, Constants::Black);
	nav->textThrower({ x, y }, text + ' ' + std::to_string(minutes) +":" + std::to_string(seconds));
}

void TimerBar::unSpawn()
{
	nav->setColor(Constants::Black);
	nav->textThrower({ x, y }, text + ' ' + std::to_string(minutes) + ":" + std::to_string(seconds));
}
