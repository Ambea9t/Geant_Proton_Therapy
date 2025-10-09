
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

class G4GeneralParticleSource;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
	public:
	
	PrimaryGeneratorAction();
	~PrimaryGeneratorAction() override;

	virtual void GeneratePrimaries(G4Event*);

	private:
	
	G4GeneralParticleSource* fParticleGun;
};

