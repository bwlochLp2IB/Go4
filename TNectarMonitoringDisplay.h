#ifndef TNectarMonitoringDISPLAY_H
#define TNectarMonitoringDISPLAY_H

class TNectarRawParam;

#include "TGo4EventProcessor.h"

#include "TGo4WinCond.h"

#include <vector>
#include "TH1.h"
#include "TH2.h"
#include "TNectarRawEvent.h"
#include "TNectarProfileEvent.h"
#include "TNectarRawProc.h"
#include "TNectarDisplay.h"
#include "TGo4Analysis.h"

#include "TLatex.h"

//********************************
class TNectarHistograms: public TGo4EventProcessor
{
  
public:

    TNectarHistograms() : TGo4EventProcessor() {}
  
    /*  Histograms Initialization */ 
    void InitHistograms(Bool_t replace);

    //**********  TARGET ON ***********//
    //--- Telescope ---//
      
    /** BB8 **/
    // Adc strips
    TH1 *BB8_V_S[16];         // Vertical strip histograms
    TH1 *BB8_H_S[16];         // Horizontal strip histograms
  
    // DT
    TH2 *BB8_DT_E_V[16];      // Delta time vs energy (ch) for vertical strips
    TH1 *h_DT_telescope;      // Telescope deltaTime   
     
    // Strips vs strips
    TH2 *BB8_1V_allH[16];     // Individual vertical strip energy vs any horitontal strip 
    TH2 *BB8_adj_V[15];       // Energy of adjacent vertical strips
    TH2 *BB8_adj_H[15];       // Energy of adjacent horizontal strips   
    TH2 *BB8_V8_H8;           // Energy ADC value for vertical strip 8 vs horizontal strip 8
    TH2 *BB8_V8_H8_mult1;     // Energy ADC value for vertical strip 8 vs horizontal strip 8 with multiplicity 1

    /** MSX04 **/
    // Adc detectors
    TH1 *h_ADC_MSX04_1;       // first stack
    TH1 *h_ADC_MSX04_2;       // first stack
    TH1 *h_ADC_MSX04_3;       // second stack
    TH1 *h_ADC_MSX04_4;       // second stack
    TH1 *h_ADC_MSX04_5;       // third stack
    TH1 *h_ADC_MSX04_6;       // third stack

    /** DE vs E plots **/
    // DE_E Energy Plots in ch for each strip then all strips
    TH2 *h_DE_E_tot_ch_strip[16];
    TH2 *h_DE_E_tot_ch;
    // DE_E Energy Plots in KeV for each strip then all strips
    TH2 *h_DE_E_tot_kev_strip[16];
    TH2 *h_DE_E_tot_keV;
    
    // DE vs Ex plots each MSX04 each strip
    TH2 *h_DE_E_1_ch_strip[16]; 
    TH2 *h_DE_E_2_ch_strip[16]; 
    TH2 *h_DE_E_3_ch_strip[16]; 
    TH2 *h_DE_E_4_ch_strip[16]; 
    TH2 *h_DE_E_5_ch_strip[16]; 
    TH2 *h_DE_E_6_ch_strip[16]; 
    
    TH2 *h_DE_E_1_keV_strip[16]; 
    TH2 *h_DE_E_2_keV_strip[16]; 
    TH2 *h_DE_E_3_keV_strip[16]; 
    TH2 *h_DE_E_4_keV_strip[16]; 
    TH2 *h_DE_E_5_keV_strip[16]; 
    TH2 *h_DE_E_6_keV_strip[16]; 

    // DE vs Ex plots each MSX04 all strips
    TH2 *h_DE_E_1_ch;
    TH2 *h_DE_E_2_ch;
    TH2 *h_DE_E_3_ch;
    TH2 *h_DE_E_4_ch;
    TH2 *h_DE_E_5_ch;
    TH2 *h_DE_E_6_ch;
    
    TH2 *h_DE_E_1_keV;
    TH2 *h_DE_E_2_keV;
    TH2 *h_DE_E_3_keV;
    TH2 *h_DE_E_4_keV;
    TH2 *h_DE_E_5_keV;
    TH2 *h_DE_E_6_keV;
    
    //** Ei vs Ej **/
    TH2 *h_E1_E2_keV;
    TH2 *h_E2_E3_keV;
    TH2 *h_E3_E4_keV;
    TH2 *h_E4_E5_keV;
    TH2 *h_E5_E6_keV;  
    

    
    /** Control **/
    TH2 *BB8_ADC_V_strip;       // Control ADC BB8  vertical strips
    TH2 *BB8_ADC_H_strip;       // Control ADC BB8  horizontal strips
    TH2 *h_BB8_Map;             // BB8 Mapping    
    TH2 *MSXO4;
      
    TH2 *h_V_E_tot;
    TH2 *h_V_ch_tot;
    TH2 *h_DE_E_tot_Mult;
    
    /** Singles **/
    // DE-E Conditionned TCut spectra
    TH2 *h_DE_E_tot_keV_cond_p;
    TH2 *h_DE_E_tot_keV_cond_d;
    
