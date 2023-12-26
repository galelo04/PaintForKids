#include "CTriangle.h"


CTriangle::CTriangle()
{
}

CTriangle::CTriangle(Point V1, Point V2, Point V3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo),Vertix1(V1),Vertix2(V2),Vertix3(V3)
{
	if (Vertix1.y < UI.ToolBarHeight)
		Vertix1.y = UI.ToolBarHeight;
	if (Vertix2.y < UI.ToolBarHeight)
		Vertix2.y = UI.ToolBarHeight;
	if (Vertix3.y < UI.ToolBarHeight)
		Vertix3.y = UI.ToolBarHeight;
	if (Vertix1.y > UI.height - UI.StatusBarHeight)
		Vertix1.y = UI.height - UI.StatusBarHeight;
	if (Vertix2.y > UI.height - UI.StatusBarHeight)
		Vertix2.y = UI.height - UI.StatusBarHeight;
	if (Vertix3.y > UI.height - UI.StatusBarHeight)
		Vertix3.y = UI.height - UI.StatusBarHeight;
	//The above lines changes the value of the y of the points to not overdraw the toolbar and the statusbar
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}

bool CTriangle::isPointInside(int x, int y) const
{
	//this method is called barycentric coordinate system it checks if a point is inside a triangle using areas summtion
	//it divides the triangle into 3 triangles formed from the 3 original vertices and the point clicked
	//and if the summtion of the areas of the 3 triangles is the same as the area of the original triangle it returns true 

	
	double area1 = abs(Vertix1.x * (Vertix2.y - y) + Vertix2.x * (y - Vertix1.y) + x * (Vertix1.y - Vertix2.y)) / 2.0;
	double area2 = abs(Vertix2.x * (Vertix3.y - y) + Vertix3.x * (y - Vertix2.y) + x * (Vertix2.y - Vertix3.y)) / 2.0;
	double area3 = abs(Vertix3.x * (Vertix1.y - y) + Vertix1.x * (y - Vertix3.y) + x * (Vertix3.y - Vertix1.y)) / 2.0;
	double area4 = abs(Vertix1.x * (Vertix2.y - Vertix3.y) + Vertix2.x * (Vertix3.y - Vertix1.y) + Vertix3.x * (Vertix1.y - Vertix2.y)) / 2.0;

	return(area4 == (area1 + area2 + area3));
	
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "\nTRIANG" << '\t' << ID << '\t' << Vertix1.x << '\t' << Vertix1.y << '\t' << Vertix2.x << '\t' << Vertix2.y << '\t' << Vertix3.x << '\t' << Vertix3.y << '\t';
	CFigure::Save(OutFile);
}

void CTriangle::Load(ifstream& Infile)
{
	Infile >> ID >> Vertix1.x >> Vertix1.y >> Vertix2.x >> Vertix2.y >> Vertix3.x >> Vertix3.y;
	CFigure::Load(Infile);
}

void CTriangle::PrintInfo(Output* pOut)
{
	int SideLength1 = sqrt(pow((Vertix1.x - Vertix2.x), 2) + pow((Vertix1.y - Vertix2.y), 2));
	int SideLength2 = sqrt(pow((Vertix2.x - Vertix3.x), 2) + pow((Vertix2.y - Vertix3.y), 2));
	int SideLength3 = sqrt(pow((Vertix1.x - Vertix3.x), 2) + pow((Vertix1.y - Vertix3.y), 2));
	pOut->PrintMessage( "ID : "+to_string(ID) + 
						" / Vertix 1 ( " + to_string(Vertix1.x) + " , " + to_string(Vertix1.y) +
						" ) / Vertix 2 ( " + to_string(Vertix2.x) + " , " + to_string(Vertix2.y) + 
						" ) / Vertix 3 ( " + to_string(Vertix3.x) + " , " + to_string(Vertix3.y) + 
					" ) / Side Length 1 : " + to_string(SideLength1) +
					" / Side Length 2 : " + to_string(SideLength2) +
					" / Side Length 3 : " + to_string(SideLength3));
}
FigType CTriangle::gettype()
{
	Type = Tri;

	return Type;
}
color CTriangle::getfillcolor()
{
	return FigGfxInfo.FillClr;
}
Point CTriangle::getvertix1()
{
	return Vertix1;
}
Point CTriangle::getvertix2()
{
	return Vertix2;
}
Point CTriangle::getvertix3()
{
	return Vertix3;
}
Point CTriangle::getcentroid()
{
	Point K;
	K.x = (Vertix1.x + Vertix2.x + Vertix3.x) /( 3);
	K.y = (Vertix1.y + Vertix2.y + Vertix3.y) /( 3);
	return K;
}
void CTriangle::move(Point P)
{
	
	int centroidx = (Vertix1.x + Vertix2.x + Vertix3.x) / (3);
	int centroidy = (Vertix1.y + Vertix2.y + Vertix3.y) / (3);
	int xref = P.x - centroidx;
	int yref = P.y - centroidy;
	Vertix1.x += xref;
	Vertix2.x += xref;
	Vertix3.x += xref;
	Vertix1.y += yref;
	Vertix2.y += yref;
	Vertix3.y += yref;
}
void CTriangle::resize(Point P)
{
	if (P.x >= Vertix1.x - 25 && P.x <= Vertix1.x + 25 && P.y >= Vertix1.y - 25 && P.y <= Vertix1.y + 25)
	{
		Vertix1.x = P.x;
		Vertix1.y = P.y;
	}
	else if (P.x >= Vertix2.x - 25 && P.x <= Vertix2.x + 25 && P.y >= Vertix2.y - 25 && P.y <= Vertix2.y + 25)
	{
		Vertix2.x = P.x;
		Vertix2.y = P.y;
	}
	else if (P.x >= Vertix3.x - 25 && P.x <= Vertix3.x + 25 && P.y >= Vertix3.y - 25 && P.y <= Vertix3.y + 25)
	{
		Vertix3.x = P.x;
		Vertix3.y = P.y;
	}

}
void CTriangle::DeleteFigure(CFigure * p) {
	delete p;
}

Point CTriangle::GetPointtoUndo()
{
	return getcentroid();
}

void CTriangle::MakeSound() {
	PlaySound(TEXT("sounds\\triangle"), NULL, SND_ASYNC);
}

CFigure* CTriangle::getFigCopy()
{
	CFigure* p = new CTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo);
	p->set_ID(ID);
	p->SetSelected(Selected);
	return p;
}