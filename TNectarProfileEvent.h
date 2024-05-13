#ifndef TNectarProfileEvent_H
#define TNectarProfileEvent_H

class TNectarRawParam;

#include "TGo4WinCond.h"
#include "TH1.h"
#include "TGo4EventElement.h"
#include <vector>
#include "TNectarRawEvent.h"
#include "TGo4Analysis.h"
#include "TGo4CompositeEvent.h"

#include "TLatex.h"


/****************************
**  NEW DATA STRUCTURE DEFINITION & HISTOGRAMS PLOTS
****************************/

class TNectarTelescope : public TGo4EventElement {
 public:
   TNectarTelescope() : TGo4EventElement() {}
   TNectarTelescope( const char* name) : TGo4EventElement(name) {}
   virtual ~TNectarTelescope() {}
  Double_t VStrip[17];
  Double_t HStrip[17];
  Double_t ADC_MSX04_1;
  Double_t ADC_MSX04_2;
  Double_t ADC_MSX04_7;
  Double_t ADC_MSX04_8;
  Double_t ADC_MSX04_9;
  Double_t ADC_MSX04_10;
   ClassDef(TNectarTelescope,1)
   };

class TNectarProfileEvent : public TNectarTelescope  //public TNectarBB8 , public TNectarMSX04
{
 public: 
  TNectarProfileEvent() : TNectarTelescope() {} //TNectarBB8() , TNectarMSX04 () {}
  TNectarProfileEvent( const char* name) : TNectarTelescope (name) {} //TNectarBB8(name) , TNectarMSX04 (name) {}
  virtual ~TNectarProfileEvent() {}
  
   ClassDef(TNectarProfileEvent,1)
};

#endif //TNECTARPROFILE.HH


