#pragma once
#include "Action.h"
class Select_Fig_Fill_Color :public Action
{
	int count = 0;
	int clickscount = 0;
	Point P;
public:
	Select_Fig_Fill_Color(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};

