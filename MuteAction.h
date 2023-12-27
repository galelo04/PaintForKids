#pragma once
#include "Action.h"
class MuteAction :public Action
{
public:
	MuteAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
};
