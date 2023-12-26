#include "DrawClrAction.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"

DrawClrAction::DrawClrAction(ApplicationManager* pApp) :Action(pApp)
{}

void DrawClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change the Drawing Color : Click on any Color");
	ActType = pIn->GetUserAction();
	pOut->ClearStatusBar();

	if (pManager->FlagForRedoUndo == 1)
	{
		for (int i = pManager->ActionCount + 1;i <= pManager->ActionCount + pManager->counterForUndoRedo;i++)
		{
			pManager->setActionList(NULL, i);
		}
		pManager->counterForUndoRedo = 0;
		pManager->FlagForRedoUndo = 0;
	}

}

void DrawClrAction::Execute()
{
	ReadActionParameters();

	if ((pManager->getSelectedFigure() != NULL))
	{
		prevClr = pManager->GetOutput()->getCrntDrawColor();
		prev_Fig = pManager->getSelectedFigure();
		switch (ActType)
		{
		case SELECT_CLR_BLACK:
		{
			crntClr = BLACK;
			pManager->GetOutput()->PrintMessage("Change the drawing color to Black");
			prev_Fig->ChngDrawClr(BLACK);
			pManager->GetOutput()->setCrntDrawColor(BLACK);
			break;
		}
		case SELECT_CLR_YELLOW:
		{
			crntClr = YELLOW;
			pManager->GetOutput()->PrintMessage("Change the drawing color to Yellow");
			prev_Fig->ChngDrawClr(YELLOW);
			pManager->GetOutput()->setCrntDrawColor(YELLOW);
			break;
		}
		case SELECT_CLR_ORANGE:
		{
			crntClr = ORANGE;
			pManager->GetOutput()->PrintMessage("Change the drawing color to Orange");
			prev_Fig->ChngDrawClr(ORANGE);
			pManager->GetOutput()->setCrntDrawColor(ORANGE);
			break;
		}
		case SELECT_CLR_RED:
		{
			crntClr = RED;
			pManager->GetOutput()->PrintMessage("Change the drawing color to Red");
			prev_Fig->ChngDrawClr(RED);
			pManager->GetOutput()->setCrntDrawColor(RED);
			break;
		}
		case SELECT_CLR_GREEN:
		{
			crntClr = GREEN;
			pManager->GetOutput()->PrintMessage("Change the drawing color to Green");
			prev_Fig->ChngDrawClr(GREEN);
			pManager->GetOutput()->setCrntDrawColor(GREEN);
			break;
		}
		case SELECT_CLR_BLUE:
		{
			crntClr = BLUE;
			pManager->GetOutput()->PrintMessage("Change the drawing color to Blue");
			prev_Fig->ChngDrawClr(BLUE);
			pManager->GetOutput()->setCrntDrawColor(BLUE);
			break;
		}
		}
	}
	else
	{
		pManager->GetOutput()->PrintMessage("There is no selected Figure to change its color");
	}

}

void DrawClrAction::Undo()
{
	MadeUndo = true;	//The Undo done
	prev_Fig->ChngDrawClr(prevClr);
	pManager->GetOutput()->setCrntDrawColor(prevClr);
}

void DrawClrAction::Redo()
{
	if (MadeUndo)
	{
		prev_Fig->ChngDrawClr(crntClr);
		pManager->GetOutput()->setCrntDrawColor(crntClr);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}


bool DrawClrAction::CanRecord() {
	return true;
}

void DrawClrAction::ExecuteRecord() {
	if ((pManager->getSelectedFigure() != NULL))
	{
		prevClr = pManager->GetOutput()->getCrntDrawColor();
		switch (ActType)
		{
		case SELECT_CLR_BLACK:
		{
			pManager->getSelectedFigure()->ChngDrawClr(BLACK);
			pManager->GetOutput()->setCrntDrawColor(BLACK);
			break;
		}
		case SELECT_CLR_YELLOW:
		{
			pManager->getSelectedFigure()->ChngDrawClr(YELLOW);
			pManager->GetOutput()->setCrntDrawColor(YELLOW);
			break;
		}
		case SELECT_CLR_ORANGE:
		{
			pManager->getSelectedFigure()->ChngDrawClr(ORANGE);
			pManager->GetOutput()->setCrntDrawColor(ORANGE);
			break;
		}
		case SELECT_CLR_RED:
		{
			pManager->getSelectedFigure()->ChngDrawClr(RED);
			pManager->GetOutput()->setCrntDrawColor(RED);
			break;
		}
		case SELECT_CLR_GREEN:
		{
			pManager->getSelectedFigure()->ChngDrawClr(GREEN);
			pManager->GetOutput()->setCrntDrawColor(GREEN);
			break;
		}
		case SELECT_CLR_BLUE:
		{
			pManager->getSelectedFigure()->ChngDrawClr(BLUE);
			pManager->GetOutput()->setCrntDrawColor(BLUE);
			break;
		}
		}
	}
}
