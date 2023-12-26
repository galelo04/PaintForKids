#include "CRectangle.h"
#include <cmath>


CRectangle::CRectangle()
{
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo),Corner1(P1),Corner2(P2)
{
	if (Corner1.y < UI.ToolBarHeight)
		Corner1.y = UI.ToolBarHeight;
	if (Corner2.y < UI.ToolBarHeight)
		Corner2.y = UI.ToolBarHeight;
	if (Corner1.y > UI.height - UI.StatusBarHeight)
		Corner1.y = UI.height - UI.StatusBarHeight;
	if (Corner2.y > UI.height - UI.StatusBarHeight)
		Corner2.y = UI.height - UI.StatusBarHeight;
	//The above lines changes the value of the y of the points to not overdraw the toolbar and the statusbar
}

/*void CRectangle::operator=(CFigure* Other)
{
	CRectangle* Rect = (CRectangle*)Other;
	ID = Rect->get_ID();
	Selected = Rect->IsSelected();
	FigGfxInfo = Rect->getgfxinfo();
	Type = Rect->gettype();
	Corner1 = Rect->Corner1;
	Corner2 = Rect->Corner2;
}*/
	
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isPointInside(int x , int y) const
{
	return (x > min(Corner1.x, Corner2.x) && x < max(Corner1.x, Corner2.x)
		&& y>min(Corner1.y, Corner2.y) && y < max(Corner1.y, Corner2.y));
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "\nRECT" << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y<<'\t';
	CFigure::Save(OutFile);
}

void CRectangle::Load(ifstream& Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	CFigure::Load(Infile);
}

void CRectangle::PrintInfo(Output* pOut)
{
	int Length = max(abs(Corner1.x - Corner2.x), abs(Corner1.y - Corner2.y));
	int Width = min(abs(Corner1.x - Corner2.x), abs(Corner1.y - Corner2.y));
	pOut->PrintMessage("ID : " + to_string(ID) +
		" / Corner 1 ( " + to_string(Corner1.x) + " , " + to_string(Corner1.y) +
		" ) / Corner 2 ( " + to_string(Corner2.x) + " , " + to_string(Corner2.y) +
		" ) / Length : " + to_string(Length) +
		" / Width : " + to_string(Width));
}
FigType CRectangle::gettype()
{
	Type = Rec;

	return Type;
}
color CRectangle::getfillcolor()
{
	return FigGfxInfo.FillClr;
}
int CRectangle::getwidth()
{
	int width;
	width =Corner1.x - Corner2.x;
	if (width > 0) return width;
	else return -width;
}
int CRectangle::getheight()
{
	int height;
	height = Corner1.y - Corner2.y;;
	if (height > 0) return height;
	else return -height;

}
void CRectangle::move(Point P)
{
	int width = abs(Corner1.x - Corner2.x);
	int height = abs(Corner1.y - Corner2.y);
	
	Corner1.x = P.x + width/2;
	Corner2.x = P.x - width/2;
	Corner1.y = P.y - height/2;
	Corner2.y = P.y + height/2;
}
void CRectangle::DeleteFigure(CFigure*p) {
	delete p;
}

Point CRectangle::GetPointtoUndo()
{
	Point P;
	P.x = abs(Corner1.x - Corner2.x) / 2;
	P.y = abs(Corner1.y - Corner2.y) / 2;
	return P;
}

//void CRectangle::MakeSound() {
	//PlaySound(TEXT("sounds\\rectangle"), NULL, SND_ASYNC);
//}