    // Target-like residues energies
    TH1 *h_Eproton_VS3_ch;
    TH1 *h_Eproton_VS3_keV;
    TH1 *h_Edeuteron_VS3_ch;
    TH1 *h_Edeuteron_VS3_keV;
    
    
    //--- Fission ---//
    /* TOP */
  
    TH1 *BB36_FFtop_V_S[16];        // Top detector BB36
    TH1 *BB36_FFtop_H_S[16];        // Top detector BB36
    TH1 *h_DT_BB36_top;
    TH2 *h_FFtop_Map;               // Mapping fission top
    TH2 *BB36_FFtop_ADC_V_STRIP;    // Control ADC V strips
    TH2 *BB36_FFtop_ADC_H_STRIP;    // Control ADC H strips
    TH2 *BB36_FFtop_DT_E_V[16];     // Delta time vs energy (ch) for vertical strips
    TH2 *h_FFtop_E_y_cond_p;        // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_FFtop_E_y_cond_d;        // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_FFtop_E_y_autotrig;      // Plot Energy vs position of fragments FF top auto triggers
    TH2 *h_FFtop_map_cond_p;        // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_FFtop_map_cond_d;        // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_FFtop_map_autotrig;      // Plot Energy vs position of fragments FF top auto triggers
  
    /* BOTTOM */
    TH1 *BB36_FFbot_V_S[16];        // Bottom detector BB36
    TH1 *BB36_FFbot_H_S[16];        // Bottom detector BB36
    TH1 *h_DT_BB36_bot;
    TH2 *h_FFbot_Map;
    TH2 *BB36_FFbot_ADC_V_STRIP;    // Control ADC V strips
    TH2 *BB36_FFbot_ADC_H_STRIP;    // Control ADC H strips
    TH2 *BB36_FFbot_DT_E_V[16];     // Delta time vs energy (ch) for vertical strips
    TH2 *h_FFbot_E_y_cond_p;        // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_FFbot_E_y_cond_d;        // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_FFbot_E_y_autotrig;      // Plot Energy vs position of fragments FF top auto triggers
    TH2 *h_FFbot_map_cond_p;        // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_FFbot_map_cond_d;        // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_FFbot_map_autotrig;      // Plot Energy vs position of fragments FF top auto triggers
  
    /* SIDE */
    TH1 *BB29_FFside_V_S[128];      // Side detector BB29
    TH1 *BB29_FFside_H_S[64];       // Side detector BB29  
    TH1 *h_DT_BB29_side_V;
    TH1 *h_DT_BB29_side_H;
    TH2 *h_FFside_Map;
    TH2 *BB29_FFside_ADC_V_STRIP;   // Control ADC V strips
    TH2 *BB29_FFside_ADC_H_STRIP;   // Control ADC H strips  
    TH2 *h_FFside_E_x_cond_p;       // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_FFside_E_x_cond_d;       // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_FFside_E_x_autotrig;     // Plot Energy vs position of fragments FF top auto triggers
    TH2 *h_FFside_map_cond_p;       // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_FFside_map_cond_d;       // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_FFside_map_autotrig;     // Plot Energy vs position of fragments FF top auto triggers    
    
    //--- Heavy residue ---//
    TH1* BB29_V_S[128];
    TH1* BB29_H_S[64];
    TH1 *h_DT_BB29_V;               // HR delta time V strips
    TH1 *h_DT_BB29_H;               // HR delta time H strips  
    TH2 *h_HR_Map;   
    TH2 *BB29_HR_ADC_V_STRIP;       // Control ADC V strips
    TH2 *BB29_HR_ADC_H_STRIP;       // Control ADC H strips
    TH2 *h_HR_E_x_cond_p;           // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_HR_E_x_cond_d;           // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_HR_E_x_autotrig;         // Plot Energy vs position of fragments FF top auto triggers
    TH2 *h_HR_map_cond_p;           // Plot Energy vs position of fragments FF top conditionned with proton event
    TH2 *h_HR_map_cond_d;           // Plot Energy vs position of fragments FF top conditionned with deuteron event
    TH2 *h_HR_map_autotrig;         // Plot Energy vs position of fragments FF top auto triggers       
  
  
    // Histograms for FFside tests in May
    TH2 *BB29_FFside_V1_V2;        // Energy ADC value for vertical strip 1 vs vertical strip 2
    TH2 *BB29_FFside_V2_V3;        // Energy ADC value for vertical strip 2 vs vertical strip 3
    TH2 *BB29_FFside_V60_V61;      // Energy ADC value for vertical strip 60 vs vertical strip 61
    TH2 *BB29_FFside_V61_V62;      // Energy ADC value for vertical strip 61 vs vertical strip 62
    TH2 *BB29_FFside_V118_V119;    // Energy ADC value for vertical strip 118 vs vertical strip 119
    TH2 *BB29_FFside_V119_V120;    // Energy ADC value for vertical strip 119 vs vertical strip 120
    
    TH2 *BB29_FFside_V1_allH;      // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_FFside_V2_allH;      // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_FFside_V60_allH;     // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_FFside_V61_allH;     // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_FFside_V119_allH;    // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_FFside_V120_allH;    // Individual vertical strip energy vs any horitontal strip
    
