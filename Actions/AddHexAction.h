#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"
class AddHexAction :public Action
{
private:
	Point P;
    GfxInfo HexGfxInfo;
	bool MadeUndo = false;							//bool that knows me if the circle Undo before Redo or not
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
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
