#ifndef TNectarRawParam_H
#define TNectarRawParam_H

#include "TGo4Parameter.h"
#include "TNectarRawEvent.h"



class TNectarRawParam : public TGo4Parameter {
   public:

      TNectarRawParam(const char* name = 0);

      virtual Bool_t UpdateFrom(TGo4Parameter *);

      Int_t fVMMR_BoardID[VMMR_MAXBOARDS]; // mapping of VMMR board numbers to (slot?) indices
      Int_t fMDPP_BoardID[MDPP_MAXBOARDS]; // mapping of MDPP board numbers to (slot?) indices

      Int_t fMDPP_ReferenceChannel[MDPP_MAXBOARDS]; // TDC reference channel for DeltaT of each MDPP board
      Bool_t fMDPP_is16Channels[MDPP_MAXBOARDS]; // true if MDPP of that index has 16 channels. otherwise assume 32 channels

      Bool_t fSlowMotion; // if true than only process one MBS event and stop.

      /* initial mapping of board id to sfp/ gosip device cabling*/
      void InitBoardMapping();

      /* copy board configuration from this parameter to static event members
       * before initialization. Usually this is done in UpdateFrom*/
      Bool_t SetConfigBoards();

      /* Evaluate the index in MDPP array for given module id. returns -1 if no such id configured*/
      Int_t GetMDPPArrayindex(Int_t uniqueid);

      Double_t BB8_H_threshold;  //threshold - Horizontal Strips BB8
      Double_t BB8_V_threshold;  //threshold - Vertical Strips BB8
      Double_t BB29_H_threshold; //threshold - Horizontal Strips BB29
      Double_t BB29_V_threshold; //threshold - Vertical Strips BB29
      Double_t MSX04_1_threshold, MSX04_2_threshold;  //thershold - MSX04 
      Double_t MSX04_7_threshold, MSX04_8_threshold;  //thershold - MSX04 
      Double_t MSX04_9_threshold, MSX04_10_threshold;  //thershold - MSX04 
      
      Double_t DT_min, DT_max;  //Range - HR selection in DT	

      //**** PARAMETERS FOR Ex energy calculation  ****//

      Double_t E_Pb, M_Pb, M_H, tfix, Beam_shift;
      Double_t A_Pos[17];
      
   private:



   ClassDef(TNectarRawParam,3)
};

#endif // TNectarRawParam_H
