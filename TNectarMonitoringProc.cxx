#include "Riostream.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TROOT.h"
#include "TMath.h"
#include "TVirtualFFT.h"
#include "TGo4Analysis.h"
#include "TGo4Log.h"
#include "TGo4Picture.h"
#include "TGo4MbsEvent.h"
#include "TGo4UserException.h"
#include "TGo4WinCond.h"
#include "TGo4ShapedCond.h"
#include "TGo4ListCond.h"
#include "TGo4CondArray.h"

#include "TNectarRawEvent.h"
#include "TNectarRawParam.h"
#include "TNectarDisplay.h"
#include "TNectarRawProc.h"
#include "TNectarMonitoringEvent.h"
#include "TNectarMonitoringDisplay.h"
#include "TNectarMonitoringProc.h"

#include "TGo4Fitter.h"
#include "TGo4FitDataHistogram.h"
#include "TGo4FitParameter.h"
#include "TGo4FitModelPolynom.h"

#include "TGo4UserException.h"

#include "TCutG.h"
#include "TGo4WinCond.h"
#include "TGo4ShapedCond.h"
#include "TGo4CondArray.h"


//*********************************************************
TNectarMonitoringProc::TNectarMonitoringProc() :
  TGo4EventProcessor()
{

}


//*********************************************************
TNectarMonitoringProc::TNectarMonitoringProc(const char* name) :
  TGo4EventProcessor(name), fPar(0)
{
    SetMakeWithAutosave(kTRUE);
    
    //* Initialize user analysis object *//
    fPar = dynamic_cast<TNectarRawParam*>(MakeParameter("NectarRawParam", "TNectarRawParam", "set_NectarRawParam.C"));
    Histo->InitHistograms(false);

    //* Condition Banana selection *//
    //Double_t cutpnts[11][2]={{-10,9000},{10000,9000},{20000,9000},{30000,9000},{40000,9000},{40000,0},{30000,0},{20000,0},{10000,0},{0,0},{-10,9000}};
    Double_t cut_protons[12][2]={{0,8500},{5000,6000},{15000,4000},{25000,3000},{40000,3000},{40000,1000},{30000,1000},{20000,1500},{10000,3000},{1000,6000},{0,7000},{0,8500}};
    fPolyCon_protons = MakePolyCond("polycon_p", 12, cut_protons, "h_DE_E_tot_keV");
    
    Double_t cut_deuterons[8][2]={{13335,2065},{12776,1300},{13015,614},{16970,303},{19527,600},{19407,1879},{14533,2252},{13335,2065}};
    fPolyCon_deuterons = MakePolyCond("polycon_d", 8, cut_deuterons, "h_DE_E_tot_keV");

    //* Strainless steel window correction *//
    //TF1* SW_Correction = new TF1("SW_Correction","[0]+[1]*x+[2]*TMath::Power(x,2)+[3]*TMath::Power(x,3)+[4]*TMath::Power(x,4)",1,10);
    SW_Correction->SetParameter(0,0.0127746);
    SW_Correction->SetParameter(1,0.150414);
    SW_Correction->SetParameter(2,-0.00560874);
    SW_Correction->SetParameter(3,-0.00148719);
    SW_Correction->SetParameter(4,0.000180784);

}

//***********************************************************
//* Event builder : Fills detectors and updates histograms *//
Bool_t TNectarMonitoringProc::BuildEvent(TGo4EventElement *target)
{
  
    TNectarDetectors* Telescope = (TNectarDetectors*) target;
    TNectarRawEvent* rawEvent = (TNectarRawEvent*) GetInputEvent(); 
    
    //  ---    * Variable initialization *  ---   //
    // --------------------------------------------
    
    //Int_t counter = 0;
    
    //--- Telescope ---//
    Telescope->DT_telescope=0;
    
    for(Int_t i=0;i<17;i++)
    {
        Telescope->BB8_V_Energy[i]=0;
        Telescope->BB8_H_Energy[i]=0;
        Telescope->BB8_VStrip[i]=0;
        Telescope->BB8_HStrip[i]=0;
    }
    
    Telescope->ADC_MSX04_1=0; Telescope->ADC_MSX04_2=0; Telescope->ADC_MSX04_3=0; 
    Telescope->ADC_MSX04_4=0; Telescope->ADC_MSX04_5=0; Telescope->ADC_MSX04_6=0;
    
    Telescope->Energy_MSX04_1=0; Telescope->Energy_MSX04_2=0; Telescope->Energy_MSX04_3=0;
    Telescope->Energy_MSX04_4=0; Telescope->Energy_MSX04_5=0; Telescope->Energy_MSX04_6=0;
  
    for(Int_t i=0;i<129;i++)
    {
        Telescope->BB29_VStrip[i]=0;
    }
    
    Telescope->DT_BB29_V=0;
    
    for(Int_t i=0;i<65;i++)
    {
        Telescope->BB29_HStrip[i]=0;
    }
    
    Telescope->DT_BB29_H=0;
    

  
    //  ---    * Calling filling functions *  ---   //
    // ----------------------------------
    //* Loop to fill detectors depending on the VMMR id *//
    for (UInt_t i = 0; i < rawEvent->fgConfigVmmrBoards.size(); ++i){
          
        UInt_t uniqueid = rawEvent->fgConfigVmmrBoards[i];
        TVmmrBoard* theVmmr = rawEvent->GetVmmrBoard(uniqueid);
        
        // Filling VMMR0 (telescope, fission)
        if(uniqueid==0){
        
            Filling_Ev_Telescope(theVmmr,Telescope);
            Filling_Ev_FFtopbot(theVmmr,Telescope);
            Filling_Ev_FFside(theVmmr,Telescope);
        }
        
        // Filling VMMR1 (heavy residue)
        if(uniqueid==1){
         
            Filling_Ev_BB29(theVmmr,Telescope);
        }
        
      //counter++;
    }

    Telescope->SetValid(kTRUE);
    
    //  ---    * Trigger type *  ---   //
    // ----------------------------------
    Telescope->Trigger = rawEvent->ftrigger;
    
    /* MOFIFICATION MARCH 2024 TO MODIFY AGAIN FOR EXPERIENCE
    Checks for the type of trigger (target or not) 
    The condition has been removed for tests without target

    if((Telescope->Trigger==1))  Update_Histograms_Target_on(Telescope);
    if((Telescope->Trigger==2))  Update_Histograms_Target_off(Telescope);
        
    if((Telescope->Trigger==1))  Online_Analysis_Target_on(Telescope);  
    if((Telescope->Trigger==2))  Online_Analysis_Target_off(Telescope); */
  
    Update_Histograms_Target_on(Telescope);
    //Update_Histograms_Target_off(Telescope);
    Online_Analysis_Target_on(Telescope);
    //Online_Analysis_Target_off(Telescope);

  return kTRUE;	
}	

//***********************************************************
//* Telescope filling function : from Raw event ADC and DT values *//
void TNectarMonitoringProc:: Filling_Ev_Telescope(TVmmrBoard* theVmmr, TNectarDetectors* Telescope)
{    
    
    for (int slid=0; slid<VMMR_CHAINS; ++slid){
    
        TVmmrSlave* theslave=theVmmr->GetSlave(slid, kFALSE);
        
        if(theslave>0){
            
            UInt_t maxvmmrmessages = theslave->NumAdcMessages();
           
            if(slid==0){
            
                //For cycle around the strips values to fill new variables
                //Conversion  Array VMMR channel -> Strips number 
                int Vmmr_strip_C[32] = {15,11,16,14,12,9,13,8,10,5,6,3,7,2,4,1,15,16,10,14,13,12,9,11,4,8,7,6,3,5,1,2};   
                
                for(UInt_t a=0;a<64;a++)
                { 
                    for (UInt_t i = 0; i < maxvmmrmessages; i++)
                    {
                        TVmmrAdcData* dat = theslave->GetAdcMessage(i);
                        
                        //  ---    * BB8 *  ---   //
                        // ------------------------
                        if(dat->fFrontEndSubaddress==a)
                        {   
                            // Horizontal strips
                            if(a<=15){   // Filling BB8 MonitoringEvent with Convertion (VMMR channel -> Strips number) 
                                
                                Int_t id = Vmmr_strip_C[a]; 
                                Telescope->BB8_HStrip[id] = dat->fData;
                                //counter++;
                            }
                            
                            // Vertical strips
                            if ((a>15)&&(a<32)){
                            
                                Int_t id = Vmmr_strip_C[a];
                                Telescope->BB8_VStrip[id] = dat->fData;
                            }                            
                            
                        }

                        //  ---    * MSX04s *  ---   //
                        // ------------------------
                        if (dat->fFrontEndSubaddress==42) Telescope->ADC_MSX04_1 = dat->fData;  
                        if (dat->fFrontEndSubaddress==43) Telescope->ADC_MSX04_2 = dat->fData;   
                        if (dat->fFrontEndSubaddress==44) Telescope->ADC_MSX04_3 = dat->fData; 
                        if (dat->fFrontEndSubaddress==45) Telescope->ADC_MSX04_4 = dat->fData;     
                        if (dat->fFrontEndSubaddress==46) Telescope->ADC_MSX04_5 = dat->fData;   
                        if (dat->fFrontEndSubaddress==47) Telescope->ADC_MSX04_6 = dat->fData;     
                    }
                }
                
                Telescope->DT_telescope = theslave->fDeltaTGate;

            }
	
        }
    }
}

