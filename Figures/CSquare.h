#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	//virtual void operator= (CFigure* Other);

	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual FigType gettype();
	virtual color getfillcolor();
	virtual void PrintInfo(Output* pOut);
	virtual void move(Point P);
	void DeleteFigure(CFigure*);
	virtual Point GetPointtoUndo();
	//void MakeSound();
};

#endif