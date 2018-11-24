#include <iostream>

#include "TCEvent.h"
#include "TCConstants.h"
#include "TCParticle.h"
#include "TClonesArray.h"
#include "TString.h"

ClassImp(TCEvent);

TCEvent::TCEvent()
    : TObject(),
      fNev(0),
      fB(0.),
      fNpart(0),
      fPsiRP(0.),
      fParticles(new TClonesArray("TCParticle", TCConstants::GetTClonesArraySize()))
{
}

TCEvent::TCEvent(const TCEvent &_e)
    : TObject(_e),
      fNev(_e.fNev),
      fB(_e.fB),
      fNpart(_e.fNpart),
      fPsiRP(_e.fPsiRP),
      fParticles(new TClonesArray("TCParticle", TCConstants::GetTClonesArraySize()))
{
}

TCEvent::~TCEvent()
{
}

TCParticle *TCEvent::GetParticle(Int_t i) const
{
  return (i >= 0 && i < fNpart) ? ((TCParticle *)fParticles->At(i)) : NULL;
}

void TCEvent::AddParticle(const TCParticle &_p)
{
  new ((*fParticles)[fNpart]) TCParticle(_p);
  fNpart++;
}

void TCEvent::AddParticle(Int_t index, Int_t pdg,
                          Double_t px, Double_t py, Double_t pz, Double_t E,
                          Double_t x, Double_t y, Double_t z, Double_t t)
{
  new ((*fParticles)[fNpart]) TCParticle(index, pdg, px, py, pz, E,
                                         x, y, z, t);
  fNpart++;
}

void TCEvent::Clear(Option_t *)
{
  fParticles->Clear();
  fNpart = 0;
}

void TCEvent::RemoveAt(Int_t i)
{
  fParticles->RemoveAt(i);
  fParticles->Compress();
}

void TCEvent::Print(Option_t * option) const
{
  std::cout << "////////////////////////////////////////////////" << std::endl
            << "-I-                 TCEvent                  -I-" << std::endl
            << "Event number                  : " << fNev << std::endl
            << "Impact parameter (fm)         : " << fB << std::endl
            << "Reaction plane angle (rad)    : " << fPsiRP << std::endl
            << "Number of particles           : " << fNpart << std::endl;
  TString opt = option;
  if (opt.Contains("all"))
  {
    std::cout << std::endl;
    TCParticle *particle;
    for (Int_t i = 0; i < fNpart; i++)
    {
      particle = (TCParticle *)fParticles->At(i);
      particle->Print(option);
    }
  }
  std::cout << "////////////////////////////////////////////////" << std::endl;
}