#pragma once
#include"Action.h"

class Play_Recording:public Action
{

public:
	Play_Recording(ApplicationManager* pApp);


	
	virtual void ReadActionParameters();

	
	virtual void Execute();
};

