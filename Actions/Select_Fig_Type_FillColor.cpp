#include "Select_Fig_Type_FillColor.h"
#include "..\ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include"time.h"
#include"time.h"
#include <fstream>
#include <string>
#include "CFigure.h"
#include "CRectangle.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "CTriangle.h"

Select_Fig_Type_FillColor::Select_Fig_Type_FillColor(ApplicationManager* pApp) :Action(pApp)
{
}

void Select_Fig_Type_FillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Pick and Hide Game");

}
void Select_Fig_Type_FillColor::Execute()
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
	else
	if (pManager->Countgreen() == 0 && pManager->Countblue() == 0 && pManager->Countblack() == 0 && pManager->Countyellow() == 0 && pManager->countorange() == 0 && pManager->CountRed() == 0)
	{
		pOut->PrintMessage("No Filled Figures, Go Fill Them to Continue The Game");
		flag = 1;
	}
	switch (flag)

	{
	case 0:
	{

		// save parameters
		int countred = pManager->CountRed();
		int countgreen = pManager->Countgreen();
		int countblue = pManager->Countblue();
		int countblack = pManager->Countblack();
		int countyellow = pManager->Countyellow();
		int countorange = pManager->countorange();



		int redSquares = pManager->Count().RedSquare;
		int redCircles = pManager->Count().RedCircle;
		int redHexagons = pManager->Count().RedHexagon;
		int redTriangles = pManager->Count().RedTriangle;
		int redRectangles = pManager->Count().RedRectangle;

		int blueSquares = pManager->Count().BlueSquare;
		int blueCircles = pManager->Count().BlueCircle;
		int blueHexagons = pManager->Count().BlueHexagon;
		int blueTriangles = pManager->Count().BlueTriangle;
		int blueRectangles = pManager->Count().BlueRectangle;

		int blackSquares = pManager->Count().BlackSquare;
		int blackCircles = pManager->Count().BlackCircle;
		int blackHexagons = pManager->Count().BlackHexagon;
		int blackTriangles = pManager->Count().BlackTriangle;
		int blackRectangles = pManager->Count().BlackRectangle;

		int greenSquares = pManager->Count().GreenSquare;
		int greenCircles = pManager->Count().GreenCircle;
		int greenHexagons = pManager->Count().GreenHexagon;
		int greenTriangles = pManager->Count().GreenTriangle;
		int greenRectangles = pManager->Count().GreenRectangle;

		int orangeSquares = pManager->Count().OrangeSquare;
		int orangeCircles = pManager->Count().OrangeCircle;
		int orangeHexagons = pManager->Count().OrangeHexagon;
		int orangeTriangles = pManager->Count().OrangeTriangle;
		int orangeRectangles = pManager->Count().OrangeRectangle;

		int yellowSquares = pManager->Count().YellowSquare;
		int yellowCircles = pManager->Count().YellowCircle;
		int yellowHexagons = pManager->Count().YellowHexagon;
		int yellowTriangles = pManager->Count().YellowTriangle;
		int yellowRectangles = pManager->Count().YellowRectangle;

		

		
		
		int k = pManager->getFigcount();
		int x = 120;
		int f=0;
		while (x == 120)
		{
			srand(time(NULL));
			 f = rand() % (k);
			color y = pManager->getfigfillcolor(f);
			if (y == RED) x = 0;
			if (y == BLACK) x = 1;
			if (y == BLUE) x = 2;
			if (y == YELLOW) x = 3;
			if (y == GREEN) x = 4;
			if (y == ORANGE) x = 5;
		}
		while (count == 0)
		{
			
			switch (x)
			{
			case 0:
				if (countred)
				{
					FigType x = pManager->getfigtype(f);
					switch (x)
					{
					case Squ:
						pOut->PrintMessage("Select all Red Squares");
						while (redSquares > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == RED && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Squ)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;

							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Cir:
						pOut->PrintMessage("Select all Red Circles");
						while (redCircles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == RED && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Cir)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;

							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Hex:
						pOut->PrintMessage("Select all Red Hexagons");
						while (redHexagons > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == RED && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Hex)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Tri:
						pOut->PrintMessage("Select all Red Triangles");
						while (redTriangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == RED && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Tri)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Rec:
						pOut->PrintMessage("Select all Red Rectangles");
						while (redRectangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == RED && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Rec)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					}


				}
				break;
			case 1:
				if (countblack)
				{
					FigType x = pManager->getfigtype(f);
					switch (x)
					{
					case Squ:
						pOut->PrintMessage("Select all black Squares");
						while (blackSquares > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLACK && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Squ)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Cir:
						pOut->PrintMessage("Select all Black Circles");
						while (blackCircles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLACK && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Cir)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Hex:
						pOut->PrintMessage("Select all Black Hexagons");
						while (blackHexagons > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLACK && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Hex)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Tri:
						pOut->PrintMessage("Select all Black Triangles");
						while (blackTriangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLACK && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Tri)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Rec:
						pOut->PrintMessage("Select all BLACK Rectangles");
						while (blackRectangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLACK	 && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Rec)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					}


				}
				break;
			case 2:
				if (countblue)
				{
					FigType x = pManager->getfigtype(f);
					switch (x)
					{
					case Squ:
						pOut->PrintMessage("Select all BLue Squares");
						while (blueSquares > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLUE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Squ)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Cir:
						pOut->PrintMessage("Select all BLue Circles");
						while (blueCircles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLUE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Cir)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Hex:
						pOut->PrintMessage("Select all Blue Hexagons");
						while (blueHexagons > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLUE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Hex)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Tri:
						pOut->PrintMessage("Select all BLue Triangles");
						while (blueTriangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLUE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Tri)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Rec:
						pOut->PrintMessage("Select all BLUE Rectangles");
						while (blueRectangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLUE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Rec)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					}


				}
				break;
			case 3:
				if (countyellow)
				{
					FigType x = pManager->getfigtype(f);
					switch (x)
					{
					case Squ:
						pOut->PrintMessage("Select all Yellow Squares");
						while (yellowSquares > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == YELLOW && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Squ)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Cir:
						pOut->PrintMessage("Select all YELLOW Circles");
						while (yellowCircles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == YELLOW && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Cir)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Hex:
						pOut->PrintMessage("Select all Yellow Hexagons");
						while (yellowHexagons > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == YELLOW && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Hex)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Tri:
						pOut->PrintMessage("Select all YELLOW Triangles");
						while (yellowTriangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == YELLOW && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Tri)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Rec:
						pOut->PrintMessage("Select all YELLOW Rectangles");
						while (yellowRectangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == YELLOW && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Rec)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					}


				}
				break;
			case 4:
				if (countgreen)
				{
					FigType x = pManager->getfigtype(f);
					switch (x)
					{
					case Squ:
						pOut->PrintMessage("Select all Green Squares");
						while (greenSquares > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == GREEN && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Squ)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Cir:
						pOut->PrintMessage("Select all Green Circles");
						while (greenCircles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == GREEN && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Cir)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Hex:
						pOut->PrintMessage("Select all GREEN Hexagons");
						while (greenHexagons > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == GREEN && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Hex)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Tri:
						pOut->PrintMessage("Select all GREEN Triangles");
						while (greenTriangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == GREEN && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Tri)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Rec:
						pOut->PrintMessage("Select all GREEN Rectangles");
						while (greenRectangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == GREEN && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Rec)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					}


				}
				break;
			case 5:
				if (countorange)
				{
					FigType x = pManager->getfigtype(f);
					switch (x)
					{
					case Squ:
						pOut->PrintMessage("Select all ORange Squares");
						while (orangeSquares > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == ORANGE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Squ)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Cir:
						pOut->PrintMessage("Select all Orange Circles");
						while (orangeCircles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == ORANGE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Cir)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Hex:
						pOut->PrintMessage("Select all Orange Hexagons");
						while (orangeHexagons > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == ORANGE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Hex)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Tri:
						pOut->PrintMessage("Select all Orange Triangles");
						while (orangeTriangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == ORANGE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Tri)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					case Rec:
						pOut->PrintMessage("Select all ORANGE Rectangles");
						while (orangeRectangles > count)
						{
							pIn->GetPointClicked(P.x, P.y);

							if (pManager->GetFigure(P.x, P.y) != NULL)
							{
								if (pManager->GetFigure(P.x, P.y)->getfillcolor() == ORANGE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled && pManager->GetFigure(P.x, P.y)->gettype() == Rec)
								{
									count++;
								}
								else
								{
									clickscount++;
								}
							}
							else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 2)
							{
								count = 0;
								clickscount = 0;
								Execute();
								return;
							}
							else continue;
							pOut->PrintMessage("You got " + std::to_string(clickscount) + " wrong and " + std::to_string(count) + " correct");

							pManager->dElEtE(pManager->GetFigure(P.x, P.y));
							pManager->UpdateInterface();
						}

						pOut->PrintMessage("You Scored, " + std::to_string(clickscount) + " Wrong Clicks and " + std::to_string(count) + " Correct Clicks");
						break;

					}


				}
				break;
			}
		}
		pManager->deselectall();
		break;
	}
	case 1:
		break;
	}
}