//***********************************************************
//* FF top and bottom filling function *//
void TNectarMonitoringProc:: Filling_Ev_FFtopbot(TVmmrBoard* theVmmr, TNectarDetectors* Telescope)
{
    for (int slid=0; slid<VMMR_CHAINS; ++slid)
    {
        TVmmrSlave* theslave=theVmmr->GetSlave(slid, kFALSE);
        if(theslave>0)
        {
            /* MOFIFICATION MARCH 2024 
            Previous if condition :             
            if(maxvmmrmessages==64){ 
            Does not work for E028 since there is another MMR64 for fission on the first VMMR 
            New condition looks for bus id instead */
            
            UInt_t maxvmmrmessages = theslave->NumAdcMessages();
            
            //* TELESCOPE *//
            if(slid==7 && maxvmmrmessages==32)
            {
                //TGo4Log::Info("max vmmr messages fftop: %d ", maxvmmrmessages); 
                //TGo4Log::Info("slave id: %d ", slid); 
                
                //For cycle around the strips values to fill new variables
                //Conversion  Array VMMR channel -> Strips number 
                int Vmmr_strip_C[32] = {15,11,16,14,12,9,13,8,10,5,6,3,7,2,4,1,15,16,10,14,13,12,9,11,4,8,7,6,3,5,1,2};   
                
                for(UInt_t a=0;a<32;a++)
                { 
                    for (UInt_t i = 0; i < maxvmmrmessages; i++)
                    {
                        TVmmrAdcData* dat = theslave->GetAdcMessage(i);
        
                        if(dat->fFrontEndSubaddress==a)
                        {   
                            // Horizontal strips
                            if(a<=15)   // Filling BB8 MonitoringEvent with Convertion (VMMR channel -> Strips number) 
                            {  
                                
                                Int_t id = Vmmr_strip_C[a]; 
                                Telescope->BB36_top_HStrip[id] = dat->fData;
                                //counter++;
                            }
                            
                            // Vertical strips
                            if ((a>15)&&(a<32))
                            {
                                Int_t id = Vmmr_strip_C[a];
                                Telescope->BB36_top_VStrip[id] = dat->fData;
                            }                            
                            
                        }

                    }
                }
                
                Telescope->DT_BB36_top = theslave->fDeltaTGate;
                //TGo4Log::Info("Trigger RAW: %d ", Telescope->DT_telescope);     
            }
            
            if(slid==4 && maxvmmrmessages==32)
            {
                //TGo4Log::Info("max vmmr messages fftop: %d ", maxvmmrmessages); 
                //TGo4Log::Info("slave id: %d ", slid); 
                
                //For cycle around the strips values to fill new variables
                //Conversion  Array VMMR channel -> Strips number 
                int Vmmr_strip_C[32] = {15,11,16,14,12,9,13,8,10,5,6,3,7,2,4,1,15,16,10,14,13,12,9,11,4,8,7,6,3,5,1,2};   
                
                for(UInt_t a=0;a<32;a++)
                { 
                    for (UInt_t i = 0; i < maxvmmrmessages; i++)
                    {
                        TVmmrAdcData* dat = theslave->GetAdcMessage(i);
        
                        if(dat->fFrontEndSubaddress==a)
                        {   
                            // Horizontal strips
                            if(a<=15)   // Filling BB8 MonitoringEvent with Convertion (VMMR channel -> Strips number) 
                            {  
                                
                                Int_t id = Vmmr_strip_C[a]; 
                                Telescope->BB36_bot_HStrip[id] = dat->fData;
                                //counter++;
                            }
                            
                            // Vertical strips
                            if ((a>15)&&(a<32))
                            {
                                Int_t id = Vmmr_strip_C[a];
                                Telescope->BB36_bot_VStrip[id] = dat->fData;
                            }                            
                            
                        }

                    }
                }
                
                Telescope->DT_BB36_bot = theslave->fDeltaTGate;
                //TGo4Log::Info("Trigger RAW: %d ", Telescope->DT_telescope);     
            }
        }
    }
}

//***********************************************************
//* FF side filling function *//
void TNectarMonitoringProc:: Filling_Ev_FFside(TVmmrBoard* theVmmr, TNectarDetectors* Telescope)
{
    // MMR- 128 channels  
    for (int slid=0; slid<VMMR_CHAINS; ++slid)
    {
        TVmmrSlave* theslave=theVmmr->GetSlave(slid, kFALSE);
        
        if(theslave>0)
        {
            UInt_t maxvmmrmessages = theslave->NumAdcMessages();
            
            if(slid==5)
            {
                int Vmmr_strip_C[128] = {0,0,40,14,36,16,30,10,34,12,38,6,44,8,42,2,48,4,46,20,52,18,50,24,56,22,54,28,60,26,58,32,57,31,59,25,53,27,55,21,49,23,51,17,45,19,47,3,41,1,43,7,37,5,33,11,29,9,35,15,39,13,0,0,62,0,66,64,112,110,116,114,120,118,68,122,70,72,74,76,78,80,82,84,88,86,92,90,96,94,100,98,104,102,108,106,107,105,103,101,99,97,95,93,91,89,87,85,81,83,77,79,73,75,69,71,67,121,119,117,115,113,111,109,65,63,61};    //Convension Array VMMR channel -> Strips number 
                
                for(UInt_t a=0;a<128;a++)
                {    
                    for (UInt_t i = 0; i < maxvmmrmessages; i++)
                    {
                        TVmmrAdcData* dat = theslave->GetAdcMessage(i);
                        
                        if(dat->fFrontEndSubaddress==a)
                        {
                            Int_t id = Vmmr_strip_C[a];
		                    Telescope->BB29_side_VStrip[id] = dat->fData;
                            // TGo4Log::Info("TNectarMonitoring V: %d ", dat->fData);
                            //Telescope->BB29_VStrip[a] = dat->fData;
                        }
                    }
                }
                
                Telescope->DT_BB29_side_V = theslave->fDeltaTGate;
            }
     
      
            // MMR - 64 channels
            //TGo4Log::Info("maxvmmrmessages: %d ", maxvmmrmessages);
            if(slid==6)
            {
                TVmmrSlave* theslave=theVmmr->GetSlave(slid, kFALSE);
                UInt_t maxvmmrmessages = theslave->NumAdcMessages();
                int Vmmr_strip_C[64] = {0,0,0,0,0,0,0,0,0,0,0,0,39,40,37,38,35,36,33,34,31,32,29,30,27,28,25,26,23,24,21,22,19,20,17,18,15,16,13,14,11,12,9,10,7,8,5,6,3,4,1,2,0,0,0,0,0,0,0,0,0,0,0,0};    //Convension Array VMMR channel -> Strips number 
	  
                for(UInt_t a=0;a<64;a++)
                {    
                    for (UInt_t i = 0; i < maxvmmrmessages; i++)
                    {
                        TVmmrAdcData* dat = theslave->GetAdcMessage(i);
                        if(dat->fFrontEndSubaddress==a)
                        {
                            Int_t id = Vmmr_strip_C[a]; 
                            Telescope->BB29_side_HStrip[id] = dat->fData;
                            //Telescope->BB29_HStrip[a] = dat->fData;
                        }
                    }
                }
                
                Telescope->DT_BB29_side_H = theslave->fDeltaTGate;
            }
        }
    }
}

