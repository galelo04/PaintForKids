#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Action.h"
#include "CFigure.h"
class AddSquareAction : public Action
{
private:
	Point P;
	GfxInfo SquareGfxInfo;
	CFigure* prevfig;
	bool MadeUndo = false;								//bool that knows me if the circle Undo before Redo or not
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

	virtual bool CanUndo() { return true; }

	virtual void Undo();

	virtual void Redo();

	bool CanRecord();
	void ExecuteRecord();
	virtual void operator=(Action*);
	virtual void playsound();

};
#endif