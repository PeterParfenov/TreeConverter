#ifndef TCPARTICLE_H
#define TCPARTICLE_H

#include "TObject.h"

class TCParticle : public TObject
{
public:
  TCParticle();
  TCParticle(Int_t index, Int_t pdg,
             Double_t px, Double_t py, Double_t pz, Double_t E,
             Double_t x, Double_t y, Double_t z, Double_t t);
  TCParticle(const TCParticle &_p);
  virtual ~TCParticle();

  inline Int_t GetIndex() const { return fIndex; };
  inline Int_t GetPdg() const { return fT; };
  inline Double_t GetPx() const { return fPx; };
  inline Double_t GetPy() const { return fPy; };
  inline Double_t GetPz() const { return fPz; };
  inline Double_t GetE() const { return fE; };
  inline Double_t GetX() const { return fX; };
  inline Double_t GetY() const { return fY; };
  inline Double_t GetZ() const { return fZ; };
  inline Double_t GetT() const { return fT; };

  inline void SetIndex(Int_t a) { fIndex = a; };
  inline void SetPdg(Int_t a) { fPdg = a; };
  inline void SetPx(Double_t a) { fPx = a; };
  inline void SetPy(Double_t a) { fPy = a; };
  inline void SetPz(Double_t a) { fPz = a; };
  inline void SetE(Double_t a) { fE = a; };
  inline void SetX(Double_t a) { fX = a; };
  inline void SetY(Double_t a) { fY = a; };
  inline void SetZ(Double_t a) { fZ = a; };
  inline void SetT(Double_t a) { fT = a; };

  void Print(Option_t* = "") const;

  const TCParticle &operator=(const TCParticle &_p);
  Bool_t operator==(const TCParticle &_p) const;

private:
  Int_t fIndex;
  Int_t fPdg;
  Double_t fPx;
  Double_t fPy;
  Double_t fPz;
  Double_t fE;
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  Double_t fT;

  ClassDef(TCParticle, 0);
};

#endif