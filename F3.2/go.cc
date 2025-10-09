
#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "PhysicsList.hh"

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4SteppingVerbose.hh"
#include "G4UImanager.hh"
#include "G4ScoringManager.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"


int main(int argc,char** argv)
{
	
	#ifdef G4MULTITHREADED
	G4MTRunManager* runManager = new G4MTRunManager;
	#else
	G4RunManager* runManager = new G4RunManager;
	#endif
	
	G4ScoringManager * scManager = G4ScoringManager::GetScoringManager();
	scManager->SetVerboseLevel(1);
  

	runManager->SetUserInitialization(new DetectorConstruction());


	runManager->SetUserInitialization(new PhysicsList());
  

	runManager->SetUserInitialization(new ActionInitialization());
	
	
	G4UIExecutive* ui = 0;
	
	if (argc == 1)
	{
	ui = new G4UIExecutive(argc, argv);
	}

	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();


	G4UImanager* UImanager = G4UImanager::GetUIpointer();
  

	UImanager->ApplyCommand("/control/execute vis.mac");
	ui->SessionStart();

	delete visManager;
	delete runManager;
}

