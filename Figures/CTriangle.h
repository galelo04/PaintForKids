#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertix1;
	Point Vertix2;
	Point Vertix3;
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

	virtual void PrintInfo(Output* pOut);
	virtual FigType gettype();
	virtual color getfillcolor();
	Point getvertix1();
	Point getvertix2();
	Point getvertix3();
	Point getcentroid();
	virtual void move(Point P);
	void DeleteFigure(CFigure*);
	virtual Point GetPointtoUndo();
	void MakeSound();
	CFigure* getFigCopy();
};

#endif