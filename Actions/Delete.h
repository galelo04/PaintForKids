#pragma once
#include"Action.h"
#include "CFigure.h"
class Delete:public Action
{
	CFigure* DeletedFig;
	bool MadeUndo = false;							//bool that checks if the delete action Undo before Redo or not
public:
	Delete(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual bool CanUndo() { return true; }
	virtual void Undo();
	virtual void Redo();

	bool CanRecord();
	void ExecuteRecord();

	~Delete();
};

