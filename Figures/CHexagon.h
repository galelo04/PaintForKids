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

<<<<<<< HEAD
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual FigType gettype();
	virtual color getfillcolor();
	virtual void PrintInfo(Output* pOut);
	virtual void move(Point P);
	virtual void resize(Point P);
=======
	void Draw(Output* pOut) const;
	bool isPointInside(int x, int y) const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	FigType gettype();
	color getfillcolor();
	void PrintInfo(Output* pOut);
	void move(Point P);
>>>>>>> 98527c84ad3931c4ba7bf0f41c4e21addd984e89
	void DeleteFigure(CFigure*);
	Point GetPointtoUndo();
	void MakeSound();
	CFigure* getFigCopy();
};

#endif