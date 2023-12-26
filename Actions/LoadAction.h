#pragma once
#include "Action.h"
class LoadAction : public Action
{
private:
	std::string FileName;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


	
};

