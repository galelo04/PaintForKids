#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"
#include "CFigure.h"
class AddTriangleAction : public Action
{
private:
	Point P1;
	Point P2;
	Point P3;
    GfxInfo TriangleGfxInfo;
	CFigure* prevfig;
	bool MadeUndo = false;									//bool that knows me if the circle Undo before Redo or not
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
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
