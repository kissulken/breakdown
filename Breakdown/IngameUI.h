#pragma once
#include <string>
#include <memory>
#include "Navigation.h"
#include "Constants.h"

class UIObject
{
	protected:
		int value, x, y;
		std::string text;
		std::shared_ptr<INavigation> nav;
	public:
		UIObject(int _x, int _y, int _value, std::string _text, std::shared_ptr<INavigation> _nav) : x(_x), y(_y), value(_value), text(_text), nav(_nav) {};
		void spawn();
		void unSpawn();
		int getValue() { return value; };
		virtual void updateValue() = 0;
};

class HPbar : public UIObject
{
public:
	HPbar(int _x, int _y, int _value, std::string _text, std::shared_ptr<INavigation> _nav) : UIObject(_x, _y, _value, _text, _nav) {};
	void updateValue() override;
};

class PointBar : public UIObject
{
public:
	PointBar(int _x, int _y, int _value, std::string _text, std::shared_ptr<INavigation> _nav) : UIObject(_x, _y, _value, _text, _nav) {};
	void updateValue() override;
};

class CountdownBar : public UIObject
{
public:
	CountdownBar(int _x, int _y, int _value, std::string _text, std::shared_ptr<INavigation> _nav) : UIObject(_x, _y, _value, _text, _nav) {};
	void countDown();
	void updateValue() override;
};