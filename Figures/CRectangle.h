#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(int x , int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

	virtual void PrintInfo(Output* pOut);
	virtual FigType gettype();
	virtual color getfillcolor();
	int getwidth();
	int getheight();
	virtual void move(Point P);
	void DeleteFigure(CFigure*);
	virtual Point GetPointtoUndo();
	void MakeSound();
	CFigure* getFigCopy();
	//void MakeSound();
};

#endif