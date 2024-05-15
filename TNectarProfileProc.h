#ifndef TNectarProfilePROCESSOR_H
#define TNectarProfilePROCESSOR_H

/* VUPROM Nectar beam monitor
 * Version 0.9 on 3-Nov-2010 by J.Adamczewski-Musch, GSI
 * V 0.92 25-Jan-2010 with mean/sigma calculation of counts by J.Adamczewski-Musch, GSI
 * */

//class TNectarRawParam;
//class TGo4Fitter;

#include "TGo4EventProcessor.h"

#include "TGo4WinCond.h"

#include <vector>

#include "TNectarRawEvent.h"
#include "TNectarProfileEvent.h"
#include "TNectarRawProc.h"
#include "TNectarDisplay.h"

class TNectarProfileProc: public TGo4EventProcessor { 
 public:
  TNectarProfileProc();
  TNectarProfileProc(const char* name);

  void InitDisp();
  /** BB8 histograms **/
  TH1* histoVStrip[16]; // BB8 histograms
  TH1* histoHStrip[16]; // BB8 histograms
  //////////////////////
  /** MSX04 **/
  TH1* h_ADC_MSX04_1;  // first stock
  TH1* h_ADC_MSX04_2;  // first stock
  TH1* h_ADC_MSX04_7;  // second stock
  TH1* h_ADC_MSX04_8;  // second stock
  TH1* h_ADC_MSX04_9;  // third stock
  TH1* h_ADC_MSX04_10; // third stock

  Bool_t BuildEvent(TGo4EventElement* target);
  
protected:

  //TNectarRawParam* fPar1;
  TNectarProfileEvent* fNectarProfileEvent;
 
  
   ClassDef(TNectarProfileProc, 1)
};
#endif  //close the TNectarProfileProc.h 
