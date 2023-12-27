#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"

class AddCircleAction :public Action
{
private:
	Point P1;	//the center
	Point P2;	//the radius point
    GfxInfo CircleGfxInfo;
	bool MadeUndo = false;	//bool that knows me if the circle Undo before Redo or not
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

	virtual bool CanUndo() { return true; }		//if i can make Undo to this action or not
	virtual void Undo();						//Undo the add circle action
	virtual void Redo();						//Undo the add circle action

	bool CanRecord();
	void ExecuteRecord();
	virtual void operator=(Action*);
	virtual void playsound();
	
};
#endif

