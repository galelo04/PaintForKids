#pragma once
#include "Action.h"
#include "CFigure.h"
class MoveFig :
    public Action
{
private:
	Point P;
	Point prevpoint;
	CFigure* Moved_Fig;
	bool MadeUndo = false;
public:
	MoveFig(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual bool CanUndo() { return true; }
	virtual void Undo();
	virtual void Redo();
	bool CanRecord();
	void ExecuteRecord();
};

