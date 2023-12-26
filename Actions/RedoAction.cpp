#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


RedoAction::RedoAction(ApplicationManager* pApp): Action(pApp)
{
}
void RedoAction::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Redo");

}

void RedoAction::Execute()
{
	ReadActionParameters();
	Action* flag = pManager->GetLastCanRedoActions();
	if (flag != NULL)
		flag->Redo();

}

bool RedoAction::CanRecord() {
	return true;
}

void RedoAction::ExecuteRecord() {
	pManager->GetLastCanRedoActions()->Redo();
}