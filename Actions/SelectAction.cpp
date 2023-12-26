#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "input.h"
#include "Output.h"
#include "CFigure.h"
#include <string>
#include"Start_Recording.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Select a Figure : Click on any Figure");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();

		
}

void SelectAction::Execute()
{
	ReadActionParameters();
	CFigure* FigAtPoint = pManager->GetFigure(P.x, P.y);
	if (FigAtPoint != NULL)
	{
		pManager->setSelectedFigure(FigAtPoint);
		pManager->getSelectedFigure()->PrintInfo(pManager->GetOutput());
		if (pManager->getSelectedFigure()->IsSelected())
		{
			pManager->getSelectedFigure()->SetSelected(false);
			pManager->setSelectedFigure(NULL);
		}
		else
		{
			pManager->deselectall();
			pManager->getSelectedFigure()->SetSelected(true);
		}
	}
	// if i pressed on the drawing area and there is selected figure i dont want the info to disappear
	else if (pManager->getSelectedFigure() != NULL) 
		pManager->getSelectedFigure()->PrintInfo(pManager->GetOutput());
}


bool SelectAction::CanRecord() {
	return true;
}

void SelectAction::ExecuteRecord() {
	pManager->setSelectedFigure(pManager->GetFigure(P.x, P.y));
	if (pManager->getSelectedFigure() != NULL)
	{
		pManager->getSelectedFigure()->PrintInfo(pManager->GetOutput());
	}
	if ((pManager->getSelectedFigure() != NULL))
	{
		if (pManager->getSelectedFigure()->IsSelected())
			pManager->getSelectedFigure()->SetSelected(false);
		else
		{
			pManager->deselectall();
			pManager->getSelectedFigure()->SetSelected(true);
		}
	}
}