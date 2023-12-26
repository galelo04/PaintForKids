#include "AddHexAction.h"
#include "CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddHexAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center");

	//Read the center and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	HexGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	HexGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	pManager->setFlagForRec(-1);
	pManager->setFlagForSou(1);
}
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P, HexGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);

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

void AddHexAction::Undo()
{
	pManager->dElEtE(pManager->GetLastFigure());
	MadeUndo = true;	//the Undo done
}

void AddHexAction::Redo()
{
	if (MadeUndo)
	{
		CHexagon* H = new CHexagon(P, HexGfxInfo);

		//Add the hexagon to the list of figures
		pManager->AddFigure(H);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}
bool AddHexAction::CanRecord() {
	return true;
}
void AddHexAction::ExecuteRecord() {
	CHexagon* H = new CHexagon(P, HexGfxInfo);
	pManager->AddFigure(H);
}


 void AddHexAction::operator=(Action*f) {
	 AddHexAction* pl = (AddHexAction*)f;
	 P.x = pl->P.x;
	 P.y = pl->P.y;
	 HexGfxInfo.BorderWdth = pl->HexGfxInfo.BorderWdth;
	 HexGfxInfo.DrawClr = pl->HexGfxInfo.DrawClr;
	 HexGfxInfo.FillClr = pl->HexGfxInfo.FillClr;
	 HexGfxInfo.isFilled = pl->HexGfxInfo.isFilled;
}
