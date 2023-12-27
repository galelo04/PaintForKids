#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
class Start_Recording;
class ApplicationManager; //forward class declaration
#include <Windows.h>
#include "MMSystem.h"

//Base class for all possible actions
class Action
{
protected:
	ApplicationManager* pManager;	//Actions needs AppMngr to do their job
	Start_Recording* pRecord;
public:

	Action(ApplicationManager* pApp) { pManager = pApp;   }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() = 0;

	//Execute action (code depends on action type)
	virtual void Execute() = 0;

	virtual bool CanUndo() { return false; }	//if i can make Undo to this action or not
	virtual void Undo() {}						//every action has a certain logic to Undo
	virtual void Redo() {}						//every action has a certain logic to Redo

	virtual bool CanRecord() { return false; }


	virtual void ExecuteRecord(){}
	virtual void operator=(Action*){}
	virtual void playsound() {}

};

#endif