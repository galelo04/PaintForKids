#pragma once
#include"Action.h"
#include"CFigure.h"
#include"Play_Recording.h"
class Start_Recording:public Action
{

public:

	Start_Recording(ApplicationManager*);
	


	virtual void ReadActionParameters();

	
	virtual void Execute();
};

