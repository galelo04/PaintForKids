#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon :public CFigure
{
private:
	Point Center;
	int hexagonLength;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);


	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual FigType gettype();
	virtual color getfillcolor();
	virtual void PrintInfo(Output* pOut);
	virtual void move(Point P);
	virtual void resize(Point P);
	void DeleteFigure(CFigure*);
	Point GetPointtoUndo();
	void MakeSound();
	CFigure* getFigCopy();
};

#endif