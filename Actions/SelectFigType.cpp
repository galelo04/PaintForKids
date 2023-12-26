#include "SelectFigType.h"
#include "..\ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include"time.h"
#include <fstream>
#include <string>
#include "CFigure.h"
#include "CRectangle.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "CTriangle.h"
#include<cstdio>
SelectFigType:: SelectFigType (ApplicationManager* pApp) :Action(pApp)
{
}
 
void SelectFigType::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Pick and Hide Game");
	
}
void SelectFigType::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

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


	bool flag = 0;
	if (pManager->CountCirlces() == 0 && pManager->CountHexagons() == 0 && pManager->CountSquares() == 0 && pManager->CountRectangles() == 0 && pManager->CountTriangles() == 0)
	{
		pOut->PrintMessage("NoFigures, Go Draw Some Figures to Continue The Game");
		flag = 1;
	}
	switch (flag)

	{
	case 0:
	{
		//save parameters
		int countcircles = pManager->CountCirlces();
		int counthexagons = pManager->CountHexagons();
		int countsquares = pManager->CountSquares();
		int counttriangles = pManager->CountTriangles();
		int countrectangles = pManager->CountRectangles();



		int k = pManager->getFigcount();
		srand(time(NULL));
		int f = rand() % (k);
		FigType x = pManager->getfigtype(f);


		//play game
		while (count == 0)
		{
			switch (x)
			{
			case Cir:

				pOut->PrintMessage(" select all the circles");
				while (countcircles > count)
				{
					
					pIn->GetPointClicked(P.x, P.y);
					if (pManager->GetFigure(P.x, P.y) != NULL)
					{

						if (pManager->GetFigure(P.x, P.y)->gettype() == Cir) count++;
						else clickscount++;

					}
					else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 0)
					{
						count = 0;
						clickscount = 0;
						Execute();
						return;
					}
					else continue;
					pOut->PrintMessage("You got  " + std::to_string(clickscount) + " wrong and  " + std::to_string(count) + "  correct ");
					pManager->dElEtE(pManager->GetFigure(P.x, P.y));
					pManager->UpdateInterface();

				}
				pOut->PrintMessage(" You Scored ,  " + std::to_string(clickscount) + " Wrong Clicks and  " + std::to_string(count) + "  Correct Clicks ");

				break;
			case Hex:

				pOut->PrintMessage(" select all the Hexagons");
				while (counthexagons > count)
				{
					pIn->GetPointClicked(P.x, P.y);
					if (pManager->GetFigure(P.x, P.y) != NULL)
					{

						if (pManager->GetFigure(P.x, P.y)->gettype() == Hex) count++;
						else clickscount++;

					}
					else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 0)
					{
						count = 0;
						clickscount = 0;
						Execute();
						return;
					}
					else continue;

					pOut->PrintMessage("You got  " + std::to_string(clickscount) + " wrong and  " + std::to_string(count) + "  correct ");
					pManager->dElEtE(pManager->GetFigure(P.x, P.y));
					pManager->UpdateInterface();
				}

				pOut->PrintMessage(" You Scored ,  " + std::to_string(clickscount) + " Wrong Clicks and  " + std::to_string(count) + "  Correct Clicks ");

				break;
			case Tri:

				pOut->PrintMessage(" select all the Triangles");
				while (counttriangles > count)
				{
					pIn->GetPointClicked(P.x, P.y);
					if (pManager->GetFigure(P.x, P.y) != NULL)
					{

						if (pManager->GetFigure(P.x, P.y)->gettype() == Tri) count++;
						else clickscount++;

					}
					else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 0)
					{
						count = 0;
						clickscount = 0;
						Execute();
						return;
					}
					else continue;

					pOut->PrintMessage(" You got  " + std::to_string(clickscount) + " wrong and  " + std::to_string(count) + "  correct ");
					pManager->dElEtE(pManager->GetFigure(P.x, P.y));
					pManager->UpdateInterface();

				}
				pOut->PrintMessage(" You Scored ,  " + std::to_string(clickscount) + " Wrong Clicks and  " + std::to_string(count) + "  Correct Clicks ");

				break;
			case Squ:

				pOut->PrintMessage(" select all the Squares");
				while (countsquares > count)
				{
					pIn->GetPointClicked(P.x, P.y);
					if (pManager->GetFigure(P.x, P.y) != NULL)
					{

						if (pManager->GetFigure(P.x, P.y)->gettype() == Squ) count++;
						else clickscount++;

					}
					else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 0)
					{
						count = 0;
						clickscount = 0;
						Execute();
						return;
					}
					else continue;
					pOut->PrintMessage(" You got  " + std::to_string(clickscount) + " wrong and  " + std::to_string(count) + "  correct ");
					pManager->dElEtE(pManager->GetFigure(P.x, P.y));
					pManager->UpdateInterface();

				}
				pOut->PrintMessage(" You Scored ,  " + std::to_string(clickscount) + " Wrong Clicks and  " + std::to_string(count) + "  Correct Clicks ");

				break;
			case Rec:

				pOut->PrintMessage(" select all the Rectangles ");
				while (countrectangles > count)
				{
					pIn->GetPointClicked(P.x, P.y);

					if (pManager->GetFigure(P.x, P.y) != NULL)
					{

						if (pManager->GetFigure(P.x, P.y)->gettype() == Rec) count++;
						else clickscount++;
					}
					else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 0)
					{
						count = 0;
						clickscount = 0;
						Execute();
						return;
					}
					else continue;
					pOut->PrintMessage("You got  " + std::to_string(clickscount) + " wrong and  " + std::to_string(count) + "  correct ");
					pManager->dElEtE(pManager->GetFigure(P.x, P.y));
					pManager->UpdateInterface();

				}
				pOut->PrintMessage(" You Scored ,  " + std::to_string(clickscount) + " Wrong Clicks and  " + std::to_string(count) + "  Correct Clicks ");

				break;

			}
		}
		pManager->deselectall();
		break;
	}
	case 1:
	{
		break;
	}
	}
}
	
	
