#include "CCircle.h"


CCircle::CCircle()
{
}

CCircle::CCircle(Point C, Point R, GfxInfo FigureGfxInfo ):CFigure(FigureGfxInfo),Center(C), RadiusPoint(R)
{
	radius = floor(sqrt(pow(Center.x - RadiusPoint.x, 2) + pow(Center.y - RadiusPoint.y, 2)));

	if (2 * radius > UI.height - 2 * UI.ToolBarHeight)
	{
		Center.y = UI.height / 2;
		radius = UI.height / 2 - UI.ToolBarHeight;
	}
	else if ((Center.y - radius) < UI.ToolBarHeight)
	{
		Center.y = radius + UI.ToolBarHeight;
	}
	else if ((Center.y + radius) > UI.height - UI.StatusBarHeight)
	{
		Center.y = UI.height - UI.ToolBarHeight - radius;
	}
	if ((Center.x - radius) < 0)
	{
		Center.x = radius;
	}
	else if ((Center.x + radius) > UI.width)
	{
		Center.x = UI.width - 15 - radius;
	}
	//The above lines changes the value of the x and y of the center of the circle to not overdraw the toolbar and the statusbar
	//and not to get out of the draw window 
	//and changes the radius to if the diameter is bigger than the window's height 
}


void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, radius, FigGfxInfo, Selected);
}

bool CCircle::isPointInside(int x, int y) const
{
	int distance = floor(sqrt(pow((Center.x - x), 2) + pow((Center.y - y), 2)));
	return distance <= radius;
}

void CCircle::Save(ofstream& OutFile)
{ 
	OutFile << "\nCIRC" << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << radius << '\t';
	CFigure::Save(OutFile);
	
}

void CCircle::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> radius ;
	CFigure::Load(Infile);
}

void CCircle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID : " + to_string(ID) +
		" / Center ( " + to_string(Center.x) + " , " + to_string(Center.y) +
		" ) / Radius : " + to_string(radius));
}
FigType CCircle::gettype()
{
	Type = Cir;
	return Type;
}
color CCircle::getfillcolor()
{
	return FigGfxInfo.FillClr;

	}
int CCircle:: getradius()
{
	return radius;
}
void CCircle::move(Point P1)
{
	Center.x = P1.x;
	Center.y = P1.y;
}
void CCircle::DeleteFigure(CFigure* p) {
	delete p;
}

Point CCircle::GetPointtoUndo()
{
	return Center;
}
void CCircle::MakeSound() {
	PlaySound(TEXT("sounds\\circle"), NULL, SND_ASYNC);
}
CFigure* CCircle::getFigCopy()
{
	CFigure* p = new CCircle(Center, RadiusPoint, FigGfxInfo);
	p->set_ID(ID);
	p->SetSelected(Selected);
	return p;
}