#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class TNectarBoardDisplay+;
#pragma link C++ class TMdppDisplay+;
#pragma link C++ class TVmmrDisplay+;
#pragma link C++ class TVmmrSlaveDisplay+;

#pragma link C++ class std::vector<TVmmrSlaveDisplay*>;

#pragma link C++ class TMdppMsg+;
#pragma link C++ class TMdppAdcData+;
#pragma link C++ class TMdppTdcData+;
#pragma link C++ class TVmmrMsg+;
#pragma link C++ class TVmmrAdcData+;

#pragma link C++ class TNectarBoard+;

#pragma link C++ class TMdppBoard+;
#pragma link C++ class std::vector<TMdppAdcData*>+;
#pragma link C++ class std::vector<TMdppTdcData*>+;

#pragma link C++ class TVmmrBoard+;
#pragma link C++ class TVmmrSlave+;
#pragma link C++ class std::vector<TVmmrSlave*>+;
#pragma link C++ class std::vector<TVmmrAdcData*>+;

#pragma link C++ class TNectarRawEvent+;
#pragma link C++ class TNectarRawProc+;
#pragma link C++ class TNectarRawParam+;

//SECOND STEP ANALYSIS 
#pragma link C++ class TNectarProfileProc+;
#pragma link C++ class TNectarProfileEvent+;
//#pragma link C++ class TNectarBB8+;
//#pragma link C++ class TNectarMSX04+;
#pragma link C++ class TNectarTelescope+;

//THIRD STEP ANALYSIS (26/04)
#pragma link C++ class TNectarMonitoringEvent+; 
#pragma link C++ class TNectarDetectors+; 
#pragma link C++ class TNectarHistograms+;
#pragma link C++ class TNectarMonitoringProc+;

//UP TO HERE

#pragma link C++ class TNectarAnalysis+;


#endif



