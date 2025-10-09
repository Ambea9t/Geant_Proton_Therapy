
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "globals.hh"

#include "Detector.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

  
class DetectorConstruction : public G4VUserDetectorConstruction
{
	public:
	
	DetectorConstruction() = default;
	~DetectorConstruction() override = default;

	G4VPhysicalVolume* Construct() override;

	private:

	G4LogicalVolume *det_log;

	virtual void ConstructSDandField();

	G4bool checkOverlaps = true;
};

