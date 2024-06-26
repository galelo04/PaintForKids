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

	 void Draw(Output* pOut) const;
      bool isPointInside(int x, int y) const;
	 void Save(ofstream& OutFile) ;	
	 void Load(ifstream& Infile) ;	

	 void PrintInfo(Output* pOut) ;
	 FigType gettype();
	int getradius();
	virtual void move(Point P);
	virtual void resize(Point P);
	void DeleteFigure(CFigure*);
	 Point GetPointtoUndo();
	void MakeSound();
};

#endif