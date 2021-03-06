#ifndef RecoEcal_EgammaCoreTools_EcalClusterLocalContCorrectionBaseClass_h
#define RecoEcal_EgammaCoreTools_EcalClusterLocalContCorrectionBaseClass_h

/** \class EcalClusterLocalContCorrection
  *  Function to correct cluster for the so called local containment
  *
  *  $Id: EcalClusterLocalContCorrection.h
  *  $Date:
  *  $Revision:
  *  \author Federico Ferri, CEA Saclay, November 2008
  */

#include "RecoEcal/EgammaCoreTools/interface/EcalClusterFunctionBaseClass.h"

//#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "CondFormats/EcalObjects/interface/EcalClusterLocalContCorrParameters.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/EgammaReco/interface/BasicCluster.h"

namespace edm {
  class EventSetup;
  class ParameterSet;
}  // namespace edm

class EcalClusterLocalContCorrectionBaseClass : public EcalClusterFunctionBaseClass {
public:
  EcalClusterLocalContCorrectionBaseClass();
  EcalClusterLocalContCorrectionBaseClass(const edm::ParameterSet &){};
  ~EcalClusterLocalContCorrectionBaseClass() override;

  // get/set explicit methods for parameters
  const EcalClusterLocalContCorrParameters *getParameters() const { return params_; }
  // check initialization
  void checkInit() const;

  // compute the correction
  float getValue(const reco::BasicCluster &, const EcalRecHitCollection &) const override = 0;
  float getValue(const reco::SuperCluster &, const int mode) const override = 0;

  // set parameters
  void init(const edm::EventSetup &es) override;

protected:
  edm::ESHandle<EcalClusterLocalContCorrParameters> esParams_;
  const EcalClusterLocalContCorrParameters *params_;
  const edm::EventSetup *es_;  //needed to access the ECAL geometry
};

#endif
