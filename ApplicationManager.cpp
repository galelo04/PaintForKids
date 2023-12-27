#include "ApplicationManager.h"
#include "AddRectAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"
#include "AddHexAction.h"
#include "AddCircleAction.h"
#include "SelectAction.h"
#include "DrawClrAction.h"
#include "FillClrAction.h"
#include "SwitchPlayAction.h"
#include "SelectFigType.h"
#include "Select_Fig_Fill_Color.h"
#include "Select_Fig_Type_FillColor.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "Action.h"
#include "ClearAction.h"
#include "FillClrAction.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "Action.h"
#include "ClearAction.h"
#include "MoveFig.h"
#include "Delete.h"
#include "UndoAction.h"
#include "RedoAction.h"
#include "Start_Recording.h"
#include"Stop_Recording.h"
#include"SwitchDraw.h"
#include "MoveByDragAction.h"
#include "ReszieByDragAction.h"
#include "VolumeAction.h"
#include "MuteAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	//PlaySound(TEXT("sounds\\welcome"), NULL, SND_ASYNC);
	
	FigCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;

	ActionCount = 0;
	for (int i = 0; i < MaxActionCount; i++)
		ActionList[i] = NULL;

	RecordCount = 0;
	for (int i = 0; i < MaxRecordCount; i++)
		RecordingList[i] = NULL;

	FlagForRedoUndo = 0;
	counterForUndoRedo = 0;
    FlagForSou=on;
	FlagForRec = on;
	forDeleteFigList = 0;
	SelectedFig = NULL;
	pRecord = NULL;
	pRecord_2 = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		break;
	case SELECT_DRAW_CLR:
		pAct = new DrawClrAction(this);
		break;
	case SELECT_FILL_CLR:
		pAct = new FillClrAction(this);
		break;
	case SELECTION:
		pAct = new SelectAction(this);
		break;
	case TO_PLAY:
		pAct = new SwitchPlayAction(this);
		break;
	case TO_DRAW:
		pAct = new SwitchDraw(this);
		break;
	case SELECT_SAVE:
		pAct = new SaveAction(this);
		break;
	case SELECT_LOAD:
		pAct = new LoadAction(this);
		break;
	case SELECT_CLEAR_ALL:
		pAct = new ClearAction(this);
		break;
	case SELECT_FIG_TYPE:
		pAct = new SelectFigType(this);
		break;
	case SELECT_FIG_COLOR:
		pAct = new Select_Fig_Fill_Color(this);
		break;
	case SELECT_FIG_TYPE_COLOR:
		pAct = new Select_Fig_Type_FillColor(this);
		break;
	case SELECT_MOVE:
		pAct = new MoveFig(this);
		break;
	case SELECT_DELETE:
		pAct = new Delete(this);
		break;
	case SELECT_START_REC:
		pAct = new Start_Recording(this);
		break;
	case SELECT_STOP_REC:
		pAct = new Stop_Recording(this);
		break;
	case SELECT_PLAY_REC:
		pAct = new Play_Recording(this);
		break;
		case SELECT_UNDO:
			pAct = new UndoAction(this);
			break;
		case SELECT_REDO:
			pAct = new RedoAction(this);
			break;
		case SELECT_MOVE_BY_DRAG:
			pAct = new MoveByDragAction(this);
			break;
		case SELECT_RESIZE:
			pAct = new ResizeByDragAction(this);
			break;
		case SELECT_VOLUME_ON:
			pAct = new VolumeAction(this);
			break;
		case SELECT_MUTE:
			pAct = new MuteAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		case EXIT:
			return;
	}
	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		if (FlagForSou == on)
			pAct->playsound();

		if ((ActionCount < MaxActionCount) && (pAct->CanUndo()))
			ActionList[ActionCount++] = pAct;

		else if ((ActionCount == MaxActionCount) && (pAct->CanUndo()))
		{
			if (get_recorder() == NULL)
				delete ActionList[0];
			for (int i = 0; i < MaxActionCount - 1; i++)
				ActionList[i] = ActionList[i + 1];
			ActionList[MaxActionCount - 1] = pAct;
		}
		

		if (!(pAct->CanUndo())&& pAct->CanRecord() == false)
			delete pAct;
		else if (this->get_recorder() != NULL && pAct->CanRecord() == true) {
			if (RecordCount < MaxRecordCount)
				RecordingList[RecordCount++] = pAct;
			else if (forDeleteFigList == 0) {
				forDeleteFigList = FigCount;
				pRecord = NULL;
			}
		}
		
		//You may need to change this line depending to your implementation

		pAct = NULL;
	}

	
}

