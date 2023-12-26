#pragma once
#include "Action.h"
class ClearAction :public Action
{
public:
	ClearAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

