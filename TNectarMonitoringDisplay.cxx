#include "TNectarMonitoringDisplay.h"

#include "Riostream.h"
#include "TString.h"
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

#include "TNectarRawEvent.h"
#include "TNectarRawParam.h"
#include "TNectarDisplay.h"
#include "TNectarRawProc.h"
#include "TNectarProfileEvent.h"
#include "TNectarMonitoringProc.h"



#include "TGo4Fitter.h"
#include "TGo4FitDataHistogram.h"
#include "TGo4FitParameter.h"
#include "TGo4FitModelPolynom.h"

#include "TGo4UserException.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

//***********************************************************

void TNectarHistograms::InitHistograms(Bool_t replace)
{
   if (replace)
      SetMakeWithAutosave(kFALSE);

 TGo4Log::Info("Monitoring: Initializing histograms");
  // Creation of histograms (or take them from autosave)
     TString obname;
     TString obtitle;
     TString foldername;
     
    //***************************************************************
    //                INIT TELESCOPE HISTOGRAMS
    //***************************************************************
     
          
    //***************************************************************
    //   - BB8 Histograms -
    
    // ADC energy value for each strip
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Telescope/BB8/Adc_Strips/Adc_V_Strips/BB8_Adc_V_%d", i+1);
        obtitle.Form("BB8_Adc_V_%d", i+1);
        BB8_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "BB8 ADC energy Vstrip (ch)", "counts");
    }
   
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Telescope/BB8/Adc_Strips/Adc_H_Strips/BB8_Adc_H_%d", i+1);
        obtitle.Form("BB8_Adc_H_%d", i+1);  
        BB8_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, " BB8 ADC energy Hstrip (ch)", "counts");
    } 

    // ADC value vertical strips vs telescope delta time
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Telescope/BB8/DT/DT_vs_Vstrip/BB8_DT_E_V_%d",i+1);
        obtitle.Form("BB8_DT_E_V_%d",i+1);  
        BB8_DT_E_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"Telescope DT (ch)", "BB8 ADC energy Vstrip (ch)"); 
    }

    // ADC value vertical strips vs any horizontal strip
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Telescope/BB8/Strip_VS_Strip/Adc_V_vs_any_H/BB8_Adc_anyH_V_%d",i+1);
        obtitle.Form("BB8_Adc_anyH_V_%d",i+1);  
        BB8_1V_allH[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE, 256, 0, VMMR_ADC_RANGE,"ADC energy vertical strip (ch)", "ADC energy all horizontal strips (ch)"); 
    }

    // Energy of adjacent vertical strips
    for(int i=0;i<15;i++)
    {
        obname.Form("DETECTORS/Target_on/Telescope/BB8/Strip_VS_Strip/Adc_V_vs_adjacent_V/BB8_Adc_V_%d_V%d",i+1,i+2);
        obtitle.Form("BB8_Adc_V_%d_V%d",i+1,i+2);  
        BB8_adj_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE, 256, 0, VMMR_ADC_RANGE,"ADC energy adjacent vertical strip i (ch)", "ADC energy adjacent vertical strip i+1 (ch)"); 
    }
    
    // Energy of adjacent horizontal strips
    for(int i=0;i<15;i++)
    {
        obname.Form("DETECTORS/Target_on/Telescope/BB8/Strip_VS_Strip/Adc_H_vs_adjacent_H/BB8_Adc_H_%d_H%d",i+1,i+2);
        obtitle.Form("BB8_Adc_H_%d_H%d",i+1,i+2);  
        BB8_adj_H[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE, 256, 0, VMMR_ADC_RANGE,"ADC energy adjacent horizontal strip i (ch)", "ADC energy adjacent horizontal strip i+1 (ch)"); 
    }
    
    // ADC value vertical strip 8 vs horizontal strip 8
    obname.Form("DETECTORS/Target_on/Telescope/BB8/Strip_VS_Strip/BB8_Adc_V8_H8");
    obtitle.Form("BB8_Adc_V8_H8");  
    BB8_V8_H8= MakeTH2('I', obname.Data(), obtitle.Data(), 256/*0xF*/, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"ADC energy VSTRIP 8(ch)", "ADC energy HSTRIP 8(ch)");  
    
    // ADC value vertical strip 8 vs horizontal strip 8 multiplicity 1
    obname.Form("DETECTORS/Target_on/Telescope/BB8/Strip_VS_Strip/BB8_Adc_V8_H8_1multiplicity");
    obtitle.Form("BB8_Adc_V8_H8_mult1");  
    BB8_V8_H8_mult1= MakeTH2('I', obname.Data(), obtitle.Data(), 256/*0xF*/, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"ADC energy VSTRIP 8(ch)", "ADC energy HSTRIP 8(ch)");  
    
    //***************************************************************
    //  - MSXO4s  Histograms -
     
    // ADC energy value each MSX04
    obname.Form("DETECTORS/Target_on/Telescope/MSX04/Adc_Det/Adc_E1");
    obtitle.Form("Adc_E1");
    h_ADC_MSX04_1= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy MSXO4 E1 (ch)", "counts");
      
    obname.Form("DETECTORS/Target_on/Telescope/MSX04/Adc_Det/Adc_E2");
    obtitle.Form("Adc_E2");  
    h_ADC_MSX04_2= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy MSXO4 E2 (ch)", "counts");  

    obname.Form("DETECTORS/Target_on/Telescope/MSX04/Adc_Det/Adc_E3");
    obtitle.Form("Adc_E3");
    h_ADC_MSX04_3= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy MSXO4 E3 (ch)", "counts");
     
    obname.Form("DETECTORS/Target_on/Telescope/MSX04/Adc_Det/Adc_E4");
    obtitle.Form("Adc_E4");  
    h_ADC_MSX04_4= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy MSXO4 E4 (ch)", "counts");  
     
    obname.Form("DETECTORS/Target_on/Telescope/MSX04/Adc_Det/Adc_E5");
    obtitle.Form("Adc_E5");
    h_ADC_MSX04_5= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy MSXO4 E5 (ch)", "counts");
     
    obname.Form("DETECTORS/Target_on/Telescope/MSX04/Adc_Det/Adc_E6");
    obtitle.Form("Adc_E6");  
    h_ADC_MSX04_6= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy MSXO4 E6 (ch)", "counts");  
  
    //***************************************************************
    // - DeltaE/E plots -
    // Attention here you need to define the final range!!!! It cannot be VMMR_ADC_RANGE!!!!
    // previous value from Michele : MakeTH2('I', obname.Data(), obtitle.Data(), 28672/32, 0, 28672, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,
    
    // Total DE-E in channels each strip 
    for(Int_t i=0; i<16 ; i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-Etot ch/h_DE_Etot_ch_%d",i+1);
        obtitle.Form("h_DE_Etot_ch_%d",i);     
        h_DE_E_tot_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 24576,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E stack (ch)", "DeltaE Energy (ch)");
    }

    // Total DE-E in keV each strip 
    for(Int_t i=0; i<16 ; i++){
       obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-Etot keV/h_DE_Etot_keV_%d",i+1);
       obtitle.Form("h_DE_Etot_keV_%d",i);     
       h_DE_E_tot_kev_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(),256,0,50000,256,0,10000,"Energy Deposited in E stack (keV)", "DeltaE Energy (keV)");
    }

    // Total DE-Ex channels each strip 
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E1 ch/h_DE_E1_ch_Strip_%d", i+1);
        obtitle.Form("h_DE_E1_ch_Strip_%d",i);     
        h_DE_E_1_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E1 (ch)", "DeltaE Energy (ch)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E2 ch/h_DE_E2_ch_Strip_%d", i+1);
        obtitle.Form("h_DE_E2_ch_Strip_%d",i);     
        h_DE_E_2_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E2 (ch)", "DeltaE Energy (ch)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E3 ch/h_DE_E3_ch_Strip_%d", i+1);
        obtitle.Form("h_DE_E3_ch_Strip_%d",i);     
        h_DE_E_3_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E3 (ch)", "DeltaE Energy (ch)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E4 ch/h_DE_E4_ch_Strip_%d", i+1);
        obtitle.Form("h_DE_E4_ch_Strip_%d",i);     
        h_DE_E_4_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E4 (ch)", "DeltaE Energy (ch)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E5 ch/h_DE_E5_ch_Strip_%d", i+1);
        obtitle.Form("h_DE_E5_ch_Strip_%d",i);     
        h_DE_E_5_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E5 (ch)", "DeltaE Energy (ch)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E6 ch/h_DE_E6_ch_Strip_%d", i+1);
        obtitle.Form("h_DE_E6_ch_Strip_%d",i);     
        h_DE_E_6_ch_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E6 (ch)", "DeltaE Energy (ch)");     
    } 
    
    // Total DE-Ex in keV each strip 
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E1_keV/h_DE_E1_keV_Strip_%d", i+1);
        obtitle.Form("h_DE_E1_keV_Strip_%d",i);     
        h_DE_E_1_keV_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E1 (keV)", "DeltaE Energy (keV)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E2_keV/h_DE_E2_keV_Strip_%d", i+1);
        obtitle.Form("h_DE_E2_keV_Strip_%d",i);     
        h_DE_E_2_keV_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E2 (keV)", "DeltaE Energy (keV)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E3_keV/h_DE_E3_keV_Strip_%d", i+1);
        obtitle.Form("h_DE_E3_keV_Strip_%d",i);     
        h_DE_E_3_keV_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E3 (keV)", "DeltaE Energy (keV)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E4_keV/h_DE_E4_keV_Strip_%d", i+1);
        obtitle.Form("h_DE_E4_keV_Strip_%d",i);     
        h_DE_E_4_keV_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E4 (keV)", "DeltaE Energy (keV)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E5_keV/h_DE_E5_keV_Strip_%d", i+1);
        obtitle.Form("h_DE_E5_keV_Strip_%d",i);     
        h_DE_E_5_keV_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E5 (keV)", "DeltaE Energy (keV)");     
    }
    for(Int_t i=0;i<16;i++){
        obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/Strip_by_strip/DE-E6_keV/h_DE_E6_keV_Strip_%d", i+1);
        obtitle.Form("h_DE_E6_keV_Strip_%d",i);     
        h_DE_E_6_keV_strip[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, VMMR_ADC_RANGE,  256, 0, VMMR_ADC_RANGE,"Energy Deposited in E6 (keV)", "DeltaE Energy (keV)");     
    } 
    
    // Total DE-E in channels all strips
    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E_tot_ch");
    obtitle.Form("h_DE_E_tot_ch");     
    h_DE_E_tot_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 512 , 0, 24576, 512, 0, VMMR_ADC_RANGE,"Energy Deposited in E stack (ch)", "DeltaE Energy (ch)");    
    
    // Total DE-E in keV all strips
    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E_tot_keV");
    obtitle.Form("h_DE_E_tot_keV");     
    h_DE_E_tot_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 512, 0, 50000, 512, 0, 10000,"Energy Deposited in E stack (keV)", "DeltaE Energy (keV)");
    
    // DE-Ei in ch all strips     
    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E1_ch");
    obtitle.Form("h_DE_E1_ch");     
    h_DE_E_1_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 4096, 256, 0, 4096,"Energy Deposited in E1 (ch)", "DeltaE Energy (ch)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E2_ch");
    obtitle.Form("h_DE_E2_ch");     
    h_DE_E_2_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 4096, 256, 0, 4096,"Energy Deposited in E2 (ch)", "DeltaE Energy (ch)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E3_ch");
    obtitle.Form("h_DE_E3_ch");     
    h_DE_E_3_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 4096, 256, 0, 4096,"Energy Deposited in E3 (ch)", "DeltaE Energy (ch)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E4_ch");
    obtitle.Form("h_DE_E4_ch");     
    h_DE_E_4_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 4096, 256, 0, 4096,"Energy Deposited in E4 (ch)", "DeltaE Energy (ch)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E5_ch");
    obtitle.Form("h_DE_E5_ch");     
    h_DE_E_5_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 4096, 256, 0, 4096,"Energy Deposited in E5 (ch", "DeltaE Energy (ch)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E6_ch");
    obtitle.Form("h_DE_E6_ch");     
    h_DE_E_6_ch= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 4096, 256, 0, 4096,"Energy Deposited in E6 (ch)", "DeltaE Energy (ch)");
    
    // DE-Ei in keV all strips     
    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E1_keV");
    obtitle.Form("h_DE_E1_keV");     
    h_DE_E_1_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 10000,"Energy Deposited in E1 (keV)", "DeltaE Energy (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E2_keV");
    obtitle.Form("h_DE_E2_keV");     
    h_DE_E_2_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 10000,"Energy Deposited in E2 (keV)", "DeltaE Energy (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E3_keV");
    obtitle.Form("h_DE_E3_keV");     
    h_DE_E_3_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 10000,"Energy Deposited in E3 (keV)", "DeltaE Energy (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E4_keV");
    obtitle.Form("h_DE_E4_keV");     
    h_DE_E_4_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 10000,"Energy Deposited in E4 (keV)", "DeltaE Energy (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E5_keV");
    obtitle.Form("h_DE_E5_keV");     
    h_DE_E_5_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 10000,"Energy Deposited in E5 (keV)", "DeltaE Energy (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/DeltaE_E_plots/h_DE_E6_keV");
    obtitle.Form("h_DE_E6_keV");     
    h_DE_E_6_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 10000,"Energy Deposited in E6 (keV)", "DeltaE Energy (keV)");

    //***************************************************************
    //  - Ei vs Ej in keV all strips -
    
    obname.Form("DETECTORS/Target_on/Telescope/Ei_Ej_plots/h_E1_E2_keV");
    obtitle.Form("h_E1_E2_keV");     
    h_E1_E2_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 25000,"Energy Deposited in E2 (keV)", "Energy Deposited in E1 (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/Ei_Ej_plots/h_E2_E3_keV");
    obtitle.Form("h_E2_E3_keV");     
    h_E2_E3_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 25000,"Energy Deposited in E3 (keV)", "Energy Deposited in E2 (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/Ei_Ej_plots/h_E3_E4_keV");
    obtitle.Form("h_E3_E4_keV");     
    h_E3_E4_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 25000,"Energy Deposited in E4 (keV)", "Energy Deposited in E3 (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/Ei_Ej_plots/h_E4_E5_keV");
    obtitle.Form("h_E4_E5_keV");     
    h_E4_E5_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 25000,"Energy Deposited in E5 (keV)", "Energy Deposited in E4 (keV)");

    obname.Form("DETECTORS/Target_on/Telescope/Ei_Ej_plots/h_E5_E6_keV");
    obtitle.Form("h_E5_E6_keV");     
    h_E5_E6_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 256, 0, 25000, 256, 0, 25000,"Energy Deposited in E6 (keV)", "Energy Deposited in E5 (keV)");

    //***************************************************************
    //  - TCuT conditionned spectra -

    // DeltaE-Etot conditionned with deuterons or proton cuts
    obname.Form("DETECTORS/Target_on/Telescope/Singles/h_DE_E_tot_keV_cond_p");
    obtitle.Form("h_DE_E_tot_keV_cond_p");     
    h_DE_E_tot_keV_cond_p= MakeTH2('I', obname.Data(), obtitle.Data(), 512, 0, 50000, 512, 0, 10000,"Energy Deposited (keV)", "DeltaE Energy (keV)");
    
    obname.Form("DETECTORS/Target_on/Telescope/Singles/h_DE_E_tot_keV_cond_d");
    obtitle.Form("h_DE_E_tot_keV_cond_d");     
    h_DE_E_tot_keV_cond_d= MakeTH2('I', obname.Data(), obtitle.Data(), 512, 0, 50000, 512, 0, 10000,"Energy Deposited (keV)", "DeltaE Energy (keV)");
    
    // Singles energy strip 3 conditionned proton event
    obname.Form("DETECTORS/Target_on/Telescope/Singles/h_Eproton_VS3_ch");
    obtitle.Form("h_Eproton_VS3_ch");     
    h_Eproton_VS3_ch= MakeTH1('I', obname.Data(), obtitle.Data(), 512, 0, VMMR_ADC_RANGE, "Proton kin energy VStrip 3 (ch)", "counts");
    
    obname.Form("DETECTORS/Target_on/Telescope/Singles/h_Eproton_VS3_keV");
    obtitle.Form("h_Eproton_VS3_keV");     
    h_Eproton_VS3_keV= MakeTH1('I', obname.Data(), obtitle.Data(), 512, 0, 50000, "Proton kin energy VStrip 3 (keV)", "counts");
    
    // Singles energy strip 3 conditionned deuteron event
    obname.Form("DETECTORS/Target_on/Telescope/Singles/h_Edeuteron_VS3_ch");
    obtitle.Form("h_Edeuteron_VS3_ch");     
    h_Edeuteron_VS3_ch= MakeTH1('I', obname.Data(), obtitle.Data(), 512, 0, VMMR_ADC_RANGE, "Deuteron kin energy VStrip 3 (ch)", "counts");
    
    obname.Form("DETECTORS/Target_on/Telescope/Singles/h_Edeuteron_VS3_keV");
    obtitle.Form("h_Edeuteron_VS3_keV");     
    h_Edeuteron_VS3_keV= MakeTH1('I', obname.Data(), obtitle.Data(), 512, 0, 50000, "Deuteron kin energy VStrip 3 (keV)", "counts");

    //***************************************************************
    //  - Control  Histograms -
    
    obname.Form("DETECTORS/Target_on/Telescope/Control/BB8_Adc_Vstrip_control");
    obtitle.Form("BB8_Adc_Vstrip_control");     
    BB8_ADC_V_strip= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"BB8_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("DETECTORS/Target_on/Telescope/Control/BB8_Adc_Hstrip_control");
    obtitle.Form("BB8_Adc_Hstrip_control");     
    BB8_ADC_H_strip= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB8_Horizontal (n^{o})", "ADC energy (ch)");
     
    obname.Form("DETECTORS/Target_on/Telescope/Control/BB8_Mapping");
    obtitle.Form("BB8_Mapping");     
    h_BB8_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, -16.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");

    obname.Form("DETECTORS/Target_on/Telescope/Control/MSXO4_Adc_control");
    obtitle.Form("MSXO4_Adc_control");     
    MSXO4= MakeTH2('I', obname.Data(), obtitle.Data(), 6, 0.5, 6.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"MSXO4 E (n^{o})", "ADC energy (ch)");
     
    //***************************************************************
    //              INIT FISSION HISTOGRAMS
    //***************************************************************
    
    //***************************************************************
    //   - FF top Histograms - 
    
    // ADC energy value each V strip
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Fission/FF_top/ADC_Strips/ADC_FFtop_V_%d", i+1);
        obtitle.Form("ADC_FFtop_V_%d", i+1);
        BB36_FFtop_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "FFtop kinetic energy (ch)", "counts");
    }
    // ADC energy value each H strip
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Fission/FF_top/ADC_Strips/ADC_FFtop_H_%d", i+1);
        obtitle.Form("ADC_FFtop_H_%d", i+1);  
        BB36_FFtop_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "FFtop kinetic energy (ch)", "counts");
    } 
    
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_top/DeltaT_vs_V/FFtop_DT_E_V_%d",i+1);
        obtitle.Form("FFtop_DT_E_V_%d",i+1);  
        BB36_FFtop_DT_E_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DT (ch)", "ADC energy (ch)"); 
    }
    
    //***************************************************************    
    //   - FF top Histograms -
    
    // ADC energy value each V strip
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Fission/FF_bot/ADC_Strips/ADC_FFbot_V_%d", i+1);
        obtitle.Form("ADC_FFbot_V_%d", i+1);
        BB36_FFbot_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "FFtop kinetic energy (ch)", "counts");
    } 
    // ADC energy value each H strip
    for(int i=0;i<16;i++)
    {
        obname.Form("DETECTORS/Target_on/Fission/FF_bot/ADC_Strips/ADC_FFbot_H_%d", i+1);
        obtitle.Form("ADC_FFbot_H_%d", i+1);  
        BB36_FFbot_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "FFtop kinetic energy (ch)", "counts");
    }
    
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_bot/DeltaT_vs_V/FFbot_DT_E_V_%d",i+1);
        obtitle.Form("FFbot_DT_E_V_%d",i+1);  
        BB36_FFbot_DT_E_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DT (ch)", "ADC value"); 
    }
    
    //***************************************************************    
    //   - FF side Histograms -
    
    for(int i=0;i<128;i++)
    {
        obname.Form("DETECTORS/Target_on/Fission/FF_side/ADC_Strips/ADC_FFside_V_%d", i+1);
        obtitle.Form("ADC_FFside_V_%d", i+1);
        BB29_FFside_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "FFside kinetic energy (ch)", "counts");
    } 
    for(int i=0;i<64;i++)
    {
        obname.Form("DETECTORS/Target_on/Fission/FF_side/ADC_Strips/ADC_FFside_H_%d", i+1);
        obtitle.Form("ADC_FFside_H_%d", i+1);  
        BB29_FFside_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "FFside kinetic energy (ch)", "counts");
    }
    
    //***************************************************************
    //  - Control  Histograms -
    
    // Control histograms strip FF top
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_top_ADC_V_control");
    obtitle.Form("FF_top_ADC_V_control");     
    BB36_FFtop_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 256, 0, VMMR_ADC_RANGE ,"FFtop_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_top_ADC_H_control");
    obtitle.Form("FF_top_ADC_H_control");     
    BB36_FFtop_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,256, 0, VMMR_ADC_RANGE,"FFtop_Horizontal (n^{o})", "ADC (ch)");
    
    // FF top mapping
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_top_Mapping");
    obtitle.Form("FF_top_Mapping");     
    h_FFtop_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 0.5, 16.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
    
    // Control histograms strip FF bot
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_bot_ADC_V_control");
    obtitle.Form("FF_bot_ADC_V_control");     
    BB36_FFbot_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 256, 0, VMMR_ADC_RANGE ,"FFtop_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_bot_ADC_H_control");
    obtitle.Form("FF_bot_ADC_H_control");     
    BB36_FFbot_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 256, 0, VMMR_ADC_RANGE,"FFtop_Horizontal (n^{o})", "ADC (ch)");    
    
    // FF bot mapping
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_bot_Mapping");
    obtitle.Form("FF_bot_Mapping");     
    h_FFbot_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 1, 17," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
    
    // Control histograms strip FF side
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_side_ADC_V_control");
    obtitle.Form("FF_side_ADC_V_control");     
    BB29_FFside_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, 256, 0, VMMR_ADC_RANGE ,"FFside_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_side_ADC_H_control");
    obtitle.Form("FF_side_ADC_H_control");     
    BB29_FFside_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 40, 0.5, 40.5, 256, 0, VMMR_ADC_RANGE,"FFside_Horizontal (n^{o})", "ADC (ch)");
    
    // FF side mapping
    obname.Form("DETECTORS/Target_on/Fission/Control/FF_side_Mapping");
    obtitle.Form("FF_side_Mapping");     
    h_FFside_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5,  40, -40.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");

    //***************************************************************
    //  - Fission conditionned with a proton event -
    obname.Form("DETECTORS/Target_on/Fission/Cond_proton/h_FFtop_E_y_cond_p");
    obtitle.Form("h_FFtop_E_y_cond_p");     
    h_FFtop_E_y_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 512, 0, VMMR_ADC_RANGE ,"FFtop Horizontal strip (n^{o})", "FFtop energy (ch)");
      
    obname.Form("DETECTORS/Target_on/Fission/Cond_proton/h_FFbot_E_y_cond_p");
    obtitle.Form("h_FFbot_E_y_cond_p");     
    h_FFbot_E_y_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 512, 0, VMMR_ADC_RANGE ,"FFbot Horizontal strip (n^{o})", "FFbot energy (ch)");
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_proton/h_FFside_E_x_cond_p");
    obtitle.Form("h_FFside_E_x_cond_p");     
    h_FFside_E_x_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5, 512, 0, VMMR_ADC_RANGE ,"FFside Vertical strip (n^{o})", "FFside energy (ch)"); 
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_proton/h_FFtop_map_cond_p");
    obtitle.Form("h_FFtop_map_cond_p");     
    h_FFtop_map_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 0.5, 16.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})"); 
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_proton/h_FFbot_map_cond_p");
    obtitle.Form("h_FFbot_map_cond_p");     
    h_FFbot_map_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 1, 17," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_proton/h_FFside_map_cond_p");
    obtitle.Form("h_FFside_map_cond_p");     
    h_FFside_map_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5,  40, -40.5, -0.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");
    
    
    //***************************************************************
    //  - Fission conditionned with a deuteron event -
    obname.Form("DETECTORS/Target_on/Fission/Cond_deuteron/h_FFtop_E_y_cond_d");
    obtitle.Form("h_FFtop_E_y_cond_d");     
    h_FFtop_E_y_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 512, 0, VMMR_ADC_RANGE ,"FFtop Horizontal strip (n^{o})", "FFtop energy (ch)");
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_deuteron/h_FFbot_E_y_cond_d");
    obtitle.Form("h_FFbot_E_y_cond_d");     
    h_FFbot_E_y_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 512, 0, VMMR_ADC_RANGE ,"FFbot Horizontal strip (n^{o})", "FFbot energy (ch)"); 

    obname.Form("DETECTORS/Target_on/Fission/Cond_deuteron/h_FFside_E_x_cond_d");
    obtitle.Form("h_FFside_E_x_cond_d");     
    h_FFside_E_x_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5, 512, 0, VMMR_ADC_RANGE ,"FFside Vertical strip (n^{o})", "FFside energy (ch)"); 
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_deuteron/h_FFtop_map_cond_d");
    obtitle.Form("h_FFtop_map_cond_d");     
    h_FFtop_map_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 0.5, 16.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})"); 
    
    obname.Form("DETECTORS/Target_on/Fission/Cond_deuteron/h_FFbot_map_cond_d");
    obtitle.Form("h_FFbot_map_cond_d");     
    h_FFbot_map_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 1, 17," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})"); 

    obname.Form("DETECTORS/Target_on/Fission/Cond_deuteron/h_FFside_map_cond_d");
    obtitle.Form("h_FFside_map_cond_d");     
    h_FFside_map_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5,  40, -40.5, -0.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");

    
    //***************************************************************
    //  - Autotriggers -
    obname.Form("DETECTORS/Target_on/Fission/Autotrig/h_FFtop_E_y_autotrig");
    obtitle.Form("h_FFtop_E_y_autotrig");     
    h_FFtop_E_y_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 512, 0, VMMR_ADC_RANGE ,"FFtop Horizontal strip (n^{o})", "FFtop energy (ch)");
    
    obname.Form("DETECTORS/Target_on/Fission/Autotrig/h_FFbot_E_y_autotrig");
    obtitle.Form("h_FFbot_E_y_autotrig");     
    h_FFbot_E_y_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 512, 0, VMMR_ADC_RANGE ,"FFbot Horizontal strip (n^{o})", "FFbot energy (ch)");
    
    obname.Form("DETECTORS/Target_on/Fission/Autotrig/h_FFside_E_x_autotrig");
    obtitle.Form("h_FFside_E_x_autotrig");     
    h_FFside_E_x_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(),122, 0.5, 122.5, 512, 0, VMMR_ADC_RANGE ,"FFside Horizontal strip (n^{o})", "FFside energy (ch)");
    
    obname.Form("DETECTORS/Target_on/Fission/Autotrig/h_FFtop_map_autotrig");
    obtitle.Form("h_FFtop_map_autotrig");     
    h_FFtop_map_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 0.5, 16.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");
    
    obname.Form("DETECTORS/Target_on/Fission/Autotrig/h_FFbot_map_autotrig");
    obtitle.Form("h_FFbot_map_autotrig");     
    h_FFbot_map_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, 1, 17," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})"); 
    
    obname.Form("DETECTORS/Target_on/Fission/Autotrig/h_FFside_map_autotrig");
    obtitle.Form("h_FFside_map_autotrig");     
    h_FFside_map_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(),122, 0.5, 122.5,  40, -40.5, -0.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");   

    //***************************************************************
    //              INIT HEAVY RESIDUE HISTOGRAMS
    //***************************************************************    
    
    for(int i=0;i<128;i++)
    {
        obname.Form("DETECTORS/Target_on/HR/ADC Strips/BB29_HR_ADC_V_%d", i+1);
        obtitle.Form("BB29_HR_ADC_V_%d", i+1);
        BB29_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    } 
    for(int i=0;i<64;i++)
    {
        obname.Form("DETECTORS/Target_on/HR/ADC Strips/BB29_HR_ADC_H_%d", i+1);
        obtitle.Form("BB29_HR_ADC_H_%d", i+1);  
        BB29_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    }
    
    // Control histograms strip HR
    obname.Form("DETECTORS/Target_on/HR/Control/HR_ADC_V_control");
    obtitle.Form("HR_ADC_V_control");     
    BB29_HR_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"HR_Vertical Strip (n^{o})", "ADC energy (ch)");
     
    obname.Form("DETECTORS/Target_on/HR/Control/HR_ADC_H_control");
    obtitle.Form("HR_ADC_H_control");     
    BB29_HR_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 40, 0.5, 40.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"HR_Horizontal Strip (n^{o})", "ADC energy (ch)");
    
    // HR mapping
    obname.Form("DETECTORS/Target_on/HR/Control/HR_Mapping");
    obtitle.Form("HR_Mapping");     
    h_HR_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5,  40, -40.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
    // Vertical all horizontals 
    
    //  - Fission conditionned with a proton event -
    obname.Form("DETECTORS/Target_on/HR/Cond_proton/h_HR_E_x_cond_p");
    obtitle.Form("h_HR_E_x_cond_p");     
    h_HR_E_x_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, 512, 0, VMMR_ADC_RANGE ,"FFtop Horizontal strip (n^{o})", "FFtop energy (ch)");    
    
    obname.Form("DETECTORS/Target_on/HR/Cond_proton/h_HR_map_cond_p");
    obtitle.Form("h_HR_map_cond_p");     
    h_HR_map_cond_p = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5,  40, -40.5, -0.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");     
    
    obname.Form("DETECTORS/Target_on/HR/Cond_deuteron/h_HR_E_x_cond_d");
    obtitle.Form("h_HR_E_x_cond_d");     
    h_HR_E_x_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, 512, 0, VMMR_ADC_RANGE ,"FFtop Horizontal strip (n^{o})", "FFtop energy (ch)");    
    
    obname.Form("DETECTORS/Target_on/HR/Cond_deuteron/h_HR_map_cond_d");
    obtitle.Form("h_HR_map_cond_d");     
    h_HR_map_cond_d = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5,  40, -40.5, -0.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");         
 
    obname.Form("DETECTORS/Target_on/HR/Autotrig/h_HR_E_x_autotrig");
    obtitle.Form("h_HR_E_x_autotrig");     
    h_HR_E_x_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, 512, 0, VMMR_ADC_RANGE ,"FFtop Horizontal strip (n^{o})", "FFtop energy (ch)");    
    
    obname.Form("DETECTORS/Target_on/HR/Autotrig/h_HR_map_autotrig");
    obtitle.Form("h_HR_map_autotrig");     
    h_HR_map_autotrig = MakeTH2('I', obname.Data(), obtitle.Data(), 122, 0.5, 122.5,  40, -40.5, -0.5," Vertical Strip (n^{o})", "Horizontal Strip (n^{o})");  
    
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_H/ADC_anyH_V1");
    obtitle.Form("ADC_anyH_V1");     
    BB29_FFside_V1_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip1 (ch)", "ADC value horizontal strips (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_H/ADC_anyH_V2");
    obtitle.Form("ADC_anyH_V2");     
    BB29_FFside_V2_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip2 (ch)", "ADC value horizontal strips (ch)");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_H/ADC_anyH_V60");
    obtitle.Form("ADC_anyH_V60");     
    BB29_FFside_V60_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip60 (ch)", "ADC value horizontal strips (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_H/ADC_anyH_V61");
    obtitle.Form("ADC_anyH_V61");     
    BB29_FFside_V61_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip61 (ch)", "ADC value horizontal strips (ch)");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_H/ADC_anyH_V119");
    obtitle.Form("ADC_anyH_V119");     
    BB29_FFside_V119_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip119 (ch)", "ADC value horizontal strips (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_H/ADC_anyH_V120");
    obtitle.Form("ADC_anyH_V120");     
    BB29_FFside_V120_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip120 (ch)", "ADC value horizontal strips (ch)");
         
    // Vertical vs vertical
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_adjV/FFside_V1_V2");
    obtitle.Form("FFside_V1_V2");     
    BB29_FFside_V1_V2= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip1 (ch)", "ADC value adjacent vertical strip2 (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_adjV/FFside_V2_V3");
    obtitle.Form("FFside_V2_V3");     
    BB29_FFside_V2_V3= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip2 (ch)", "ADC value adjacent vertical strip3 (ch)");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_adjV/FFside_V60_V61");
    obtitle.Form("FFside_V60_V61");     
    BB29_FFside_V60_V61= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip60 (ch)", "ADC value adjacent vertical strip61 (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_adjV/FFside_V61_V62");
    obtitle.Form("FFside_V61_V62");     
    BB29_FFside_V61_V62= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip61 (ch)", "ADC value adjacent vertical strip62 (ch)");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_adjV/FFside_V118_V119");
    obtitle.Form("FFside_V118_V119");     
    BB29_FFside_V118_V119= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip60 (ch)", "ADC value adjacent vertical strip61 (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_V_vs_adjV/FFside_V119_V120");
    obtitle.Form("FFside_V119_V120");     
    BB29_FFside_V119_V120= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip61 (ch)", "ADC value adjacent vertical strip62 (ch)");
    
    // DT vs vertical ADC
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V1");
    obtitle.Form("FFside_DT_E_V1");     
    BB29_FFside_DT_V1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V2");
    obtitle.Form("FFside_DT_E_V2");     
    BB29_FFside_DT_V2= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V60");
    obtitle.Form("FFside_DT_E_V60");     
    BB29_FFside_DT_V60= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V61");
    obtitle.Form("FFside_DT_E_V61");     
    BB29_FFside_DT_V61= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V119");
    obtitle.Form("FFside_DT_E_V119");     
    BB29_FFside_DT_V119= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V119");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V120");
    obtitle.Form("FFside_DT_E_V120");     
    BB29_FFside_DT_V120= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V120");
    
    // DT vs horizontal ADC
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H1");
    obtitle.Form("FFside_DT_E_H1");     
    BB29_FFside_DT_H1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H2");
    obtitle.Form("FFside_DT_E_H2");     
    BB29_FFside_DT_H2= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H20");
    obtitle.Form("FFside_DT_E_H20");     
    BB29_FFside_DT_H20= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H21");
    obtitle.Form("FFside_DT_E_H21");     
    BB29_FFside_DT_H21= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H39");
    obtitle.Form("FFside_DT_E_H39");     
    BB29_FFside_DT_H39= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H40");
    obtitle.Form("FFside_DT_E_H40");     
    BB29_FFside_DT_H40= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");
    
    

    //***************************************************************
    //  Init HR  Histograms
    //***************************************************************


    
        // Vertical all horizontals    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_H/HR_ADC_anyH_V1");
    obtitle.Form("HR_ADC_anyH_V1");     
    BB29_HR_V1_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip1 (ch)", "ADC value horizontal strips (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_H/HR_ADC_anyH_V2");
    obtitle.Form("HR_ADC_anyH_V2");     
    BB29_HR_V2_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip2 (ch)", "ADC value horizontal strips (ch)");

    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_H/HR_ADC_anyH_V60");
    obtitle.Form("HR_ADC_anyH_V60");     
    BB29_HR_V60_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip60 (ch)", "ADC value horizontal strips (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_H/HR_ADC_anyH_V61");
    obtitle.Form("HR_ADC_anyH_V61");     
    BB29_HR_V61_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip61 (ch)", "ADC value horizontal strips (ch)");

    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_H/HR_ADC_anyH_V119");
    obtitle.Form("HR_ADC_anyH_V119");     
    BB29_HR_V119_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip119 (ch)", "ADC value horizontal strips (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_H/HR_ADC_anyH_V120");
    obtitle.Form("HR_ADC_anyH_V120");     
    BB29_HR_V120_allH= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip120 (ch)", "ADC value horizontal strips (ch)");
    
    // DT vs vertical ADC
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V1");
    obtitle.Form("HR_DT_E_V1");     
    BB29_HR_DT_V1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V2");
    obtitle.Form("HR_DT_E_V2");     
    BB29_HR_DT_V2= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V60");
    obtitle.Form("HR_DT_E_V60");     
    BB29_HR_DT_V60= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V61");
    obtitle.Form("HR_DT_E_V61");     
    BB29_HR_DT_V61= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V119");
    obtitle.Form("HR_DT_E_V119");     
    BB29_HR_DT_V119= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V119");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V120");
    obtitle.Form("HR_DT_E_V120");     
    BB29_HR_DT_V120= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V120");
    
    // DT vs horizontal ADC
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H1");
    obtitle.Form("HR_DT_E_H1");     
    BB29_HR_DT_H1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H2");
    obtitle.Form("HR_DT_E_H2");     
    BB29_HR_DT_H2= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H20");
    obtitle.Form("HR_DT_E_H20");     
    BB29_HR_DT_H20= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H21");
    obtitle.Form("HR_DT_E_H21");     
    BB29_HR_DT_H21= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H39");
    obtitle.Form("HR_DT_E_H39");     
    BB29_HR_DT_H39= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H40");
    obtitle.Form("HR_DT_E_H40");     
    BB29_HR_DT_H40= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");
    
    // Vertical vs vertical
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_adjV/HR_V1_V2");
    obtitle.Form("HR_V1_V2");     
    BB29_HR_V1_V2= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip1 (ch)", "ADC value adjacent vertical strip2 (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_adjV/HR_V2_V3");
    obtitle.Form("HR_V2_V3");     
    BB29_HR_V2_V3= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip2 (ch)", "ADC value adjacent vertical strip3 (ch)");

    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_adjV/HR_V60_V61");
    obtitle.Form("HR_V60_V61");     
    BB29_HR_V60_V61= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip60 (ch)", "ADC value adjacent vertical strip61 (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_adjV/HR_V61_V62");
    obtitle.Form("HR_V61_V62");     
    BB29_HR_V61_V62= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip61 (ch)", "ADC value adjacent vertical strip62 (ch)");

    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_adjV/HR_V118_V119");
    obtitle.Form("HR_V118_V119");     
    BB29_HR_V118_V119= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip60 (ch)", "ADC value adjacent vertical strip61 (ch)");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/ADC_V_vs_adjV/HR_V119_V120");
    obtitle.Form("HR_V119_V120");     
    BB29_HR_V119_V120= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"ADC value adjacent vertical strip61 (ch)", "ADC value adjacent vertical strip62 (ch)");
    

     

      /** DeltaT detector vs detector **/
      
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFtop_V1");
    obtitle.Form("DT_tel_vs_FFtop_V1");     
    DTtel_ADCFFtop_V1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFtop_V8");
    obtitle.Form("DT_tel_vs_FFtop_V8");     
    DTtel_ADCFFtop_V8= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP8");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFbot_V1");
    obtitle.Form("DT_tel_vs_FFbot_V1");     
    DTtel_ADCFFbot_V1= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF bot VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFbot_V8");
    obtitle.Form("DT_tel_vs_FFbot_V8");     
    DTtel_ADCFFbot_V8= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_V1");
    obtitle.Form("DT_tel_vs_FFside_V1");     
    DTtel_ADCFFside_V1= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_V60");
    obtitle.Form("DT_tel_vs_FFside_V60");     
    DTtel_ADCFFside_V60= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_H1");
    obtitle.Form("DT_tel_vs_FFside_H1");     
    DTtel_ADCFFside_H1= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_H20");
    obtitle.Form("DT_tel_vs_FFside_H20");     
    DTtel_ADCFFside_H20= MakeTH2('I', obname.Data(), obtitle.Data(), 300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_HR_V1");
    obtitle.Form("DT_tel_vs_HR_V1");     
    DTtel_ADCHR_V1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT HR verticals(ch)", "ADC value telescope BB8 VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_HR_V60");
    obtitle.Form("DT_tel_vs_HR_V60");     
    DTtel_ADCHR_V60= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT HR verticals(ch)", "ADC value telescope BB8  VSTRIP8");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_HR_H1");
    obtitle.Form("DT_tel_vs_HR_H1");     
    DTtel_ADCHR_H1= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT HR verticals(ch)", "ADC value telescope BB8   HSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_HR_H20");
    obtitle.Form("DT_tel_vs_HR_H20");     
    DTtel_ADCHR_H20= MakeTH2('I', obname.Data(), obtitle.Data(),300, 0,300, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT HR verticals(ch)", "ADC value telescope BB8  HSTRIP8");
    
     //******************** 
     //Init Delta Time Histograms
     //*******************

     obname.Form("Monitoring/Target_on/DT/DT_telescope");
     obtitle.Form("h_DT_telescope");
     h_DT_telescope= MakeTH1('I', obname.Data(), obtitle.Data(), 2000, 0,2000, "DT (ch)", "counts");
     
     obname.Form("Monitoring/Target_on/DT/DT_BB29_V");
     obtitle.Form("h_DT_BB29_V");  
     h_DT_BB29_V= MakeTH1('I', obname.Data(), obtitle.Data(), 2000, 0, 2000, "DT (ch)", "counts");  

     obname.Form("Monitoring/Target_on/DT/DT_BB29_H");
     obtitle.Form("h_DT_BB29_H");  
     h_DT_BB29_H= MakeTH1('I', obname.Data(), obtitle.Data(), 2000, 0, 2000, "DT (ch)", "counts"); 
     

     
     //******************************* 
     //Multiplicity Spectra BB8 & BB29
     //*******************************

     obname.Form("Monitoring/Target_on/Multiplicity/h_Mult_BB8_V");
     obtitle.Form("h_Mult_BB8_V");  
     h_Mult_BB8_V= MakeTH1('I', obname.Data(), obtitle.Data(), 10, 0.5, 10.5, "Multiplicity (n^{o})", "counts");

      obname.Form("Monitoring/Target_on/Multiplicity/h_Mult_BB8_H");
     obtitle.Form("h_Mult_BB8_H");  
     h_Mult_BB8_H= MakeTH1('I', obname.Data(), obtitle.Data(), 10, 0.5, 10.5, "Multiplicity (n^{o})", "counts");

     obname.Form("Monitoring/Target_on/Multiplicity/h_Mult_BB29_V");
     obtitle.Form("h_Mult_BB29_V");  
     h_Mult_BB29_V= MakeTH1('I', obname.Data(), obtitle.Data(), 10, 0.5, 10.5, "Multiplicity (n^{o})", "counts");

      obname.Form("Monitoring/Target_on/Multiplicity/h_Mult_BB29_H");
     obtitle.Form("h_Mult_BB29_H");  
     h_Mult_BB29_H= MakeTH1('I', obname.Data(), obtitle.Data(), 10, 0.5, 10.5, "Multiplicity (n^{o})", "counts");
   
     
     






     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_V_E_tot");
     obtitle.Form("h_V_E_tot");     
     h_V_E_tot= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 250,0,50000,"Strip_V (n^{o})","Protons Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_V_ch_tot");
     obtitle.Form("h_V_ch_tot");     
     h_V_ch_tot= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, 250,0,50000,"Strip_V (n^{o})","Protons Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Multiplicity/h_DE_E_tot_Mult");
     obtitle.Form("h_DE_E_tot_Mult");     
     h_DE_E_tot_Mult= MakeTH2('I', obname.Data(), obtitle.Data(),250,0,50000,80,0,16000,"Energy Deposited (keV)","BB8 Energy (keV)");  

     //**************** DETECTORS MAPPING  ****//////////  
     /*
     obname.Form("Monitoring/Target_on/Online_2D_plots/Mapping/h_BB8_Map");
     obtitle.Form("h_BB8_Map");     
     h_BB8_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, -16.5, -0.5,"Strip_X (n^{o})", "Strip_Y (n^{o})");
     */
     /*
     obname.Form("Monitoring/Target_on/Online_2D_plots/Mapping/Map_BB29_no_cond");
     obtitle.Form("h_Map_BB29");     
     h_Map_HR= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5, 64, -64.5, -0.5, "Strip_X (n^{o} strip)", "Strip_Y (n^{o} strip)");*/
     
     obname.Form("Monitoring/Target_on/Online_2D_plots/Mapping/Map_BB29_DT_DE-E");
     obtitle.Form("h_cond_Map_BB29");     
     h_cond_Map_BB29= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,  64, -64.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
     
     obname.Form("Monitoring/Target_on/Online_2D_plots/Mapping/Map_BB29_cond_DT");
     obtitle.Form("h_cond_Map_BB29_DT");     
     h_cond_Map_BB29_DT= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,  64, -64.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Mapping/Map_BB29_cond_DE-E");
     obtitle.Form("h_cond_Map_BB29_DE-E");     
     h_cond_Map_BB29_DE= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,  64, -64.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");  




     obname.Form("Monitoring/Target_on/Online_2D_plots/Mapping/h_Map_BB29_Mult");
     obtitle.Form("h_Map_BB29_Mult");     
     h_Map_BB29_Mult= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,  64, -64.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");  

     
     
     //**************************
     //  Control Histograms
     //************************

     
     obname.Form("Monitoring/Target_on/Control_Histograms/BB29_ADC_V_strip");
     obtitle.Form("BB29_ADC_V_strip");     
     BB29_ADC_V_strip= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB29_Vertical (n^{o})", "ADC (ch)");
     
     obname.Form("Monitoring/Target_on/Control_Histograms/BB29_ADC_H_strip");
     obtitle.Form("BB29_ADC_H_strip");     
     BB29_ADC_H_strip= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB29_Horizontal (n^{o})", "ADC (ch)");
     



     //**************************************
     //    TARGET OFF HISTOGRAMS
     //**************************************
     
     
     /** Mapping Telescope - BB29 **/
     /*
     obname.Form("Monitoring/Target_off/Online_2D_plots/h_BB8_Map_TO");
     obtitle.Form("h_BB8_Map");     
     h_BB8_Map_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, -16.5, -0.5,"Strip_X (n^{o} strip)", "Strip_Y (n^{o} strip)");
     */
     
     obname.Form("Monitoring/Target_off/Online_2D_plots/Map_BB29_no_cond_TO");
     obtitle.Form("h_Map_BB29");     
     h_Map_BB29_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5, 64, -64.5, -0.5, "Strip_X (n^{o} strip)", "Strip_Y (n^{o} strip)");
     
     obname.Form("Monitoring/Target_off/Online_2D_plots/Map_BB29_cond_DT_TO");
     obtitle.Form("h_cond_Map_BB29_DT_TO");     
     h_cond_Map_BB29_DT_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,  64, -64.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
     
          
     /* Control Histograms */
     
     obname.Form("Monitoring/Target_off/Control_Histograms/BB8_ADC_V_strip_TO");
     obtitle.Form("BB8_ADC_V_strip");     
     BB8_ADC_V_strip_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"BB8_Vertical (n^{o})", "ADC (ch)");
     
     obname.Form("Monitoring/Target_off/Control_Histograms/BB8_ADC_H_strip_TO");
     obtitle.Form("BB8_ADC_H_strip");     
     BB8_ADC_H_strip_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB8_Horizontal (n^{o})", "ADC (ch)");
     
     obname.Form("Monitoring/Target_off/Control_Histograms/BB29_ADC_V_strip_TO");
     obtitle.Form("BB29_ADC_V_strip");     
     BB29_ADC_V_strip_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB29_Vertical (n^{o})", "ADC (ch)");
     
     obname.Form("Monitoring/Target_off/Control_Histograms/BB29_ADC_H_strip_TO");
     obtitle.Form("BB29_ADC_H_strip");     
     BB29_ADC_H_strip_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 128, 0.5, 128.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB29_Horizontal (n^{o})", "ADC (ch)");
     
     obname.Form("Monitoring/Target_off/Control_Histograms/MSXO4_ADC_TO");
     obtitle.Form("MSXO4_ADC");     
     MSXO4_TO= MakeTH2('I', obname.Data(), obtitle.Data(), 10, 0.5, 10.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"MSXO4 (n^{o})", "ADC (ch)");

     /** DT Histograms **/

     
     obname.Form("Monitoring/Target_off/DT/DT_telescope_TO");
     obtitle.Form("h_DT_telescope");
     h_DT_telescope_TO= MakeTH1('I', obname.Data(), obtitle.Data(), 800, 0,800, "DT (ch)", "counts");
     
     obname.Form("Monitoring/Target_off/DT/DT_BB29_V_TO");
     obtitle.Form("h_DT_BB29_V");  
     h_DT_BB29_V_TO= MakeTH1('I', obname.Data(), obtitle.Data(), 800, 0, 800, "DT (ch)", "counts");  

     obname.Form("Monitoring/Target_off/DT/DT_BB29_H_TO");
     obtitle.Form("h_DT_BB29_H");  
     h_DT_BB29_H_TO= MakeTH1('I', obname.Data(), obtitle.Data(), 800, 0, 800, "DT (ch)", "counts");  

     /** Excitation Energy Plots **/
       
     obname.Form("Monitoring/Target_on/Ex_Energy/h_Ex");
     obtitle.Form("h_Ex");
     h_Ex= MakeTH1('I', obname.Data(), obtitle.Data(),1000,0,10, "Ex (MeV)","Counts");

     obname.Form("Monitoring/Target_on/Ex_Energy/Kinematics_plot");
     obtitle.Form("Kinematics_plot");     
     h_Kinematics_plot= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 30.0, 80.0,1000, 0, 50000,"Theta_Angle (deg)", "Protons Energy (keV)");
    

     
}
