#include "TCParticle.h"
#include "TMath.h"
#include "TCConstants.h"

ClassImp(TCParticle);

TCParticle::TCParticle()
    : TObject(),
      fPdg(0),
      fPx(0.),
      fPy(0.),
      fPz(0.),
      fE(0.),
      fX(0.),
      fY(0.),
      fZ(0.),
      fT(0.)
{
}

TCParticle::~TCParticle()
{
}

const TCParticle &TCParticle::operator=(const TCParticle &_p)
{
  TObject::operator=(_p);
  fPdg = _p.fPdg;
  fPx = _p.fPx;
  fPy = _p.fPy;
  fPz = _p.fPz;
  fE = _p.fE;
  fX = _p.fX;
  fY = _p.fY;
  fZ = _p.fZ;
  fT = _p.fT;
  return (*this);
}

Bool_t TCParticle::operator==(const TCParticle &_p) const
{
  return (fPdg == _p.fPdg &&
          ((TMath::Abs((fPx - _p.fPx) / fPx) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fPx) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fPx) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fPy - _p.fPy) / fPy) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fPy) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fPy) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fPz - _p.fPz) / fPz) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fPz) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fPz) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fE - _p.fE) / fE) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fE) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fE) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fX - _p.fX) / fX) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fX) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fX) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fY - _p.fY) / fY) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fY) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fY) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fZ - _p.fZ) / fZ) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fZ) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fZ) < TCConstants::GetDoubleZero())) &&
          ((TMath::Abs((fT - _p.fT) / fT) < TCConstants::GetDoubleComparisonPrecision()) ||
           (TMath::Abs(fT) < TCConstants::GetDoubleZero() && TMath::Abs(_p.fT) < TCConstants::GetDoubleZero())));
}