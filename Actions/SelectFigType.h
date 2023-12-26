#pragma once
#include "Action.h"
class SelectFigType :public Action
{
	int count=0;
	int clickscount = 0;
	Point P;
public:
	SelectFigType(ApplicationManager* pApp) ;
	virtual void Execute();
	virtual void ReadActionParameters();
};

