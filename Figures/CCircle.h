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
	 color getfillcolor();
	int getradius();
<<<<<<< HEAD
	virtual void move(Point P);
	virtual void resize(Point P);
=======
	 void move(Point P);
>>>>>>> 98527c84ad3931c4ba7bf0f41c4e21addd984e89
	void DeleteFigure(CFigure*);
	 Point GetPointtoUndo();
	void MakeSound();
	CFigure* getFigCopy();
};

#endif