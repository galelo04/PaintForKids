#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"


class CCircle : public CFigure
{
private:
	Point Center;
	Point RadiusPoint;
	int radius;
public:
	CCircle();
	CCircle (Point, Point, GfxInfo FigureGfxInfo);
	//virtual void operator= (CFigure* Other);

	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(int x, int y) const;
	virtual void Save(ofstream& OutFile) ;	
	virtual void Load(ifstream& Infile) ;	

	virtual void PrintInfo(Output* pOut) ;
	virtual FigType gettype();
	virtual color getfillcolor();
	int getradius();
	virtual void move(Point P);
	void DeleteFigure(CFigure*);
	virtual Point GetPointtoUndo();
	//void MakeSound();
};

#endif