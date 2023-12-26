
#include "SwitchDraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <string>
#include "CFigure.h"
#include "CRectangle.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "CTriangle.h"
#include<cstdio>
SwitchDraw::SwitchDraw(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchDraw::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Switch to Draw Mode");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}

void SwitchDraw::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->clearall();
	//load action
	std::string currentdrawcolor, currentfillcolor, type, FileName;
	FileName = "PlayMode";
	int figcount;
	std::ifstream InFile(FileName + ".txt");
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
	pManager->deselectall();
	pManager->UpdateInterface();
	
	//delete the file
	std::remove("PlayMode.txt");
	std::ofstream file("PlayMode.txt", std::ios::trunc);
	file.close();

}

