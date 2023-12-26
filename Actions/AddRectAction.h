#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	bool MadeUndo = false;								//bool that knows me if the circle Undo before Redo or not
public:
	AddRectAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;

	virtual bool CanUndo() { return true; }

	virtual void Undo();

	virtual void Redo();

	bool CanRecord();
	void ExecuteRecord();

	virtual void operator=(Action*);
	
};

#endif