#ifndef ADD_DRAWCLR_ACTION_H
#define ADD_DRAWCLR_ACTION_H

#include "Action.h"
#include"CFigure.h"

class DrawClrAction : public Action
{
private:
	ActionType ActType;		//To know the chosen Color 
	color prevClr;			//The Previous Color that will use in Undo
	color crntClr;			//The current Color that will use in Redo
	CFigure* prev_Fig;		//The Selected Figure 
	bool MadeUndo = false;	//bool that checks if the delete action Undo before Redo or not
public:
	DrawClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual bool CanUndo() { return true; }		//if i can make Undo to this action or not
	virtual void Undo();
	virtual void Redo();

	bool CanRecord();
	void ExecuteRecord();
};
#endif