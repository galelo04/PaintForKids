#include "Output.h"




Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1366;
	UI.height = 768;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 48;
	UI.isfilled = false;
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = LIGHTSKYBLUE;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	//CreatePlayToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar() const {
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string DrawMenuItemImages[DRAW_ITM_COUNT];

	DrawMenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	DrawMenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Sqr.jpg";
	DrawMenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	DrawMenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	DrawMenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	DrawMenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	DrawMenuItemImages[ITM_DRAWCLR] = "images\\MenuItems\\Menu_DrawClr.jpg";
	DrawMenuItemImages[ITM_FILLCLR] = "images\\MenuItems\\Menu_FillClr.jpg";
	DrawMenuItemImages[ITM_COLOR_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	DrawMenuItemImages[ITM_COLOR_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	DrawMenuItemImages[ITM_COLOR_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	DrawMenuItemImages[ITM_COLOR_RED] = "images\\MenuItems\\Menu_Red.jpg";
	DrawMenuItemImages[ITM_COLOR_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	DrawMenuItemImages[ITM_COLOR_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	DrawMenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	DrawMenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	DrawMenuItemImages[ITM_MOVE_BY_DRAG] = "images\\MenuItems\\Menu_Movebydrag.jpg";
	DrawMenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";
	DrawMenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	DrawMenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	DrawMenuItemImages[ITM_CLEAR_ALL] = "images\\MenuItems\\Menu_Clear.jpg";
	DrawMenuItemImages[ITM_STRT_REC] = "images\\MenuItems\\Menu_StartRec.jpg";
	DrawMenuItemImages[ITM_STP_REC] = "images\\MenuItems\\Menu_StopRec.jpg";
	DrawMenuItemImages[ITM_PLY_REC] = "images\\MenuItems\\Menu_PlayRec.jpg";
	DrawMenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	DrawMenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	DrawMenuItemImages[ITM_SWITCH_TO_PLAY] = "images\\MenuItems\\Menu_PlayMode.jpg";
	DrawMenuItemImages[ITM_EXIT_DRAW] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
	{
		pWind->DrawImage(DrawMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayMenuItemImages[PLAY_ITM_COUNT];

	PlayMenuItemImages[ITM_FIG_TYPE] = "images\\MenuItems\\Menu_FigType.jpg";
	PlayMenuItemImages[ITM_FIG_COLOR] = "images\\MenuItems\\Menu_FigClr.jpg";
	PlayMenuItemImages[ITM_FIG_TYPE_COLOR] = "images\\MenuItems\\Menu_FigTypeClr.jpg";
	PlayMenuItemImages[ITM_TRY_AGAIN] = "images\\MenuItems\\Menu_TryAgain.jpg";
	PlayMenuItemImages[ITM_SWITCH_TO_DRAW] = "images\\MenuItems\\Menu_DrawMode.jpg";
	PlayMenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(PlayMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::clearmouseclicks()
{
	pWind->FlushMouseQueue();
}

void Output::clearkeyspressed()
{
	pWind->FlushKeyQueue();
}

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
void Output::setCrntDrawColor(color clr)
{
	UI.DrawColor = clr;
}
void Output::setCrntFillColor(color clr)
{
	UI.FillColor = clr;
	//UI.isfilled = true;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawSquare(Point P1, GfxInfo SqrGfxInfo, bool selected) const
{
	int arrx[4] = { P1.x - squareLength / 2, P1.x - squareLength / 2, P1.x + squareLength / 2, P1.x + squareLength / 2 };
	int arry[4] = { P1.y - squareLength / 2, P1.y + squareLength / 2, P1.y + squareLength / 2, P1.y - squareLength / 2 };

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SqrGfxInfo.BorderWdth);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(arrx, arry, 4, style);

}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}


void Output::DrawHex(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	
	int arrx[6];
	int arry[6];
	for (int i = 0; i < 6; i++)
	{
		arrx[i] = P1.x + floor(hexagonLength * cos(PI * i / 3.0));
		arry[i] = P1.y + floor(hexagonLength * sin(PI * i / 3.0));
	}

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, HexGfxInfo.BorderWdth);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(arrx, arry, 6, style);

}


void Output::DrawCircle(Point P1,int radius, GfxInfo CircGfxInfo, bool selected) const
{
	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
	{
		DrawingClr = CircGfxInfo.DrawClr;
	}
	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, radius, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

