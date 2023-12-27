#include "MuteAction.h"
#include "..\ApplicationManager.h"
MuteAction::MuteAction(ApplicationManager* pApp) :Action(pApp) {

}

//Reads circle parameters
void MuteAction::ReadActionParameters() {

}

//Add circle to the ApplicationManager
void MuteAction::Execute() {
	pManager->setFlagForSou(off);
}
