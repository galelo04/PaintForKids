#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include "input.h"
#include "Output.h"
#include "CFigure.h"
#include "CRectangle.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "CTriangle.h"
#include <string>

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Load file , Write the name of the file (Don't add the extension of the file because it is already prewritten)");
	pOut->clearkeyspressed();
	FileName = pIn->GetSrting(pOut);
	pOut->clearmouseclicks();
	pOut->ClearStatusBar();
	pOut->PrintMessage("The file loaded is " + FileName + ".txt");
}

void LoadAction::Execute()
{
	ReadActionParameters();
	std::ifstream InFile(FileName + ".txt");
	if(InFile.is_open())
		pManager->GetOutput()->PrintMessage("The file loaded is " + FileName + ".txt");
	else
		pManager->GetOutput()->PrintMessage("There is no file with that name");
	std::string currentdrawcolor, currentfillcolor , type;
	int figcount;
	
	InFile >> currentdrawcolor >> currentfillcolor;
	InFile >> figcount;
	CFigure* myfig = NULL;
	for (int i = 0; i < figcount; i++)
	{
		InFile >> type;
		if (type == "RECT")
			myfig = new CRectangle;
		else if (type == "SQR")
			myfig = new CSquare;
		else if (type == "CIRC")
			myfig = new CCircle;
		else if (type == "HEX")
			myfig = new CHexagon;
		else if (type == "TRIANG")
			myfig = new CTriangle;
		myfig->Load(InFile);
		pManager->AddFigure(myfig);
	}
	if (currentdrawcolor == "RED")
		UI.DrawColor = RED;
	else if (currentdrawcolor == "BLUE")
		UI.DrawColor = BLUE;
	else if (currentdrawcolor == "BLACK")
		UI.DrawColor = BLACK;
	else if (currentdrawcolor == "GREEN")
		UI.DrawColor = GREEN;
	else if (currentdrawcolor == "ORANGE")
		UI.DrawColor = ORANGE;
	else if (currentdrawcolor == "YELLOW")
		UI.DrawColor = YELLOW;
	if (currentfillcolor == "NO_FILL")
		UI.isfilled = false;
	else if (currentfillcolor == "RED")
		UI.FillColor = RED;
	else if (currentfillcolor == "BLUE")
		UI.FillColor = BLUE;
	else if (currentfillcolor == "BLACK")
		UI.FillColor = BLACK;
	else if (currentfillcolor == "GREEN")
		UI.FillColor = GREEN;
	else if (currentfillcolor == "ORANGE")
		UI.FillColor = ORANGE;
	else if (currentfillcolor == "YELLOW")
		UI.FillColor = YELLOW;
	pManager->deselectall();
	
}
