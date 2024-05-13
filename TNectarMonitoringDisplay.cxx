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
    //   Init BB8 Histograms
    //***************************************************************

    // ADC energy value for each strip
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_Strips/BB8_ADC_V_%d", i+1);
        //TGo4Log::Info("Monitoring: Initializing histograms 12");
        obtitle.Form("BB8_ADC_V_%d", i+1);
        //TGo4Log::Info("Monitoring: Initializing histograms 12");
        BB8_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy Vstrip (ch)", "counts");
        // TGo4Log::Info("Monitoring: Initializing histograms 12");
    }
     //TGo4Log::Info("Monitoring: Initializing histograms 1");
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_Strips/BB8_ADC_H_%d", i+1);
        obtitle.Form("BB8_ADC_H_%d", i+1);  
        BB8_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy Hstrip (ch)", "counts");
    } 
     
     /* FOLLOWING HISTOGRAMS ADDED IN MARCH 2024 FOR BB8 SOURCE TESTS */
     //TGo4Log::Info("Monitoring: Initializing histograms 1");

    // ADC value vertical strips vs telescope delta time
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/BB8/DeltaT_vs_V/BB8_DT_E_V_%d",i+1);
        obtitle.Form("BB8_DT_E_V_%d",i+1);  
        BB8_DT_E_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"Telescope DT (ch)", "ADC energy Vstrip (ch)"); 
    }

    // ADC value vertical strips vs any horizontal strip
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_V_vs_H/BB8_ADC_anyH_V_%d",i+1);
        obtitle.Form("BB8_ADC_anyH_V_%d",i+1);  
        BB8_1V_allH[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"ADC energy vertical strip (ch)", "ADC energy horizontal strips (ch)"); 
    }
    
    // ADC value vertical strip 8 vs horizontal strip 8
    obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_V_vs_H/BB8_ADC_V8_H8");
    obtitle.Form("BB8_ADC_V8_H8");  
    BB8_V8_H8= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"ADC energy VSTRIP 8(ch)", "ADC energy HSTRIP 8(ch)");  
    
    // ADC value vertical strip 8 vs horizontal strip 8 multiplicity 1
    obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_V_vs_H/BB8_ADC_V8_H8_mult1");
    obtitle.Form("BB8_ADC_V8_H8_mult1");  
    BB8_V8_H8_mult1= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"ADC energy VSTRIP 8(ch)", "ADC energy HSTRIP 8(ch)");  
    
    // Energy of adjacent vertical strips
    for(int i=0;i<15;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_V_vs_adjV/BB8_ADC_V_%d_V%d",i+1,i+2);
        obtitle.Form("BB8_ADC_V_%d_V%d",i+1,i+2);  
        BB8_adj_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"ADC energy adjacent vertical strip1 (ch)", "ADC energy adjacent vertical strip2 (ch)"); 
    }
    
    // Energy of adjacent horizontal strips
    for(int i=0;i<15;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/BB8/ADC_H_vs_adjH/BB8_ADC_H_%d_H%d",i+1,i+2);
        obtitle.Form("BB8_ADC_H_%d_H%d",i+1,i+2);  
        BB8_adj_H[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"ADC energy adjacent horizontal strip1 (ch)", "ADC energy adjacent horizontal strip2 (ch)"); 
    }
    
    // Control histograms strip 
    obname.Form("Monitoring/Target_on/Detectors/BB8/BB8_ADC_VSTRIP_control");
    obtitle.Form("BB8_ADC_VSTRIP_control");     
    BB8_ADC_V_strip= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"BB8_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("Monitoring/Target_on/Detectors/BB8/BB8_ADC_HSTRIP_control");
    obtitle.Form("BB8_ADC_HSTRIP_control");     
    BB8_ADC_H_strip= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"BB8_Horizontal (n^{o})", "ADC energy (ch)");
     
    obname.Form("Monitoring/Target_on/Detectors/BB8/BB8_Mapping");
    obtitle.Form("BB8_Mapping");     
    h_BB8_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, -16.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
     
     //TGo4Log::Info("Monitoring: Initializing histograms 2");
    //***************************************************************
    //   Init MSXO4s  Histograms
    //***************************************************************
     
    // ADC energy value each MSX04
    obname.Form("Monitoring/Target_on/Detectors/MSX04/ADC_Strips/ADC_MSX04_1");
    obtitle.Form("ADC_MSX04_1");
    h_ADC_MSX04_1= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");
      
    obname.Form("Monitoring/Target_on/Detectors/MSX04/ADC_Strips/ADC_MSX04_2");
    obtitle.Form("ADC_MSX04_2");  
    h_ADC_MSX04_2= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");  

    obname.Form("Monitoring/Target_on/Detectors/MSX04/ADC_Strips/ADC_MSX04_7");
    obtitle.Form("ADC_MSX04_7");
    h_ADC_MSX04_7= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");
     
    obname.Form("Monitoring/Target_on/Detectors/MSX04/ADC_Strips/ADC_MSX04_8");
    obtitle.Form("ADC_MSX04_8");  
    h_ADC_MSX04_8= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");  
     
    obname.Form("Monitoring/Target_on/Detectors/MSX04/ADC_Strips/ADC_MSX04_9");
    obtitle.Form("ADC_MSX04_9");
    h_ADC_MSX04_9= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");
     
    obname.Form("Monitoring/Target_on/Detectors/MSX04/ADC_Strips/ADC_MSX04_10");
    obtitle.Form("ADC_MSX04_10");  
    h_ADC_MSX04_10= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");  
    
    obname.Form("Monitoring/Target_on/Detectors/MSX04/MSXO4_ADC_control");
    obtitle.Form("MSXO4_ADC_control");     
    MSXO4= MakeTH2('I', obname.Data(), obtitle.Data(), 10, 0.5, 10.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"MSXO4 (n^{o})", "ADC energy (ch)");
     

    //***************************************************************
    //  Init HR  Histograms
    //***************************************************************

    for(int i=0;i<128;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/HR/ADC Strips/BB29_HR_ADC_V_%d", i+1);
        obtitle.Form("BB29_HR_ADC_V_%d", i+1);
        BB29_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    } 
    for(int i=0;i<64;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/HR/ADC Strips/BB29_HR_ADC_H_%d", i+1);
        obtitle.Form("BB29_HR_ADC_H_%d", i+1);  
        BB29_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    }
    
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
    BB29_HR_DT_V1= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V2");
    obtitle.Form("HR_DT_E_V2");     
    BB29_HR_DT_V2= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V60");
    obtitle.Form("HR_DT_E_V60");     
    BB29_HR_DT_V60= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V61");
    obtitle.Form("HR_DT_E_V61");     
    BB29_HR_DT_V61= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V119");
    obtitle.Form("HR_DT_E_V119");     
    BB29_HR_DT_V119= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V119");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_V120");
    obtitle.Form("HR_DT_E_V120");     
    BB29_HR_DT_V120= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V120");
    
    // DT vs horizontal ADC
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H1");
    obtitle.Form("HR_DT_E_H1");     
    BB29_HR_DT_H1= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H2");
    obtitle.Form("HR_DT_E_H2");     
    BB29_HR_DT_H2= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H20");
    obtitle.Form("HR_DT_E_H20");     
    BB29_HR_DT_H20= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H21");
    obtitle.Form("HR_DT_E_H21");     
    BB29_HR_DT_H21= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H39");
    obtitle.Form("HR_DT_E_H39");     
    BB29_HR_DT_H39= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/HR/DeltaT_vs_V/HR_DT_E_H40");
    obtitle.Form("HR_DT_E_H40");     
    BB29_HR_DT_H40= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");
    
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
    
    // Control histograms strip 
    obname.Form("Monitoring/Target_on/Detectors/HR/HR_ADC_V_control");
    obtitle.Form("HR_ADC_V_control");     
    BB29_HR_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"HR_Vertical Strip (n^{o})", "ADC energy (ch)");
     
    obname.Form("Monitoring/Target_on/Detectors/HR/HR_ADC_H_control");
    obtitle.Form("HR_ADC_H_control");     
    BB29_HR_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 40, 0.5, 40.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"HR_Horizontal Strip (n^{o})", "ADC energy (ch)");
    
    // HR mapping
    obname.Form("Monitoring/Target_on/Detectors/HR/HR_Mapping");
    obtitle.Form("HR_Mapping");     
    h_HR_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5,  40, -40.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
     
    //***************************************************************
    //  Init Fission  Histograms
    //***************************************************************
    
    //* FF top - BB36 *//
    // ADC energy value each strip
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_top/ADC_Strips/ADC_FFtop_V_%d", i+1);
        obtitle.Form("ADC_FFtop_V_%d", i+1);
        BB36_FFtop_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");
    }
     
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_top/ADC_Strips/ADC_FFtop_H_%d", i+1);
        obtitle.Form("ADC_FFtop_H_%d", i+1);  
        BB36_FFtop_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC energy (ch)", "counts");
    } 
    
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_top/DeltaT_vs_V/FFtop_DT_E_V_%d",i+1);
        obtitle.Form("FFtop_DT_E_V_%d",i+1);  
        BB36_FFtop_DT_E_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DT (ch)", "ADC energy (ch)"); 
    }
    
    // Control histograms strip 
    obname.Form("Monitoring/Target_on/Detectors/FF_top/FF_top_ADC_V_control");
    obtitle.Form("FF_top_ADC_V_control");     
    BB36_FFtop_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"FFtop_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("Monitoring/Target_on/Detectors/FF_top/FF_top_ADC_H_control");
    obtitle.Form("FF_top_ADC_H_control");     
    BB36_FFtop_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"FFtop_Horizontal (n^{o})", "ADC (ch)");
    
    // FF side mapping
    obname.Form("Monitoring/Target_on/Detectors/FF_top/FF_top_Mapping");
    obtitle.Form("FF_top_Mapping");     
    h_FFtop_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, -16.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
     
    //* FF bot - BB36 *//
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_bot/ADC_Strips/ADC_FFbot_V_%d", i+1);
        obtitle.Form("ADC_FFbot_V_%d", i+1);
        BB36_FFbot_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    } 
     
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_bot/ADC_Strips/ADC_FFbot_H_%d", i+1);
        obtitle.Form("ADC_FFbot_H_%d", i+1);  
        BB36_FFbot_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    }
    
    for(int i=0;i<16;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_bot/DeltaT_vs_V/FFbot_DT_E_V_%d",i+1);
        obtitle.Form("FFbot_DT_E_V_%d",i+1);  
        BB36_FFbot_DT_E_V[i]= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DT (ch)", "ADC value"); 
    }

    // Control histograms strip 
    obname.Form("Monitoring/Target_on/Detectors/FF_bot/FF_bot_ADC_V_control");
    obtitle.Form("FF_bot_ADC_V_control");     
    BB36_FFbot_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"FFtop_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("Monitoring/Target_on/Detectors/FF_bot/FF_bot_ADC_H_control");
    obtitle.Form("FF_bot_ADC_H_control");     
    BB36_FFbot_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"FFtop_Horizontal (n^{o})", "ADC (ch)");
    
    // FF side mapping
    obname.Form("Monitoring/Target_on/Detectors/FF_bot/FF_bot_Mapping");
    obtitle.Form("FF_bot_Mapping");     
    h_FFbot_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 16, 0.5, 16.5,  16, -16.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");
    
    
     
    //* FF side - BB29 *//
    for(int i=0;i<128;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_Strips/ADC_FFside_V_%d", i+1);
        obtitle.Form("ADC_FFside_V_%d", i+1);
        BB29_FFside_V_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    } 
    for(int i=0;i<64;i++)
    {
        obname.Form("Monitoring/Target_on/Detectors/FF_side/ADC_Strips/ADC_FFside_H_%d", i+1);
        obtitle.Form("ADC_FFside_H_%d", i+1);  
        BB29_FFside_H_S[i]= MakeTH1('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE, "ADC value", "counts");
    }
    
    // Vertical all horizontals 
    
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
    BB29_FFside_DT_V1= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V2");
    obtitle.Form("FFside_DT_E_V2");     
    BB29_FFside_DT_V2= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V60");
    obtitle.Form("FFside_DT_E_V60");     
    BB29_FFside_DT_V60= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V61");
    obtitle.Form("FFside_DT_E_V61");     
    BB29_FFside_DT_V61= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V119");
    obtitle.Form("FFside_DT_E_V119");     
    BB29_FFside_DT_V119= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V119");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_V120");
    obtitle.Form("FFside_DT_E_V120");     
    BB29_FFside_DT_V120= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V120");
    
    // DT vs horizontal ADC
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H1");
    obtitle.Form("FFside_DT_E_H1");     
    BB29_FFside_DT_H1= MakeTH2('I', obname.Data(), obtitle.Data(),100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V1");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H2");
    obtitle.Form("FFside_DT_E_H2");     
    BB29_FFside_DT_H2= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V2");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H20");
    obtitle.Form("FFside_DT_E_H20");     
    BB29_FFside_DT_H20= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H21");
    obtitle.Form("FFside_DT_E_H21");     
    BB29_FFside_DT_H21= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");

    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H39");
    obtitle.Form("FFside_DT_E_H39");     
    BB29_FFside_DT_H39= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V60");
    
    obname.Form("Monitoring/Target_on/Detectors/FF_side/DeltaT_vs_V/FFside_DT_E_H40");
    obtitle.Form("FFside_DT_E_H40");     
    BB29_FFside_DT_H40= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value V61");
    
    
    // Control histograms strip 
    obname.Form("Monitoring/Target_on/Detectors/FF_side/FF_side_ADC_V_control");
    obtitle.Form("FF_side_ADC_V_control");     
    BB29_FFside_ADC_V_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5, VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE ,"FFside_Vertical (n^{o})", "ADC (ch)");
     
    obname.Form("Monitoring/Target_on/Detectors/FF_side/FF_side_ADC_H_control");
    obtitle.Form("FF_side_ADC_H_control");     
    BB29_FFside_ADC_H_STRIP= MakeTH2('I', obname.Data(), obtitle.Data(), 40, 0.5, 40.5,VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"FFside_Horizontal (n^{o})", "ADC (ch)");
    
    // FF side mapping
    obname.Form("Monitoring/Target_on/Detectors/FF_side/FF_side_Mapping");
    obtitle.Form("FF_side_Mapping");     
    h_FFside_Map= MakeTH2('I', obname.Data(), obtitle.Data(), 120, 0.5, 120.5,  40, -40.5, -0.5," Vertical Strip X (strip number)", "Horizontal Strip Y (strip number)");

      /** DeltaT detector vs detector **/
      
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFtop_V1");
    obtitle.Form("DT_tel_vs_FFtop_V1");     
    DTtel_ADCFFtop_V1= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFtop_V8");
    obtitle.Form("DT_tel_vs_FFtop_V8");     
    DTtel_ADCFFtop_V8= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP8");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFbot_V1");
    obtitle.Form("DT_tel_vs_FFbot_V1");     
    DTtel_ADCFFbot_V1= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF bot VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFbot_V8");
    obtitle.Form("DT_tel_vs_FFbot_V8");     
    DTtel_ADCFFbot_V8= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_V1");
    obtitle.Form("DT_tel_vs_FFside_V1");     
    DTtel_ADCFFside_V1= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_V60");
    obtitle.Form("DT_tel_vs_FFside_V60");     
    DTtel_ADCFFside_V60= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_H1");
    obtitle.Form("DT_tel_vs_FFside_H1");     
    DTtel_ADCFFside_H1= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    
    obname.Form("Monitoring/Target_on/Detectors/DT_tel_vs_dets/DT_tel_vs_FFside_H20");
    obtitle.Form("DT_tel_vs_FFside_H20");     
    DTtel_ADCFFside_H20= MakeTH2('I', obname.Data(), obtitle.Data(), 100, 0,100, VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE ,"DeltaT (ch)", "ADC value FF top VSTRIP1");
    

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
   
     
     
     //***********************
     //DE vs E (Online_Analysis Histograms)
     //***********************
    
     for(Int_t i=0;i<16;i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/DE_vs_E_1_Strip_%d", i+1);
     obtitle.Form("h_DE_E_1_Strip_%d",i);     
     h_DE_E_1[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");     
     }
 for(Int_t i=0;i<16;i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/DE_vs_E_2_Strip_%d", i+1);
     obtitle.Form("h_DE_E_2_Strip_%d",i);     
     h_DE_E_2[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");     
     }
 for(Int_t i=0;i<16;i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/DE_vs_E_7_Strip_%d", i+1);
     obtitle.Form("h_DE_E_7_Strip_%d",i);     
     h_DE_E_7[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");     
     }
 for(Int_t i=0;i<16;i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/DE_vs_E_8_Strip_%d", i+1);
     obtitle.Form("h_DE_E_8_Strip_%d",i);     
     h_DE_E_8[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");     
     }
 for(Int_t i=0;i<16;i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/DE_vs_E_9_Strip_%d", i+1);
     obtitle.Form("h_DE_E_9_Strip_%d",i);     
     h_DE_E_9[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");     
     }
 for(Int_t i=0;i<16;i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/DE_vs_E_10_Strip_%d", i+1);
     obtitle.Form("h_DE_E_10_Strip_%d",i);     
     h_DE_E_10[i]= MakeTH2('I', obname.Data(), obtitle.Data(), VMMR_ADC_RANGE/*0xF*/, 0, VMMR_ADC_RANGE,  VMMR_ADC_RANGE, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");     
     }
 
     //Attention here you need to define the final range!!!! It cannot be VMMR_ADC_RANGE!!!!
     for(Int_t i=0; i<16 ; i++){
     obname.Form("Monitoring/Target_on/Online_2D_plots/ADC_Spectra/h_DE_E_tot_ch_%d",i+1);
     obtitle.Form("h_DE_E_tot_ch_%d",i);     
     h_DE_E_tot_ch[i]= MakeTH2('I', obname.Data(), obtitle.Data(), 28672/32, 0, 28672,  VMMR_ADC_RANGE/0xF, 0, VMMR_ADC_RANGE,"Energy Deposited (ch)", "BB8 Energy (ch)");
     }

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_DE_E_tot_keV");
     obtitle.Form("h_DE_E_tot_MeV");     
     h_DE_E_tot_keV= MakeTH2('I', obname.Data(), obtitle.Data(), 250, 0, 50000, 80, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");
     
     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_DE_E_tot_MeV_cond");
     obtitle.Form("h_DE_E_tot_MeV_cond");     
     h_DE_E_tot_keV_cond= MakeTH2('I', obname.Data(), obtitle.Data(), 250, 0, 50000, 80, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");


     for(Int_t i=0; i<16 ; i++){
       obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_DE_E_tot_E_%d",i+1);
       obtitle.Form("h_DE_E_tot_E_%d",i);     
       h_DE_E_tot_E[i]= MakeTH2('I', obname.Data(), obtitle.Data(),250,0,50000,80,0,16000,"Energy Deposited (keV)", "BB8 Energy (keV)");
     }
     
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
    
     /* Energy Calibration */


     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_Calib_E_1_keV");
     obtitle.Form("h_Calib_E_1_Calib");     
     h_DE_E_1_Calib= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 0, 50000, 160, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_Calib_E_2_keV");
     obtitle.Form("h_Calib_E_2_Calib");     
     h_DE_E_2_Calib= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 0, 50000, 160, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_Calib_E_7_keV");
     obtitle.Form("h_Calib_E_7_Calib");     
     h_DE_E_7_Calib= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 0, 50000, 160, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_Calib_E_8_keV");
     obtitle.Form("h_Calib_E_8_Calib");     
     h_DE_E_8_Calib= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 0, 50000, 160, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_Calib_E_9_keV");
     obtitle.Form("h_Calib_E_9_Calib");     
     h_DE_E_9_Calib= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 0, 50000, 160, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");

     obname.Form("Monitoring/Target_on/Online_2D_plots/Energy_Spectra/h_Calib_E_10_keV");
     obtitle.Form("h_Calib_E_10_Calib");     
     h_DE_E_10_Calib= MakeTH2('I', obname.Data(), obtitle.Data(), 500, 0, 50000, 160, 0, 16000,"Energy Deposited (keV)", "BB8 Energy (keV)");


     
}
