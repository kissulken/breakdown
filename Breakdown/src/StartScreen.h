#pragma once
#include <string>
#include <memory>
#include "Constants.h"
#include "Navigation.h"

class StartScreenObject
{
	protected:
		int x, y;
		std::string blockName;
		std::shared_ptr<INavigation> nav;
		
	public:
		StartScreenObject(int _x, int _y, std::shared_ptr<INavigation> _nav, const std::string& _blockName): x(_x), y(_y), nav(_nav), blockName(_blockName) {};
		virtual void lightUp() = 0;
		virtual void buttonAction() = 0;
		void unLightUp();
		void create();
		void unCreate();
};

class NewGameContainer : public StartScreenObject
{
	public:
		NewGameContainer(int _x, int _y, std::shared_ptr<INavigation> _nav, const std::string& _blockName) : StartScreenObject(_x, _y, _nav, _blockName) {};
		void buttonAction() override;
		void lightUp() override;
};

class ExitContainer : public StartScreenObject
{
	public:
		ExitContainer(int _x, int _y, std::shared_ptr<INavigation> _nav, const std::string& _blockName) : StartScreenObject(_x, _y, _nav, _blockName) {};
		void buttonAction() override;
		void lightUp() override;
};






