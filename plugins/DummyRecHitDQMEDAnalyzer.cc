// -*- C++ -*-
//
// Package:    Validation/DummyRecHitDQMEDAnalyzer
// Class:      DummyRecHitDQMEDAnalyzer
//
/**\class DummyRecHitDQMEDAnalyzer DummyRecHitDQMEDAnalyzer.cc Validation/DummyRecHitDQMEDAnalyzer/plugins/DummyRecHitDQMEDAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Yu-Wei Kao
//         Created:  Tue, 24 Jan 2023 08:16:27 GMT
//
//

#include <string>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "DQMServices/Core/interface/DQMGlobalEDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


//
// class declaration
//

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
  std::string folder_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
DummyRecHitDQMEDAnalyzer::DummyRecHitDQMEDAnalyzer(const edm::ParameterSet& iConfig)
    : folder_(iConfig.getParameter<std::string>("folder")) {
  // now do what ever initialization is needed
}

DummyRecHitDQMEDAnalyzer::~DummyRecHitDQMEDAnalyzer() {
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}

//
// member functions
//

// ------------ method called for each event  ------------

void DummyRecHitDQMEDAnalyzer::dqmAnalyze(edm::Event const& iEvent,
                           edm::EventSetup const& iSetup,
                           Histograms_DummyRecHitDQMEDAnalyzer const& histos) const {
  histos.histo_->Fill(1.);
}


void DummyRecHitDQMEDAnalyzer::bookHistograms(DQMStore::IBooker& ibook,
                               edm::Run const& run,
                               edm::EventSetup const& iSetup,
                               Histograms_DummyRecHitDQMEDAnalyzer& histos) const {
  ibook.setCurrentFolder(folder_);
  histos.histo_ = ibook.book1D("EXAMPLE", "EXAMPLE", 10, 0., 10.);
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void DummyRecHitDQMEDAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  // The following says we do not know what parameters are allowed so do no
  // validation
  // Please change this to state exactly what you do use, even if it is no
  // parameters
  edm::ParameterSetDescription desc;
  desc.add<std::string>("folder", "MY_FOLDER");
  descriptions.add("dummyrechitdqmedanalyzer", desc);
}

// define this as a plug-in
DEFINE_FWK_MODULE(DummyRecHitDQMEDAnalyzer);
