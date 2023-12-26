#pragma once
#include "Action.h"
class ResizeByDragAction : public Action
{
private:
	Point P;

public:
	ResizeByDragAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual bool CanUndo() { return true; }
	virtual void Undo();
	virtual void Redo();
	bool CanRecord();
	void ExecuteRecord();
};
