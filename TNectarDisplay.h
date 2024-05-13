#ifndef TNectarDISPLAY_H
#define TNectarDISPLAY_H

class TNectarRawParam;

#include "TGo4EventProcessor.h"
#include "TGo4WinCond.h"

#include <vector>
#include "TNectarRawEvent.h"

#include "TGo4Analysis.h"

#include "TLatex.h"

#include "TH1.h"



/********************************
 * Histogram display container for each Nectar board
 *  (JAM September 2021)
 *
 * */
class TNectarBoardDisplay: public  TGo4EventProcessor
{

public:

  TNectarBoardDisplay() : TGo4EventProcessor(), fDisplayId(0)
  {
    ;
  }
  TNectarBoardDisplay(UInt_t boardid): TGo4EventProcessor(), fDisplayId(boardid){;}
  virtual ~TNectarBoardDisplay(){;}

  /* recreate histograms using actual parameters*/
  virtual void InitDisplay(UInt_t parentid=0, Bool_t replace = kFALSE){;}

  /** reset some histograms here e*/
  virtual void ResetDisplay(){;}

 


   //
 UInt_t GetDevId()
     {
       return fDisplayId;
     }



protected:

  UInt_t fDisplayId;


ClassDef(TNectarBoardDisplay,1)
};
////////////////////////////////////////////////////////////////////

class TMdppDisplay: public  TNectarBoardDisplay
{
public:
  TMdppDisplay() : TNectarBoardDisplay(), hExtTimeStamp(0),hMsgTypes(0)
   {;}
   TMdppDisplay(UInt_t boardid, Bool_t has16channels);
   virtual ~TMdppDisplay();

   /* recreate histograms using actual parameters*/
   virtual void InitDisplay(UInt_t parentid=0, Bool_t replace = kFALSE);

   /** reset some histograms here e*/
   virtual void ResetDisplay();


   /* true if this display is meant for MDPP-16, false if we expect MDPP-32 */
   Bool_t fHas16channels;

   /* ADC values accumulated*/
   TH1 *hRawADC[MDPP_CHANNELS];

   /* TDC values accumulated*/
   TH1 *hRawTDC[MDPP_CHANNELS];

   /* TDC time difference to reference channel*/
   TH1 *hDeltaTDC[MDPP_CHANNELS];

   /* delta t from external trigger inputs (MDPP32 only)*/
   TH1 *hExtTrigTime[MDPP_EXTDTCHANNELS];

   /* extended time stamps*/
   TH1 *hExtTimeStamp;

   /* statistics of messages in data stream*/
   TH1* hMsgTypes;

   /* account data amount for each ADC channel*/
   TH1* hADC_ChannelScaler;

   /* account data amount for each TDC channel*/
     TH1* hTDC_ChannelScaler;

  ClassDef(TMdppDisplay,1)
};

/////////////////////////////////////////////////////////////////////////////////////


class TVmmrSlaveDisplay: public  TNectarBoardDisplay
{
public:
  TVmmrSlaveDisplay() : TNectarBoardDisplay(), hDeltaTime(0)
   {
     ;
   }
   TVmmrSlaveDisplay(UInt_t boardid);
   virtual ~TVmmrSlaveDisplay();

   /* recreate histograms using actual parameters*/
   virtual void InitDisplay(UInt_t parentboard, Bool_t replace = kFALSE);

   /** reset some histograms here e*/
   virtual void ResetDisplay();



   /* ADC values accumulated*/
     TH1 *hRawADC[VMMR_CHANNELS];
    
 /* test histogram*/
     //TH2 *hRawADC1vs2;
     
 /* test histo for 1ch (vertical) vs data (horizontal) from 16 ch - ms & js 7 feb 22 */
     //TH2 *hRawADCVvsH[16];
     
 /* test histo for 1ch (horizontal) vs data (vertical) from 16 ch - ms & js 7 feb 22 */
     //TH2 *hRawADCHvsV[16];
     
  /* STRIP MAPPING histogram */
  
     //TH2 *hSTRIPmap;   
  
     /* Time differenceGate start to bus triggers*/
     TH1 *hDeltaTime;
   

   


   ClassDef(TVmmrSlaveDisplay,1)
};

class TVmmrDisplay: public  TNectarBoardDisplay
{
public:
  TVmmrDisplay() : TNectarBoardDisplay(), hExtTimeStamp(0),hMsgTypes(0)
   {
     ;
   }
   TVmmrDisplay(UInt_t boardid);
   virtual ~TVmmrDisplay();

   /* recreate histograms using actual parameters*/
   virtual void InitDisplay(UInt_t parentid=0, Bool_t replace = kFALSE);

   /** reset some histograms here e*/
   virtual void ResetDisplay();

   /** Access to the slave display of chain id. Independent of position in vector*/
   TVmmrSlaveDisplay* GetSlaveDisplay(UInt_t id);

 /* extended  time stamps*/
     TH1* hExtTimeStamp;

     /* statistics of messages in data stream*/
     TH1* hMsgTypes;

  


protected:

   /** Dynamically build display for given chain id. Returns the handle*/
   TVmmrSlaveDisplay* AddSlaveDisplay(UInt_t id);


   /* dynamic vector of slave histogram sets */
     std::vector<TVmmrSlaveDisplay*> fSlaveDisplays;

  ClassDef(TVmmrDisplay,1)
};

class TCommonHisto
{
public:
  TCommonHisto()
   {
     Int_t adc_range = 8192;
     Int_t tdc_range = 8192;

     TString obname;
     TString obtitle;
     
     for(int ch=0;ch<32;ch++)
       {
	 obname.Form("Raw/ADC/ADC_Channel_%d", ch);
	 obtitle.Form("Caen V785 ADC - Channel %d ", ch);
	 hRawV785_ADC[ch] = new TH1I(obname.Data(), obtitle.Data(), adc_range, 0.5, adc_range+0.5);
       }

   }
  //TCommonHisto();
   virtual ~TCommonHisto();

   /* recreate histograms using actual parameters*/
   virtual void InitHisto();

   /** reset some histograms here e*/
   virtual void ResetHisto();

   /* ADC values accumulated*/
   TH1 *hRawV785_ADC[32];

   /* TDC values accumulated*/
   TH1 *hRawV775_TDC[32];

   /* TDC time difference to reference channel*/
   TH1 *hRawV830_Scaler[32];

   /* Trigger pattern*/
   TH1* hRawTRLO_tpat;

   /* TRLO scaler*/
   TH1* hRawTRLO_bdt[16];
   TH1* hRawTRLO_adt[16];
   TH1* hRawTRLO_ared[16];

   //ClassDef(TCommonHisto,1);
};

#endif //TNectarDISPLAY_H

