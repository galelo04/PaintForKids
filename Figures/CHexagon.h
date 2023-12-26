#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon :public CFigure
{
private:
	Point Center;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);

	void Draw(Output* pOut) const;
	bool isPointInside(int x, int y) const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	FigType gettype();
	color getfillcolor();
	void PrintInfo(Output* pOut);
	void move(Point P);
	void DeleteFigure(CFigure*);
	Point GetPointtoUndo();
	void MakeSound();
	CFigure* getFigCopy();
};

#endif