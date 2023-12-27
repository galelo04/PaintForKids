#include "CFigure.h"

int CFigure::last_ID = 1;

CFigure::CFigure()
{
}

CFigure::CFigure(GfxInfo FigureGfxInfo):FigGfxInfo(FigureGfxInfo),Selected(false)
{
	set_ID(last_ID++);
}



void CFigure::set_ID(int rid)
{
	ID = rid;
}
int CFigure::get_ID() const
{
	return ID;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;

}

void CFigure::ChngFillClr(color Fclr)
{	
	setisFilled(true);
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::Save(ofstream& OutFile)
{
	OutFile << FigGfxInfo.BorderWdth << '\t';
	if (FigGfxInfo.DrawClr == RED)
		OutFile << "RED" << '\t';
	else if (FigGfxInfo.DrawClr == BLUE)
		OutFile << "BLUE" << '\t';
	else if (FigGfxInfo.DrawClr == BLACK)
		OutFile << "BLACK" << '\t';
	else if (FigGfxInfo.DrawClr == GREEN)
		OutFile << "GREEN" << '\t';
	else if (FigGfxInfo.DrawClr == ORANGE)
		OutFile << "ORANGE" << '\t';
	else if (FigGfxInfo.DrawClr == YELLOW)
		OutFile << "YELLOW" << '\t';
	if (FigGfxInfo.isFilled)
	{
		if (FigGfxInfo.FillClr == RED)
			OutFile << "RED" << '\t';
		else if (FigGfxInfo.FillClr == BLUE)
			OutFile << "BLUE" << '\t';
		else if (FigGfxInfo.FillClr == BLACK)
			OutFile << "BLACK" << '\t';
		else if (FigGfxInfo.FillClr == GREEN)
			OutFile << "GREEN" << '\t';
		else if (FigGfxInfo.FillClr == ORANGE)
			OutFile << "ORANGE" << '\t';
		else if (FigGfxInfo.FillClr == YELLOW)
			OutFile << "YELLOW" << '\t';
	}
	else
		OutFile << "NO_FILL";
}

void CFigure::Load(ifstream& Infile)
{
	std::string drawcolor;
	std::string fillcolor;
	Infile >> FigGfxInfo.BorderWdth>> drawcolor >> fillcolor;
	if (drawcolor == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (drawcolor == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	else if (drawcolor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (drawcolor == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (drawcolor == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (drawcolor == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	if (fillcolor == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else if (fillcolor == "RED")
		FigGfxInfo.FillClr = RED;
	else if (fillcolor == "BLUE")
		FigGfxInfo.FillClr = BLUE;
	else if (fillcolor == "BLACK")
		FigGfxInfo.FillClr = BLACK;
	else if (fillcolor == "GREEN")
		FigGfxInfo.FillClr = GREEN;
	else if (fillcolor == "ORANGE")
		FigGfxInfo.FillClr = ORANGE;
	else if (fillcolor == "YELLOW")
		FigGfxInfo.FillClr = YELLOW;
}
color CFigure::getfillcolor()
{
	return FigGfxInfo.FillClr;
}
color CFigure::getdrawcolor()
{
	return FigGfxInfo.DrawClr;
}
GfxInfo CFigure::getgfxinfo()
{
	return FigGfxInfo;
}

void CFigure::setisFilled(bool flag)
{
	FigGfxInfo.isFilled = flag;
}

