#include "Delete.h"
#include "..\ApplicationManager.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Start_Recording.h"
Delete::Delete(ApplicationManager* pApp):Action(pApp) {}

void Delete::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}
void Delete::Execute() 
{
	ReadActionParameters();
	
	if (pManager->getSelectedFigure() != NULL) 
	{
		DeletedFig = pManager->getSelectedFigure();
		pManager->dElEtE(pManager->getSelectedFigure());
	}
}

void Delete::Undo()
{
	MadeUndo = true;	//The Undo done
	pManager->AddFigure(DeletedFig);
}

void Delete::Redo()
{
	if (MadeUndo)
	{
		pManager->dElEtE(DeletedFig);
	}
	else
		pManager->GetOutput()->PrintMessage("There is no action to Redo, You must make Undo first");
}
bool Delete::CanRecord() {
	return true;
}

void Delete::ExecuteRecord() {
	DeletedFig = pManager->getSelectedFigure();
	if (pManager->getSelectedFigure() != NULL)
		pManager->dElEtE(pManager->getSelectedFigure());
}