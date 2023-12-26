#ifndef ADD_FILLCLR_ACTION_H
#define ADD_FILLCLR_ACTION_H

#include "Action.h"
#include "CFigure.h"

class FillClrAction : public Action
{
private:
	ActionType ActType;		//To know the chosen Color 
	color prevClr;			//The Previous Color that will use in Undo
	color crntClr;			//The current Color that will use in Redo
	bool WasFilled;			//The Figure statue before changing the Color
	CFigure* prev_Fig;		//The Selected Figure 
	bool MadeUndo = false;	//bool that checks if the delete action Undo before Redo or not
public:
	FillClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual bool CanUndo() { return true; }
	virtual void Undo();
	virtual void Redo();

	bool CanRecord();
	void ExecuteRecord();
};
#endif