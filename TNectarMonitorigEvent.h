#ifndef TNectarMonitoringEvent_H
#define TNectarMonitoringEvent_H

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

class TNectarDetectors : public TGo4EventElement {
 public:
   TNectarDetectors() : TGo4EventElement() {}
   TNectarDetectors( const char* name) : TGo4EventElement(name) {}
   virtual ~TNectarDetectors() {}
  Double_t BB8_VStrip[17];
  Double_t BB8_HStrip[17];
  Double_t ADC_MSX04_1;
  Double_t ADC_MSX04_2;
  Double_t ADC_MSX04_7;
  Double_t ADC_MSX04_8;
  Double_t ADC_MSX04_9;
  Double_t ADC_MSX04_10;
  Double_t DT_telescope;
  Double_t BB29_VStrip[17];
  Double_t BB29_HStrip[17];
  Double_t DT_BB29;

  ClassDef(TNectarDetectors,1)
   };



#endif //TNECTARPROFILE.HH




//**COMMENTED SECTIONS OF THE CODE **////

/* data of VMMR frontend - new structure */

/*class TNectarMSX04 : public TGo4EventElement {
 public:
   TNectarMSX04() : TGo4EventElement() {}
   TNectarMSX04( const char* name) : TGo4EventElement(name) {}
   virtual ~TNectarMSX04() {}
  Double_t ADC_MSX04_1;
  Double_t ADC_MSX04_2;
  Double_t ADC_MSX04_7;
  Double_t ADC_MSX04_8;
  Double_t ADC_MSX04_9;
  Double_t ADC_MSX04_10;
  
  ClassDef(TNectarMSX04,1)
  };*/


/*class TNectarBB8 : public TGo4EventElement {
 public:
   TNectarBB8() : TGo4EventElement() {}
   TNectarBB8( const char* name) : TGo4EventElement(name) {}
   virtual ~TNectarBB8() {}
  Double_t VStrip[17];
  Double_t HStrip[17];
   ClassDef(TNectarBB8,1)
   };*/

/*class TNectarBB29 : public TGo4EventElement {

public:
  TNectarBB29() : TGo4EventElement() {}
  TNectarBB29( const char* name) : TGo4EventElement(name) {}
  virtual ~TNectarBB29() {}
  Double_t BB29_V_Strip[129];
  Double_t BB29_H_Strip[69];
  ClassDef(TNectarBB29,1)
};

class TNectarProfileEvent : public TGo4CompositeEvent
{
 public: 
  TNectarProfileEvent() ; //: TNectarTelescope() {} //TNectarBB8() , TNectarMSX04 () {}
  TNectarProfileEvent( const char* name);// : TNectarTelescope (name) {} //TNectarBB8(name) , TNectarMSX04 (name) {}
  virtual ~TNectarProfileEvent() {}

  TNectarTelescope* Telescope;
  TNectarBB29* BB29;
  
   ClassDef(TNectarProfileEvent,1)
};
*/
