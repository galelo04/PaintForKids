#include "MoveFig.h"
#include "..\ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"

MoveFig::MoveFig(ApplicationManager* pApp) :Action(pApp)
{}

void MoveFig::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move Figure : Click on the point");
	pIn->GetPointClicked(P.x, P.y);
	Moved_Fig = pManager->getSelectedFigure();
	prevpoint = pManager->getSelectedFigure()->GetPointtoUndo();

}

void MoveFig::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	pManager->getSelectedFigure()->move(P);
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pManager->deselectall();
}

void MoveFig::Undo()
{
	MadeUndo = true;	//The Undo done
	Moved_Fig->move(prevpoint);
}

void MoveFig::Redo()
{
	if (MadeUndo)
	{
		Moved_Fig->move(P);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}

bool MoveFig::CanRecord() {
	return true;
}
void MoveFig::ExecuteRecord() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->getSelectedFigure()->move(P);
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pManager->deselectall();
}