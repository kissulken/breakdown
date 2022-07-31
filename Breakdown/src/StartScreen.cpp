#include "StartScreen.h"

void StartScreenObject::create()
{
	nav->setColor(Constants::White, Constants::Black);
	nav->textThrower({ x, y }, blockName);
}

void StartScreenObject::unCreate()
{
	nav->setColor(Constants::Black);
	nav->textThrower({ x, y }, blockName);
}

void StartScreenObject::unLightUp()
{
	nav->setColor(Constants::White, Constants::Black);
	nav->textThrower({ x, y }, blockName);
}

void NewGameContainer::lightUp()
{
	nav->setColor(Constants::Black, Constants::Green);
	nav->textThrower({ x, y }, blockName);
}

void ExitContainer::lightUp()
{
	nav->setColor(Constants::Black, Constants::Red);
	nav->textThrower({ x, y }, blockName);
}

void NewGameContainer::buttonAction()
{
	unCreate();
}

void ExitContainer::buttonAction()
{
	unCreate();
	exit(0);
}


