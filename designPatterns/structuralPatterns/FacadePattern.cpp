/*
@Author @Source: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

Usage: Facade defines a higher-level interface that makes the subsystem easier to use. 

*/

#include <string>
#include <iostream>

using namespace std;

class Alarm
{
public:
	void alarmOn()
	{
		cout << "Alarm is on and house is secured"<<endl;
	}

	void alarmOff()
	{
		cout << "Alarm is off and you can go into the house"<<endl;
	}
};

class Ac
{
public:
	void acOn()
	{
		cout << "Ac is on"<<endl;
	}

	void acOff()
	{
		cout << "AC is off"<<endl;
	}
};

class Tv
{
public:
	void tvOn()
	{
		cout << "Tv is on"<<endl;
	}

	void tvOff()
	{
		cout << "TV is off"<<endl;
	}
};

class HouseFacade
{
	Alarm alarm;
	Ac ac;
	Tv tv;

public:
	HouseFacade(){}

	void goToWork()
	{
		ac.acOff();
		tv.tvOff();
		alarm.alarmOn();
	}

	void comeHome()
	{
		alarm.alarmOff();
		ac.acOn();
		tv.tvOn();
	}
};

int main()
{
	HouseFacade hf;

	hf.goToWork();
	hf.comeHome();
}
