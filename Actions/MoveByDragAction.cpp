#include "MoveByDragAction.h"
#include "..\ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"

MoveByDragAction::MoveByDragAction(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveByDragAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move Figure by Draging : Hold on the Figure ");
	pIn->GetCoordofmouse(P.x, P.y);
}

void MoveByDragAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	buttonstate prev_buttonstate = BUTTON_UP;
	buttonstate current_buttonstate;
	CFigure* FigAtPoint = NULL;

	while (true)
	{

		pIn->GetCoordofmouse(P.x, P.y);
		current_buttonstate = pManager->GetInput()->getmousebuttonstate(LEFT_BUTTON, P.x, P.y);
		
		if (current_buttonstate == BUTTON_DOWN)
		{
			if (FigAtPoint == NULL)
				FigAtPoint = pManager->GetFigure(P.x, P.y);
			if (FigAtPoint != NULL)
			{
				FigAtPoint->move(P);
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
