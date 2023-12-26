#include "Select_Fig_Fill_Color.h"
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
Select_Fig_Fill_Color::Select_Fig_Fill_Color(ApplicationManager* pApp) :Action(pApp)
{
}

void Select_Fig_Fill_Color::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Pick and Hide Game");

}
void Select_Fig_Fill_Color::Execute()
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
	

	bool flag=0;
	if (pManager->Countgreen() == 0 && pManager->Countblue() == 0 && pManager->Countblack() == 0 && pManager->Countyellow() == 0 && pManager->countorange() == 0  && pManager->CountRed() == 0)
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



		int k = pManager->getFigcount();
		int x = 120;
		int f;
		while (x == 120)
		{
			srand(time(NULL));
			f = rand() % (k);
			color y = pManager->getfigfillcolor(f);
			if (y == RED) x = 0;
			if (y == BLUE) x = 1;
			if (y == BLACK) x = 2;
			if (y == GREEN) x = 3;
			if (y == YELLOW) x = 4;
			if (y == ORANGE) x = 5;
		}

		
		while (count == 0)
		{
			switch (x)
			{
			case 0:
				if (countred)
				{
					pOut->PrintMessage(" select all Red Figures");
					while (countred > count)
					{
						pIn->GetPointClicked(P.x, P.y);
						if (pManager->GetFigure(P.x, P.y) != NULL)
						{
							if (pManager->GetFigure(P.x, P.y)->getfillcolor() == RED && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled) count++;
							else clickscount++;
						}
						else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 1)
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
				}
				break;
			case 1:
				if (countblue)
				{
					pOut->PrintMessage(" select all Blue Figures");
					while (countblue > count)
					{
						pIn->GetPointClicked(P.x, P.y);
						if (pManager->GetFigure(P.x, P.y) != NULL)
						{
							if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLUE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled) count++;
							else clickscount++;

						}
						else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 1)
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
				}
				break;
			case 2:
				if (countblack)
				{
					pOut->PrintMessage(" select all Black Figures ");
					while (countblack > count)
					{
						pIn->GetPointClicked(P.x, P.y);
						if (pManager->GetFigure(P.x, P.y) != NULL)
						{
							if (pManager->GetFigure(P.x, P.y)->getfillcolor() == BLACK && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled) count++;
							else clickscount++;

						}
						else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 1)
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
				}
				break;
			case 3:
				if (countgreen)
				{
					pOut->PrintMessage(" select all the green figures");
					while (countgreen > count)
					{
						pIn->GetPointClicked(P.x, P.y);
						if (pManager->GetFigure(P.x, P.y) != NULL)
						{
							if (pManager->GetFigure(P.x, P.y)->getfillcolor() == GREEN && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled) count++;
							else clickscount++;

						}
						else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 1)
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
				}
				break;
			case 4:
				if (countyellow)
				{
					pOut->PrintMessage(" select all the yellow figures");
					while (countyellow > count)
					{
						pIn->GetPointClicked(P.x, P.y);
						if (pManager->GetFigure(P.x, P.y) != NULL)
						{
							if (pManager->GetFigure(P.x, P.y)->getfillcolor() == YELLOW && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled) count++;
							else clickscount++;

						}
						else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 1)
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
				}
				break;
			case 5:
				if (countorange)
				{
					pOut->PrintMessage(" select all the orange figures");
					while (countorange > count)
					{
						pIn->GetPointClicked(P.x, P.y);
						if (pManager->GetFigure(P.x, P.y) != NULL)
						{
							if (pManager->GetFigure(P.x, P.y)->getfillcolor() == ORANGE && pManager->GetFigure(P.x, P.y)->getgfxinfo().isFilled) count++;
							else  clickscount++;

						}
						else if (P.y >= 0 && P.y < UI.ToolBarHeight && (P.x / UI.MenuItemWidth) == 1)
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
