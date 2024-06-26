#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{
	RectGfxInfo.isFilled = false;
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->setFlagForRec(off);
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	prevfig = R;
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);

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

void AddRectAction::Undo()
{
	pManager->deleteforundo(prevfig);
	MadeUndo = true;	//The Undo done
}

void AddRectAction::Redo()
{
	if (MadeUndo)
	{
		//Add the rectangle to the list of figures
		pManager->AddFigure(prevfig);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}
bool AddRectAction::CanRecord() {
	return true;
}

void AddRectAction::ExecuteRecord() {
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);
	pManager->AddFigure(R);
}

void AddRectAction::operator=(Action* f) {
	AddRectAction* pl = (AddRectAction*)f;
	P1.x = pl->P1.x;
	P1.y = pl->P1.y;
	P2.x = pl->P2.x;
	P2.y = pl->P2.y;
	RectGfxInfo.BorderWdth = pl->RectGfxInfo.BorderWdth;
	RectGfxInfo.DrawClr = pl->RectGfxInfo.DrawClr;
	RectGfxInfo.FillClr = pl->RectGfxInfo.FillClr;
	RectGfxInfo.isFilled = pl->RectGfxInfo.isFilled;
}

void AddRectAction::playsound()
{
	string voice = "sounds\\rectangle";
	PlaySound(voice.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

