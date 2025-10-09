
#include "RunAction.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"


RunAction::RunAction()
{
	G4int nbins = 1000;
  	G4double vmin = -10.;
  	G4double vmax = 10.;
	G4RunManager::GetRunManager()->SetPrintProgress(1);
	auto analysisManager = G4AnalysisManager::Instance();
	analysisManager->SetVerboseLevel(1);
	analysisManager->SetNtupleMerging(true);
	
	analysisManager->CreateH1("Z","Edep-Z disribution", nbins, vmin *cm, vmax *cm);

	analysisManager->CreateNtuple("Test", "Hits");
    	analysisManager->CreateNtupleDColumn("Z");
    	analysisManager->CreateNtupleDColumn("E");
    	analysisManager->FinishNtuple();
}


void RunAction::BeginOfRunAction(const G4Run* )
{
	auto analysisManager = G4AnalysisManager::Instance();
	
	analysisManager->OpenFile("F3_2.root"); 
	G4cout << "Using " << analysisManager->GetType() << G4endl;
}


void RunAction::EndOfRunAction(const G4Run* )
{
	auto analysisManager = G4AnalysisManager::Instance();

	analysisManager->Write();
	analysisManager->CloseFile();
}

