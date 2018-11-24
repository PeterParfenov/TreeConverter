#ifndef TCEVENT_H
#define TCEVENT_H

#include "TObject.h"

class TCParticle;
class TClonesArray;

class TCEvent : public TObject
{
public:
  TCEvent();
  TCEvent(const TCEvent &_e);
  virtual ~TCEvent();

  inline Double_t GetB() const { return fB; };
  inline Double_t GetPsiRP() const { return fPsiRP; };
  inline Int_t GetNpart() const { return fNpart; };
  inline Int_t GetNev() const { return fNev; };
  TClonesArray *GetParticleList() const { return fParticles; };
  TCParticle *GetParticle(Int_t i) const;

  void AddParticle(const TCParticle &_p);
  void AddParticle(Int_t index, Int_t pdg,
                          Double_t px, Double_t py, Double_t pz, Double_t E,
                          Double_t x, Double_t y, Double_t z, Double_t t);

  inline void SetB(Double_t a) { fB = a; };
  inline void SetPsiRP(Double_t a) { fPsiRP = a; };
  inline void SetNpart(Int_t a) { fNpart = a; };
  inline void SetNev(Int_t a) { fNev = a; };

  void Clear(Option_t* = "");
  void RemoveAt(Int_t i);
  void Print(Option_t* = "") const;

private:
  Double_t fPsiRP;
  Double_t fB;
  Int_t fNpart;
  Int_t fNev;
  TClonesArray *fParticles;

  ClassDef(TCEvent, 0);
};

#endif