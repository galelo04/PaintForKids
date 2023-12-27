#include "VolumeAction.h"
#include "..\ApplicationManager.h"
VolumeAction::VolumeAction(ApplicationManager* pApp) :Action(pApp) {

}

//Reads circle parameters
void VolumeAction::ReadActionParameters() {

}

//Add circle to the ApplicationManager
void VolumeAction::Execute() {
	pManager->setFlagForSou(on);
}
