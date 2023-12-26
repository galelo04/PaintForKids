#pragma once
#include"Action.h"
class Stop_Recording:public Action
{
public:
	Stop_Recording(ApplicationManager* pApp);


	virtual void ReadActionParameters() ;

	
	virtual void Execute() ;
};

