#ifndef TNectarMonitoringPROCESSOR_H
#define TNectarMonitoringPROCESSOR_H

/* VUPROM Nectar beam monitor
 * Version 0.9 on 3-Nov-2010 by J.Adamczewski-Musch, GSI
 * V 0.92 25-Jan-2010 with mean/sigma calculation of counts by J.Adamczewski-Musch, GSI
 * */
class TNectarRawParam;
class TGo4Fitter;

#include "TGo4EventProcessor.h"

#include "TGo4WinCond.h"

#include <vector>
#include "TNectarMonitoringDisplay.h"
#include "TNectarRawEvent.h"
#include "TNectarMonitoringEvent.h"
#include "TNectarRawProc.h"
#include "TNectarDisplay.h"
#include "TF1.h"

class TNectarMonitoringProc: public TGo4EventProcessor { 
 public:
  TNectarMonitoringProc();
  TNectarMonitoringProc(const char* name);

  void Filling_Ev_Telescope(TVmmrBoard* theVmmr, TNectarDetectors* Telescope);
  void Filling_Ev_FFtopbot(TVmmrBoard* theVmmr, TNectarDetectors* Telescope);
  void Filling_Ev_FFside(TVmmrBoard* theVmmr, TNectarDetectors* Telescope);
  void Filling_Ev_BB29(TVmmrBoard* theVmmr, TNectarDetectors* Telescope);
  void Online_Analysis_Target_on(TNectarDetectors* Telescope);
  void Online_Analysis_Target_off(TNectarDetectors* Telescope);

  
  Double_t Calib_BB8_H(Double_t ADC, Int_t nH);
  Double_t Calib_BB8_V(Double_t ADC, Int_t nV);
  Double_t Calib_MSX04(Double_t ADC, Int_t N_MSX04);

  void Update_Histograms_Target_on(TNectarDetectors* Telescope);
  void Update_Histograms_Target_off(TNectarDetectors* Telescope);
  Bool_t BuildEvent(TGo4EventElement* target);

  //Ex calculation function

  void Ex_Calculation(Int_t n_V, Int_t n_H, TNectarDetectors* Telescope, Double_t Total_E);

protected:

  TNectarHistograms* Histo = new TNectarHistograms();
  TF1* SW_Correction = new TF1("SW_Correction","[0]+[1]*x+[2]*TMath::Power(x,2)+[3]*TMath::Power(x,3)+[4]*TMath::Power(x,4)",1,10);
  std::vector<TVmmrSlave*>fSlave;  
  TGo4PolyCond  *fPolyCon_protons{nullptr};
  TGo4PolyCond  *fPolyCon_deuterons{nullptr};

   TNectarRawParam* fPar;
  
   ClassDef(TNectarMonitoringProc, 1)
};
#endif  //close the TNectarMonitoringProc.h 