Action* ApplicationManager::GetLastCanUndoActions()
{
	--ActionCount;
	if(ActionCount>=0)
		return ActionList[ActionCount];
	else
	{
		ActionCount = 0;
		return NULL;
	}
}

Action* ApplicationManager::GetLastCanRedoActions()
{
	
	if(ActionCount<=5)
		return ActionList[ActionCount++];
	else
	{
		ActionCount = 5;
		return NULL;
	}
}
Action* ApplicationManager::getActionList(int i) {
	return ActionList[i];
}
void ApplicationManager::setActionList(Action* p, int i) {
	ActionList[i] = p;
}


void ApplicationManager::set_recorder_for_play(Start_Recording* p) {
	pRecord_2 = p;
}
Start_Recording* ApplicationManager::get_recorder_for_play() {
	return pRecord_2;
}

void ApplicationManager::set_recorder(Start_Recording* p) {
	pRecord = p;
}
Start_Recording* ApplicationManager::get_recorder() {
	return pRecord;
}
int ApplicationManager::getRecordCount() {
	return RecordCount;
}
Action* ApplicationManager::getActionRecordList(int i) {
	return RecordingList[i];
}
void ApplicationManager::setRecordCountto_0() {
	RecordCount = 0;
}
void ApplicationManager::deleteFigureForRecord(int i){
	delete FigList[i];
	FigList[i] = NULL;
}

void ApplicationManager::UpdateInterfaceForRecord() const
{
	for (int i = 0; i < RecordCount; i++)
	{
		if (FigList[i] != NULL)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
void ApplicationManager::setFlagForRec(RecordControl p) {
	FlagForRec = p;
}
RecordControl ApplicationManager::getFlagForRec() {
	return FlagForRec;
}
void ApplicationManager::setFlagForSou(RecordControl p) {
	FlagForSou = p;
}
RecordControl ApplicationManager::getFlagForSou() {
	return FlagForSou;
}
void ApplicationManager::setForDeleteFigList(int p) {
	forDeleteFigList = p;
}
int ApplicationManager::getForDeleteFigLis() {
	return forDeleteFigList;
}

int ApplicationManager::CountRectangles()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->gettype() == Rec) count++;
	return count;
}
int ApplicationManager::CountSquares()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->gettype() == Squ) count++;
	return count;
}
int ApplicationManager::CountTriangles()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->gettype() == Tri) count++;
	return count;
}
int ApplicationManager::CountCirlces()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->gettype() == Cir) count++;
	return count;
}
int ApplicationManager::CountHexagons()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->gettype() == Hex) count++;
	return count;
}
int ApplicationManager::CountRed()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getfillcolor() == RED && FigList[i]->getgfxinfo().isFilled) count++;
	return count;
}
int ApplicationManager::Countblack()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getfillcolor() == BLACK && FigList[i]->getgfxinfo().isFilled) count++;
	return count;
}
int ApplicationManager::Countyellow()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getfillcolor() == YELLOW && FigList[i]->getgfxinfo().isFilled) count++;
	return count;
}
int ApplicationManager::Countgreen()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getfillcolor() == GREEN && FigList[i]->getgfxinfo().isFilled) count++;
	return count;
}
int ApplicationManager::Countblue()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getfillcolor() == BLUE && FigList[i]->getgfxinfo().isFilled) count++;
	return count;
}
int ApplicationManager::countorange()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getfillcolor() == ORANGE && FigList[i]->getgfxinfo().isFilled) count++;
	return count;
}

