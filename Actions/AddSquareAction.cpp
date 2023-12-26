#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center");

	//Read the center and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	SquareGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	pManager->setFlagForRec(-1);
	pManager->setFlagForSou(1);
}

void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* S = new CSquare(P, SquareGfxInfo);


	//Add the square to the list of figures
	pManager->AddFigure(S);

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

void AddSquareAction::Undo()
{
	pManager->dElEtE(pManager->GetLastFigure());
	MadeUndo = true;	//The Undo done
}

void AddSquareAction::Redo()
{
	if (MadeUndo)
	{
		CSquare* S = new CSquare(P, SquareGfxInfo);

		//Add the square to the list of figures
		pManager->AddFigure(S);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}

bool AddSquareAction::CanRecord() {
	return true;
}
void AddSquareAction::ExecuteRecord() {
	CSquare* S = new CSquare(P, SquareGfxInfo);

	pManager->AddFigure(S);
}

void AddSquareAction::operator=(Action* f) {
	AddSquareAction* pl = (AddSquareAction*)f;
	P.x = pl->P.x;
	P.y = pl->P.y;
	SquareGfxInfo.BorderWdth = pl->SquareGfxInfo.BorderWdth;
	SquareGfxInfo.DrawClr = pl->SquareGfxInfo.DrawClr;
	SquareGfxInfo.FillClr = pl->SquareGfxInfo.FillClr;
	SquareGfxInfo.isFilled = pl-> SquareGfxInfo.isFilled;
}

