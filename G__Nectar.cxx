// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Nectar
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "./TNectarRawProc.h"
#include "./TNectarMonitoringEvent.h"
#include "./TNectarAnalysis.h"
#include "./TNectarMonitoringProc.h"
#include "./TNectarRawParam.h"
#include "./TNectarMonitorigEvent.h"
#include "./TNectarProfileProc.h"
#include "./TNectarMonitoringDisplay.h"
#include "./libGo4UserAnalysis815aa6ab56_dictContent.h"
#include "./TNectarRawEvent.h"
#include "./TNectarDisplay.h"
#include "./libGo4UserAnalysise7c62a8a82_dictUmbrella.h"
#include "./TNectarProfileEvent.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TNectarBoard(void *p = 0);
   static void *newArray_TNectarBoard(Long_t size, void *p);
   static void delete_TNectarBoard(void *p);
   static void deleteArray_TNectarBoard(void *p);
   static void destruct_TNectarBoard(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarBoard*)
   {
      ::TNectarBoard *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarBoard >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarBoard", ::TNectarBoard::Class_Version(), "TNectarRawEvent.h", 73,
                  typeid(::TNectarBoard), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarBoard::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarBoard) );
      instance.SetNew(&new_TNectarBoard);
      instance.SetNewArray(&newArray_TNectarBoard);
      instance.SetDelete(&delete_TNectarBoard);
      instance.SetDeleteArray(&deleteArray_TNectarBoard);
      instance.SetDestructor(&destruct_TNectarBoard);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarBoard*)
   {
      return GenerateInitInstanceLocal((::TNectarBoard*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarBoard*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *TMdppMsg_Dictionary();
   static void TMdppMsg_TClassManip(TClass*);
   static void *new_TMdppMsg(void *p = 0);
   static void *newArray_TMdppMsg(Long_t size, void *p);
   static void delete_TMdppMsg(void *p);
   static void deleteArray_TMdppMsg(void *p);
   static void destruct_TMdppMsg(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMdppMsg*)
   {
      ::TMdppMsg *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TMdppMsg));
      static ::ROOT::TGenericClassInfo 
         instance("TMdppMsg", "TNectarRawEvent.h", 114,
                  typeid(::TMdppMsg), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TMdppMsg_Dictionary, isa_proxy, 4,
                  sizeof(::TMdppMsg) );
      instance.SetNew(&new_TMdppMsg);
      instance.SetNewArray(&newArray_TMdppMsg);
      instance.SetDelete(&delete_TMdppMsg);
      instance.SetDeleteArray(&deleteArray_TMdppMsg);
      instance.SetDestructor(&destruct_TMdppMsg);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMdppMsg*)
   {
      return GenerateInitInstanceLocal((::TMdppMsg*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMdppMsg*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TMdppMsg_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TMdppMsg*)0x0)->GetClass();
      TMdppMsg_TClassManip(theClass);
   return theClass;
   }

   static void TMdppMsg_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TMdppAdcData_Dictionary();
   static void TMdppAdcData_TClassManip(TClass*);
   static void *new_TMdppAdcData(void *p = 0);
   static void *newArray_TMdppAdcData(Long_t size, void *p);
   static void delete_TMdppAdcData(void *p);
   static void deleteArray_TMdppAdcData(void *p);
   static void destruct_TMdppAdcData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMdppAdcData*)
   {
      ::TMdppAdcData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TMdppAdcData));
      static ::ROOT::TGenericClassInfo 
         instance("TMdppAdcData", "TNectarRawEvent.h", 142,
                  typeid(::TMdppAdcData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TMdppAdcData_Dictionary, isa_proxy, 4,
                  sizeof(::TMdppAdcData) );
      instance.SetNew(&new_TMdppAdcData);
      instance.SetNewArray(&newArray_TMdppAdcData);
      instance.SetDelete(&delete_TMdppAdcData);
      instance.SetDeleteArray(&deleteArray_TMdppAdcData);
      instance.SetDestructor(&destruct_TMdppAdcData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMdppAdcData*)
   {
      return GenerateInitInstanceLocal((::TMdppAdcData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMdppAdcData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TMdppAdcData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TMdppAdcData*)0x0)->GetClass();
      TMdppAdcData_TClassManip(theClass);
   return theClass;
   }

   static void TMdppAdcData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TMdppTdcData_Dictionary();
   static void TMdppTdcData_TClassManip(TClass*);
   static void *new_TMdppTdcData(void *p = 0);
   static void *newArray_TMdppTdcData(Long_t size, void *p);
   static void delete_TMdppTdcData(void *p);
   static void deleteArray_TMdppTdcData(void *p);
   static void destruct_TMdppTdcData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMdppTdcData*)
   {
      ::TMdppTdcData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TMdppTdcData));
      static ::ROOT::TGenericClassInfo 
         instance("TMdppTdcData", "TNectarRawEvent.h", 152,
                  typeid(::TMdppTdcData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TMdppTdcData_Dictionary, isa_proxy, 4,
                  sizeof(::TMdppTdcData) );
      instance.SetNew(&new_TMdppTdcData);
      instance.SetNewArray(&newArray_TMdppTdcData);
      instance.SetDelete(&delete_TMdppTdcData);
      instance.SetDeleteArray(&deleteArray_TMdppTdcData);
      instance.SetDestructor(&destruct_TMdppTdcData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMdppTdcData*)
   {
      return GenerateInitInstanceLocal((::TMdppTdcData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMdppTdcData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TMdppTdcData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TMdppTdcData*)0x0)->GetClass();
      TMdppTdcData_TClassManip(theClass);
   return theClass;
   }

   static void TMdppTdcData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_TMdppBoard(void *p = 0);
   static void *newArray_TMdppBoard(Long_t size, void *p);
   static void delete_TMdppBoard(void *p);
   static void deleteArray_TMdppBoard(void *p);
   static void destruct_TMdppBoard(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMdppBoard*)
   {
      ::TMdppBoard *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMdppBoard >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMdppBoard", ::TMdppBoard::Class_Version(), "TNectarRawEvent.h", 164,
                  typeid(::TMdppBoard), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMdppBoard::Dictionary, isa_proxy, 4,
                  sizeof(::TMdppBoard) );
      instance.SetNew(&new_TMdppBoard);
      instance.SetNewArray(&newArray_TMdppBoard);
      instance.SetDelete(&delete_TMdppBoard);
      instance.SetDeleteArray(&deleteArray_TMdppBoard);
      instance.SetDestructor(&destruct_TMdppBoard);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMdppBoard*)
   {
      return GenerateInitInstanceLocal((::TMdppBoard*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMdppBoard*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *TVmmrMsg_Dictionary();
   static void TVmmrMsg_TClassManip(TClass*);
   static void *new_TVmmrMsg(void *p = 0);
   static void *newArray_TVmmrMsg(Long_t size, void *p);
   static void delete_TVmmrMsg(void *p);
   static void deleteArray_TVmmrMsg(void *p);
   static void destruct_TVmmrMsg(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVmmrMsg*)
   {
      ::TVmmrMsg *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TVmmrMsg));
      static ::ROOT::TGenericClassInfo 
         instance("TVmmrMsg", "TNectarRawEvent.h", 238,
                  typeid(::TVmmrMsg), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TVmmrMsg_Dictionary, isa_proxy, 4,
                  sizeof(::TVmmrMsg) );
      instance.SetNew(&new_TVmmrMsg);
      instance.SetNewArray(&newArray_TVmmrMsg);
      instance.SetDelete(&delete_TVmmrMsg);
      instance.SetDeleteArray(&deleteArray_TVmmrMsg);
      instance.SetDestructor(&destruct_TVmmrMsg);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVmmrMsg*)
   {
      return GenerateInitInstanceLocal((::TVmmrMsg*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVmmrMsg*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TVmmrMsg_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TVmmrMsg*)0x0)->GetClass();
      TVmmrMsg_TClassManip(theClass);
   return theClass;
   }

   static void TVmmrMsg_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TVmmrAdcData_Dictionary();
   static void TVmmrAdcData_TClassManip(TClass*);
   static void *new_TVmmrAdcData(void *p = 0);
   static void *newArray_TVmmrAdcData(Long_t size, void *p);
   static void delete_TVmmrAdcData(void *p);
   static void deleteArray_TVmmrAdcData(void *p);
   static void destruct_TVmmrAdcData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVmmrAdcData*)
   {
      ::TVmmrAdcData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TVmmrAdcData));
      static ::ROOT::TGenericClassInfo 
         instance("TVmmrAdcData", "TNectarRawEvent.h", 268,
                  typeid(::TVmmrAdcData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TVmmrAdcData_Dictionary, isa_proxy, 4,
                  sizeof(::TVmmrAdcData) );
      instance.SetNew(&new_TVmmrAdcData);
      instance.SetNewArray(&newArray_TVmmrAdcData);
      instance.SetDelete(&delete_TVmmrAdcData);
      instance.SetDeleteArray(&deleteArray_TVmmrAdcData);
      instance.SetDestructor(&destruct_TVmmrAdcData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVmmrAdcData*)
   {
      return GenerateInitInstanceLocal((::TVmmrAdcData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVmmrAdcData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TVmmrAdcData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TVmmrAdcData*)0x0)->GetClass();
      TVmmrAdcData_TClassManip(theClass);
   return theClass;
   }

   static void TVmmrAdcData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_TVmmrSlave(void *p = 0);
   static void *newArray_TVmmrSlave(Long_t size, void *p);
   static void delete_TVmmrSlave(void *p);
   static void deleteArray_TVmmrSlave(void *p);
   static void destruct_TVmmrSlave(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVmmrSlave*)
   {
      ::TVmmrSlave *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVmmrSlave >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVmmrSlave", ::TVmmrSlave::Class_Version(), "TNectarRawEvent.h", 284,
                  typeid(::TVmmrSlave), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVmmrSlave::Dictionary, isa_proxy, 4,
                  sizeof(::TVmmrSlave) );
      instance.SetNew(&new_TVmmrSlave);
      instance.SetNewArray(&newArray_TVmmrSlave);
      instance.SetDelete(&delete_TVmmrSlave);
      instance.SetDeleteArray(&deleteArray_TVmmrSlave);
      instance.SetDestructor(&destruct_TVmmrSlave);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVmmrSlave*)
   {
      return GenerateInitInstanceLocal((::TVmmrSlave*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVmmrSlave*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TVmmrBoard(void *p = 0);
   static void *newArray_TVmmrBoard(Long_t size, void *p);
   static void delete_TVmmrBoard(void *p);
   static void deleteArray_TVmmrBoard(void *p);
   static void destruct_TVmmrBoard(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVmmrBoard*)
   {
      ::TVmmrBoard *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVmmrBoard >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVmmrBoard", ::TVmmrBoard::Class_Version(), "TNectarRawEvent.h", 317,
                  typeid(::TVmmrBoard), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVmmrBoard::Dictionary, isa_proxy, 4,
                  sizeof(::TVmmrBoard) );
      instance.SetNew(&new_TVmmrBoard);
      instance.SetNewArray(&newArray_TVmmrBoard);
      instance.SetDelete(&delete_TVmmrBoard);
      instance.SetDeleteArray(&deleteArray_TVmmrBoard);
      instance.SetDestructor(&destruct_TVmmrBoard);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVmmrBoard*)
   {
      return GenerateInitInstanceLocal((::TVmmrBoard*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVmmrBoard*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarRawEvent(void *p = 0);
   static void *newArray_TNectarRawEvent(Long_t size, void *p);
   static void delete_TNectarRawEvent(void *p);
   static void deleteArray_TNectarRawEvent(void *p);
   static void destruct_TNectarRawEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarRawEvent*)
   {
      ::TNectarRawEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarRawEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarRawEvent", ::TNectarRawEvent::Class_Version(), "TNectarRawEvent.h", 355,
                  typeid(::TNectarRawEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarRawEvent::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarRawEvent) );
      instance.SetNew(&new_TNectarRawEvent);
      instance.SetNewArray(&newArray_TNectarRawEvent);
      instance.SetDelete(&delete_TNectarRawEvent);
      instance.SetDeleteArray(&deleteArray_TNectarRawEvent);
      instance.SetDestructor(&destruct_TNectarRawEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarRawEvent*)
   {
      return GenerateInitInstanceLocal((::TNectarRawEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarRawEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarBoardDisplay(void *p = 0);
   static void *newArray_TNectarBoardDisplay(Long_t size, void *p);
   static void delete_TNectarBoardDisplay(void *p);
   static void deleteArray_TNectarBoardDisplay(void *p);
   static void destruct_TNectarBoardDisplay(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarBoardDisplay*)
   {
      ::TNectarBoardDisplay *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarBoardDisplay >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarBoardDisplay", ::TNectarBoardDisplay::Class_Version(), "TNectarDisplay.h", 25,
                  typeid(::TNectarBoardDisplay), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarBoardDisplay::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarBoardDisplay) );
      instance.SetNew(&new_TNectarBoardDisplay);
      instance.SetNewArray(&newArray_TNectarBoardDisplay);
      instance.SetDelete(&delete_TNectarBoardDisplay);
      instance.SetDeleteArray(&deleteArray_TNectarBoardDisplay);
      instance.SetDestructor(&destruct_TNectarBoardDisplay);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarBoardDisplay*)
   {
      return GenerateInitInstanceLocal((::TNectarBoardDisplay*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarBoardDisplay*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TMdppDisplay(void *p = 0);
   static void *newArray_TMdppDisplay(Long_t size, void *p);
   static void delete_TMdppDisplay(void *p);
   static void deleteArray_TMdppDisplay(void *p);
   static void destruct_TMdppDisplay(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TMdppDisplay*)
   {
      ::TMdppDisplay *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TMdppDisplay >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TMdppDisplay", ::TMdppDisplay::Class_Version(), "TNectarDisplay.h", 63,
                  typeid(::TMdppDisplay), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TMdppDisplay::Dictionary, isa_proxy, 4,
                  sizeof(::TMdppDisplay) );
      instance.SetNew(&new_TMdppDisplay);
      instance.SetNewArray(&newArray_TMdppDisplay);
      instance.SetDelete(&delete_TMdppDisplay);
      instance.SetDeleteArray(&deleteArray_TMdppDisplay);
      instance.SetDestructor(&destruct_TMdppDisplay);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TMdppDisplay*)
   {
      return GenerateInitInstanceLocal((::TMdppDisplay*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TMdppDisplay*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TVmmrSlaveDisplay(void *p = 0);
   static void *newArray_TVmmrSlaveDisplay(Long_t size, void *p);
   static void delete_TVmmrSlaveDisplay(void *p);
   static void deleteArray_TVmmrSlaveDisplay(void *p);
   static void destruct_TVmmrSlaveDisplay(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVmmrSlaveDisplay*)
   {
      ::TVmmrSlaveDisplay *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVmmrSlaveDisplay >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVmmrSlaveDisplay", ::TVmmrSlaveDisplay::Class_Version(), "TNectarDisplay.h", 111,
                  typeid(::TVmmrSlaveDisplay), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVmmrSlaveDisplay::Dictionary, isa_proxy, 4,
                  sizeof(::TVmmrSlaveDisplay) );
      instance.SetNew(&new_TVmmrSlaveDisplay);
      instance.SetNewArray(&newArray_TVmmrSlaveDisplay);
      instance.SetDelete(&delete_TVmmrSlaveDisplay);
      instance.SetDeleteArray(&deleteArray_TVmmrSlaveDisplay);
      instance.SetDestructor(&destruct_TVmmrSlaveDisplay);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVmmrSlaveDisplay*)
   {
      return GenerateInitInstanceLocal((::TVmmrSlaveDisplay*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVmmrSlaveDisplay*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TVmmrDisplay(void *p = 0);
   static void *newArray_TVmmrDisplay(Long_t size, void *p);
   static void delete_TVmmrDisplay(void *p);
   static void deleteArray_TVmmrDisplay(void *p);
   static void destruct_TVmmrDisplay(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TVmmrDisplay*)
   {
      ::TVmmrDisplay *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TVmmrDisplay >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TVmmrDisplay", ::TVmmrDisplay::Class_Version(), "TNectarDisplay.h", 155,
                  typeid(::TVmmrDisplay), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TVmmrDisplay::Dictionary, isa_proxy, 4,
                  sizeof(::TVmmrDisplay) );
      instance.SetNew(&new_TVmmrDisplay);
      instance.SetNewArray(&newArray_TVmmrDisplay);
      instance.SetDelete(&delete_TVmmrDisplay);
      instance.SetDeleteArray(&deleteArray_TVmmrDisplay);
      instance.SetDestructor(&destruct_TVmmrDisplay);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TVmmrDisplay*)
   {
      return GenerateInitInstanceLocal((::TVmmrDisplay*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TVmmrDisplay*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarRawProc(void *p = 0);
   static void *newArray_TNectarRawProc(Long_t size, void *p);
   static void delete_TNectarRawProc(void *p);
   static void deleteArray_TNectarRawProc(void *p);
   static void destruct_TNectarRawProc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarRawProc*)
   {
      ::TNectarRawProc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarRawProc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarRawProc", ::TNectarRawProc::Class_Version(), "TNectarRawProc.h", 23,
                  typeid(::TNectarRawProc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarRawProc::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarRawProc) );
      instance.SetNew(&new_TNectarRawProc);
      instance.SetNewArray(&newArray_TNectarRawProc);
      instance.SetDelete(&delete_TNectarRawProc);
      instance.SetDeleteArray(&deleteArray_TNectarRawProc);
      instance.SetDestructor(&destruct_TNectarRawProc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarRawProc*)
   {
      return GenerateInitInstanceLocal((::TNectarRawProc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarRawProc*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarDetectors(void *p = 0);
   static void *newArray_TNectarDetectors(Long_t size, void *p);
   static void delete_TNectarDetectors(void *p);
   static void deleteArray_TNectarDetectors(void *p);
   static void destruct_TNectarDetectors(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarDetectors*)
   {
      ::TNectarDetectors *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarDetectors >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarDetectors", ::TNectarDetectors::Class_Version(), "TNectarMonitoringEvent.h", 21,
                  typeid(::TNectarDetectors), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarDetectors::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarDetectors) );
      instance.SetNew(&new_TNectarDetectors);
      instance.SetNewArray(&newArray_TNectarDetectors);
      instance.SetDelete(&delete_TNectarDetectors);
      instance.SetDeleteArray(&deleteArray_TNectarDetectors);
      instance.SetDestructor(&destruct_TNectarDetectors);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarDetectors*)
   {
      return GenerateInitInstanceLocal((::TNectarDetectors*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarDetectors*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarMonitoringEvent(void *p = 0);
   static void *newArray_TNectarMonitoringEvent(Long_t size, void *p);
   static void delete_TNectarMonitoringEvent(void *p);
   static void deleteArray_TNectarMonitoringEvent(void *p);
   static void destruct_TNectarMonitoringEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarMonitoringEvent*)
   {
      ::TNectarMonitoringEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarMonitoringEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarMonitoringEvent", ::TNectarMonitoringEvent::Class_Version(), "TNectarMonitoringEvent.h", 66,
                  typeid(::TNectarMonitoringEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarMonitoringEvent::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarMonitoringEvent) );
      instance.SetNew(&new_TNectarMonitoringEvent);
      instance.SetNewArray(&newArray_TNectarMonitoringEvent);
      instance.SetDelete(&delete_TNectarMonitoringEvent);
      instance.SetDeleteArray(&deleteArray_TNectarMonitoringEvent);
      instance.SetDestructor(&destruct_TNectarMonitoringEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarMonitoringEvent*)
   {
      return GenerateInitInstanceLocal((::TNectarMonitoringEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarMonitoringEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarAnalysis(void *p = 0);
   static void *newArray_TNectarAnalysis(Long_t size, void *p);
   static void delete_TNectarAnalysis(void *p);
   static void deleteArray_TNectarAnalysis(void *p);
   static void destruct_TNectarAnalysis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarAnalysis*)
   {
      ::TNectarAnalysis *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarAnalysis >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarAnalysis", ::TNectarAnalysis::Class_Version(), "TNectarAnalysis.h", 7,
                  typeid(::TNectarAnalysis), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarAnalysis::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarAnalysis) );
      instance.SetNew(&new_TNectarAnalysis);
      instance.SetNewArray(&newArray_TNectarAnalysis);
      instance.SetDelete(&delete_TNectarAnalysis);
      instance.SetDeleteArray(&deleteArray_TNectarAnalysis);
      instance.SetDestructor(&destruct_TNectarAnalysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarAnalysis*)
   {
      return GenerateInitInstanceLocal((::TNectarAnalysis*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarAnalysis*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarTelescope(void *p = 0);
   static void *newArray_TNectarTelescope(Long_t size, void *p);
   static void delete_TNectarTelescope(void *p);
   static void deleteArray_TNectarTelescope(void *p);
   static void destruct_TNectarTelescope(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarTelescope*)
   {
      ::TNectarTelescope *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarTelescope >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarTelescope", ::TNectarTelescope::Class_Version(), "TNectarProfileEvent.h", 21,
                  typeid(::TNectarTelescope), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarTelescope::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarTelescope) );
      instance.SetNew(&new_TNectarTelescope);
      instance.SetNewArray(&newArray_TNectarTelescope);
      instance.SetDelete(&delete_TNectarTelescope);
      instance.SetDeleteArray(&deleteArray_TNectarTelescope);
      instance.SetDestructor(&destruct_TNectarTelescope);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarTelescope*)
   {
      return GenerateInitInstanceLocal((::TNectarTelescope*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarTelescope*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarProfileEvent(void *p = 0);
   static void *newArray_TNectarProfileEvent(Long_t size, void *p);
   static void delete_TNectarProfileEvent(void *p);
   static void deleteArray_TNectarProfileEvent(void *p);
   static void destruct_TNectarProfileEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarProfileEvent*)
   {
      ::TNectarProfileEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarProfileEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarProfileEvent", ::TNectarProfileEvent::Class_Version(), "TNectarProfileEvent.h", 37,
                  typeid(::TNectarProfileEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarProfileEvent::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarProfileEvent) );
      instance.SetNew(&new_TNectarProfileEvent);
      instance.SetNewArray(&newArray_TNectarProfileEvent);
      instance.SetDelete(&delete_TNectarProfileEvent);
      instance.SetDeleteArray(&deleteArray_TNectarProfileEvent);
      instance.SetDestructor(&destruct_TNectarProfileEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarProfileEvent*)
   {
      return GenerateInitInstanceLocal((::TNectarProfileEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarProfileEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarHistograms(void *p = 0);
   static void *newArray_TNectarHistograms(Long_t size, void *p);
   static void delete_TNectarHistograms(void *p);
   static void deleteArray_TNectarHistograms(void *p);
   static void destruct_TNectarHistograms(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarHistograms*)
   {
      ::TNectarHistograms *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarHistograms >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarHistograms", ::TNectarHistograms::Class_Version(), "TNectarMonitoringDisplay.h", 22,
                  typeid(::TNectarHistograms), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarHistograms::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarHistograms) );
      instance.SetNew(&new_TNectarHistograms);
      instance.SetNewArray(&newArray_TNectarHistograms);
      instance.SetDelete(&delete_TNectarHistograms);
      instance.SetDeleteArray(&deleteArray_TNectarHistograms);
      instance.SetDestructor(&destruct_TNectarHistograms);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarHistograms*)
   {
      return GenerateInitInstanceLocal((::TNectarHistograms*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarHistograms*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarMonitoringProc(void *p = 0);
   static void *newArray_TNectarMonitoringProc(Long_t size, void *p);
   static void delete_TNectarMonitoringProc(void *p);
   static void deleteArray_TNectarMonitoringProc(void *p);
   static void destruct_TNectarMonitoringProc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarMonitoringProc*)
   {
      ::TNectarMonitoringProc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarMonitoringProc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarMonitoringProc", ::TNectarMonitoringProc::Class_Version(), "TNectarMonitoringProc.h", 23,
                  typeid(::TNectarMonitoringProc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarMonitoringProc::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarMonitoringProc) );
      instance.SetNew(&new_TNectarMonitoringProc);
      instance.SetNewArray(&newArray_TNectarMonitoringProc);
      instance.SetDelete(&delete_TNectarMonitoringProc);
      instance.SetDeleteArray(&deleteArray_TNectarMonitoringProc);
      instance.SetDestructor(&destruct_TNectarMonitoringProc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarMonitoringProc*)
   {
      return GenerateInitInstanceLocal((::TNectarMonitoringProc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarMonitoringProc*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarRawParam(void *p = 0);
   static void *newArray_TNectarRawParam(Long_t size, void *p);
   static void delete_TNectarRawParam(void *p);
   static void deleteArray_TNectarRawParam(void *p);
   static void destruct_TNectarRawParam(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarRawParam*)
   {
      ::TNectarRawParam *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarRawParam >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarRawParam", ::TNectarRawParam::Class_Version(), "TNectarRawParam.h", 9,
                  typeid(::TNectarRawParam), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarRawParam::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarRawParam) );
      instance.SetNew(&new_TNectarRawParam);
      instance.SetNewArray(&newArray_TNectarRawParam);
      instance.SetDelete(&delete_TNectarRawParam);
      instance.SetDeleteArray(&deleteArray_TNectarRawParam);
      instance.SetDestructor(&destruct_TNectarRawParam);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarRawParam*)
   {
      return GenerateInitInstanceLocal((::TNectarRawParam*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarRawParam*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TNectarProfileProc(void *p = 0);
   static void *newArray_TNectarProfileProc(Long_t size, void *p);
   static void delete_TNectarProfileProc(void *p);
   static void deleteArray_TNectarProfileProc(void *p);
   static void destruct_TNectarProfileProc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TNectarProfileProc*)
   {
      ::TNectarProfileProc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TNectarProfileProc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TNectarProfileProc", ::TNectarProfileProc::Class_Version(), "TNectarProfileProc.h", 23,
                  typeid(::TNectarProfileProc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TNectarProfileProc::Dictionary, isa_proxy, 4,
                  sizeof(::TNectarProfileProc) );
      instance.SetNew(&new_TNectarProfileProc);
      instance.SetNewArray(&newArray_TNectarProfileProc);
      instance.SetDelete(&delete_TNectarProfileProc);
      instance.SetDeleteArray(&deleteArray_TNectarProfileProc);
      instance.SetDestructor(&destruct_TNectarProfileProc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TNectarProfileProc*)
   {
      return GenerateInitInstanceLocal((::TNectarProfileProc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TNectarProfileProc*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TNectarBoard::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarBoard::Class_Name()
{
   return "TNectarBoard";
}

//______________________________________________________________________________
const char *TNectarBoard::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoard*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarBoard::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoard*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarBoard::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoard*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarBoard::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoard*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TMdppBoard::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMdppBoard::Class_Name()
{
   return "TMdppBoard";
}

//______________________________________________________________________________
const char *TMdppBoard::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMdppBoard*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMdppBoard::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMdppBoard*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMdppBoard::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMdppBoard*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMdppBoard::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMdppBoard*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TVmmrSlave::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVmmrSlave::Class_Name()
{
   return "TVmmrSlave";
}

//______________________________________________________________________________
const char *TVmmrSlave::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlave*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVmmrSlave::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlave*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVmmrSlave::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlave*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVmmrSlave::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlave*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TVmmrBoard::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVmmrBoard::Class_Name()
{
   return "TVmmrBoard";
}

//______________________________________________________________________________
const char *TVmmrBoard::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrBoard*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVmmrBoard::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrBoard*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVmmrBoard::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrBoard*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVmmrBoard::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrBoard*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarRawEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarRawEvent::Class_Name()
{
   return "TNectarRawEvent";
}

//______________________________________________________________________________
const char *TNectarRawEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarRawEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarRawEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarRawEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarBoardDisplay::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarBoardDisplay::Class_Name()
{
   return "TNectarBoardDisplay";
}

//______________________________________________________________________________
const char *TNectarBoardDisplay::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoardDisplay*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarBoardDisplay::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoardDisplay*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarBoardDisplay::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoardDisplay*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarBoardDisplay::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarBoardDisplay*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TMdppDisplay::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TMdppDisplay::Class_Name()
{
   return "TMdppDisplay";
}

//______________________________________________________________________________
const char *TMdppDisplay::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMdppDisplay*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TMdppDisplay::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TMdppDisplay*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TMdppDisplay::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMdppDisplay*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TMdppDisplay::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TMdppDisplay*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TVmmrSlaveDisplay::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVmmrSlaveDisplay::Class_Name()
{
   return "TVmmrSlaveDisplay";
}

//______________________________________________________________________________
const char *TVmmrSlaveDisplay::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlaveDisplay*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVmmrSlaveDisplay::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlaveDisplay*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVmmrSlaveDisplay::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlaveDisplay*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVmmrSlaveDisplay::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrSlaveDisplay*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TVmmrDisplay::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TVmmrDisplay::Class_Name()
{
   return "TVmmrDisplay";
}

//______________________________________________________________________________
const char *TVmmrDisplay::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrDisplay*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TVmmrDisplay::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TVmmrDisplay*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TVmmrDisplay::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrDisplay*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TVmmrDisplay::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TVmmrDisplay*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarRawProc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarRawProc::Class_Name()
{
   return "TNectarRawProc";
}

//______________________________________________________________________________
const char *TNectarRawProc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawProc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarRawProc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawProc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarRawProc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawProc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarRawProc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawProc*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarDetectors::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarDetectors::Class_Name()
{
   return "TNectarDetectors";
}

//______________________________________________________________________________
const char *TNectarDetectors::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarDetectors*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarDetectors::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarDetectors*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarDetectors::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarDetectors*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarDetectors::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarDetectors*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarMonitoringEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarMonitoringEvent::Class_Name()
{
   return "TNectarMonitoringEvent";
}

//______________________________________________________________________________
const char *TNectarMonitoringEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarMonitoringEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarMonitoringEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarMonitoringEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarAnalysis::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarAnalysis::Class_Name()
{
   return "TNectarAnalysis";
}

//______________________________________________________________________________
const char *TNectarAnalysis::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarAnalysis*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarAnalysis::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarAnalysis*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarAnalysis::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarAnalysis*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarAnalysis::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarAnalysis*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarTelescope::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarTelescope::Class_Name()
{
   return "TNectarTelescope";
}

//______________________________________________________________________________
const char *TNectarTelescope::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarTelescope*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarTelescope::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarTelescope*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarTelescope::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarTelescope*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarTelescope::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarTelescope*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarProfileEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarProfileEvent::Class_Name()
{
   return "TNectarProfileEvent";
}

//______________________________________________________________________________
const char *TNectarProfileEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarProfileEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarProfileEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarProfileEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarHistograms::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarHistograms::Class_Name()
{
   return "TNectarHistograms";
}

//______________________________________________________________________________
const char *TNectarHistograms::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarHistograms*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarHistograms::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarHistograms*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarHistograms::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarHistograms*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarHistograms::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarHistograms*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarMonitoringProc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarMonitoringProc::Class_Name()
{
   return "TNectarMonitoringProc";
}

//______________________________________________________________________________
const char *TNectarMonitoringProc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringProc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarMonitoringProc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringProc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarMonitoringProc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringProc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarMonitoringProc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarMonitoringProc*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarRawParam::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarRawParam::Class_Name()
{
   return "TNectarRawParam";
}

//______________________________________________________________________________
const char *TNectarRawParam::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawParam*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarRawParam::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawParam*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarRawParam::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawParam*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarRawParam::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarRawParam*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TNectarProfileProc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TNectarProfileProc::Class_Name()
{
   return "TNectarProfileProc";
}

//______________________________________________________________________________
const char *TNectarProfileProc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileProc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TNectarProfileProc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileProc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TNectarProfileProc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileProc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TNectarProfileProc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TNectarProfileProc*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TNectarBoard::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarBoard.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarBoard::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarBoard::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarBoard(void *p) {
      return  p ? new(p) ::TNectarBoard : new ::TNectarBoard;
   }
   static void *newArray_TNectarBoard(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarBoard[nElements] : new ::TNectarBoard[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarBoard(void *p) {
      delete ((::TNectarBoard*)p);
   }
   static void deleteArray_TNectarBoard(void *p) {
      delete [] ((::TNectarBoard*)p);
   }
   static void destruct_TNectarBoard(void *p) {
      typedef ::TNectarBoard current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarBoard

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMdppMsg(void *p) {
      return  p ? new(p) ::TMdppMsg : new ::TMdppMsg;
   }
   static void *newArray_TMdppMsg(Long_t nElements, void *p) {
      return p ? new(p) ::TMdppMsg[nElements] : new ::TMdppMsg[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMdppMsg(void *p) {
      delete ((::TMdppMsg*)p);
   }
   static void deleteArray_TMdppMsg(void *p) {
      delete [] ((::TMdppMsg*)p);
   }
   static void destruct_TMdppMsg(void *p) {
      typedef ::TMdppMsg current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TMdppMsg

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMdppAdcData(void *p) {
      return  p ? new(p) ::TMdppAdcData : new ::TMdppAdcData;
   }
   static void *newArray_TMdppAdcData(Long_t nElements, void *p) {
      return p ? new(p) ::TMdppAdcData[nElements] : new ::TMdppAdcData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMdppAdcData(void *p) {
      delete ((::TMdppAdcData*)p);
   }
   static void deleteArray_TMdppAdcData(void *p) {
      delete [] ((::TMdppAdcData*)p);
   }
   static void destruct_TMdppAdcData(void *p) {
      typedef ::TMdppAdcData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TMdppAdcData

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMdppTdcData(void *p) {
      return  p ? new(p) ::TMdppTdcData : new ::TMdppTdcData;
   }
   static void *newArray_TMdppTdcData(Long_t nElements, void *p) {
      return p ? new(p) ::TMdppTdcData[nElements] : new ::TMdppTdcData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMdppTdcData(void *p) {
      delete ((::TMdppTdcData*)p);
   }
   static void deleteArray_TMdppTdcData(void *p) {
      delete [] ((::TMdppTdcData*)p);
   }
   static void destruct_TMdppTdcData(void *p) {
      typedef ::TMdppTdcData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TMdppTdcData

//______________________________________________________________________________
void TMdppBoard::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMdppBoard.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TMdppBoard::Class(),this);
   } else {
      R__b.WriteClassBuffer(TMdppBoard::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMdppBoard(void *p) {
      return  p ? new(p) ::TMdppBoard : new ::TMdppBoard;
   }
   static void *newArray_TMdppBoard(Long_t nElements, void *p) {
      return p ? new(p) ::TMdppBoard[nElements] : new ::TMdppBoard[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMdppBoard(void *p) {
      delete ((::TMdppBoard*)p);
   }
   static void deleteArray_TMdppBoard(void *p) {
      delete [] ((::TMdppBoard*)p);
   }
   static void destruct_TMdppBoard(void *p) {
      typedef ::TMdppBoard current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TMdppBoard

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVmmrMsg(void *p) {
      return  p ? new(p) ::TVmmrMsg : new ::TVmmrMsg;
   }
   static void *newArray_TVmmrMsg(Long_t nElements, void *p) {
      return p ? new(p) ::TVmmrMsg[nElements] : new ::TVmmrMsg[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVmmrMsg(void *p) {
      delete ((::TVmmrMsg*)p);
   }
   static void deleteArray_TVmmrMsg(void *p) {
      delete [] ((::TVmmrMsg*)p);
   }
   static void destruct_TVmmrMsg(void *p) {
      typedef ::TVmmrMsg current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TVmmrMsg

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVmmrAdcData(void *p) {
      return  p ? new(p) ::TVmmrAdcData : new ::TVmmrAdcData;
   }
   static void *newArray_TVmmrAdcData(Long_t nElements, void *p) {
      return p ? new(p) ::TVmmrAdcData[nElements] : new ::TVmmrAdcData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVmmrAdcData(void *p) {
      delete ((::TVmmrAdcData*)p);
   }
   static void deleteArray_TVmmrAdcData(void *p) {
      delete [] ((::TVmmrAdcData*)p);
   }
   static void destruct_TVmmrAdcData(void *p) {
      typedef ::TVmmrAdcData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TVmmrAdcData

//______________________________________________________________________________
void TVmmrSlave::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVmmrSlave.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TVmmrSlave::Class(),this);
   } else {
      R__b.WriteClassBuffer(TVmmrSlave::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVmmrSlave(void *p) {
      return  p ? new(p) ::TVmmrSlave : new ::TVmmrSlave;
   }
   static void *newArray_TVmmrSlave(Long_t nElements, void *p) {
      return p ? new(p) ::TVmmrSlave[nElements] : new ::TVmmrSlave[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVmmrSlave(void *p) {
      delete ((::TVmmrSlave*)p);
   }
   static void deleteArray_TVmmrSlave(void *p) {
      delete [] ((::TVmmrSlave*)p);
   }
   static void destruct_TVmmrSlave(void *p) {
      typedef ::TVmmrSlave current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TVmmrSlave

//______________________________________________________________________________
void TVmmrBoard::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVmmrBoard.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TVmmrBoard::Class(),this);
   } else {
      R__b.WriteClassBuffer(TVmmrBoard::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVmmrBoard(void *p) {
      return  p ? new(p) ::TVmmrBoard : new ::TVmmrBoard;
   }
   static void *newArray_TVmmrBoard(Long_t nElements, void *p) {
      return p ? new(p) ::TVmmrBoard[nElements] : new ::TVmmrBoard[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVmmrBoard(void *p) {
      delete ((::TVmmrBoard*)p);
   }
   static void deleteArray_TVmmrBoard(void *p) {
      delete [] ((::TVmmrBoard*)p);
   }
   static void destruct_TVmmrBoard(void *p) {
      typedef ::TVmmrBoard current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TVmmrBoard

//______________________________________________________________________________
void TNectarRawEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarRawEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarRawEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarRawEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarRawEvent(void *p) {
      return  p ? new(p) ::TNectarRawEvent : new ::TNectarRawEvent;
   }
   static void *newArray_TNectarRawEvent(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarRawEvent[nElements] : new ::TNectarRawEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarRawEvent(void *p) {
      delete ((::TNectarRawEvent*)p);
   }
   static void deleteArray_TNectarRawEvent(void *p) {
      delete [] ((::TNectarRawEvent*)p);
   }
   static void destruct_TNectarRawEvent(void *p) {
      typedef ::TNectarRawEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarRawEvent

//______________________________________________________________________________
void TNectarBoardDisplay::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarBoardDisplay.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarBoardDisplay::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarBoardDisplay::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarBoardDisplay(void *p) {
      return  p ? new(p) ::TNectarBoardDisplay : new ::TNectarBoardDisplay;
   }
   static void *newArray_TNectarBoardDisplay(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarBoardDisplay[nElements] : new ::TNectarBoardDisplay[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarBoardDisplay(void *p) {
      delete ((::TNectarBoardDisplay*)p);
   }
   static void deleteArray_TNectarBoardDisplay(void *p) {
      delete [] ((::TNectarBoardDisplay*)p);
   }
   static void destruct_TNectarBoardDisplay(void *p) {
      typedef ::TNectarBoardDisplay current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarBoardDisplay

//______________________________________________________________________________
void TMdppDisplay::Streamer(TBuffer &R__b)
{
   // Stream an object of class TMdppDisplay.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TMdppDisplay::Class(),this);
   } else {
      R__b.WriteClassBuffer(TMdppDisplay::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TMdppDisplay(void *p) {
      return  p ? new(p) ::TMdppDisplay : new ::TMdppDisplay;
   }
   static void *newArray_TMdppDisplay(Long_t nElements, void *p) {
      return p ? new(p) ::TMdppDisplay[nElements] : new ::TMdppDisplay[nElements];
   }
   // Wrapper around operator delete
   static void delete_TMdppDisplay(void *p) {
      delete ((::TMdppDisplay*)p);
   }
   static void deleteArray_TMdppDisplay(void *p) {
      delete [] ((::TMdppDisplay*)p);
   }
   static void destruct_TMdppDisplay(void *p) {
      typedef ::TMdppDisplay current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TMdppDisplay

//______________________________________________________________________________
void TVmmrSlaveDisplay::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVmmrSlaveDisplay.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TVmmrSlaveDisplay::Class(),this);
   } else {
      R__b.WriteClassBuffer(TVmmrSlaveDisplay::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVmmrSlaveDisplay(void *p) {
      return  p ? new(p) ::TVmmrSlaveDisplay : new ::TVmmrSlaveDisplay;
   }
   static void *newArray_TVmmrSlaveDisplay(Long_t nElements, void *p) {
      return p ? new(p) ::TVmmrSlaveDisplay[nElements] : new ::TVmmrSlaveDisplay[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVmmrSlaveDisplay(void *p) {
      delete ((::TVmmrSlaveDisplay*)p);
   }
   static void deleteArray_TVmmrSlaveDisplay(void *p) {
      delete [] ((::TVmmrSlaveDisplay*)p);
   }
   static void destruct_TVmmrSlaveDisplay(void *p) {
      typedef ::TVmmrSlaveDisplay current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TVmmrSlaveDisplay

//______________________________________________________________________________
void TVmmrDisplay::Streamer(TBuffer &R__b)
{
   // Stream an object of class TVmmrDisplay.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TVmmrDisplay::Class(),this);
   } else {
      R__b.WriteClassBuffer(TVmmrDisplay::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TVmmrDisplay(void *p) {
      return  p ? new(p) ::TVmmrDisplay : new ::TVmmrDisplay;
   }
   static void *newArray_TVmmrDisplay(Long_t nElements, void *p) {
      return p ? new(p) ::TVmmrDisplay[nElements] : new ::TVmmrDisplay[nElements];
   }
   // Wrapper around operator delete
   static void delete_TVmmrDisplay(void *p) {
      delete ((::TVmmrDisplay*)p);
   }
   static void deleteArray_TVmmrDisplay(void *p) {
      delete [] ((::TVmmrDisplay*)p);
   }
   static void destruct_TVmmrDisplay(void *p) {
      typedef ::TVmmrDisplay current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TVmmrDisplay

//______________________________________________________________________________
void TNectarRawProc::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarRawProc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarRawProc::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarRawProc::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarRawProc(void *p) {
      return  p ? new(p) ::TNectarRawProc : new ::TNectarRawProc;
   }
   static void *newArray_TNectarRawProc(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarRawProc[nElements] : new ::TNectarRawProc[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarRawProc(void *p) {
      delete ((::TNectarRawProc*)p);
   }
   static void deleteArray_TNectarRawProc(void *p) {
      delete [] ((::TNectarRawProc*)p);
   }
   static void destruct_TNectarRawProc(void *p) {
      typedef ::TNectarRawProc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarRawProc

//______________________________________________________________________________
void TNectarDetectors::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarDetectors.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarDetectors::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarDetectors::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarDetectors(void *p) {
      return  p ? new(p) ::TNectarDetectors : new ::TNectarDetectors;
   }
   static void *newArray_TNectarDetectors(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarDetectors[nElements] : new ::TNectarDetectors[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarDetectors(void *p) {
      delete ((::TNectarDetectors*)p);
   }
   static void deleteArray_TNectarDetectors(void *p) {
      delete [] ((::TNectarDetectors*)p);
   }
   static void destruct_TNectarDetectors(void *p) {
      typedef ::TNectarDetectors current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarDetectors

//______________________________________________________________________________
void TNectarMonitoringEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarMonitoringEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarMonitoringEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarMonitoringEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarMonitoringEvent(void *p) {
      return  p ? new(p) ::TNectarMonitoringEvent : new ::TNectarMonitoringEvent;
   }
   static void *newArray_TNectarMonitoringEvent(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarMonitoringEvent[nElements] : new ::TNectarMonitoringEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarMonitoringEvent(void *p) {
      delete ((::TNectarMonitoringEvent*)p);
   }
   static void deleteArray_TNectarMonitoringEvent(void *p) {
      delete [] ((::TNectarMonitoringEvent*)p);
   }
   static void destruct_TNectarMonitoringEvent(void *p) {
      typedef ::TNectarMonitoringEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarMonitoringEvent

//______________________________________________________________________________
void TNectarAnalysis::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarAnalysis.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarAnalysis::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarAnalysis::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarAnalysis(void *p) {
      return  p ? new(p) ::TNectarAnalysis : new ::TNectarAnalysis;
   }
   static void *newArray_TNectarAnalysis(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarAnalysis[nElements] : new ::TNectarAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarAnalysis(void *p) {
      delete ((::TNectarAnalysis*)p);
   }
   static void deleteArray_TNectarAnalysis(void *p) {
      delete [] ((::TNectarAnalysis*)p);
   }
   static void destruct_TNectarAnalysis(void *p) {
      typedef ::TNectarAnalysis current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarAnalysis

//______________________________________________________________________________
void TNectarTelescope::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarTelescope.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarTelescope::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarTelescope::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarTelescope(void *p) {
      return  p ? new(p) ::TNectarTelescope : new ::TNectarTelescope;
   }
   static void *newArray_TNectarTelescope(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarTelescope[nElements] : new ::TNectarTelescope[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarTelescope(void *p) {
      delete ((::TNectarTelescope*)p);
   }
   static void deleteArray_TNectarTelescope(void *p) {
      delete [] ((::TNectarTelescope*)p);
   }
   static void destruct_TNectarTelescope(void *p) {
      typedef ::TNectarTelescope current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarTelescope

//______________________________________________________________________________
void TNectarProfileEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarProfileEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarProfileEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarProfileEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarProfileEvent(void *p) {
      return  p ? new(p) ::TNectarProfileEvent : new ::TNectarProfileEvent;
   }
   static void *newArray_TNectarProfileEvent(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarProfileEvent[nElements] : new ::TNectarProfileEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarProfileEvent(void *p) {
      delete ((::TNectarProfileEvent*)p);
   }
   static void deleteArray_TNectarProfileEvent(void *p) {
      delete [] ((::TNectarProfileEvent*)p);
   }
   static void destruct_TNectarProfileEvent(void *p) {
      typedef ::TNectarProfileEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarProfileEvent

//______________________________________________________________________________
void TNectarHistograms::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarHistograms.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarHistograms::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarHistograms::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarHistograms(void *p) {
      return  p ? new(p) ::TNectarHistograms : new ::TNectarHistograms;
   }
   static void *newArray_TNectarHistograms(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarHistograms[nElements] : new ::TNectarHistograms[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarHistograms(void *p) {
      delete ((::TNectarHistograms*)p);
   }
   static void deleteArray_TNectarHistograms(void *p) {
      delete [] ((::TNectarHistograms*)p);
   }
   static void destruct_TNectarHistograms(void *p) {
      typedef ::TNectarHistograms current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarHistograms

//______________________________________________________________________________
void TNectarMonitoringProc::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarMonitoringProc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarMonitoringProc::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarMonitoringProc::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarMonitoringProc(void *p) {
      return  p ? new(p) ::TNectarMonitoringProc : new ::TNectarMonitoringProc;
   }
   static void *newArray_TNectarMonitoringProc(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarMonitoringProc[nElements] : new ::TNectarMonitoringProc[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarMonitoringProc(void *p) {
      delete ((::TNectarMonitoringProc*)p);
   }
   static void deleteArray_TNectarMonitoringProc(void *p) {
      delete [] ((::TNectarMonitoringProc*)p);
   }
   static void destruct_TNectarMonitoringProc(void *p) {
      typedef ::TNectarMonitoringProc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarMonitoringProc

//______________________________________________________________________________
void TNectarRawParam::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarRawParam.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarRawParam::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarRawParam::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarRawParam(void *p) {
      return  p ? new(p) ::TNectarRawParam : new ::TNectarRawParam;
   }
   static void *newArray_TNectarRawParam(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarRawParam[nElements] : new ::TNectarRawParam[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarRawParam(void *p) {
      delete ((::TNectarRawParam*)p);
   }
   static void deleteArray_TNectarRawParam(void *p) {
      delete [] ((::TNectarRawParam*)p);
   }
   static void destruct_TNectarRawParam(void *p) {
      typedef ::TNectarRawParam current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarRawParam

//______________________________________________________________________________
void TNectarProfileProc::Streamer(TBuffer &R__b)
{
   // Stream an object of class TNectarProfileProc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TNectarProfileProc::Class(),this);
   } else {
      R__b.WriteClassBuffer(TNectarProfileProc::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TNectarProfileProc(void *p) {
      return  p ? new(p) ::TNectarProfileProc : new ::TNectarProfileProc;
   }
   static void *newArray_TNectarProfileProc(Long_t nElements, void *p) {
      return p ? new(p) ::TNectarProfileProc[nElements] : new ::TNectarProfileProc[nElements];
   }
   // Wrapper around operator delete
   static void delete_TNectarProfileProc(void *p) {
      delete ((::TNectarProfileProc*)p);
   }
   static void deleteArray_TNectarProfileProc(void *p) {
      delete [] ((::TNectarProfileProc*)p);
   }
   static void destruct_TNectarProfileProc(void *p) {
      typedef ::TNectarProfileProc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TNectarProfileProc

namespace ROOT {
   static TClass *vectorlETVmmrSlaveDisplaymUgR_Dictionary();
   static void vectorlETVmmrSlaveDisplaymUgR_TClassManip(TClass*);
   static void *new_vectorlETVmmrSlaveDisplaymUgR(void *p = 0);
   static void *newArray_vectorlETVmmrSlaveDisplaymUgR(Long_t size, void *p);
   static void delete_vectorlETVmmrSlaveDisplaymUgR(void *p);
   static void deleteArray_vectorlETVmmrSlaveDisplaymUgR(void *p);
   static void destruct_vectorlETVmmrSlaveDisplaymUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVmmrSlaveDisplay*>*)
   {
      vector<TVmmrSlaveDisplay*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVmmrSlaveDisplay*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVmmrSlaveDisplay*>", -2, "vector", 386,
                  typeid(vector<TVmmrSlaveDisplay*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVmmrSlaveDisplaymUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TVmmrSlaveDisplay*>) );
      instance.SetNew(&new_vectorlETVmmrSlaveDisplaymUgR);
      instance.SetNewArray(&newArray_vectorlETVmmrSlaveDisplaymUgR);
      instance.SetDelete(&delete_vectorlETVmmrSlaveDisplaymUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETVmmrSlaveDisplaymUgR);
      instance.SetDestructor(&destruct_vectorlETVmmrSlaveDisplaymUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVmmrSlaveDisplay*> >()));

      ::ROOT::AddClassAlternate("vector<TVmmrSlaveDisplay*>","std::vector<TVmmrSlaveDisplay*, std::allocator<TVmmrSlaveDisplay*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TVmmrSlaveDisplay*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVmmrSlaveDisplaymUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVmmrSlaveDisplay*>*)0x0)->GetClass();
      vectorlETVmmrSlaveDisplaymUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVmmrSlaveDisplaymUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVmmrSlaveDisplaymUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrSlaveDisplay*> : new vector<TVmmrSlaveDisplay*>;
   }
   static void *newArray_vectorlETVmmrSlaveDisplaymUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrSlaveDisplay*>[nElements] : new vector<TVmmrSlaveDisplay*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVmmrSlaveDisplaymUgR(void *p) {
      delete ((vector<TVmmrSlaveDisplay*>*)p);
   }
   static void deleteArray_vectorlETVmmrSlaveDisplaymUgR(void *p) {
      delete [] ((vector<TVmmrSlaveDisplay*>*)p);
   }
   static void destruct_vectorlETVmmrSlaveDisplaymUgR(void *p) {
      typedef vector<TVmmrSlaveDisplay*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVmmrSlaveDisplay*>

namespace ROOT {
   static TClass *vectorlETVmmrSlavemUgR_Dictionary();
   static void vectorlETVmmrSlavemUgR_TClassManip(TClass*);
   static void *new_vectorlETVmmrSlavemUgR(void *p = 0);
   static void *newArray_vectorlETVmmrSlavemUgR(Long_t size, void *p);
   static void delete_vectorlETVmmrSlavemUgR(void *p);
   static void deleteArray_vectorlETVmmrSlavemUgR(void *p);
   static void destruct_vectorlETVmmrSlavemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVmmrSlave*>*)
   {
      vector<TVmmrSlave*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVmmrSlave*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVmmrSlave*>", -2, "vector", 386,
                  typeid(vector<TVmmrSlave*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVmmrSlavemUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TVmmrSlave*>) );
      instance.SetNew(&new_vectorlETVmmrSlavemUgR);
      instance.SetNewArray(&newArray_vectorlETVmmrSlavemUgR);
      instance.SetDelete(&delete_vectorlETVmmrSlavemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETVmmrSlavemUgR);
      instance.SetDestructor(&destruct_vectorlETVmmrSlavemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVmmrSlave*> >()));

      ::ROOT::AddClassAlternate("vector<TVmmrSlave*>","std::vector<TVmmrSlave*, std::allocator<TVmmrSlave*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TVmmrSlave*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVmmrSlavemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVmmrSlave*>*)0x0)->GetClass();
      vectorlETVmmrSlavemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVmmrSlavemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVmmrSlavemUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrSlave*> : new vector<TVmmrSlave*>;
   }
   static void *newArray_vectorlETVmmrSlavemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrSlave*>[nElements] : new vector<TVmmrSlave*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVmmrSlavemUgR(void *p) {
      delete ((vector<TVmmrSlave*>*)p);
   }
   static void deleteArray_vectorlETVmmrSlavemUgR(void *p) {
      delete [] ((vector<TVmmrSlave*>*)p);
   }
   static void destruct_vectorlETVmmrSlavemUgR(void *p) {
      typedef vector<TVmmrSlave*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVmmrSlave*>

namespace ROOT {
   static TClass *vectorlETVmmrDisplaymUgR_Dictionary();
   static void vectorlETVmmrDisplaymUgR_TClassManip(TClass*);
   static void *new_vectorlETVmmrDisplaymUgR(void *p = 0);
   static void *newArray_vectorlETVmmrDisplaymUgR(Long_t size, void *p);
   static void delete_vectorlETVmmrDisplaymUgR(void *p);
   static void deleteArray_vectorlETVmmrDisplaymUgR(void *p);
   static void destruct_vectorlETVmmrDisplaymUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVmmrDisplay*>*)
   {
      vector<TVmmrDisplay*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVmmrDisplay*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVmmrDisplay*>", -2, "vector", 386,
                  typeid(vector<TVmmrDisplay*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVmmrDisplaymUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TVmmrDisplay*>) );
      instance.SetNew(&new_vectorlETVmmrDisplaymUgR);
      instance.SetNewArray(&newArray_vectorlETVmmrDisplaymUgR);
      instance.SetDelete(&delete_vectorlETVmmrDisplaymUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETVmmrDisplaymUgR);
      instance.SetDestructor(&destruct_vectorlETVmmrDisplaymUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVmmrDisplay*> >()));

      ::ROOT::AddClassAlternate("vector<TVmmrDisplay*>","std::vector<TVmmrDisplay*, std::allocator<TVmmrDisplay*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TVmmrDisplay*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVmmrDisplaymUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVmmrDisplay*>*)0x0)->GetClass();
      vectorlETVmmrDisplaymUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVmmrDisplaymUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVmmrDisplaymUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrDisplay*> : new vector<TVmmrDisplay*>;
   }
   static void *newArray_vectorlETVmmrDisplaymUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrDisplay*>[nElements] : new vector<TVmmrDisplay*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVmmrDisplaymUgR(void *p) {
      delete ((vector<TVmmrDisplay*>*)p);
   }
   static void deleteArray_vectorlETVmmrDisplaymUgR(void *p) {
      delete [] ((vector<TVmmrDisplay*>*)p);
   }
   static void destruct_vectorlETVmmrDisplaymUgR(void *p) {
      typedef vector<TVmmrDisplay*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVmmrDisplay*>

namespace ROOT {
   static TClass *vectorlETVmmrAdcDatamUgR_Dictionary();
   static void vectorlETVmmrAdcDatamUgR_TClassManip(TClass*);
   static void *new_vectorlETVmmrAdcDatamUgR(void *p = 0);
   static void *newArray_vectorlETVmmrAdcDatamUgR(Long_t size, void *p);
   static void delete_vectorlETVmmrAdcDatamUgR(void *p);
   static void deleteArray_vectorlETVmmrAdcDatamUgR(void *p);
   static void destruct_vectorlETVmmrAdcDatamUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVmmrAdcData*>*)
   {
      vector<TVmmrAdcData*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVmmrAdcData*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVmmrAdcData*>", -2, "vector", 386,
                  typeid(vector<TVmmrAdcData*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVmmrAdcDatamUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TVmmrAdcData*>) );
      instance.SetNew(&new_vectorlETVmmrAdcDatamUgR);
      instance.SetNewArray(&newArray_vectorlETVmmrAdcDatamUgR);
      instance.SetDelete(&delete_vectorlETVmmrAdcDatamUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETVmmrAdcDatamUgR);
      instance.SetDestructor(&destruct_vectorlETVmmrAdcDatamUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVmmrAdcData*> >()));

      ::ROOT::AddClassAlternate("vector<TVmmrAdcData*>","std::vector<TVmmrAdcData*, std::allocator<TVmmrAdcData*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TVmmrAdcData*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVmmrAdcDatamUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVmmrAdcData*>*)0x0)->GetClass();
      vectorlETVmmrAdcDatamUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVmmrAdcDatamUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVmmrAdcDatamUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrAdcData*> : new vector<TVmmrAdcData*>;
   }
   static void *newArray_vectorlETVmmrAdcDatamUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVmmrAdcData*>[nElements] : new vector<TVmmrAdcData*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVmmrAdcDatamUgR(void *p) {
      delete ((vector<TVmmrAdcData*>*)p);
   }
   static void deleteArray_vectorlETVmmrAdcDatamUgR(void *p) {
      delete [] ((vector<TVmmrAdcData*>*)p);
   }
   static void destruct_vectorlETVmmrAdcDatamUgR(void *p) {
      typedef vector<TVmmrAdcData*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVmmrAdcData*>

namespace ROOT {
   static TClass *vectorlETMdppTdcDatamUgR_Dictionary();
   static void vectorlETMdppTdcDatamUgR_TClassManip(TClass*);
   static void *new_vectorlETMdppTdcDatamUgR(void *p = 0);
   static void *newArray_vectorlETMdppTdcDatamUgR(Long_t size, void *p);
   static void delete_vectorlETMdppTdcDatamUgR(void *p);
   static void deleteArray_vectorlETMdppTdcDatamUgR(void *p);
   static void destruct_vectorlETMdppTdcDatamUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TMdppTdcData*>*)
   {
      vector<TMdppTdcData*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TMdppTdcData*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TMdppTdcData*>", -2, "vector", 386,
                  typeid(vector<TMdppTdcData*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETMdppTdcDatamUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TMdppTdcData*>) );
      instance.SetNew(&new_vectorlETMdppTdcDatamUgR);
      instance.SetNewArray(&newArray_vectorlETMdppTdcDatamUgR);
      instance.SetDelete(&delete_vectorlETMdppTdcDatamUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETMdppTdcDatamUgR);
      instance.SetDestructor(&destruct_vectorlETMdppTdcDatamUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TMdppTdcData*> >()));

      ::ROOT::AddClassAlternate("vector<TMdppTdcData*>","std::vector<TMdppTdcData*, std::allocator<TMdppTdcData*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TMdppTdcData*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETMdppTdcDatamUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TMdppTdcData*>*)0x0)->GetClass();
      vectorlETMdppTdcDatamUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETMdppTdcDatamUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETMdppTdcDatamUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TMdppTdcData*> : new vector<TMdppTdcData*>;
   }
   static void *newArray_vectorlETMdppTdcDatamUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TMdppTdcData*>[nElements] : new vector<TMdppTdcData*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETMdppTdcDatamUgR(void *p) {
      delete ((vector<TMdppTdcData*>*)p);
   }
   static void deleteArray_vectorlETMdppTdcDatamUgR(void *p) {
      delete [] ((vector<TMdppTdcData*>*)p);
   }
   static void destruct_vectorlETMdppTdcDatamUgR(void *p) {
      typedef vector<TMdppTdcData*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TMdppTdcData*>

namespace ROOT {
   static TClass *vectorlETMdppDisplaymUgR_Dictionary();
   static void vectorlETMdppDisplaymUgR_TClassManip(TClass*);
   static void *new_vectorlETMdppDisplaymUgR(void *p = 0);
   static void *newArray_vectorlETMdppDisplaymUgR(Long_t size, void *p);
   static void delete_vectorlETMdppDisplaymUgR(void *p);
   static void deleteArray_vectorlETMdppDisplaymUgR(void *p);
   static void destruct_vectorlETMdppDisplaymUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TMdppDisplay*>*)
   {
      vector<TMdppDisplay*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TMdppDisplay*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TMdppDisplay*>", -2, "vector", 386,
                  typeid(vector<TMdppDisplay*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETMdppDisplaymUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TMdppDisplay*>) );
      instance.SetNew(&new_vectorlETMdppDisplaymUgR);
      instance.SetNewArray(&newArray_vectorlETMdppDisplaymUgR);
      instance.SetDelete(&delete_vectorlETMdppDisplaymUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETMdppDisplaymUgR);
      instance.SetDestructor(&destruct_vectorlETMdppDisplaymUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TMdppDisplay*> >()));

      ::ROOT::AddClassAlternate("vector<TMdppDisplay*>","std::vector<TMdppDisplay*, std::allocator<TMdppDisplay*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TMdppDisplay*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETMdppDisplaymUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TMdppDisplay*>*)0x0)->GetClass();
      vectorlETMdppDisplaymUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETMdppDisplaymUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETMdppDisplaymUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TMdppDisplay*> : new vector<TMdppDisplay*>;
   }
   static void *newArray_vectorlETMdppDisplaymUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TMdppDisplay*>[nElements] : new vector<TMdppDisplay*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETMdppDisplaymUgR(void *p) {
      delete ((vector<TMdppDisplay*>*)p);
   }
   static void deleteArray_vectorlETMdppDisplaymUgR(void *p) {
      delete [] ((vector<TMdppDisplay*>*)p);
   }
   static void destruct_vectorlETMdppDisplaymUgR(void *p) {
      typedef vector<TMdppDisplay*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TMdppDisplay*>

namespace ROOT {
   static TClass *vectorlETMdppAdcDatamUgR_Dictionary();
   static void vectorlETMdppAdcDatamUgR_TClassManip(TClass*);
   static void *new_vectorlETMdppAdcDatamUgR(void *p = 0);
   static void *newArray_vectorlETMdppAdcDatamUgR(Long_t size, void *p);
   static void delete_vectorlETMdppAdcDatamUgR(void *p);
   static void deleteArray_vectorlETMdppAdcDatamUgR(void *p);
   static void destruct_vectorlETMdppAdcDatamUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TMdppAdcData*>*)
   {
      vector<TMdppAdcData*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TMdppAdcData*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TMdppAdcData*>", -2, "vector", 386,
                  typeid(vector<TMdppAdcData*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETMdppAdcDatamUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TMdppAdcData*>) );
      instance.SetNew(&new_vectorlETMdppAdcDatamUgR);
      instance.SetNewArray(&newArray_vectorlETMdppAdcDatamUgR);
      instance.SetDelete(&delete_vectorlETMdppAdcDatamUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETMdppAdcDatamUgR);
      instance.SetDestructor(&destruct_vectorlETMdppAdcDatamUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TMdppAdcData*> >()));

      ::ROOT::AddClassAlternate("vector<TMdppAdcData*>","std::vector<TMdppAdcData*, std::allocator<TMdppAdcData*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TMdppAdcData*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETMdppAdcDatamUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TMdppAdcData*>*)0x0)->GetClass();
      vectorlETMdppAdcDatamUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETMdppAdcDatamUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETMdppAdcDatamUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TMdppAdcData*> : new vector<TMdppAdcData*>;
   }
   static void *newArray_vectorlETMdppAdcDatamUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TMdppAdcData*>[nElements] : new vector<TMdppAdcData*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETMdppAdcDatamUgR(void *p) {
      delete ((vector<TMdppAdcData*>*)p);
   }
   static void deleteArray_vectorlETMdppAdcDatamUgR(void *p) {
      delete [] ((vector<TMdppAdcData*>*)p);
   }
   static void destruct_vectorlETMdppAdcDatamUgR(void *p) {
      typedef vector<TMdppAdcData*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TMdppAdcData*>

namespace {
  void TriggerDictionaryInitialization_libGo4UserAnalysis_Impl() {
    static const char* headers[] = {
"./TNectarRawProc.h",
"./TNectarMonitoringEvent.h",
"./TNectarAnalysis.h",
"./TNectarMonitoringProc.h",
"./TNectarRawParam.h",
"./TNectarMonitorigEvent.h",
"./TNectarProfileProc.h",
"./TNectarMonitoringDisplay.h",
"./libGo4UserAnalysis815aa6ab56_dictContent.h",
"./TNectarRawEvent.h",
"./TNectarDisplay.h",
"./libGo4UserAnalysise7c62a8a82_dictUmbrella.h",
"./TNectarProfileEvent.h",
0
    };
    static const char* includePaths[] = {
"/LynxOS/mbsusr/mbsdaq/analysis/go4/601-02/include",
"/LynxOS/mbsusr/mbsdaq/analysis/go4/601-02",
"/LynxOS/mbsusr/mbsdaq/analysis/root/620-08/include/",
"/LynxOS/mbsusr/mbsdaq/go4/go4/Go4_may_start/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGo4UserAnalysis dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TMdppAdcData;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TMdppTdcData;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TVmmrAdcData;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TVmmrSlave;
class __attribute__((annotate("$clingAutoload$TNectarDisplay.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TVmmrSlaveDisplay;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TNectarBoard;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TMdppMsg;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TMdppBoard;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TVmmrMsg;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TVmmrBoard;
class __attribute__((annotate("$clingAutoload$TNectarRawEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TNectarRawEvent;
class __attribute__((annotate("$clingAutoload$TNectarDisplay.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TNectarBoardDisplay;
class __attribute__((annotate("$clingAutoload$TNectarDisplay.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TMdppDisplay;
class __attribute__((annotate("$clingAutoload$TNectarDisplay.h")))  __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TVmmrDisplay;
class __attribute__((annotate("$clingAutoload$./TNectarRawProc.h")))  TNectarRawProc;
class __attribute__((annotate("$clingAutoload$./TNectarMonitoringEvent.h")))  TNectarDetectors;
class __attribute__((annotate("$clingAutoload$./TNectarMonitoringEvent.h")))  TNectarMonitoringEvent;
class __attribute__((annotate("$clingAutoload$./TNectarAnalysis.h")))  TNectarAnalysis;
class __attribute__((annotate("$clingAutoload$TNectarProfileEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarMonitoringProc.h")))  TNectarTelescope;
class __attribute__((annotate("$clingAutoload$TNectarProfileEvent.h")))  __attribute__((annotate("$clingAutoload$./TNectarMonitoringProc.h")))  TNectarProfileEvent;
class __attribute__((annotate("$clingAutoload$TNectarMonitoringDisplay.h")))  __attribute__((annotate("$clingAutoload$./TNectarMonitoringProc.h")))  TNectarHistograms;
class __attribute__((annotate("$clingAutoload$./TNectarMonitoringProc.h")))  TNectarMonitoringProc;
class __attribute__((annotate("$clingAutoload$./TNectarRawParam.h")))  TNectarRawParam;
class __attribute__((annotate("$clingAutoload$./TNectarProfileProc.h")))  TNectarProfileProc;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGo4UserAnalysis dictionary payload"

#ifndef Linux
  #define Linux 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "./TNectarRawProc.h"
#include "./TNectarMonitoringEvent.h"
#include "./TNectarAnalysis.h"
#include "./TNectarMonitoringProc.h"
#include "./TNectarRawParam.h"
#include "./TNectarMonitorigEvent.h"
#include "./TNectarProfileProc.h"
#include "./TNectarMonitoringDisplay.h"
#include "./libGo4UserAnalysis815aa6ab56_dictContent.h"
#include "./TNectarRawEvent.h"
#include "./TNectarDisplay.h"
#include "./libGo4UserAnalysise7c62a8a82_dictUmbrella.h"
#include "./TNectarProfileEvent.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TMdppAdcData", payloadCode, "@",
"TMdppBoard", payloadCode, "@",
"TMdppDisplay", payloadCode, "@",
"TMdppMsg", payloadCode, "@",
"TMdppTdcData", payloadCode, "@",
"TNectarAnalysis", payloadCode, "@",
"TNectarBoard", payloadCode, "@",
"TNectarBoardDisplay", payloadCode, "@",
"TNectarDetectors", payloadCode, "@",
"TNectarHistograms", payloadCode, "@",
"TNectarMonitoringEvent", payloadCode, "@",
"TNectarMonitoringProc", payloadCode, "@",
"TNectarProfileEvent", payloadCode, "@",
"TNectarProfileProc", payloadCode, "@",
"TNectarRawEvent", payloadCode, "@",
"TNectarRawParam", payloadCode, "@",
"TNectarRawProc", payloadCode, "@",
"TNectarTelescope", payloadCode, "@",
"TVmmrAdcData", payloadCode, "@",
"TVmmrBoard", payloadCode, "@",
"TVmmrDisplay", payloadCode, "@",
"TVmmrMsg", payloadCode, "@",
"TVmmrSlave", payloadCode, "@",
"TVmmrSlaveDisplay", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGo4UserAnalysis",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGo4UserAnalysis_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGo4UserAnalysis_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGo4UserAnalysis() {
  TriggerDictionaryInitialization_libGo4UserAnalysis_Impl();
}
