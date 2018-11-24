#include <iostream>

#include "TCEvent.h"
#include "TCParticle.h"
#include "TROOT.h"
#include "TObject.h"
#include "TClonesArray.h"
#include "TString.h"

int main()
{
  TString printOpt = "";
  TCEvent *event = new TCEvent();

  event->AddParticle(0,2212,0.2,1.8,100.,100.005,0.,0.,0.,200.);
  TCParticle *part = new TCParticle(1,211,0.5,0.3,100.,100.0005,0.,0.,0.,200.);
  event->AddParticle(*part);

  event->Print(printOpt.Data());

  return 0;
}