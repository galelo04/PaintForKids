#pragma once
#include "Action.h"
class MoveByDragAction : public Action
{
private:
	Point P;

public:
	MoveByDragAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

