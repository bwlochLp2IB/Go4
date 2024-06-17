// written by macro saveparam.C at Mon Sep 13 14:55:46 2021
// JAM feel free to modify this setup manually :)
void set_NectarRawParam()
{
#ifndef __GO4ANAMACRO__
   std::cout << "Macro set_NectarRawParam can execute only in analysis" << std::endl;
   return;
#endif
   TNectarRawParam* param0 = (TNectarRawParam*) go4->GetParameter("NectarRawParam","TNectarRawParam");

   if (param0==0) {
      TGo4Log::Error("Could not find parameter NectarRawParam of class TNectarRawParam");
      return;
   }

   TGo4Log::Info("Set parameter NectarRawParam from script set_NectarRawParam.C");


   param0->fUseSetup2024=kTRUE; // JAM 5-2024: set this to kFALSE for processing old data with V830 and V785 modules

   param0->fVMMR_BoardID[0] =  0; // this is board ID send by frontends
   param0->fVMMR_BoardID[1] = 1; // -1 means no board is expected
   param0->fVMMR_BoardID[2] = -1;
   param0->fVMMR_BoardID[3] = -1;
   param0->fVMMR_BoardID[4] = -1;
   param0->fVMMR_BoardID[5] = -1;
   param0->fVMMR_BoardID[6] = -1;
   param0->fVMMR_BoardID[7] = -1;
   param0->fVMMR_BoardID[8] = -1;
   param0->fVMMR_BoardID[9] = -1;
   
   
   param0->fMDPP_BoardID[0] = 0; // this is board ID send by frontends
   param0->fMDPP_BoardID[1] = -1;
   param0->fMDPP_BoardID[2] = -1;
   param0->fMDPP_BoardID[3] = -1;
   param0->fMDPP_BoardID[4] = -1;
   param0->fMDPP_BoardID[5] = -1;
   param0->fMDPP_BoardID[6] = -1;
   param0->fMDPP_BoardID[7] = -1;
   param0->fMDPP_BoardID[8] = -1;
   param0->fMDPP_BoardID[9] = -1;
   
   param0->fMDPP_ReferenceChannel[0] = 15; // TDC reference channel of this board
   param0->fMDPP_ReferenceChannel[1] = -1;
   param0->fMDPP_ReferenceChannel[2] = -1;
   param0->fMDPP_ReferenceChannel[3] = -1;
   param0->fMDPP_ReferenceChannel[4] = -1;
   param0->fMDPP_ReferenceChannel[5] = -1;
   param0->fMDPP_ReferenceChannel[6] = -1;
   param0->fMDPP_ReferenceChannel[7] = -1;
   param0->fMDPP_ReferenceChannel[8] = -1;
   param0->fMDPP_ReferenceChannel[9] = -1;
   
   param0->fMDPP_is16Channels[0] = kTRUE; // specify if we have mdpp-16 (true) or mdpp-32 (false)
   param0->fMDPP_is16Channels[1] = kFALSE;
   param0->fMDPP_is16Channels[2] = kFALSE;
   param0->fMDPP_is16Channels[3] = kFALSE;
   param0->fMDPP_is16Channels[4] = kFALSE;
   param0->fMDPP_is16Channels[5] = kFALSE;
   param0->fMDPP_is16Channels[6] = kFALSE;
   param0->fMDPP_is16Channels[7] = kFALSE;
   param0->fMDPP_is16Channels[8] = kFALSE;
   param0->fMDPP_is16Channels[9] = kFALSE;

   /*** THRESHOLD PARAMETERS**/
   param0->BB8_H_threshold = 200;   //** Modified april 2024
   param0->BB8_V_threshold = 200;
   param0->BB29_H_threshold = 200;
   param0->BB29_V_threshold = 200;

   param0->BB36FF_H_threshold = 200;   
   param0->BB36FF_V_threshold = 200;
   param0->BB29FF_H_threshold = 200;
   param0->BB29FF_V_threshold = 200;   


   param0->MSX04_1_threshold = 200;
   param0->MSX04_2_threshold = 200;
   param0->MSX04_3_threshold = 200;
   param0->MSX04_4_threshold = 200;
   param0->MSX04_5_threshold = 200;
   param0->MSX04_6_threshold = 200;

    
   param0->DT_min = 140; 
   param0->DT_max = 240; 


   //**** PARAMETERS FOR Ex energy calculation  ****//

   param0-> E_Pb = 6240;
   param0-> M_Pb = 193729.0;
   param0-> M_H  = 938.27;
   param0-> tfix = 60;
   param0-> A_Pos[0] = 0;
   param0-> A_Pos[1] = -9.375;
   param0-> A_Pos[2] = -8.125; 
   param0-> A_Pos[3] = -6.875;
   param0-> A_Pos[4] = -5.625;
   param0-> A_Pos[5] = -4.375;
   param0-> A_Pos[6] = -3.125;
   param0-> A_Pos[7] = -1.875;
   param0-> A_Pos[8] = -0.625;
   param0-> A_Pos[9] = 0.625;
   param0-> A_Pos[10] = 1.875;
   param0-> A_Pos[11] = 3.125;
   param0-> A_Pos[12] = 4.375;
   param0-> A_Pos[13] = 5.625;
   param0-> A_Pos[14] = 6.875;
   param0-> A_Pos[15] = 8.125;
   param0-> A_Pos[16] = 9.375;
  
         
   param0-> Beam_shift = 0;
   
   param0->fSlowMotion = kFALSE; // stop go4 analysis after each event if true

}
