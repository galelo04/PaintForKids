#pragma once
#include "Action.h"
class VolumeAction : public Action
{
public:
	VolumeAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
};

