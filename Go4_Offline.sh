#!/bin/bash 

##############################################################
#  FILE BASH - CONVERSION lmd - root - Launch Offline Analysis
##############################################################

cd  /cvmfs/eel.gsi.de/bin/
. /go4login

### SET THE PATH TO THE lmd and go4 lib file directory

direct_lmd="/u/litv-exp/e146"
direct_go4="/u/litv-exp/e146/Go4_E146_Final"

### SET THE PATH TO THE root and Offline Analysis

direct_root="/u/litv-exp/e146"
#direct_offline=""

## Files Conversion and store

for i in {1..1}

go4analysis ${direct_go4}/libGo4UserAnalysis.so -file Prova_$i.lmd -step raw -step Monitoring -store ${direct_root}/$i.root

done



