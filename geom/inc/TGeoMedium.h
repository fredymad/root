// @(#)root/geom:$Name:  $:$Id: TGeoMedium.h,v 1.2 2004/04/13 07:04:42 brun Exp $
// Author: Rene Brun   26/12/02

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TGeoMedium
#define ROOT_TGeoMedium

#ifndef ROOT_TGeoMaterial
#include "TGeoMaterial.h"
#endif

/*************************************************************************
 * TGeoMedium - base class describing tracking media
 *
 *************************************************************************/

class TGeoMedium : public TNamed
{

protected:
   Int_t                    fId;         // unique Id
   Double_t                 fParams[20]; // parameters
   TGeoMaterial            *fMaterial;   // pointer to material
	 
// methods

public:
   // constructors
   TGeoMedium();
   TGeoMedium(const char *name, Int_t numed, const TGeoMaterial *mat, Double_t *params=0);
   TGeoMedium(const char *name, Int_t numed, Int_t imat, Int_t isvol, Int_t ifield,
              Double_t fieldm, Double_t tmaxfd, Double_t stemax, Double_t deemax, Double_t epsil, Double_t stmin);
   virtual ~TGeoMedium();
   // methods
   virtual Int_t            GetByteCount() const {return sizeof(this);}
   Int_t                    GetId()   const     {return fId;}
   Double_t                 GetParam(Int_t i) const {return fParams[i];}
   TGeoMaterial            *GetMaterial() const {return fMaterial;}
   void                     SetMaterial(TGeoMaterial *mat) {fMaterial = mat;}
   virtual void             SetCerenkovProperties(TObject* cerenkov) {fMaterial->SetCerenkovProperties(cerenkov);}   
  ClassDef(TGeoMedium, 1)              // tracking medium

};

#endif

