#ifndef ADD_UNDO_ACTION_H
#define ADD_UNDO_ACTION_H

#include "Action.h"

class UndoAction : public Action
{
public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	bool CanRecord();
	void ExecuteRecord();
};
#endif