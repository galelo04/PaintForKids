#ifndef ADD_REDO_ACTION_H
#define ADD_REDO_ACTION_H

#include "Action.h"

class RedoAction : public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	bool CanRecord();
	void ExecuteRecord();
};
#endif