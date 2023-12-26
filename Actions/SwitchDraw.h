#pragma once
#include "Action.h"
class SwitchDraw : public Action
{
private:
	ActionType ActType;
public:
	SwitchDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