    TH2 *BB29_FFside_DT_V1; // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_FFside_DT_V2; // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_FFside_DT_V60; // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_FFside_DT_V61; // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_FFside_DT_V119; // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_FFside_DT_V120; // Individual vertical strip energy vs deltaT fission side V

    TH2 *BB29_FFside_DT_H1; // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_FFside_DT_H2; // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_FFside_DT_H20; // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_FFside_DT_H21; // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_FFside_DT_H39; // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_FFside_DT_H40; // Individual vertical strip energy vs deltaT fission side H

    // Histograms for HR tests in May
    TH2 *BB29_HR_V1_V2;        // Energy ADC value for vertical strip 1 vs vertical strip 2
    TH2 *BB29_HR_V2_V3;        // Energy ADC value for vertical strip 2 vs vertical strip 3
    TH2 *BB29_HR_V60_V61;      // Energy ADC value for vertical strip 60 vs vertical strip 61
    TH2 *BB29_HR_V61_V62;      // Energy ADC value for vertical strip 61 vs vertical strip 62
    TH2 *BB29_HR_V118_V119;    // Energy ADC value for vertical strip 118 vs vertical strip 119
    TH2 *BB29_HR_V119_V120;    // Energy ADC value for vertical strip 119 vs vertical strip 120
    
    TH2 *BB29_HR_V1_allH;      // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_HR_V2_allH;      // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_HR_V60_allH;     // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_HR_V61_allH;     // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_HR_V119_allH;    // Individual vertical strip energy vs any horitontal strip
    TH2 *BB29_HR_V120_allH;    // Individual vertical strip energy vs any horitontal strip
    
    TH2 *BB29_HR_DT_V1;       // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_HR_DT_V2;       // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_HR_DT_V60;      // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_HR_DT_V61;      // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_HR_DT_V119;      // Individual vertical strip energy vs deltaT fission side V
    TH2 *BB29_HR_DT_V120;         // Individual vertical strip energy vs deltaT fission side V

    TH2 *BB29_HR_DT_H1;       // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_HR_DT_H2;       // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_HR_DT_H20;       // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_HR_DT_H21;      // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_HR_DT_H39;      // Individual vertical strip energy vs deltaT fission side H
    TH2 *BB29_HR_DT_H40;      // Individual vertical strip energy vs deltaT fission side H



  

  /** DeltaT detector vs detector **/
  TH2 *DTtel_ADCFFtop_V1;      // Delta time telescope vs energy (ch) for vertical strips FF top
  TH2 *DTtel_ADCFFtop_V8;      // Delta time telescope vs energy (ch) for vertical strips FF top
  TH2 *DTtel_ADCFFbot_V1;      // Delta time telescope vs energy (ch) for vertical strips FF bot
  TH2 *DTtel_ADCFFbot_V8;      // Delta time telescope vs energy (ch) for vertical strips FF bot
  TH2 *DTtel_ADCFFside_V1;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCFFside_V60;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCFFside_H1;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCFFside_H20;      // Delta time telescope vs energy (ch) for vertical strips FF side
  
  TH2 *DTtel_ADCHR_V1;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCHR_V60;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCHR_H1;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCHR_H20;      // Delta time telescope vs energy (ch) for vertical strips FF side
  
  
  /** Multiplicity Spectra   **/
  TH1 *h_Mult_BB8_V;
  TH1 *h_Mult_BB8_H;
  TH1 *h_Mult_BB29_V;
  TH1 *h_Mult_BB29_H;
 


  
  
  /** Mapping Telescope - BB29 **/


  TH2 *h_BB8_Map_Mult;
  TH2 *h_Map_BB29_Mult;
  
  TH2 *h_cond_Map_BB29;  
  TH2 *h_cond_Map_BB29_DE;  
  TH2 *h_cond_Map_BB29_DT;  
  
  /** Mapping Fission detectors **/
  TH2 *h_BB36_FFtop_Map;
  TH2 *h_BB36_FFbot_Map;
  TH2 *h_BB36_FFside_Map;
  

  /* Control Histograms */


  TH2 *BB29_ADC_V_strip;
  TH2 *BB29_ADC_H_strip;


  //*******  TARGET OFF ***********//


  /** Mapping Telescope - BB29 **/
  TH2 *h_BB8_Map_TO;
  TH2 *h_Map_BB29_TO;
  TH2 *h_cond_Map_BB29_DT_TO;  
 
   /* Control Histograms */

  TH2 *BB8_ADC_V_strip_TO;
  TH2 *BB8_ADC_H_strip_TO;
  TH2 *BB29_ADC_V_strip_TO;
  TH2 *BB29_ADC_H_strip_TO;
  TH2 *MSXO4_TO;

  /* DT_histogram */

  TH1 *h_DT_telescope_TO;
  TH1 *h_DT_BB29_V_TO;
  TH1 *h_DT_BB29_H_TO;

  //Excitation Energy Calculation Plots

  TH1* h_Ex;
  TH2* h_Kinematics_plot;
    
  
  

  ClassDef(TNectarHistograms, 1)
};
#endif
