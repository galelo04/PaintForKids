#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "CFigure.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Action.h"
#include"Start_Recording.h"
#include <Windows.h>
#include "MMSystem.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200};	//Max no of figures
	enum { MaxActionCount = 5 };
	enum { MaxRecordCount = 20 };
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig;//Pointer to the selected figure
	int ActionCount;
	Action* ActionList[MaxActionCount];

	RecordControl FlagForSou;
	RecordControl FlagForRec;
	int RecordCount;
	int forDeleteFigList;
	Action* RecordingList[MaxRecordCount];

	Start_Recording* pRecord;
	Start_Recording* pRecord_2;
	//Pointers to Input and Output classes
	Input *pIn;
	Output* pOut;
	
public:	
	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void setSelectedFigure(CFigure* pFig);
	CFigure* getSelectedFigure() const ;
	int getFigcount() const;
	void setFigCount(int);
	void clearall();
	
	void saveall(ofstream& OutFile);
	void deselectall();
	
	//void AddActions(Action* pAct);
	CFigure* GetLastFigure() const;
	Action* GetLastCanUndoActions();
	Action* GetLastCanRedoActions();

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface()const ;	//Redraws all the drawing window

	int CountRectangles();
	int CountSquares();
	int CountTriangles();
	int CountCirlces();
	int CountHexagons();
	int CountRed();
	int Countblack();
	int Countyellow();
	int Countgreen();
	int Countblue();
	int countorange();
	Figcounttypecolor Count();
	void dElEtE(CFigure* Fig);
	void set_recorder_for_play(Start_Recording* p);
	Start_Recording* get_recorder_for_play();

	void set_recorder(Start_Recording* p);
	Start_Recording* get_recorder();
	color getfigfillcolor(int);
	FigType getfigtype(int);

	int getIndexFigList(CFigure*);
	int getRecordCount();
	void setRecordCountto_0();
	Action* getActionRecordList(int);
	void deleteFigureForRecord(int);
	void UpdateInterfaceForRecord() const;
	void setFlagForRec(RecordControl);
	RecordControl getFlagForRec();
	void setFlagForSou(RecordControl);
	RecordControl getFlagForSou();
	void setForDeleteFigList(int);
	int getForDeleteFigLis();
};

#endif