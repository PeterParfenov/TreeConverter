#include "TCEvent.h"
#include "TCConstants.h"

ClassImp(TCEvent);

TCEvent::TCEvent()
    : TObject(),
      fNev(0),
      fB(0.),
      fNpart(0),
      fPsiRP(0.),
      fParticles(new TClonesArray("TCParticle",TCConstants::GetTClonesArraySize()))
{
}

TCEvent::~TCEvent()
{
}

TCParticle* TCEvent::GetParticle(Int_t i) const
{
  return (i>=0 && i<fNpart) ? ((TCParticle*) fParticles->At(i)) : NULL;
}