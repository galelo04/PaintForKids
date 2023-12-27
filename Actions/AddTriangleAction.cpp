#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first vertix");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second vertix");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third vertix");

	//Read 2nd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->setFlagForRec(off);
	//Create a rectangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	prevfig = T;
	//Add the rectangle to the list of figures
	pManager->AddFigure(T);

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

void AddTriangleAction::Undo()
{
	pManager->deleteforundo(prevfig);
	MadeUndo = true;	//The Undo done
}

void AddTriangleAction::Redo()
{
	if (MadeUndo)
	{

		//Add the rectangle to the list of figures
		pManager->AddFigure(prevfig);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}
bool AddTriangleAction::CanRecord() {
	return true;
}

void  AddTriangleAction::ExecuteRecord() {

	CTriangle* T = new CTriangle(P1, P2, P3, TriangleGfxInfo);
	pManager->AddFigure(T);
}

void AddTriangleAction::operator=(Action* f) {
	AddTriangleAction* pl = (AddTriangleAction*)f;
	P1.x = pl->P1.x;
	P1.y = pl->P1.y;
	P2.x = pl->P2.x;
	P2.y = pl->P2.y;
	P3.x = pl->P3.x;
	P3.y = pl->P3.y;
	TriangleGfxInfo.BorderWdth = pl->TriangleGfxInfo.BorderWdth;
	TriangleGfxInfo.DrawClr = pl->TriangleGfxInfo.DrawClr;
	TriangleGfxInfo.FillClr = pl->TriangleGfxInfo.FillClr;
	TriangleGfxInfo.isFilled = pl->TriangleGfxInfo.isFilled;
}

void AddTriangleAction::playsound()
{
	string voice = "sounds\\triangle";
	PlaySound(voice.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

