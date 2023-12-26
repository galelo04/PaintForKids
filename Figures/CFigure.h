#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <string>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int last_ID;
	FigType	Type;
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	//virtual void operator= (CFigure* Other) = 0;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool isPointInside(int x ,int y) const = 0;
	void set_ID(int rid);
	int get_ID() const;

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) ;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) ;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0 ;	//print all figure info on the status bar
	virtual FigType gettype() = 0;
	virtual color getfillcolor() = 0;
	GfxInfo getgfxinfo(); 
	void setisFilled(bool flag);
    virtual void move(Point P) = 0;
	virtual void resize(Point P) = 0;
	virtual void DeleteFigure(CFigure*)=0;
	
	virtual Point GetPointtoUndo() = 0;		 //Get the central point to return the Figure into its place after Undo
	
	//virtual void MakeSound() = 0;
};

#endif