color ApplicationManager:: getfigfillcolor(int i)
{
	if (FigList[i]!=NULL && FigList[i]->getgfxinfo().isFilled)
		return FigList[i]->getfillcolor();
	else return SKYBLUE;
}
FigType ApplicationManager::getfigtype(int i)
{
	return FigList[i]->gettype();
}
Figcounttypecolor ApplicationManager::Count()
{
	Figcounttypecolor a;
	for (int i = 0; i < FigCount; i++)
	{
		
		if (FigList[i]->getfillcolor() == RED && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Squ) a.RedSquare++;
		if (FigList[i]->getfillcolor() == RED && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Cir) a.RedCircle++;
		if (FigList[i]->getfillcolor() == RED && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Hex) a.RedHexagon++;
		if (FigList[i]->getfillcolor() == RED && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Tri) a.RedTriangle++;
		if (FigList[i]->getfillcolor() == RED && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Rec) a.RedRectangle++;

		if (FigList[i]->getfillcolor() == BLUE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Squ) a.BlueSquare++;
		if (FigList[i]->getfillcolor() == BLUE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Cir) a.BlueCircle++;
		if (FigList[i]->getfillcolor() == BLUE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Hex) a.BlueHexagon++;
		if (FigList[i]->getfillcolor() == BLUE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Tri) a.BlueTriangle++;
		if (FigList[i]->getfillcolor() == BLUE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Rec) a.BlueRectangle++;

		if (FigList[i]->getfillcolor() == BLACK && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Squ) a.BlackSquare++;
		if (FigList[i]->getfillcolor() == BLACK && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Cir) a.BlackCircle++;
		if (FigList[i]->getfillcolor() == BLACK && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Hex) a.BlackHexagon++;
		if (FigList[i]->getfillcolor() == BLACK && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Tri) a.BlackTriangle++;
		if (FigList[i]->getfillcolor() == BLACK && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Rec) a.BlackRectangle++;

		if (FigList[i]->getfillcolor() == GREEN && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Squ) a.GreenSquare++;
		if (FigList[i]->getfillcolor() == GREEN && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Cir) a.GreenCircle++;
		if (FigList[i]->getfillcolor() == GREEN && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Hex) a.GreenHexagon++;
		if (FigList[i]->getfillcolor() == GREEN && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Tri) a.GreenTriangle++;
		if (FigList[i]->getfillcolor() == GREEN && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Rec) a.GreenRectangle++;

		if (FigList[i]->getfillcolor() == ORANGE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Squ) a.OrangeSquare++;
		if (FigList[i]->getfillcolor() == ORANGE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Cir) a.OrangeCircle++;
		if (FigList[i]->getfillcolor() == ORANGE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Hex) a.OrangeHexagon++;
		if (FigList[i]->getfillcolor() == ORANGE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Tri) a.OrangeTriangle++;
		if (FigList[i]->getfillcolor() == ORANGE && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Rec) a.OrangeRectangle++;

		if (FigList[i]->getfillcolor() == YELLOW && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Squ) a.YellowSquare++;
		if (FigList[i]->getfillcolor() == YELLOW && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Cir) a.YellowCircle++;
		if (FigList[i]->getfillcolor() == YELLOW && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Hex) a.YellowHexagon++;
		if (FigList[i]->getfillcolor() == YELLOW && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Tri) a.YellowTriangle++;
		if (FigList[i]->getfillcolor() == YELLOW && FigList[i]->getgfxinfo().isFilled && FigList[i]->gettype() == Rec) a.YellowRectangle++;
	}
	return a;
}


//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
	}
}
void ApplicationManager::setFigCount(int i) {
	FigCount = i;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount-1; i>= 0; i--)
	{
		if (FigList[i]->isPointInside(x, y))
		{
			return FigList[i];
		}
	}
	return NULL;
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	//
}

CFigure* ApplicationManager::GetLastFigure() const
{
	return FigList[FigCount-1];
}


void ApplicationManager::setSelectedFigure(CFigure* pFig)
{
	SelectedFig = pFig;
}

CFigure* ApplicationManager::getSelectedFigure() const
{
	return SelectedFig;
}

int ApplicationManager::getFigcount() const
{
	return FigCount;
}

void ApplicationManager::clearall()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	for (int i = 0; i < getRecordCount(); i++)
	{
		delete RecordingList[i];
		RecordingList[i] = NULL;
	}
	//don"t forget delete the array of action
	//for stop recording
	set_recorder(NULL);
	set_recorder_for_play(NULL);
	FigCount = 0;
	pOut->ClearDrawArea();

}

int ApplicationManager::getIndexFigList(CFigure*p) {
	for (int i = 0; i < FigCount; i++)
		if (p == FigList[i])
			return i;
}
void ApplicationManager::dElEtE(CFigure * Fig) {
	
		int k = getIndexFigList(Fig);

		Fig->DeleteFigure(Fig);
		setSelectedFigure(NULL);
		FigList[k] = NULL;
		for (int i = k; i < FigCount - 1; i++)
			swap(FigList[i], FigList[i + 1]);
		FigCount -= 1;
		pOut->ClearDrawArea();
	
	
}




void ApplicationManager::saveall(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}

void ApplicationManager::deselectall()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
}



//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();

	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]!=NULL)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}

	
	
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut;	}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < MaxActionCount; i++)
	{
		if (ActionList[i]!=NULL)
			delete ActionList[i];
	}
	delete pIn;
	delete pOut;
	
	
}
