#include "ReszieByDragAction.h"
#include "..\ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"

ResizeByDragAction::ResizeByDragAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ResizeByDragAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Resize Figure by Draging : Hold on the Figure ");
	pIn->GetCoordofmouse(P.x, P.y);
}

void ResizeByDragAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	buttonstate prev_buttonstate = BUTTON_UP;
	buttonstate current_buttonstate;

	while (true)
	{

		pIn->GetCoordofmouse(P.x, P.y);
		current_buttonstate = pManager->GetInput()->getmousebuttonstate(LEFT_BUTTON, P.x, P.y);

		if (current_buttonstate == BUTTON_DOWN)
		{
			if (pManager->getSelectedFigure() != NULL)
			{
				pManager->getSelectedFigure()->resize(P);
				pManager->UpdateInterface();
				pOut->CreateDrawToolBar();
				pOut->CreateStatusBar();
			}
		}
		else if (current_buttonstate == BUTTON_UP && prev_buttonstate == BUTTON_DOWN)
			break;
		prev_buttonstate = current_buttonstate;
	}
}

void ResizeByDragAction::Undo()
{
}

void ResizeByDragAction::Redo()
{
}

bool ResizeByDragAction::CanRecord()
{
	return false;
}

void ResizeByDragAction::ExecuteRecord()
{
}

