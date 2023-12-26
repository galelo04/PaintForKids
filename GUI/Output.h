#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearToolBar() const;
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo RectGfxInfo, int sizelength,bool selected = false) const;  //Draw a Square
	void DrawCircle(Point P1, int radius, GfxInfo RectGfxInfo, bool selected) const;
	void DrawHex(Point P1, GfxInfo RectGfxInfo, int sizelength , bool selected ) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const;

	///Make similar functions for drawing all other figure types.
	void clearmouseclicks();
	void clearkeyspressed();
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	void setCrntDrawColor(color clr);
	void setCrntFillColor(color clr);
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif