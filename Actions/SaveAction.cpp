#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include "input.h"
#include "Output.h"
#include "CFigure.h"
#include <string>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Save All , Write the name of the file (Don't add the extension of the file because it is already prewritten)");
	pOut->clearkeyspressed();
	FileName = pIn->GetSrting(pOut);
	pOut->clearmouseclicks();
	pOut->ClearStatusBar();
	pOut->PrintMessage("The file has been saved as " + FileName+".txt");
}

void SaveAction::Execute()
{
	
	ReadActionParameters();
	std::ofstream OutFile(FileName+".txt");
	if(UI.DrawColor==RED)
		OutFile << "RED\t";
	else if (UI.DrawColor == BLUE)
		OutFile << "BLUE\t";
	else if (UI.DrawColor == BLACK)
		OutFile << "BLACK\t";
	else if (UI.DrawColor == GREEN)
		OutFile << "GREEN\t";
	else if (UI.DrawColor == ORANGE)
		OutFile << "ORANGE\t";
	else if (UI.DrawColor == YELLOW)
		OutFile << "YELLOW\t";
	if (UI.isfilled)
	{
		if (UI.FillColor == RED)
			OutFile << "RED\n";
		else if (UI.FillColor == BLUE)
			OutFile << "BLUE\n";
		else if (UI.FillColor == BLACK)
			OutFile << "BLACK\n";
		else if (UI.FillColor == GREEN)
			OutFile << "GREEN\n";
		else if (UI.FillColor == ORANGE)
			OutFile << "ORANGE\n";
		else if (UI.FillColor == YELLOW)
			OutFile << "YELLOW\n";
	}
	else
		OutFile << "NO_FILL\n";
	OutFile << pManager->getFigcount();
	pManager->saveall(OutFile);
	OutFile.close();
}


