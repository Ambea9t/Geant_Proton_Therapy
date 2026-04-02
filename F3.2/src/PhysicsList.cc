
#include "PhysicsList.hh"


PhysicsList::PhysicsList()
{
        RegisterPhysics (new G4EmStandardPhysics());
        RegisterPhysics (new G4EmExtraPhysics());
        RegisterPhysics (new G4DecayPhysics());
        RegisterPhysics (new G4HadronElasticPhysicsXS());
        RegisterPhysics (new G4StoppingPhysics());
        RegisterPhysics (new G4IonPhysics());
        RegisterPhysics (new G4HadronInelasticQBBC());
        RegisterPhysics (new G4NeutronTrackingCut());
}

