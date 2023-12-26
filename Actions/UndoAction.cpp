#include "UndoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
}

void UndoAction::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Undo");
}

void UndoAction::Execute()
{
	ReadActionParameters();
	Action* flag = pManager->GetLastCanUndoActions();
	if (flag != NULL)
	{
		flag->Undo();
		pManager->counterForUndoRedo++;
		pManager->FlagForRedoUndo = 1;
	}
}


bool UndoAction::CanRecord() {
	return true;
}

void UndoAction::ExecuteRecord() {
	pManager->GetLastCanUndoActions()->Undo();
}