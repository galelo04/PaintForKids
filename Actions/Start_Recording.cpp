#include "Start_Recording.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"Play_Recording.h"
Start_Recording::Start_Recording(ApplicationManager* pApp):Action(pApp) {

}

void Start_Recording::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//for condition about recording at the beginning of the program  and after clearall
	if (pManager->getFlagForRec() == 1 || pManager->getFlagForRec() == 0) {
		pOut->PrintMessage("S T A R T__R E C O R D I N G");
		Sleep(1000);
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("ERRROR B A B Y");
	}
}

void Start_Recording::Execute() {

		ReadActionParameters();
	
 }




