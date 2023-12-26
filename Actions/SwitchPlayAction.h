#pragma once
#include "Action.h"
class SwitchPlayAction :public Action
{
private:
	ActionType ActType;
public:
	SwitchPlayAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

