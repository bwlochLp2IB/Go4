#ifndef TNectarRawPROCESSOR_H
#define TNectarRawPROCESSOR_H

/* VUPROM Nectar beam monitor
 * Version 0.9 on 3-Nov-2010 by J.Adamczewski-Musch, GSI
 * V 0.92 25-Jan-2010 with mean/sigma calculation of counts by J.Adamczewski-Musch, GSI
 * */

class TNectarRawParam;
class TGo4Fitter;

#include "TGo4EventProcessor.h"
#include "TGo4WinCond.h"

#include <vector>

#include "TNectarRawEvent.h"
#include "TNectarDisplay.h"

//#include "TH1Irolling.h"


class TNectarRawProc: public TGo4EventProcessor
{


public:
  TNectarRawProc();
  TNectarRawProc(const char* name);
  virtual ~TNectarRawProc();

  Bool_t BuildEvent(TGo4EventElement* target);    // event processing function

protected:


  /** extract payload of  mdpp */
  Bool_t UnpackMdpp();

  /** extract payload of  vmmr */
  Bool_t UnpackVmmr();

  /** extract payload of  V775 */
  Bool_t UnpackV775(UShort_t triggertype);

  /** extract payload of  V785 */
  Bool_t UnpackV785(UShort_t triggertype);

  /** extract payload of  V830 */
  Bool_t UnpackV830();
  
  /** extract payload of  Vulom TPAT */
  Bool_t UnpackTPAT(Int_t header);

  /** extract payload of  Vulom Scalers */
  Bool_t UnpackVSCA(Int_t header);

  void FillBeamScalers();

  void ScalerReset(TH1* histo);
  
  void ResetScalers();
  
  /** Additional histogram filling here*/
  Bool_t UpdateDisplays();

  /** access to histogram set for current board id*/
  TMdppDisplay* GetMdppDisplay(UInt_t uniqueid);

  /** access to histogram set for current board id*/
  TVmmrDisplay* GetVmmrDisplay(UInt_t uniqueid);

  /** recreate histograms ; if replace redefine previous histograms of same name*/
  void InitDisplay(Bool_t replace = kFALSE);



  /** subdisplays for each frontend board */
  std::vector<TMdppDisplay*> fMdppDisplays;

  /** subdisplays for each frontend board */
   std::vector<TVmmrDisplay*> fVmmrDisplays;

   //add ADC/TDC/Scaler histos for Caen Modules by hand
   TH1 *hRawV785_ADC[3];
   //TH1 *hRawV775_TDC[32];
   //TH1 *hRawV830_Scaler[32];
   //TH1* hRawTRLO_blmu[16];
   //TH1* hRawTRLO_bdt[16];
   //TH1* hRawTRLO_adt[16];
   //TH1* hRawTRLO_ared[16];

   TH1* hRawTRLO_tpat;
   TH1* hRawTRLO_trigger;

   //TRLO timestamp and derived values
   uint64_t TRLO_TS;
   uint64_t TRLO_TS_start;
   uint64_t TRLO_TS_old = 0;
   double_t TRLO_runtime;
   double_t SCAtime;
   uint64_t SCAoffset = 0;

   // mapped histos
   TH1* h_trafo;
   TH1* h_i_cooler;
   // xray
   TH1* h_E_Xray[3];
   TH1* h_t_Xray[3];
   TH1* h_E_Xray_OFF[3];
   TH1* h_t_Xray_OFF[3];
   
   // ESR scalers
   uint32_t V830_old[32] = {0};
   uint32_t V830_diff[32] = {0};
   TH1* h_I_cooler;
   TH1* h_U_cooler;
   TH1* h_jet_S1;
   TH1* h_jet_S2;
   TH1* h_pmt;
   
   
      
   // TRLO scalers
   TH1* h_Tel_blmu;
   TH1* h_Tel_bdt;
   TH1* h_Tel_adt;
   TH1* h_Tel_ared;
   TH1* h_HRes_blmu;
   TH1* h_HRes_bdt;
   TH1* h_HRes_adt;
   TH1* h_HRes_ared;
   TH1* h_Xray1_blmu;
   TH1* h_Xray2_blmu;
   TH1* h_Xray3_blmu;
   TH1* h_Xray_bdt;
   TH1* h_Xray_adt;
   TH1* h_Xray_ared;

   uint32_t blmu_old[16] = {0};
   uint32_t bdt_old[16] = {0};
   uint32_t adt_old[16] = {0};
   uint32_t ared_old[16] = {0};

  /** parameter for runtime settings*/
  TNectarRawParam* fPar;

  /** reference to output data*/
  TNectarRawEvent* fNectarRawEvent;  //!

  /** pointer to currrent mbs subevent*/
  TGo4MbsSubEvent* pSubevt;

  /** pointer cursor to current data in input subevent buffer*/
  Int_t *pData;

  /** total length of current subevent payload in words.*/
  Int_t lWords;

  ClassDef(TNectarRawProc,1)
};

#endif //TUNPACKPROCESSOR_H
