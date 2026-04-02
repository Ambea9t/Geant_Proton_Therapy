
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4StoppingPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4NeutronTrackingCut.hh"


class PhysicsList : public G4VModularPhysicsList
{
public:
	PhysicsList();
	~PhysicsList() override = default;
};