//***********************************************************
//* HR filling function *//
void TNectarMonitoringProc:: Filling_Ev_BB29(TVmmrBoard* theVmmr, TNectarDetectors* Telescope)
{
  // MMR- 128 channels  
  for (int slid=0; slid<VMMR_CHAINS; ++slid)
    {
      TVmmrSlave* theslave=theVmmr->GetSlave(slid, kFALSE);
      if(theslave>0){
	UInt_t maxvmmrmessages = theslave->NumAdcMessages();
	if(slid==5){
	  int Vmmr_strip_C[128] = {0,0,40,14,36,16,30,10,34,12,38,6,44,8,42,2,48,4,46,20,52,18,50,24,56,22,54,28,60,26,58,32,57,31,59,25,53,27,55,21,49,23,51,17,45,19,47,3,41,1,43,7,37,5,33,11,29,9,35,15,39,13,0,0,62,0,66,64,112,110,116,114,120,118,68,122,70,72,74,76,78,80,82,84,88,86,92,90,96,94,100,98,104,102,108,106,107,105,103,101,99,97,95,93,91,89,87,85,81,83,77,79,73,75,69,71,67,121,119,117,115,113,111,109,65,63,61};    //Convension Array VMMR channel -> Strips number 
	  for(UInt_t a=0;a<128;a++){    
	    for (UInt_t i = 0; i < maxvmmrmessages; i++)
	      {
		TVmmrAdcData* dat = theslave->GetAdcMessage(i);
		if(dat->fFrontEndSubaddress==a){
		  Int_t id = Vmmr_strip_C[a];
		  Telescope->BB29_VStrip[id] = dat->fData;
		  // TGo4Log::Info("TNectarMonitoring V: %d ", dat->fData);
		  //Telescope->BB29_VStrip[a] = dat->fData;
		}
	      }
	  }
	  Telescope->DT_BB29_V = theslave->fDeltaTGate;
	}
     
      
	// MMR - 64 channels
	//TGo4Log::Info("maxvmmrmessages: %d ", maxvmmrmessages);
	if(slid==6){
	  TVmmrSlave* theslave=theVmmr->GetSlave(slid, kFALSE);
	  UInt_t maxvmmrmessages = theslave->NumAdcMessages();
	  int Vmmr_strip_C[64] = {0,0,0,0,0,0,0,0,0,0,0,0,39,40,37,38,35,36,33,34,31,32,29,30,27,28,25,26,23,24,21,22,19,20,17,18,15,16,13,14,11,12,9,10,7,8,5,6,3,4,1,2,0,0,0,0,0,0,0,0,0,0,0,0};    //Convension Array VMMR channel -> Strips number 
	  for(UInt_t a=0;a<64;a++){    
	    for (UInt_t i = 0; i < maxvmmrmessages; i++)
	      {
		TVmmrAdcData* dat = theslave->GetAdcMessage(i);
		if(dat->fFrontEndSubaddress==a){
		  Int_t id = Vmmr_strip_C[a]; 
		  Telescope->BB29_HStrip[id] = dat->fData;
		  //Telescope->BB29_HStrip[a] = dat->fData;
		}
	      }
	  }
	  Telescope->DT_BB29_H = theslave->fDeltaTGate;
	}
      }
    }
}

