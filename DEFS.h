#ifndef DEFS_H
#define DEFS_H
#include<cstring>
#include "CMUgraphicsLib\CMUgraphics.h"
#include <cmath>

const double PI = atan(1) * 4; //defining pi
const int squareLength = 200;
const int hexagonLength = 100;



//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CIRCLE,
	SELECTION,
	SELECT_DRAW_CLR,
	SELECT_FILL_CLR,
	SELECT_CLR_BLACK,
	SELECT_CLR_YELLOW,
	SELECT_CLR_ORANGE,
	SELECT_CLR_RED,
	SELECT_CLR_GREEN,
	SELECT_CLR_BLUE,
	SELECT_DELETE,
	SELECT_MOVE,
	SELECT_MOVE_BY_DRAG,
	SELECT_RESIZE,
	SELECT_UNDO,
	SELECT_REDO,
	SELECT_CLEAR_ALL,
	SELECT_START_REC,
	SELECT_STOP_REC,
	SELECT_PLAY_REC,
	SELECT_SAVE,
	SELECT_LOAD,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	SELECT_FIG_TYPE,
	SELECT_FIG_COLOR,
	SELECT_FIG_TYPE_COLOR,
	SELECT_TRY_AGAIN

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};
struct Figcounttypecolor
{
	int RedCircle, RedHexagon, RedSquare, RedTriangle, RedRectangle,
		BlueCircle, BlueHexagon, BlueSquare, BlueTriangle, BlueRectangle,
		BlackCircle, BlackHexagon, BlackSquare, BlackTriangle, BlackRectangle,
		GreenCircle, GreenHexagon, GreenSquare, GreenTriangle, GreenRectangle,
		OrangeCircle, OrangeHexagon, OrangeSquare, OrangeTriangle, OrangeRectangle,
		YellowCircle, YellowHexagon, YellowSquare, YellowTriangle, YellowRectangle;
	Figcounttypecolor() 
	{ 
		std::memset(this, 0, sizeof(Figcounttypecolor));
	}
};
enum FigType
{
	Rec, Squ, Cir, Tri, Hex
};
enum RecordControl {
	on,off
};

#endif