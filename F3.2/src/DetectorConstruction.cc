#include "DetectorConstruction.hh"

#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"

struct FilterParams {
    G4double posX;      
    G4double thickness; 
    G4String name;      
};

G4VPhysicalVolume *DetectorConstruction::Construct()
{

	G4int nLayers = 1000;
	G4NistManager* nist = G4NistManager::Instance();


	////////World////////
	G4double env_size = 20.0*cm;
	G4double p_size = 10.0*cm;

	G4Material* AIR = nist->FindOrBuildMaterial("G4_AIR");

	G4Box *universe_s = new G4Box("universe_S", p_size, p_size, env_size);

	auto universe_log = new G4LogicalVolume(universe_s, AIR,"universe_L",0,0,0);                                       

	auto physWorld = new G4PVPlacement(0, G4ThreeVector(), universe_log,"universe_P", 0, false, 0, checkOverlaps);
	///
	
	
	////////Filter////////
        ///
        G4Material* Org_Glass = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
        ///1.17 = ph/ps
        std::vector<FilterParams> filters_150 = //6-9 150 MeV
        {
            {-5.5*cm, 8.4316*cm, "Filter0"},
            {-4.5*cm, 8.1752*cm, "Filter1"},
            {-3.5*cm, 7.918*cm, "Filter2"},
            {-2.5*cm,  7.6623*cm, "Filter3"},
            {-1.5*cm,  7.4059*cm, "Filter4"},
            {-0.5*cm,  7.1495*cm, "Filter5"},
            {0.5*cm,  6.8931*cm, "Filter6"},
            {1.5*cm,  6.6367*cm, "Filter7"},
            {2.5*cm,  6.380*cm, "Filter8"},
            {3.5*cm,  6.1237*cm, "Filter9"},
            {4.5*cm,  5.8675*cm, "Filter10"}
        };
        
        std::vector<FilterParams> filters_200 = //11-15 200MeV
        {
            {-5.5*cm, 12.6923*cm, "Filter0"},
            {-4.5*cm, 12.3504*cm, "Filter1"},
            {-3.5*cm, 12.0085*cm, "Filter2"},
            {-2.5*cm,  11.6666*cm, "Filter3"},
            {-1.5*cm,  11.3247*cm, "Filter4"},
            {-0.5*cm,  10.9829*cm, "Filter5"},
            {0.5*cm,  10.641*cm, "Filter6"},
            {1.5*cm,  10.2991*cm, "Filter7"},
            {2.5*cm,  9.9572*cm, "Filter8"},
            {3.5*cm,  9.6153*cm, "Filter9"},
            {4.5*cm,  9.2739*cm, "Filter10"}
        };
        
        
        std::vector<FilterParams> filters = filters_200;
        for (size_t i = 0; i < filters.size(); i++)
        {
                G4double thickness = filters[i].thickness;
                G4double posX = filters[i].posX;
        
                G4Box* filter_S = new G4Box("Filter_s" + std::to_string(i+1), 0.5*cm, 0.5*cm, thickness/2.0); 
        
                G4LogicalVolume* filter_Log = new G4LogicalVolume(filter_S, Org_Glass, "Filter_L" + std::to_string(i+1));
        
                auto det_phys = new G4PVPlacement(0, G4ThreeVector(posX, 0.0, -7.0*cm), filter_Log,"RidgeFilter_P" + std::to_string(i+1), universe_log, false, i+1, true);
        }
        ///
        
        
  	////////detector////////
  	///
	G4Material* H2O = nist->FindOrBuildMaterial("G4_WATER");
	
  	auto det_s = new G4Box("det_S", p_size, p_size, 0.5/nLayers *env_size); 
  	
  	det_log = new G4LogicalVolume(det_s, H2O, "det_L");
  	
  	for(G4int i = 0; i < nLayers; i++)
	{
                auto det_phys = new G4PVPlacement(0, G4ThreeVector(0, 0, (i+0.5)*env_size/nLayers), det_log, "det_P", universe_log, false, i*nLayers, 1);
	}
	///
	
  	return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
	SensitiveDetector *sensDet = new SensitiveDetector("SensitiveDetector1");
	det_log->SetSensitiveDetector(sensDet);
}
