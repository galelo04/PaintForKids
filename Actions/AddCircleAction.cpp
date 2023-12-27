#include "AddCircleAction.h"
#include "CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"
 
AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at the radius point");

	//Read the radius and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	
	CircleGfxInfo.isFilled = UI.isfilled;//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->setFlagForRec(off);

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CircleGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);

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

void AddCircleAction::Undo()
{
	pManager->dElEtE(pManager->GetLastFigure());
	MadeUndo = true;	//The Undo done
}

void AddCircleAction::Redo()
{
	if (MadeUndo)
	{
		CCircle* C = new CCircle(P1, P2, CircleGfxInfo);

		//Add the circle to the list of figures
		pManager->AddFigure(C);
	}
	else 
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}
bool AddCircleAction::CanRecord() {
	return true;
}

void AddCircleAction::ExecuteRecord() {

	CCircle* C = new CCircle(P1, P2, CircleGfxInfo);


	pManager->AddFigure(C);
}

void AddCircleAction::operator=(Action* f) {
	AddCircleAction* pl = (AddCircleAction*)f;
	P1.x = pl->P1.x;
	P1.y = pl->P1.y;
	P2.x = pl->P2.x;
	P2.y = pl->P2.y;
	CircleGfxInfo.BorderWdth = pl->CircleGfxInfo.BorderWdth;
	CircleGfxInfo.DrawClr = pl->CircleGfxInfo.DrawClr;
	CircleGfxInfo.FillClr = pl->CircleGfxInfo.FillClr;
	CircleGfxInfo.isFilled = pl->CircleGfxInfo.isFilled;
}

void AddCircleAction::playsound()
{
	string voice = "sounds\\circle";
	PlaySound(voice.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}
