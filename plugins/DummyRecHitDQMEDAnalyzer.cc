#include "Validation/DummyRecHitDQMEDAnalyzer/interface/DummyRecHitDQMEDAnalyzer.h"

//using namespace std;
//using namespace edm;

DummyRecHitDQMEDAnalyzer::DummyRecHitDQMEDAnalyzer(const edm::ParameterSet& iConfig) {
    //calibration_flags = iConfig.getParameter<std::vector<int> >( "CalibrationFlags" );
    //myTag = iConfig.getParameter<std::string>( "DataType" );
}

DummyRecHitDQMEDAnalyzer::~DummyRecHitDQMEDAnalyzer() {
}

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
  //folder_.assign("HGCAL/RecHits");
  ibook.setCurrentFolder("HGCAL/RecHits");
  histos.histo_ = ibook.book1D("EXAMPLE", "EXAMPLE", 10, 0., 10.);
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void DummyRecHitDQMEDAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<std::string>("folder", "MY_FOLDER");
  descriptions.add("dummyrechitdqmedanalyzer", desc);
}

// define this as a plug-in
DEFINE_FWK_MODULE(DummyRecHitDQMEDAnalyzer);
