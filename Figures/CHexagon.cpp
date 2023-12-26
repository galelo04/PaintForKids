#include "CHexagon.h"




CHexagon::CHexagon()
{
}

CHexagon::CHexagon(Point C, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo),Center(C)
{
	if (Center.y - cos(PI / 6.0) * hexagonLength < UI.ToolBarHeight)
	{
		Center.y = cos(PI / 6.0) * hexagonLength + UI.ToolBarHeight;
	}
	if (Center.y + cos(PI / 6.0) * hexagonLength > UI.height - UI.StatusBarHeight)
	{
		Center.y = UI.height - UI.StatusBarHeight - cos(PI / 6.0) * hexagonLength;
	}
	if (Center.x - hexagonLength < 0)
	{
		Center.x = hexagonLength;
	}
	if ((Center.x + hexagonLength) > UI.width)
	{
		Center.x = UI.width - 15 - hexagonLength;
	}
	//The above lines changes the value of the x and y of the center of the hexagon to not overdraw the toolbar  and the statusbar
	//and not to get out of the draw window
}

/*void CHexagon::operator=(CFigure* Other)
{
	CHexagon* Hex = (CHexagon*)Other;
	ID = Hex->get_ID();
	Selected = Hex->IsSelected();
	FigGfxInfo = Hex->getgfxinfo();
	Type = Hex->gettype();
	Center = Hex->Center;
}*/

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

bool CHexagon::isPointInside(int x, int y) const
{

	//by dividing the hexagon into four triangles and applying
	//the same logic used to find if the point inside a triangle four times
	//and if the point found in any of the four triangles it returns true

	Point Vertix1, Vertix2 ,Vertix3;
	//the third vertix is the center and it is the same for all triangles

	Vertix3.x = Center.x + floor(hexagonLength * cos(PI / 3.0));
	Vertix3.y = Center.y + floor(hexagonLength * sin(PI / 3.0));

	for (int i = 1; i < 5; i++)
	{
		Vertix1.x = Center.x + floor(hexagonLength * cos(PI * (i+1) / 3.0));
		Vertix1.y = Center.y + floor(hexagonLength * sin(PI * (i+1) / 3.0));
		Vertix2.x = Center.x + floor(hexagonLength * cos(PI * (i+2) / 3.0));
		Vertix2.y = Center.y + floor(hexagonLength * sin(PI * (i+2) / 3.0));


		
		double area1 = abs(Vertix1.x * (Vertix2.y - y) + Vertix2.x * (y - Vertix1.y) + x * (Vertix1.y - Vertix2.y)) / 2.0;
		double area2 = abs(Vertix2.x * (Vertix3.y - y) + Vertix3.x * (y - Vertix2.y) + x * (Vertix2.y - Vertix3.y)) / 2.0;
		double area3 = abs(Vertix3.x * (Vertix1.y - y) + Vertix1.x * (y - Vertix3.y) + x * (Vertix3.y - Vertix1.y)) / 2.0;
		double area4 = abs(Vertix1.x * (Vertix2.y - Vertix3.y) + Vertix2.x * (Vertix3.y - Vertix1.y) + Vertix3.x * (Vertix1.y - Vertix2.y)) / 2.0;
		if (area4 == (area1 + area2 + area3))
		{
			return true;
		}
	}
	return false;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "\nHEX" << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t';
	CFigure::Save(OutFile);
}

void CHexagon::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y;
	CFigure::Load(Infile);
}

void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID : " + to_string(ID) +
		" / Center ( " + to_string(Center.x) + " , " + to_string(Center.y) +
		" ) / Hexagon Side Length : " + to_string(hexagonLength));
}
FigType CHexagon::gettype()
{
	Type = Hex;

	return Type;
}
color CHexagon::getfillcolor()
{
	return FigGfxInfo.FillClr;
}
void CHexagon::move(Point P1)
{
	Center.x = P1.x;
	Center.y = P1.y;
}
void CHexagon::DeleteFigure(CFigure*p) {
	delete p;
}

Point CHexagon::GetPointtoUndo()
{
	return Center;
}
//void CHexagon::MakeSound() {
	//PlaySound(TEXT("sounds\\hexagon"), NULL, SND_ASYNC);
//}