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
  TH1 *BB8_V_S[16];         // Vertical strip histograms
  TH1 *BB8_H_S[16];         // Horizontal strip histograms
  
    // Tests March 2024
  TH2 *BB8_V8_H8;           // Energy ADC value for vertical strip 8 vs horizontal strip 8
  TH2 *BB8_V8_H8_mult1;           // Energy ADC value for vertical strip 8 vs horizontal strip 8
  TH2 *BB8_DT_E_V[16];      // Delta time vs energy (ch) for vertical strips
  TH2 *BB8_1V_allH[16];     // Individual vertical strip energy vs any horitontal strip
  TH2 *BB8_adj_V[15];       // Energy of adjacent vertical strips
  TH2 *BB8_adj_H[15];       // Energy of adjacent horizontal strips
  
  /** MSX04 **/
  TH1 *h_ADC_MSX04_1;       // first stack
  TH1 *h_ADC_MSX04_2;       // first stack
  TH1 *h_ADC_MSX04_7;       // second stack
  TH1 *h_ADC_MSX04_8;       // second stack
  TH1 *h_ADC_MSX04_9;       // third stack
  TH1 *h_ADC_MSX04_10;      // third stack
  
  TH1 *h_DT_telescope;      // Telescope deltaTime
  
  //--- Heavy residue ---//
  TH1* BB29_V_S[128];
  TH1* BB29_H_S[64];
  TH1 *h_DT_BB29_V;          // HR delta time V strips
  TH1 *h_DT_BB29_H;          // HR delta time H strips  
  TH2 *h_HR_Map;
  
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

  TH2 *BB29_HR_ADC_V_STRIP; // Control ADC V strips
  TH2 *BB29_HR_ADC_H_STRIP; // Control ADC H strips
  
  //--- Fission ---//
  /* TOP */
  
  TH1 *BB36_FFtop_V_S[16];      // Top detector BB36
  TH1 *BB36_FFtop_H_S[16];      // Top detector BB36
  TH1 *h_DT_BB36_top;
  TH2 *h_FFtop_Map;             // Mapping fission top
  TH2 *BB36_FFtop_ADC_V_STRIP; // Control ADC V strips
  TH2 *BB36_FFtop_ADC_H_STRIP; // Control ADC H strips
  TH2 *BB36_FFtop_DT_E_V[16];      // Delta time vs energy (ch) for vertical strips
  
  /* BOTTOM */
  TH1 *BB36_FFbot_V_S[16];  // Bottom detector BB36
  TH1 *BB36_FFbot_H_S[16];  // Bottom detector BB36
  TH1 *h_DT_BB36_bot;
  TH2 *h_FFbot_Map;
  TH2 *BB36_FFbot_ADC_V_STRIP; // Control ADC V strips
  TH2 *BB36_FFbot_ADC_H_STRIP; // Control ADC H strips
  TH2 *BB36_FFbot_DT_E_V[16];      // Delta time vs energy (ch) for vertical strips
  
  /* SIDE */
  TH1 *BB29_FFside_V_S[128];  // Bottom detector BB36
  TH1 *BB29_FFside_H_S[64];  // Bottom detector BB36
  TH1 *h_DT_BB29_side_V;
  TH1 *h_DT_BB29_side_H;
  TH2 *h_FFside_Map;
  
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

  TH2 *BB29_FFside_ADC_V_STRIP; // Control ADC V strips
  TH2 *BB29_FFside_ADC_H_STRIP; // Control ADC H strips
  

  /** DeltaT detector vs detector **/
  TH2 *DTtel_ADCFFtop_V1;      // Delta time telescope vs energy (ch) for vertical strips FF top
  TH2 *DTtel_ADCFFtop_V8;      // Delta time telescope vs energy (ch) for vertical strips FF top
  TH2 *DTtel_ADCFFbot_V1;      // Delta time telescope vs energy (ch) for vertical strips FF bot
  TH2 *DTtel_ADCFFbot_V8;      // Delta time telescope vs energy (ch) for vertical strips FF bot
  TH2 *DTtel_ADCFFside_V1;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCFFside_V60;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCFFside_H1;      // Delta time telescope vs energy (ch) for vertical strips FF side
  TH2 *DTtel_ADCFFside_H20;      // Delta time telescope vs energy (ch) for vertical strips FF side
  
  
  /** Multiplicity Spectra   **/
  TH1 *h_Mult_BB8_V;
  TH1 *h_Mult_BB8_H;
  TH1 *h_Mult_BB29_V;
  TH1 *h_Mult_BB29_H;
 
  /** DE vs E (Online_Analysis) **/
  TH2 *h_DE_E_1[16]; 
  TH2 *h_DE_E_2[16]; 
  TH2 *h_DE_E_7[16]; 
  TH2 *h_DE_E_8[16]; 
  TH2 *h_DE_E_9[16]; 
  TH2 *h_DE_E_10[16]; 
  TH2 *h_DE_E_tot_ch[16];
  TH2 *h_DE_E_tot_E[16];
  TH2 *h_DE_E_tot_keV;
  TH2 *h_DE_E_tot_keV_cond;
  TH2 *h_V_E_tot;
  TH2 *h_V_ch_tot;
  TH2 *h_DE_E_tot_Mult;

  // Energy Calibration Plots

  TH2 *h_DE_E_1_Calib;
  TH2 *h_DE_E_2_Calib;
  TH2 *h_DE_E_7_Calib;
  TH2 *h_DE_E_8_Calib;
  TH2 *h_DE_E_9_Calib;
  TH2 *h_DE_E_10_Calib;

  
  
  /** Mapping Telescope - BB29 **/
  TH2 *h_BB8_Map;

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

  TH2 *BB8_ADC_V_strip;
  TH2 *BB8_ADC_H_strip;
  TH2 *BB29_ADC_V_strip;
  TH2 *BB29_ADC_H_strip;
  TH2 *MSXO4;

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
