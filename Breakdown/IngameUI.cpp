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
}

void PointBar::updateValue()
{
	value++;
}

void CountdownBar::updateValue()
{
	value--;
}

void CountdownBar::countDown()
{
	int tempValue = value;
	for (int i = 0; i < tempValue; i++)
	{
		spawn();
		nav->Do_Sleep(1000);
		unSpawn();
		updateValue();
	}
}
