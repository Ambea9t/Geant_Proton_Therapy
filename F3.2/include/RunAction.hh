
#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"


class RunAction : public G4UserRunAction
{
	public:
	
	RunAction();
	~RunAction() override = default;

	void BeginOfRunAction(const G4Run*) override;
	void EndOfRunAction(const G4Run*) override;
};

