#include "SwitchPlayAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchPlayAction::SwitchPlayAction(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchPlayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Switch to Play Mode");
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}

void SwitchPlayAction::Execute()
{
	ReadActionParameters();
	
	//save action
	std::string FileName;
	FileName = "PlayMode";
	std::ofstream OutFile(FileName + ".txt");
	if (UI.DrawColor == RED)
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
