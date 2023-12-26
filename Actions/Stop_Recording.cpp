#include "Stop_Recording.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Stop_Recording::Stop_Recording(ApplicationManager* pApp):Action(pApp) {}


void Stop_Recording::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearStatusBar();
	if (pManager->get_recorder() != NULL) {
		pOut->PrintMessage("S T O P__R E C O R D I N G");
		pManager->set_recorder_for_play(pManager->get_recorder());
		pManager->set_recorder(NULL);
	}
	
}


void Stop_Recording::Execute() {
	ReadActionParameters();
}
