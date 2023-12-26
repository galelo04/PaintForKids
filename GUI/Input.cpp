#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

buttonstate Input::getmousebuttonstate(const button btMouse, int& x, int& y)
{
	return pWind->GetButtonState(btMouse,x,y);
}

void Input::GetCoordofmouse(int& x, int& y) const
{
	pWind->GetMouseCoord(x, y);
}



//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_SELECT: return SELECTION;
			case ITM_DRAWCLR: return SELECT_DRAW_CLR;
			case ITM_FILLCLR: return SELECT_FILL_CLR;
			case ITM_COLOR_BLACK: return SELECT_CLR_BLACK;
			case ITM_COLOR_YELLOW: return SELECT_CLR_YELLOW;
			case ITM_COLOR_ORANGE: return SELECT_CLR_ORANGE;
			case ITM_COLOR_RED: return SELECT_CLR_RED;
			case ITM_COLOR_GREEN: return SELECT_CLR_GREEN;
			case ITM_COLOR_BLUE: return SELECT_CLR_BLUE;
			case ITM_DELETE: return SELECT_DELETE;
			case ITM_MOVE: return SELECT_MOVE;
			case ITM_MOVE_BY_DRAG: return SELECT_MOVE_BY_DRAG;
			case ITM_RESIZE: return SELECT_RESIZE;
			case ITM_UNDO: return SELECT_UNDO;
			case ITM_REDO: return SELECT_REDO;
			case ITM_CLEAR_ALL: return SELECT_CLEAR_ALL;
			case ITM_STRT_REC: return SELECT_START_REC;
			case ITM_STP_REC: return SELECT_STOP_REC;
			case ITM_PLY_REC: return SELECT_PLAY_REC;
			case ITM_SAVE: return SELECT_SAVE;
			case ITM_LOAD: return SELECT_LOAD;
			case ITM_SWITCH_TO_PLAY: return TO_PLAY;
			case ITM_EXIT_DRAW: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder) {
			case ITM_FIG_TYPE: return SELECT_FIG_TYPE;
			case ITM_FIG_COLOR: return SELECT_FIG_COLOR;
			case ITM_FIG_TYPE_COLOR: return SELECT_FIG_TYPE_COLOR;
			case ITM_TRY_AGAIN: return SELECT_TRY_AGAIN;
			case ITM_SWITCH_TO_DRAW: return TO_DRAW;
			case ITM_EXIT_PLAY: return EXIT;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
