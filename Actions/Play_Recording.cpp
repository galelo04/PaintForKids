#include "Play_Recording.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Start_Recording.h"
#include<Windows.h>


Play_Recording::Play_Recording(ApplicationManager* pApp):Action(pApp){}

void Play_Recording::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	if (pManager->get_recorder_for_play() != NULL) {
		pOut->PrintMessage("P L A Y__R E C O R D I N G");
		pOut->ClearDrawArea();
	}

 }


void Play_Recording::Execute() {
	ReadActionParameters();
	if (pManager->get_recorder_for_play() != NULL){
		int k = pManager->getFigcount();
		for (int i = 0; i < pManager->getRecordCount(); i++) {
			pManager->deleteFigureForRecord(i);
		}
		pManager->setFigCount(0);
		for (int i = 0; i < pManager->getRecordCount(); i++) {
			Sleep(1000);
			pManager->getActionRecordList(i)->ExecuteRecord();
			pManager->UpdateInterfaceForRecord();
		}
		for (int i = 0; i < pManager->getRecordCount(); i++)
			delete pManager->getActionRecordList(i);
		pManager->setRecordCountto_0();
		pManager->setFigCount(k);
		pManager->set_recorder_for_play(NULL);
		Output* pOut = pManager->GetOutput();
		pOut->clearmouseclicks();
	}
}

