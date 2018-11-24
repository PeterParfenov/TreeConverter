#ifndef TCCONSTANTS_H
#define TCCONSTANTS_H

#include "TROOT.h"


/////////////////////////////////////////////
// Class for maintaining constant expressions
// that are used in this TreeConverter.
//
// All constant values are set in .cxx file
/////////////////////////////////////////////
class TCConstants
{
public:
  TCConstants();
  virtual ~TCConstants();

  inline static const Int_t     GetTClonesArraySize()         {return nTClonesArraySize;};
  inline static const Double_t  GetDoubleZero()               {return nDoubleZero;};
  inline static const Double_t  GetDoubleComparisonPrecision(){return nDoubleComparisonPrecision;};

private:
  static const Int_t nTClonesArraySize;
  static const Double_t nDoubleZero;
  static const Double_t nDoubleComparisonPrecision;

ClassDef(TCConstants,0);
};

#endif