//***********************************************************
//* Online analysis target on function *//
void TNectarMonitoringProc:: Online_Analysis_Target_on(TNectarDetectors* Telescope)
{
    Int_t S_E_id=0, S_E_id_V=0  /*(modified to test mapping BB29)*/, S_E_id_H=0, nV=0, nV1=0, nV2=0, nH=0, Total_ch=0, strip_BB29_V=0, strip_BB29_H=0,  S_E_id_V_HR=0, S_E_id_H_HR=0;
    Double_t Total_E=0, E_1=0, E_2=0, E_3=0, E_4=0, E_5=0, E_6=0; //, E_BB8_Mult=0;
    Int_t mult_BB8_V=0, mult_BB8_H=0;
    Int_t DT_m = Telescope->DT_telescope + fPar->DT_min;
    Int_t DT_M = Telescope->DT_telescope + fPar->DT_max;  
    Int_t DT = Telescope->DT_BB29_V;
  
    fPolyCon_protons->Enable();
    fPolyCon_deuterons->Enable();
        
    //  ---    * Telescope *  ---   //
    // -------------------------------
    
    // MSX04 filling energy variables with calibration function
    if(Telescope->ADC_MSX04_1>fPar->MSX04_1_threshold) Telescope->Energy_MSX04_1 = Calib_MSX04(Telescope->ADC_MSX04_1,1);
    if(Telescope->ADC_MSX04_2>fPar->MSX04_2_threshold) Telescope->Energy_MSX04_2 = Calib_MSX04(Telescope->ADC_MSX04_2,2);
    if(Telescope->ADC_MSX04_3>fPar->MSX04_3_threshold) Telescope->Energy_MSX04_3 = Calib_MSX04(Telescope->ADC_MSX04_3,3);
    if(Telescope->ADC_MSX04_4>fPar->MSX04_4_threshold) Telescope->Energy_MSX04_4 = Calib_MSX04(Telescope->ADC_MSX04_4,4);
    if(Telescope->ADC_MSX04_5>fPar->MSX04_5_threshold) Telescope->Energy_MSX04_5 = Calib_MSX04(Telescope->ADC_MSX04_5,5);
    if(Telescope->ADC_MSX04_6>fPar->MSX04_6_threshold) Telescope->Energy_MSX04_6 = Calib_MSX04(Telescope->ADC_MSX04_6,6);
    
    // BB8 filling strip by strip calibrated energy, mapping, DT vs energy, deltaE/E plots...
    for(Int_t i=1; i<17; i++){
        
        if(Telescope->BB8_VStrip[i]>fPar->BB8_V_threshold){
            nV=i; S_E_id++; S_E_id_V++, mult_BB8_V++;
            // Calibration V
            Telescope->BB8_V_Energy[nV] = Calib_BB8_V(Telescope->BB8_VStrip[nV],nV) ;
            // DT vs Estrip V
            Histo->BB8_DT_E_V[i-1]->Fill(Telescope->DT_telescope,Telescope->BB8_VStrip[nV]);
            
            for(Int_t j=1; j<17; j++){
                
                if(Telescope->BB8_HStrip[j]>fPar->BB8_H_threshold){
                    
                    nH=j; S_E_id++; S_E_id_H++, mult_BB8_H++;
                    // Calibration H
                    Telescope->BB8_H_Energy[nH] = Calib_BB8_H(Telescope->BB8_VStrip[nH],nH);
                    // Mapping BB8
                    if((Telescope->BB8_HStrip[j]>200) && (Telescope->BB8_VStrip[i]>200)) Histo->h_BB8_Map->Fill(nV,-nH);
                    
                    // 1 V strip vs any H strip
                    Histo->BB8_1V_allH[nV-1]->Fill(Telescope->BB8_VStrip[nV],Telescope->BB8_HStrip[nH]);
                    
                }	  	  
            }
        }
    }
    
            // DeltaE/E global plot multiplicity 1
            // Condition on the events with 1 V Strip and 1 H Strip on the BB8
            // It must be setted equal to 1 in order to consider only one strip events
            //if((S_E_id_V==1)&&(S_E_id_H==1)){ 
        
                Total_ch=0;
                Total_E=0;
 
                // --- DeltaE/E plots ---
                if(Telescope->ADC_MSX04_1>fPar->MSX04_1_threshold){
                    Total_ch=Total_ch+(Telescope->ADC_MSX04_1);
                    Total_E=Total_E+(Telescope->Energy_MSX04_1);
                    
                    if(Telescope->ADC_MSX04_2>fPar->MSX04_2_threshold){
                        Total_ch=Total_ch+(Telescope->ADC_MSX04_2);
                        Total_E=Total_E+(Telescope->Energy_MSX04_2);
        
                        if(Telescope->ADC_MSX04_3>fPar->MSX04_3_threshold){
                            Total_ch=Total_ch+(Telescope->ADC_MSX04_3);
                            Total_E=Total_E+(Telescope->Energy_MSX04_3);
        
                            if(Telescope->ADC_MSX04_4>fPar->MSX04_4_threshold){
                                Total_ch=Total_ch+(Telescope->ADC_MSX04_4);
                                Total_E=Total_E+(Telescope->Energy_MSX04_4);
            
                                if(Telescope->ADC_MSX04_5>fPar->MSX04_5_threshold){
                                    Total_ch=Total_ch+(Telescope->ADC_MSX04_5);
                                    Total_E=Total_E+(Telescope->Energy_MSX04_5);
            
                                    if(Telescope->ADC_MSX04_6>fPar->MSX04_6_threshold){
                                        Total_ch=Total_ch+(Telescope->ADC_MSX04_6);
                                        Total_E=Total_E+(Telescope->Energy_MSX04_6);
                                    }
                                }
                            }
                        }
                    }
                }
                
                // DE_E Energy Plots in ch for each strip then all strips
                Histo->h_DE_E_tot_ch_strip[nV-1]->Fill(Total_ch, Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_tot_ch->Fill(Total_E,Telescope->BB8_VStrip[nV]);
                
                // DE_E Energy Plots in KeV for each strip then all strips
                Histo->h_DE_E_tot_kev_strip[nV-1]->Fill(Total_E,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_tot_keV->Fill(Total_E,Telescope->BB8_V_Energy[nV]);
                
                // --- DeltaE/Ex plots ---
                // In ch for each strips
                Histo->h_DE_E_1_ch_strip[nV-1]->Fill(Telescope->ADC_MSX04_1,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_2_ch_strip[nV-1]->Fill(Telescope->ADC_MSX04_2,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_3_ch_strip[nV-1]->Fill(Telescope->ADC_MSX04_3,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_4_ch_strip[nV-1]->Fill(Telescope->ADC_MSX04_4,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_5_ch_strip[nV-1]->Fill(Telescope->ADC_MSX04_5,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_6_ch_strip[nV-1]->Fill(Telescope->ADC_MSX04_6,Telescope->BB8_VStrip[nV]);
                // Then all strips
                Histo->h_DE_E_1_ch->Fill(Telescope->ADC_MSX04_1,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_2_ch->Fill(Telescope->ADC_MSX04_2,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_3_ch->Fill(Telescope->ADC_MSX04_3,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_4_ch->Fill(Telescope->ADC_MSX04_4,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_5_ch->Fill(Telescope->ADC_MSX04_5,Telescope->BB8_VStrip[nV]);
                Histo->h_DE_E_6_ch->Fill(Telescope->ADC_MSX04_6,Telescope->BB8_VStrip[nV]);                

                // In keV for all strips
                Histo->h_DE_E_1_keV_strip[nV-1]->Fill(Telescope->Energy_MSX04_1,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_2_keV_strip[nV-1]->Fill(Telescope->Energy_MSX04_2,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_3_keV_strip[nV-1]->Fill(Telescope->Energy_MSX04_3,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_4_keV_strip[nV-1]->Fill(Telescope->Energy_MSX04_4,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_5_keV_strip[nV-1]->Fill(Telescope->Energy_MSX04_5,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_6_keV_strip[nV-1]->Fill(Telescope->Energy_MSX04_6,Telescope->BB8_V_Energy[nV]);               
                // Then all strips
                Histo->h_DE_E_1_keV->Fill(Telescope->Energy_MSX04_1,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_2_keV->Fill(Telescope->Energy_MSX04_2,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_3_keV->Fill(Telescope->Energy_MSX04_3,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_4_keV->Fill(Telescope->Energy_MSX04_4,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_5_keV->Fill(Telescope->Energy_MSX04_5,Telescope->BB8_V_Energy[nV]);
                Histo->h_DE_E_6_keV->Fill(Telescope->Energy_MSX04_6,Telescope->BB8_V_Energy[nV]);
                
                // --- Ei vs Ej plots ---
                Histo->h_E1_E2_keV->Fill(Telescope->Energy_MSX04_2,Telescope->Energy_MSX04_1);
                Histo->h_E2_E3_keV->Fill(Telescope->Energy_MSX04_3,Telescope->Energy_MSX04_2);
                Histo->h_E3_E4_keV->Fill(Telescope->Energy_MSX04_4,Telescope->Energy_MSX04_3);
                Histo->h_E4_E5_keV->Fill(Telescope->Energy_MSX04_5,Telescope->Energy_MSX04_4);
                Histo->h_E5_E6_keV->Fill(Telescope->Energy_MSX04_6,Telescope->Energy_MSX04_5);
                
                // --- Singles conditionned ---
                // Conditionned plots DeltaE-E with proton or deuteron condition 
                // Proton event in the telescope
                if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                    Histo->h_DE_E_tot_keV_cond_p->Fill(Total_E,Telescope->BB8_V_Energy[nV]);
                    
                    if (nV==3){
                        Histo->h_Eproton_VS3_ch->Fill(Telescope->BB8_VStrip[nV]+Total_ch);
                        Histo->h_Eproton_VS3_keV->Fill(Telescope->BB8_V_Energy[nV]+Total_E);
                    }
                }
                
                // Deuteron event in the telescope
                if(fPolyCon_deuterons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                    Histo->h_DE_E_tot_keV_cond_d->Fill(Total_E,Telescope->BB8_V_Energy[nV]);
                    
                    if (nV==3){
                        Histo->h_Edeuteron_VS3_ch->Fill(Telescope->BB8_VStrip[nV]+Total_ch);
                        Histo->h_Edeuteron_VS3_keV->Fill(Telescope->BB8_V_Energy[nV]+Total_E);
                    }
                    
                }
                
                
                
                // - Misc / not changed
                //Strip vs Total Energy plot
                Histo->h_V_E_tot->Fill(nV,Total_E+Telescope->BB8_V_Energy[nV]);
                Histo->h_V_ch_tot->Fill(nV,Total_ch+Telescope->BB8_VStrip[nV]);
                //Histo->h_DE_E_tot_keV_cond->Fill(Total_E,Telescope->BB8_V_Energy[nV]);
                if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV])) Ex_Calculation(nV,nH,Telescope,Total_E);   //Excitation Energy calculation for Banana Selection
                


           // } // closing condition multiplicity 1
        //} 
    //}
  
    // BB8 bidim energy of adjacent vertical strips
    for(Int_t i=1; i<17; i++){
        if(Telescope->BB8_VStrip[i]>fPar->BB8_V_threshold){

            for(Int_t j=1; j<17; j++){
                if(Telescope->BB8_VStrip[i]>fPar->BB8_V_threshold){
                
                    if (j==i+1){
                        Histo->BB8_adj_V[i-1]->Fill(Telescope->BB8_VStrip[i],Telescope->BB8_VStrip[j]);
                    }
                }   
            }
        } 
    }
    
    // BB8 bidim energy of adjacent horizontal strips
    for(Int_t i=1; i<17; i++){
        
        if(Telescope->BB8_HStrip[i]>fPar->BB8_H_threshold){

            for(Int_t j=1; j<17; j++){
                if(Telescope->BB8_HStrip[i]>fPar->BB8_H_threshold){

                    if (j==i+1){
                        Histo->BB8_adj_H[i-1]->Fill(Telescope->BB8_HStrip[i],Telescope->BB8_HStrip[j]);
                    }
                }
            }
        } 
    }
    
    // BB8 center pixel with and without multiplicity 1 condition
    Histo->BB8_V8_H8->Fill(Telescope->BB8_VStrip[8],Telescope->BB8_HStrip[8]);      
    if((mult_BB8_V==1)&&(mult_BB8_H==1)){
        Histo->BB8_V8_H8_mult1->Fill(Telescope->BB8_VStrip[8],Telescope->BB8_HStrip[8]);
    }
  
    // DeltaE/E with interstrips
    /*
    //Condition on Events with Multiplicity larger than 1
    if(((S_E_id_V>1)&&(S_E_id_H>=1))||((S_E_id_V>=1)&&(S_E_id_H>1))){
      
      if(Telescope->ADC_MSX04_1>fPar->MSX04_1_threshold) {
	  Total_ch=Total_ch+(Telescope->ADC_MSX04_1);
	  E_1=Calib_MSX04(Telescope->ADC_MSX04_1, 1);
	  Total_E=Total_E+E_1;
      
	  if(Telescope->ADC_MSX04_2>fPar->MSX04_2_threshold)
	    {
	      Total_ch=Total_ch+(Telescope->ADC_MSX04_2);
	      E_2=Calib_MSX04(Telescope->ADC_MSX04_2, 2);
	      Total_E=Total_E+E_2;
          
	      if(Telescope->ADC_MSX04_3>fPar->MSX04_3_threshold)
		{
		  Total_ch=Total_ch+(Telescope->ADC_MSX04_3);
		  E_3=Calib_MSX04(Telescope->ADC_MSX04_3, 3);
		  Total_E=Total_E+E_3;
          
		  if(Telescope->ADC_MSX04_4>fPar->MSX04_4_threshold)
		    {
		      Total_ch=Total_ch+(Telescope->ADC_MSX04_4);
		      E_4=Calib_MSX04(Telescope->ADC_MSX04_4, 4);
		      Total_E=Total_E+E_4;
              
		      if(Telescope->ADC_MSX04_5>fPar->MSX04_5_threshold)
			{
			  Total_ch=Total_ch+(Telescope->ADC_MSX04_5);
			  E_5=Calib_MSX04(Telescope->ADC_MSX04_5, 5);
			  Total_E=Total_E+E_5;
              
			  if(Telescope->ADC_MSX04_6>fPar->MSX04_6_threshold)
			    {
			      Total_ch=Total_ch+(Telescope->ADC_MSX04_6);
			      E_6=Calib_MSX04(Telescope->ADC_MSX04_6, 6);
			      Total_E=Total_E+E_6;
			    }
			}
		    }
		}
	    }
	}
      
      Histo->h_DE_E_tot_Mult->Fill(Total_E,Telescope->BB8_V_Energy[nV]);
      
    } */

    //  ---    * FF top *  ---   //
    // ----------------------------
    for(Int_t i=1; i<17; i++){
        if(Telescope->BB36_top_VStrip[i]>fPar->BB36FF_V_threshold){
            
            Histo->BB36_FFtop_DT_E_V[i-1]->Fill(Telescope->DT_BB36_top,Telescope->BB36_top_VStrip[nV]);
        
            for(Int_t j=1; j<17; j++){
                if(Telescope->BB36_top_HStrip[j]>fPar->BB36FF_H_threshold){
                    
                    if((Telescope->BB36_top_VStrip[i]>200) && (Telescope->BB36_top_HStrip[j]>200)) Histo->h_FFtop_Map->Fill(i,(16-j)+1);
                    
                    if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_FFtop_E_y_cond_p->Fill(j,Telescope->BB36_top_HStrip[j]);
                        Histo->h_FFtop_map_cond_p->Fill(i,(16-j)+1);

                    }
                    
                    else if(fPolyCon_deuterons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_FFtop_E_y_cond_d->Fill(j,Telescope->BB36_top_HStrip[j]);
                        Histo->h_FFtop_map_cond_d->Fill(i,(16-j)+1);

                    }
                    
                    else {
                        Histo->h_FFtop_E_y_autotrig->Fill(j,Telescope->BB36_top_HStrip[j]);
                        Histo->h_FFtop_map_autotrig->Fill(i,(16-j)+1);
                    }
                }	  	  
            }
        } 
    }

    //  ---    * FF bot *  ---   //
    // ----------------------------    
    for(Int_t i=1; i<17; i++){

        if(Telescope->BB36_bot_VStrip[i]>fPar->BB36FF_V_threshold){
            
            Histo->BB36_FFbot_DT_E_V[i-1]->Fill(Telescope->DT_BB36_bot,Telescope->BB36_bot_VStrip[nV]);
            
            for(Int_t j=1; j<17; j++){
                if(Telescope->BB36_bot_HStrip[j]>fPar->BB36FF_H_threshold){

                    if((Telescope->BB36_bot_VStrip[i]>200) && (Telescope->BB36_bot_HStrip[j]>200)) Histo->h_FFbot_Map->Fill(i,j); 
                    
                    if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_FFbot_E_y_cond_p->Fill(j,Telescope->BB36_bot_HStrip[j]);
                        Histo->h_FFbot_map_cond_p->Fill(i,j);

                    }
                    
                    else if(fPolyCon_deuterons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_FFbot_E_y_cond_d->Fill(j,Telescope->BB36_bot_HStrip[j]);
                        Histo->h_FFbot_map_cond_d->Fill(i,j);

                    }
                    
                    else {
                        Histo->h_FFbot_E_y_autotrig->Fill(j,Telescope->BB36_bot_HStrip[j]);
                        Histo->h_FFbot_map_autotrig->Fill(i,j);
                    }
                }	  	  
            }
        } 
    }

    //  ---    * FF side *  ---   //
    // ----------------------------  
    
    for(Int_t i=1; i<129; i++){

        if(Telescope->BB29_side_VStrip[i]>fPar->BB29FF_V_threshold){
       
            for(Int_t j=1; j<65; j++){
                if(Telescope->BB29_side_HStrip[j]>fPar->BB29FF_H_threshold){

                    if((Telescope->BB29_side_HStrip[j]>200) && (Telescope->BB29_side_VStrip[i]>200)) Histo->h_FFside_Map->Fill(i,-j);
                    
                    if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_FFside_E_x_cond_p->Fill(j,Telescope->BB29_side_HStrip[j]);
                        Histo->h_FFside_map_cond_p->Fill(i,-j);

                    }
                    
                    else if(fPolyCon_deuterons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_FFside_E_x_cond_d->Fill(j,Telescope->BB29_side_HStrip[j]);
                        Histo->h_FFside_map_cond_d->Fill(i,-j);

                    }
                    
                    else {
                        Histo->h_FFside_E_x_autotrig->Fill(j,Telescope->BB29_side_HStrip[j]);
                        Histo->h_FFside_map_autotrig->Fill(i,-j);
                    }
                    
                    // Histograms for FF side tests in May
                    if (i==1)   Histo->BB29_FFside_V1_allH->Fill(Telescope->BB29_side_VStrip[i],Telescope->BB29_side_HStrip[j]);
                    if (i==2)   Histo->BB29_FFside_V2_allH->Fill(Telescope->BB29_side_VStrip[i],Telescope->BB29_side_HStrip[j]);
                    if (i==60)   Histo->BB29_FFside_V60_allH->Fill(Telescope->BB29_side_VStrip[i],Telescope->BB29_side_HStrip[j]);
                    if (i==61)   Histo->BB29_FFside_V61_allH->Fill(Telescope->BB29_side_VStrip[i],Telescope->BB29_side_HStrip[j]);
                    if (i==119)   Histo->BB29_FFside_V119_allH->Fill(Telescope->BB29_side_VStrip[i],Telescope->BB29_side_HStrip[j]);
                    if (i==120)   Histo->BB29_FFside_V120_allH->Fill(Telescope->BB29_side_VStrip[i],Telescope->BB29_side_HStrip[j]);
                
                }	  	  
            }
        } 
    }
  

    
    
    for(Int_t i=1; i<129; i++){
    //Total_ch=0;
    //Total_E=0;
        if(Telescope->BB29_VStrip[i]>fPar->BB29_V_threshold){
       
            for(Int_t j=1; j<65; j++){
                if(Telescope->BB29_HStrip[j]>fPar->BB29_H_threshold){

                    if((Telescope->BB29_HStrip[j]>200) && (Telescope->BB29_VStrip[i]>200)) Histo->h_HR_Map->Fill(i,-j);
                    
                    if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_HR_E_x_cond_p->Fill(j,Telescope->BB29_HStrip[j]);
                        Histo->h_HR_map_cond_p->Fill(i,-j);

                    }
                    
                    else if(fPolyCon_deuterons->Test(Total_E,Telescope->BB8_V_Energy[nV])){  
                    
                        Histo->h_HR_E_x_cond_d->Fill(j,Telescope->BB29_HStrip[j]);
                        Histo->h_HR_map_cond_d->Fill(i,-j);

                    }
                    
                    else {
                        Histo->h_HR_E_x_autotrig->Fill(j,Telescope->BB29_HStrip[j]);
                        Histo->h_HR_map_autotrig->Fill(i,-j);
                    }
                    
                    // Histograms for HR tests in May
                    if (i==1)   Histo->BB29_HR_V1_allH->Fill(Telescope->BB29_VStrip[i],Telescope->BB29_HStrip[j]);
                    if (i==2)   Histo->BB29_HR_V2_allH->Fill(Telescope->BB29_VStrip[i],Telescope->BB29_HStrip[j]);
                    if (i==60)   Histo->BB29_HR_V60_allH->Fill(Telescope->BB29_VStrip[i],Telescope->BB29_HStrip[j]);
                    if (i==61)   Histo->BB29_HR_V61_allH->Fill(Telescope->BB29_VStrip[i],Telescope->BB29_HStrip[j]);
                    if (i==119)   Histo->BB29_HR_V119_allH->Fill(Telescope->BB29_VStrip[i],Telescope->BB29_HStrip[j]);
                    if (i==120)   Histo->BB29_HR_V120_allH->Fill(Telescope->BB29_VStrip[i],Telescope->BB29_HStrip[j]);
              
                }	  	  
            }
        } 
    }  
    
    //HR
    for(Int_t a=1;a<=128;a++){
        if(Telescope->BB29_VStrip[a]>fPar->BB29_V_threshold){
            strip_BB29_V=a; S_E_id_V_HR++;
            for(Int_t b=1;b<=64;b++){
                if(Telescope->BB29_HStrip[b]>fPar->BB29_H_threshold)
                { 
                    strip_BB29_H=-b; S_E_id_H_HR++;
                    //Histo->h_Map_HR->Fill(strip_BB29_V,strip_BB29_H);
                    if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV]))    Histo->h_cond_Map_BB29_DE->Fill(strip_BB29_V,strip_BB29_H);
                    if((DT>DT_m)&&(DT<DT_M))
                    {
                        Histo->h_cond_Map_BB29_DT->Fill(strip_BB29_V,strip_BB29_H);  
                        if(fPolyCon_protons->Test(Total_E,Telescope->BB8_V_Energy[nV]))    Histo->h_cond_Map_BB29->Fill(strip_BB29_V,strip_BB29_H);
                    }
                }
            }
      //BB29 Conditioned Mapping
        }
    }
    
    
      // Histograms for FF side tests in May
    Histo->BB29_FFside_V1_V2->Fill(Telescope->BB29_side_VStrip[1],Telescope->BB29_side_VStrip[2]);
    Histo->BB29_FFside_V2_V3->Fill(Telescope->BB29_side_VStrip[2],Telescope->BB29_side_VStrip[3]);
    Histo->BB29_FFside_V60_V61->Fill(Telescope->BB29_side_VStrip[60],Telescope->BB29_side_VStrip[61]);
    Histo->BB29_FFside_V61_V62->Fill(Telescope->BB29_side_VStrip[61],Telescope->BB29_side_VStrip[62]);
    Histo->BB29_FFside_V118_V119->Fill(Telescope->BB29_side_VStrip[118],Telescope->BB29_side_VStrip[119]);
    Histo->BB29_FFside_V119_V120->Fill(Telescope->BB29_side_VStrip[119],Telescope->BB29_side_VStrip[120]);
    
    Histo->BB29_FFside_DT_V1->Fill(Telescope->DT_BB29_side_V,Telescope->BB29_side_VStrip[1]);
    Histo->BB29_FFside_DT_V2->Fill(Telescope->DT_BB29_side_V,Telescope->BB29_side_VStrip[2]);
    Histo->BB29_FFside_DT_V60->Fill(Telescope->DT_BB29_side_V,Telescope->BB29_side_VStrip[60]);
    Histo->BB29_FFside_DT_V61->Fill(Telescope->DT_BB29_side_V,Telescope->BB29_side_VStrip[61]);
    Histo->BB29_FFside_DT_V119->Fill(Telescope->DT_BB29_side_V,Telescope->BB29_side_VStrip[119]);
    Histo->BB29_FFside_DT_V120->Fill(Telescope->DT_BB29_side_V,Telescope->BB29_side_VStrip[120]);
    
    Histo->BB29_FFside_DT_H1->Fill(Telescope->DT_BB29_side_H,Telescope->BB29_side_HStrip[1]);
    Histo->BB29_FFside_DT_H2->Fill(Telescope->DT_BB29_side_H,Telescope->BB29_side_HStrip[2]);
    Histo->BB29_FFside_DT_H20->Fill(Telescope->DT_BB29_side_H,Telescope->BB29_side_HStrip[20]);
    Histo->BB29_FFside_DT_H21->Fill(Telescope->DT_BB29_side_H,Telescope->BB29_side_HStrip[21]);
    Histo->BB29_FFside_DT_H39->Fill(Telescope->DT_BB29_side_H,Telescope->BB29_side_HStrip[39]);
    Histo->BB29_FFside_DT_H40->Fill(Telescope->DT_BB29_side_H,Telescope->BB29_side_HStrip[40]);
    
    Histo->DTtel_ADCFFtop_V1->Fill(Telescope->DT_telescope,Telescope->BB36_top_VStrip[1]);
    Histo->DTtel_ADCFFtop_V8->Fill(Telescope->DT_telescope,Telescope->BB36_top_VStrip[8]);
    Histo->DTtel_ADCFFbot_V1->Fill(Telescope->DT_telescope,Telescope->BB36_bot_VStrip[1]);
    Histo->DTtel_ADCFFbot_V8->Fill(Telescope->DT_telescope,Telescope->BB36_bot_VStrip[8]);
    Histo->DTtel_ADCFFside_V1->Fill(Telescope->DT_telescope,Telescope->BB29_side_VStrip[1]);
    Histo->DTtel_ADCFFside_V60->Fill(Telescope->DT_telescope,Telescope->BB29_side_VStrip[60]);
    Histo->DTtel_ADCFFside_H1->Fill(Telescope->DT_telescope,Telescope->BB29_side_HStrip[1]);
    Histo->DTtel_ADCFFside_H20->Fill(Telescope->DT_telescope,Telescope->BB29_side_HStrip[20]);  
  
    // Histograms for HR tests in May
    Histo->BB29_HR_DT_V1->Fill(Telescope->DT_BB29_V,Telescope->BB29_VStrip[1]);
    Histo->BB29_HR_DT_V2->Fill(Telescope->DT_BB29_V,Telescope->BB29_VStrip[2]);
    Histo->BB29_HR_DT_V60->Fill(Telescope->DT_BB29_V,Telescope->BB29_VStrip[60]);
    Histo->BB29_HR_DT_V61->Fill(Telescope->DT_BB29_V,Telescope->BB29_VStrip[61]);
    Histo->BB29_HR_DT_V119->Fill(Telescope->DT_BB29_V,Telescope->BB29_VStrip[119]);
    Histo->BB29_HR_DT_V120->Fill(Telescope->DT_BB29_V,Telescope->BB29_VStrip[120]);
    
    Histo->BB29_HR_DT_H1->Fill(Telescope->DT_BB29_H,Telescope->BB29_HStrip[1]);
    Histo->BB29_HR_DT_H2->Fill(Telescope->DT_BB29_H,Telescope->BB29_HStrip[2]);
    Histo->BB29_HR_DT_H20->Fill(Telescope->DT_BB29_H,Telescope->BB29_HStrip[20]);
    Histo->BB29_HR_DT_H21->Fill(Telescope->DT_BB29_H,Telescope->BB29_HStrip[21]);
    Histo->BB29_HR_DT_H39->Fill(Telescope->DT_BB29_H,Telescope->BB29_HStrip[39]);
    Histo->BB29_HR_DT_H40->Fill(Telescope->DT_BB29_H,Telescope->BB29_HStrip[40]);
    
    Histo->BB29_HR_V1_V2->Fill(Telescope->BB29_VStrip[1],Telescope->BB29_VStrip[2]);
    Histo->BB29_HR_V2_V3->Fill(Telescope->BB29_VStrip[2],Telescope->BB29_VStrip[3]);
    Histo->BB29_HR_V60_V61->Fill(Telescope->BB29_VStrip[60],Telescope->BB29_VStrip[61]);
    Histo->BB29_HR_V61_V62->Fill(Telescope->BB29_VStrip[61],Telescope->BB29_VStrip[62]);
    Histo->BB29_HR_V118_V119->Fill(Telescope->BB29_VStrip[118],Telescope->BB29_VStrip[119]);
    Histo->BB29_HR_V119_V120->Fill(Telescope->BB29_VStrip[119],Telescope->BB29_VStrip[120]);
    

    Histo->DTtel_ADCHR_V1->Fill(Telescope->DT_BB29_V,Telescope->BB8_VStrip[1]);
    Histo->DTtel_ADCHR_V60->Fill(Telescope->DT_BB29_V,Telescope->BB8_VStrip[8]);
    Histo->DTtel_ADCHR_H1->Fill(Telescope->DT_BB29_V,Telescope->BB8_HStrip[1]);
    Histo->DTtel_ADCHR_H20->Fill(Telescope->DT_BB29_V,Telescope->BB8_HStrip[8]);  
  

    //Multiplicity BB8
    if(S_E_id_V>0) Histo->h_Mult_BB8_V->Fill(S_E_id_V);
    if(S_E_id_H>0) Histo->h_Mult_BB8_H->Fill(S_E_id_H);
    
  
  

  //Histo->h_Map_BB29->Fill(strip_BB29_V,strip_BB29_H);
  
  //BB29 Conditioned Mapping
  // if(fPolyCon1->Test(DSSSD_E_V,Total_E))        Histo->h_cond_Map_BB29->Fill(strip_BB29_V,strip_BB29_H); 
  
  
    //Multiplicity BB29
    if(S_E_id_V_HR>0) Histo->h_Mult_BB29_V->Fill(S_E_id_V_HR);
    if(S_E_id_H_HR>0) Histo->h_Mult_BB29_H->Fill(S_E_id_H_HR);
    

}



void TNectarMonitoringProc:: Online_Analysis_Target_off(TNectarDetectors* Telescope){

  Int_t nV=0, nH=0;
  Int_t DT_m = Telescope->DT_telescope + fPar->DT_min;
  Int_t DT_M = Telescope->DT_telescope + fPar->DT_max;  
  Int_t DT = Telescope->DT_BB29_V;
 
  
  for(Int_t i=1; i<17; i++){
    if(Telescope->BB8_VStrip[i]>fPar->BB8_V_threshold)
      {
	nV=i;
	for(Int_t a=1; a<17; a++){
	  if(Telescope->BB8_HStrip[i]>fPar->BB8_H_threshold)
	    {
	      nH=a;
	      Histo->h_BB8_Map_TO->Fill(nV,-nH);
	    }
	}
      }
  }

  for(Int_t a=0;a<=128;a++){
    if(Telescope->BB29_VStrip[a]>fPar->BB29_V_threshold){
      for(Int_t b=0;b<=64;b++){
	if(Telescope->BB29_HStrip[b]>fPar->BB29_H_threshold)
	  { 
	    Histo->h_Map_BB29_TO->Fill(a,-b);
	    if((DT>DT_m)&&(DT<DT_M)){
	      Histo->h_cond_Map_BB29_DT_TO->Fill(a,-b);  
	    }
	  }
      }
      //BB29 Conditioned Mapping
    }
  }
}


//***********************************************************
//* Calibration function V strips BB8 *//
Double_t TNectarMonitoringProc:: Calib_BB8_V(Double_t ADC, Int_t nV)
{
    Double_t Energy_V=0;
    // Camille 2024 calibration
    Double_t m_calib_V[16]={2.768,2.746,2.718,2.755,2.746,2.737,2.736,2.692,
                            2.750,2.743,2.682,2.724,2.776,2.705,2.735,2.706}; // coeff
    Double_t q_calib_V[16]={188.868,125.690,186.557,199.707,147.290,122.399,190.961,145.179,
                            190.115,188.129,118.185,143.286,201.079,118.474,186.224,132.924}; // offset
    
    /*
    // Michele 2022 calibration
    Double_t m_calib_V[16]={4.12604,4.06538,4.15413,4.12212,4.06069,3.92988,3.9986,4.02184,4.10397,4.06809,3.98872,3.97404,4.02592,4.09213,4.06796,4.16795};
    Double_t q_calib_V[16]={454.266,318.196,474.151,475.37,406.817,300.797,454.835,424.663,458.116,463.144,315.981,418.269,466.007,319.59,478.288,427.156};*/
  
    Energy_V = m_calib_V[nV-1] * ADC - q_calib_V[nV-1];
    
    return Energy_V;
}

//***********************************************************
//* Calibration function H strips BB8 *//
Double_t TNectarMonitoringProc:: Calib_BB8_H(Double_t ADC, Int_t nH)
{
    Double_t Energy_H=0;
    // Camille 2024 calibration
    Double_t m_calib_H[16]={2.652,2.590,2.630,2.642,2.596,2.649,2.613,2.606,
                            2.545,2.642,2.602,2.635,2.668,2.570,2.589,2.609};
    Double_t q_calib_H[16]={103.564,118.919,118.195,174.878,135.279,178.097,175.311,119.015,
                            137.991,181.942,133.646,186.071,186.762,109.678,177.969,170.842};
    
    /*
    // Michele 2022 calibration
    Double_t m_calib_H[16]={3.92803,3.737,3.73528,3.94152,3.76983,3.94507,3.82148,3.80815,3.79017,3.91643,3.80309,3.75779,3.97353,3.91514,3.79044,3.90423};
    Double_t q_calib_H[16]={294.683,381.02,292.063,437.912,379.667,436.76,438.463,292.005,383.706,456.686,373.67,430.678,430.87,322.961,396.87,410.609};
    */

    Energy_H = m_calib_H[nH-1] * ADC - q_calib_H[nH-1];
    
    return Energy_H;
}

//***********************************************************
//* Calibration function MSX04s *//
Double_t TNectarMonitoringProc:: Calib_MSX04(Double_t ADC, Int_t N_MSX04)
{

    Double_t Energy=0;
    
    // Camille 2024 calibration
    Double_t m_calib[6]={6.834,7.073,6.925,7.265,6.928,7.211}; // coeff
    Double_t q_calib[6]={422.355, 620.76, 352.192, 597.304, 432.349, 642.772}; // offset
    
    // Old 2022 calibration
    /*
    Double_t m_calib[11]={0,4.23,4.21,0,0,0,0,4.324,4.457,4.334,4.347}; //Camille Calib
    Double_t q_calib[11]={0,326.089,402.757,0,0,0,0,324.731,483.684,332.537,417.8}; //Camille Calib
    */
    Energy = m_calib[N_MSX04-1] * ADC - q_calib[N_MSX04];
    
    return Energy;
}

//***********************************************************
//* Excitation energy calculation for (d,p) reaction *//
void TNectarMonitoringProc:: Ex_Calculation(Int_t n_V, Int_t n_H, TNectarDetectors* Telescope, Double_t Total_E){
  
  Double_t a=0,b=0,c=0, Ex=0, z=96, x1=0,y1=0,z1=0, r1=0, Total_Energy=0, H_Theta=0;
  Double_t tfix = (fPar->tfix*TMath::Pi())/180; 
  Total_Energy = Total_E/1000 + SW_Correction->Eval((Telescope->BB8_V_Energy[n_V])/1000)+Telescope->BB8_V_Energy[n_V]/1000;
  
  //Theta angle calculation
  
  x1 = z*TMath::Sin(tfix)+(fPar->A_Pos[n_V]+fPar->Beam_shift)*TMath::Cos(tfix);
  y1 = fPar->A_Pos[17-n_H];
  z1 = z*TMath::Cos(tfix)-(fPar->A_Pos[n_V]+fPar->Beam_shift)*TMath::Sin(tfix);
  r1 = TMath::Sqrt(TMath::Power(x1,2)+TMath::Power(y1,2));
  H_Theta = TMath::ATan(r1/z1); 
 
  //Excitation Energy Equation 
  
  a = TMath::Power((fPar->E_Pb + fPar->M_Pb)-(Total_Energy+fPar->M_H)+fPar->M_H,2);
  b = TMath::Power(fPar->E_Pb, 2)+2*fPar->E_Pb*fPar->M_Pb;
  c = TMath::Power(Total_Energy,2)+2*Total_Energy*fPar->M_H; 
  Ex = TMath::Sqrt(a-b-c+2*TMath::Sqrt(b)*TMath::Sqrt(c)*TMath::Cos(H_Theta))-fPar->M_Pb;
  
  Histo->h_Ex->Fill(Ex);
  Histo->h_Kinematics_plot->Fill(H_Theta*180/TMath::Pi(),Total_Energy*1000);
  
}



//***********************************************************
//* Fill monitoring ADC values with raw events for each hit *//
void TNectarMonitoringProc:: Update_Histograms_Target_on(TNectarDetectors* Telescope)
{

    //  ---    * BB8 *  ---   //
    // ------------------------
    Int_t Adc=0;
    
    //Fill the vertical Strips Histograms::  BB8
    for(Int_t i=0; i<16; i++){
        Adc=Telescope->BB8_VStrip[i+1];
        if(Adc>0) Histo->BB8_V_S[i]->Fill(Adc);             // ADC strips 
        if(Adc>0) Histo->BB8_ADC_V_strip->Fill(i+1,Adc);    // control histogram V
    }
    //Fill the horizontal Strips Histograms:: BB8
    for(Int_t i=0; i<16; i++){
        Adc=Telescope->BB8_HStrip[i+1]; 
        if(Adc>0) Histo->BB8_H_S[i]->Fill(Adc);             // ADC strips
        if(Adc>0) Histo->BB8_ADC_H_strip->Fill(i+1,Adc);    // control histogram H
    }   

    //  ---    * MSX04 *  ---   //
    // --------------------------
    // Fill the ADC_histogram:  MSX04 Detectors
    // MSX04_1 & 2
    if(Telescope->ADC_MSX04_1>0) Histo->h_ADC_MSX04_1->Fill(Telescope->ADC_MSX04_1);
    if(Telescope->ADC_MSX04_1>0) Histo->MSXO4->Fill(1,Telescope->ADC_MSX04_1);

    if(Telescope->ADC_MSX04_2>0) Histo->h_ADC_MSX04_2->Fill(Telescope->ADC_MSX04_2);
    if(Telescope->ADC_MSX04_2>0) Histo->MSXO4->Fill(2,Telescope->ADC_MSX04_2);
    // MSX04_3 & 4
    if(Telescope->ADC_MSX04_3>0) Histo->h_ADC_MSX04_3->Fill(Telescope->ADC_MSX04_3);
    if(Telescope->ADC_MSX04_3>0) Histo->MSXO4->Fill(3,Telescope->ADC_MSX04_3);

    if(Telescope->ADC_MSX04_4>0) Histo->h_ADC_MSX04_4->Fill(Telescope->ADC_MSX04_4);
    if(Telescope->ADC_MSX04_4>0) Histo->MSXO4->Fill(4,Telescope->ADC_MSX04_4);
    // MSX04_5 & 6
    if(Telescope->ADC_MSX04_5>0) Histo->h_ADC_MSX04_5->Fill(Telescope->ADC_MSX04_5);
    if(Telescope->ADC_MSX04_5>0) Histo->MSXO4->Fill(5,Telescope->ADC_MSX04_5);
    
    if(Telescope->ADC_MSX04_6>0) Histo->h_ADC_MSX04_6->Fill(Telescope->ADC_MSX04_6);
    if(Telescope->ADC_MSX04_6>0) Histo->MSXO4->Fill(6,Telescope->ADC_MSX04_6);
  
    // Delta time histograms telescope 
    if(Telescope->DT_telescope>0) Histo->h_DT_telescope->Fill(Telescope->DT_telescope);
  
    //  ---    * FF top *  ---   //
    // --------------------------
    
    //Fill the vertical Strips Histograms
    for(Int_t i=0; i<16; i++){
        Adc=Telescope->BB36_top_VStrip[i+1];
        if(Adc>0) Histo->BB36_FFtop_V_S[i]->Fill(Adc);          // ADC strips
        if(Adc>0) Histo->BB36_FFtop_ADC_V_STRIP->Fill(i+1,Adc); // control histogram V

    }
    //Fill the horizontal Strips Histograms
    for(Int_t i=0; i<16; i++){
        Adc=Telescope->BB36_top_HStrip[i+1]; 
        if(Adc>0) Histo->BB36_FFtop_H_S[i]->Fill(Adc);          // ADC strips
        if(Adc>0) Histo->BB36_FFtop_ADC_H_STRIP->Fill(i+1,Adc); // control histogram H
    } 
    
    // Delta time histograms FF top 
    //if(Telescope->DT_BB36_top>0) Histo->h_DT_BB36_top->Fill(Telescope->DT_BB36_top);
    
    //  ---    * FF bot *  ---   //
    // --------------------------
    
    //Fill the vertical Strips Histograms
    for(Int_t i=0; i<16; i++){
        Adc=Telescope->BB36_bot_VStrip[i+1];
        if(Adc>0) Histo->BB36_FFbot_V_S[i]->Fill(Adc);          // ADC strips
        if(Adc>0) Histo->BB36_FFbot_ADC_V_STRIP->Fill(i+1,Adc); // control histogram V
    }
    //Fill the horizontal Strips Histograms
    for(Int_t i=0; i<16; i++){
        Adc=Telescope->BB36_bot_HStrip[i+1]; 
        if(Adc>0) Histo->BB36_FFbot_H_S[i]->Fill(Adc);          // ADC strips
        if(Adc>0) Histo->BB36_FFbot_ADC_H_STRIP->Fill(i+1,Adc); // control histogram H
    }
    
    //  ---    * FF side *  ---   //
    // --------------------------
    
    //Fill the vertical Strips Histograms::  B29
    for(Int_t i=0; i<128; i++){
        Adc=Telescope->BB29_side_VStrip[i+1];
        if(Adc>0) Histo->BB29_FFside_V_S[i]->Fill(Adc);
        if(Adc>0) Histo->BB29_FFside_ADC_V_STRIP->Fill(i+1,Adc);
    }
    //Fill the horizontal Strips Histograms:: B29
    for(Int_t i=0; i<64; i++){
        Adc=Telescope->BB29_side_HStrip[i+1]; 
        if(Adc>0) Histo->BB29_FFside_H_S[i]->Fill(Adc);
        if(Adc>0) Histo->BB29_FFside_ADC_H_STRIP->Fill(i+1,Adc);
    }  
    //Delta time histograms
    
    if(Telescope->DT_BB29_V>0) Histo->h_DT_BB29_V->Fill(Telescope->DT_BB29_V);
    if(Telescope->DT_BB29_H>0) Histo->h_DT_BB29_H->Fill(Telescope->DT_BB29_H);
    
    
    //  ---    * HEAVY RESIDUE *  ---   //
    // ----------------------------------
  
    Adc=0;
    // Fill the vertical Strips Histograms::  B29
    for(Int_t i=0; i<128; i++){
        Adc=Telescope->BB29_VStrip[i+1];
        if(Adc>0) Histo->BB29_V_S[i]->Fill(Adc);
        if(Adc>0) Histo->BB29_HR_ADC_V_STRIP->Fill(i+1,Adc);
    }
    // Fill the horizontal Strips Histograms:: B29
    for(Int_t i=0; i<64; i++){
        Adc=Telescope->BB29_HStrip[i+1]; 
        if(Adc>0) Histo->BB29_H_S[i]->Fill(Adc);
        if(Adc>0) Histo->BB29_HR_ADC_H_STRIP->Fill(i+1,Adc);
    }    
}


void TNectarMonitoringProc:: Update_Histograms_Target_off(TNectarDetectors* Telescope)
{
  
  //Int_t Adc=0;
  //Fill the vertical Strips Histograms::  BB8
  for(Int_t i=0; i<16; i++){
    if(Telescope->BB8_HStrip[i+1]>0)  Histo->BB8_ADC_V_strip_TO->Fill(i+1,Telescope->BB8_VStrip[i+1]);
  }
  //Fill the horizontal Strips Histograms:: BB8
  for(Int_t i=0; i<16; i++){
    if(Telescope->BB8_HStrip[i+1]>0)  Histo->BB8_ADC_H_strip->Fill(i+1,Telescope->BB8_HStrip[i+1]); 
  }    
  //Fill the ADC_histogram:  MSX04 Detectors
  // MSX04_1 & 2
  if(Telescope->ADC_MSX04_1>0) Histo->MSXO4_TO->Fill(1,Telescope->ADC_MSX04_1);
  if(Telescope->ADC_MSX04_2>0) Histo->MSXO4_TO->Fill(2,Telescope->ADC_MSX04_2);
  // MSX04_7 & 8
  if(Telescope->ADC_MSX04_3>0) Histo->MSXO4_TO->Fill(3,Telescope->ADC_MSX04_3);
  if(Telescope->ADC_MSX04_4>0) Histo->MSXO4_TO->Fill(4,Telescope->ADC_MSX04_4);
  // MSX04_9 & 10
  if(Telescope->ADC_MSX04_5>0) Histo->MSXO4_TO->Fill(5,Telescope->ADC_MSX04_5);
  if(Telescope->ADC_MSX04_6>0) Histo->MSXO4_TO->Fill(6,Telescope->ADC_MSX04_6);

  
   //Delta time histograms

  if(Telescope->DT_telescope>0) Histo->h_DT_telescope_TO->Fill(Telescope->DT_telescope);

  //*******************
  //Histograms BB29 
  //*******************
  
  //Adc=0;
  //Fill the vertical Strips Histograms::  B29
  for(Int_t i=0; i<128; i++){
    if(Telescope->BB29_VStrip[i+1]>0)  Histo->BB29_ADC_V_strip_TO->Fill(i+1,Telescope->BB29_VStrip[i+1]);
  }
  //Fill the horizontal Strips Histograms:: B29
  for(Int_t i=0; i<64; i++){
    if(Telescope->BB29_HStrip[i+1]>0)  Histo->BB29_ADC_H_strip_TO->Fill(i+1,Telescope->BB29_HStrip[i+1]);
  }    
   //Delta time histograms

  if(Telescope->DT_BB29_V>0) Histo->h_DT_BB29_V_TO->Fill(Telescope->DT_BB29_V);
  if(Telescope->DT_BB29_H>0) Histo->h_DT_BB29_H_TO->Fill(Telescope->DT_BB29_H);

}



