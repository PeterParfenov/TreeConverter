#ifndef TCEVENT_H
#define TCEVENT_H

#include "TCParticle.h"
#include "TClonesArray.h"
#include "TObject.h"

class TCEvent : public TObject
{
public:
  TCEvent();
  virtual ~TCEvent();

  inline Double_t       GetB()            const {return fB;};
  inline Double_t       GetPsiRP()        const {return fPsiRP;};
  inline Int_t          GetNpart()        const {return fNpart;};
  inline Int_t          GetNev()          const {return fNev;};
  inline TClonesArray*  GetParticleList() const {return fParticles;};
  inline TCParticle*    GetParticle(Int_t i) const;


  inline void SetB    (Double_t a){fB = a;};
  inline void SetPsiRP(Double_t a){fPsiRP = a;};
  inline void SetNpart(Int_t a)   {fNpart = a;};
  inline void SetNev  (Int_t a)   {fNev = a;};

private:
  Double_t        fPsiRP;
  Double_t        fB;
  Int_t           fNpart;
  Int_t           fNev;
  TClonesArray   *fParticles;

  ClassDef(TCEvent, 0);
};

#endif