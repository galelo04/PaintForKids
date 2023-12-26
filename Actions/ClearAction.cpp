#include "ClearAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAction::ClearAction(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Cleared All");

	
}

void ClearAction::Execute()
{
	ReadActionParameters();
	pManager->setFlagForRec(on);
	pManager->clearall();
	UI.isfilled = false;
	UI.DrawColor = BLUE;
}
