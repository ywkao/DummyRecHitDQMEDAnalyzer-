#ifndef __DQM_HGCAL_IINTERFACE_DummyRecHitDQMEDAnalyzer_h__
#define __DQM_HGCAL_IINTERFACE_DummyRecHitDQMEDAnalyzer_h__

#include <string>
#include <vector>
#include "TString.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "DQMServices/Core/interface/DQMGlobalEDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//----------------------------------------------------------------------------------------------------

struct Histograms_DummyRecHitDQMEDAnalyzer {
 dqm::reco::MonitorElement* histo_;
};

class DummyRecHitDQMEDAnalyzer : public DQMGlobalEDAnalyzer<Histograms_DummyRecHitDQMEDAnalyzer> {
public:
  explicit DummyRecHitDQMEDAnalyzer(const edm::ParameterSet&);
  ~DummyRecHitDQMEDAnalyzer() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void bookHistograms(DQMStore::IBooker&,
                      edm::Run const&,
                      edm::EventSetup const&,
                      Histograms_DummyRecHitDQMEDAnalyzer&) const override;

  void dqmAnalyze(edm::Event const&, edm::EventSetup const&, Histograms_DummyRecHitDQMEDAnalyzer const&) const override;

  // ------------ member data ------------
  std::vector<int> calibration_flags;
  TString myTag;

};
#endif
