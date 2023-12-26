#include "FillClrAction.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"

FillClrAction::FillClrAction(ApplicationManager* pApp) :Action(pApp)
{
}

void FillClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change the Filling Color : Click on any Color");
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

void FillClrAction::Execute()
{
	ReadActionParameters();
	if ((pManager->getSelectedFigure() != NULL))
	{
		WasFilled = pManager->getSelectedFigure()->getgfxinfo().isFilled;
		UI.isfilled = true;
		prevClr = pManager->GetOutput()->getCrntFillColor();
		prev_Fig = pManager->getSelectedFigure();
		switch (ActType)
		{
		case SELECT_CLR_BLACK:
		{
			pManager->GetOutput()->PrintMessage("Change the fill color to Black");
			crntClr = BLACK;
			prev_Fig->ChngFillClr(BLACK);
			pManager->GetOutput()->setCrntFillColor(BLACK);
			break;
		}
		case SELECT_CLR_YELLOW:
		{
			pManager->GetOutput()->PrintMessage("Change the fill color to Yellow");
			crntClr = YELLOW;
			prev_Fig->ChngFillClr(YELLOW);
			pManager->GetOutput()->setCrntFillColor(YELLOW);
			break;
		}
		case SELECT_CLR_ORANGE:
		{
			pManager->GetOutput()->PrintMessage("Change the fill color to Orange");
			crntClr = ORANGE;
			prev_Fig->ChngFillClr(ORANGE);
			pManager->GetOutput()->setCrntFillColor(ORANGE);
			break;
		}
		case SELECT_CLR_RED:
		{
			pManager->GetOutput()->PrintMessage("Change the fill color to Red");
			crntClr = RED;
			prev_Fig->ChngFillClr(RED);
			pManager->GetOutput()->setCrntFillColor(RED);
			break;
		}
		case SELECT_CLR_GREEN:
		{
			pManager->GetOutput()->PrintMessage("Change the fill color to Green");
			crntClr = GREEN;
			prev_Fig->ChngFillClr(GREEN);
			pManager->GetOutput()->setCrntFillColor(GREEN);
			break;
		}
		case SELECT_CLR_BLUE:
		{
			pManager->GetOutput()->PrintMessage("Change the fill color to Blue");
			crntClr = BLUE;
			prev_Fig->ChngFillClr(BLUE);
			pManager->GetOutput()->setCrntFillColor(BLUE);
			break;
		}
		}
	}
	else 
	{
		pManager->GetOutput()->PrintMessage("There is no selected Figure to change its color");
	}

}

void FillClrAction::Undo()
{
	MadeUndo = true;	//The Undo done
	if (WasFilled)
	{
		prev_Fig->ChngFillClr(prevClr);
		pManager->GetOutput()->setCrntFillColor(prevClr);
	}
	else
	{
		prev_Fig->ChngFillClr(UI.BkGrndColor);
		UI.isfilled = false;
		prev_Fig->setisFilled(false);
	}
}

void FillClrAction::Redo()
{
	if (MadeUndo)
	{
		UI.isfilled = true;
		prev_Fig->ChngFillClr(crntClr);
		pManager->GetOutput()->setCrntFillColor(crntClr);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}

bool FillClrAction::CanRecord() {
	return true;
}

void FillClrAction::ExecuteRecord() {
	if ((pManager->getSelectedFigure() != NULL))
	{
		prevClr = pManager->GetOutput()->getCrntFillColor();
		prev_Fig = pManager->getSelectedFigure();
		switch (ActType)
		{
		case SELECT_CLR_BLACK:
		{
			crntClr = BLACK;
			prev_Fig->ChngFillClr(BLACK);
			pManager->GetOutput()->setCrntFillColor(BLACK);
			break;
		}
		case SELECT_CLR_YELLOW:
		{
			crntClr = YELLOW;
			prev_Fig->ChngFillClr(YELLOW);
			pManager->GetOutput()->setCrntFillColor(YELLOW);
			break;
		}
		case SELECT_CLR_ORANGE:
		{
			crntClr = ORANGE;
			prev_Fig->ChngFillClr(ORANGE);
			pManager->GetOutput()->setCrntFillColor(ORANGE);
			break;
		}
		case SELECT_CLR_RED:
		{
			crntClr = RED;
			prev_Fig->ChngFillClr(RED);
			pManager->GetOutput()->setCrntFillColor(RED);
			break;
		}
		case SELECT_CLR_GREEN:
		{
			crntClr = GREEN;
			prev_Fig->ChngFillClr(GREEN);
			pManager->GetOutput()->setCrntFillColor(GREEN);
			break;
		}
		case SELECT_CLR_BLUE:
		{
			crntClr = BLUE;
			prev_Fig->ChngFillClr(BLUE);
			pManager->GetOutput()->setCrntFillColor(BLUE);
			break;
		}
		}
	}
}