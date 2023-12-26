#include "CSquare.h"



CSquare::CSquare()
{
}

CSquare::CSquare(Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo),Center(C)
{
	
	if ((Center.y - squareLength / 2) < UI.ToolBarHeight)
	{
		Center.y = squareLength / 2 + UI.ToolBarHeight;
	}
	if ((Center.y + squareLength / 2) > UI.height - UI.StatusBarHeight)
	{
		Center.y = UI.height - UI.StatusBarHeight - squareLength / 2;
	}
	if ((Center.x - squareLength / 2) < 0)
	{
		Center.x = squareLength / 2;
	}
	if ((Center.x + squareLength / 2) > UI.width)
	{
		Center.x = UI.width - 15 - squareLength / 2;
	}
	//The above lines changes the value of the x and y of the center of the square to not overdraw the toolbar and the statusbar
	//and not to get out of the draw window
}

/*void CSquare::operator=(CFigure* Other)
{
	CSquare* Squ = (CSquare*)Other;
	ID = Squ->get_ID();
	Selected = Squ->IsSelected();
	FigGfxInfo = Squ->getgfxinfo();
	Type = Squ->gettype();
	Center = Squ->Center;
}*/

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::isPointInside(int x, int y) const
{
	return(x >= Center.x - squareLength / 2 && x <= Center.x + squareLength / 2
		&& y >= Center.y - squareLength / 2 && y <= Center.y + squareLength / 2);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "\nSQR" << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t';
	CFigure::Save(OutFile);
}

void CSquare::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y;
	CFigure::Load(Infile);
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID : "+to_string(ID)+
		" / Center ( "+to_string(Center.x)+" , " +to_string(Center.y)+ 
		" ) / Square Side Length : " + to_string(squareLength));
}
FigType CSquare::gettype()
{
	Type = Squ;
	return Type;
}
color CSquare::getfillcolor()
{
	return FigGfxInfo.FillClr;
}
void CSquare::move(Point P1)
{
	Center.x = P1.x;
	Center.y = P1.y;
}
void CSquare::DeleteFigure(CFigure*p) {
	delete p;
}

Point CSquare::GetPointtoUndo()
{
	return Center;
}
//void CSquare::MakeSound() {
	//PlaySound(TEXT("sounds\\square"), NULL, SND_ASYNC);
//}