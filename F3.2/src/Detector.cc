#include "Detector.hh"


SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name){}


G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();
	G4ParticleDefinition * fpParticleDefinition = track->GetDefinition();
	//G4String namePart = fpParticleDefinition->GetParticleName();
	//if(namePart!="gamma")
	//{track->SetTrackStatus(fStopAndKill);}
	//else
	
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
	const G4double eDeposit = aStep->GetTotalEnergyDeposit();
	//if (postStepPoint->GetStepStatus() == fGeomBoundary)
	//{G4double eDeposit = 0;};
	//G4ThreeVector posPart = preStepPoint->GetPosition();
	//if(posPart[2]>0)
	
	//G4double ePart = preStepPoint->GetKineticEnergy();
	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	G4VPhysicalVolume *physVol = touchable->GetVolume();
    	G4ThreeVector posDetector = physVol->GetTranslation();
    	
    	G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
	
	analysisManager->FillH1(0, posDetector[2], eDeposit);
	
        analysisManager->FillNtupleDColumn(0, posDetector[2]);
        analysisManager->FillNtupleDColumn(1, eDeposit);
        analysisManager->AddNtupleRow();
        
        
	return true;
}
