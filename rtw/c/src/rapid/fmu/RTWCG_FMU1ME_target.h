/* Copyright 1990-2017 The MathWorks, Inc. */
/*
 * @file: RTWCG_FMU1_target.h
 *  
 * @brief fmustruct 
 *
 * Abstract:
 *      FMI 1.0 data types, function signatures and FMU2_CS_RTWCG(struct)
 *
 *      FMU1_CS_RTWCG is a data struct to store FMU info, handle all 
 *      dynamic function calls to FMU lib 
 *      
 * =============================================================================
 */


/* 

   Type definitions of variables passed as arguments
   Version "standard32" means:

   fmiComponent     : 32 bit pointer
   fmiValueReference: 32 bit
   fmiReal          : 64 bit
   fmiInteger       : 32 bit
   fmiBoolean       :  8 bit
   fmiString        : 32 bit pointer

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <simstruc.h>
#include <slsv_diagnostic_codegen_c_api.h>
#include "FMUME1Header/fmiFunctions.h"

/*raccel_utils.h is needed by win plateform to mute warning warning C4013*/
#include "rapid/raccel_utils.h"

#ifndef __FMU1_COMMON
#define __FMU1_COMMON

#ifdef _WIN32
#include "windows.h"
#define FMUHANDLE                      HMODULE
#define LOAD_LIBRARY(LIBRARY_LOC)      LoadLibraryEx(LIBRARY_LOC, NULL, LOAD_WITH_ALTERED_SEARCH_PATH)
#define LOAD_FUNCTION                  GetProcAddress
#define CLOSE_LIBRARY                  FreeLibrary

#else
#include <dlfcn.h>
#define FMUHANDLE                      void*
#define LOAD_LIBRARY(LIBRARY_LOC)      dlopen(LIBRARY_LOC, RTLD_NOW | RTLD_LOCAL)
#define LOAD_FUNCTION                  dlsym
#define CLOSE_LIBRARY                  dlclose
#endif

#define FULL_FCN_NAME_MAX_LEN 256
#define FCN_NAME_MAX_LEN      28

#ifndef isSimTargetSimulating_GUARD
#define isSimTargetSimulating_GUARD
#define isSimTargetSimulating(S)                                      \
    ssGetSimMode((SimStruct*)(S))==SS_SIMMODE_NORMAL || ssRTWGenIsAccelerator((SimStruct*)(S))
#endif

#ifndef ssGetMdlSfuncS_GUARD
#define ssGetMdlSfuncS_GUARD
#define ssGetMdlSfuncS(S)                \
    (S)->_mdlRefSfcnS
#endif

#ifndef RTWCG_FMU1ME_GUARD
#define RTWCG_FMU1ME_GUARD
/*typedef default function type*/
typedef fmiStatus (*_fmi_default_fcn_type) (fmiComponent, ...);

/***************************************************
Types for FMI 1.0 Common Functions
****************************************************/
typedef const char* (*_fmiGetVersion)(void);
typedef fmiStatus (*_fmiSetDebugLogging)    (fmiComponent c, fmiBoolean loggingOn);
typedef fmiStatus (*_fmiSetReal)   (fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiReal    value[]);
typedef fmiStatus (*_fmiSetInteger)(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiInteger value[]);
typedef fmiStatus (*_fmiSetBoolean)(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiBoolean value[]);
typedef fmiStatus (*_fmiSetString) (fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiString  value[]);
typedef fmiStatus (*_fmiGetReal)   (fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiReal    value[]);
typedef fmiStatus (*_fmiGetInteger)(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiInteger value[]);
typedef fmiStatus (*_fmiGetBoolean)(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiBoolean value[]);
typedef fmiStatus (*_fmiGetString) (fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiString  value[]);
#endif
/*Model Exchange*/
typedef const char* (*_fmiGetModelTypesPlatform)(void);
typedef fmiComponent (*_fmiInstantiateModel) (fmiString            instanceName,
                                           fmiString            GUID,
                                           fmiCallbackFunctions functions,
                                           fmiBoolean           loggingOn);
typedef void      (*_fmiFreeModelInstance) (fmiComponent c);
typedef fmiStatus (*_fmiSetTime)                (fmiComponent c, fmiReal time);
typedef fmiStatus (*_fmiSetContinuousStates)    (fmiComponent c, const fmiReal x[], size_t nx);
typedef fmiStatus (*_fmiCompletedIntegratorStep) (fmiComponent c, fmiBoolean* callEventUpdate);
typedef fmiStatus (*_fmiInitialize) (fmiComponent c, fmiBoolean toleranceControlled,
                                 fmiReal relativeTolerance, fmiEventInfo* eventInfo);
typedef fmiStatus (*_fmiGetDerivatives)    (fmiComponent c, fmiReal derivatives[]    , size_t nx);
typedef fmiStatus (*_fmiGetEventIndicators)(fmiComponent c, fmiReal eventIndicators[], size_t ni);
typedef fmiStatus (*_fmiEventUpdate)               (fmiComponent c, fmiBoolean intermediateResults, fmiEventInfo* eventInfo);
typedef fmiStatus (*_fmiGetContinuousStates)       (fmiComponent c, fmiReal states[], size_t nx);
typedef fmiStatus (*_fmiGetNominalContinuousStates)(fmiComponent c, fmiReal x_nominal[], size_t nx);
typedef fmiStatus (*_fmiGetStateValueReferences)   (fmiComponent c, fmiValueReference vrx[], size_t nx);
typedef fmiStatus (*_fmiTerminate) (fmiComponent c);

struct FMU1_ME_RTWCG {
    _fmiGetModelTypesPlatform getModelTypesPlatform;
    _fmiGetVersion getVersion;
    
    _fmiSetDebugLogging setDebugLogging;
    _fmiSetReal setReal;
    _fmiSetInteger setInteger;
    _fmiSetBoolean setBoolean;
    _fmiSetString setString;
    _fmiGetReal getReal;
    _fmiGetInteger getInteger;
    _fmiGetBoolean getBoolean;
    _fmiGetString getString;

    _fmiInstantiateModel  instantiateModel;
    _fmiFreeModelInstance freeModelInstance;
    _fmiSetTime setTime;
    _fmiSetContinuousStates setContinuousStates;
    _fmiCompletedIntegratorStep completedIntegratorStep;
    _fmiInitialize initialize;
    _fmiGetDerivatives getDerivatives;
    _fmiGetEventIndicators getEventIndicators;
    _fmiEventUpdate eventUpdate;
    _fmiGetContinuousStates getContinuousStates;
    _fmiGetNominalContinuousStates getNominalContinuousStates;
    _fmiGetStateValueReferences getStateValueReferences;
    _fmiTerminate terminate;
    
    char * fmuname;
    char * dllfile;
    FMUHANDLE Handle;
    fmiComponent mFMIComp;
    SimStruct *ssPtr;
    fmiStatus FMUErrorStatus;

    fmiEventInfo eventInfo;
};

/**/

void fmu1Logger(fmiComponent c, fmiString instanceName, fmiStatus status,
                      fmiString category, fmiString message, ...);


fmiBoolean FMU1_terminateModel(void **fmuv); /*include terminate and freeModel*/
fmiStatus FMU1_initialize(void **fmuv, fmiReal isToleranceUsed, fmiReal toleranceValue);
fmiStatus FMU1_setTime(void **fmuv, fmiReal time);
fmiStatus FMU1_completedIntegratorStep(void **fmuv, int8_T* hasStepEvent);
fmiStatus FMU1_setContinuousStates(void **fmuv, fmiReal states[], size_t nx);
fmiStatus FMU1_getContinuousStates(void **fmuv, fmiReal states[], size_t nx);
fmiStatus FMU1_getDerivatives(void **fmuv, fmiReal derivatives[], size_t nx);
fmiStatus FMU1_getEventIndicators(void **fmuv, fmiReal eventIndicators[], size_t nx);

/*event helper function*/
fmiStatus FMU1_eventIteration(void **fmuv, const char* blkPath, fmiReal time);
void FMU1_ifStateVRchanged(void **fmuv, int8_T* fmustateValueOrStateValueRefChanged);
void FMU1_setIterationConverged(void **fmuv, int fmuIsInitialized, fmiReal time);
void FMU1_getNextEventTime(void **fmuv, fmiReal* nextEventTime, int8_T* upcomingTimeEvent);

fmiStatus FMU1ME_setRealVal(void **fmuv, const fmiValueReference dvr, size_t nvr, const fmiReal dvalue);
fmiStatus FMU1ME_setReal(void **fmuv, const fmiValueReference dvr, size_t nvr, const fmiReal value[]);
fmiStatus FMU1ME_getReal(void **fmuv, const fmiValueReference dvr, size_t nvr, fmiReal value[]);
fmiStatus FMU1ME_setIntegerVal(void **fmuv, const fmiValueReference dvr, size_t nvr, const fmiInteger dvalue);
fmiStatus FMU1ME_setInteger(void **fmuv, const fmiValueReference dvr, size_t nvr, const fmiInteger value[]);
fmiStatus FMU1ME_getInteger(void **fmuv, const fmiValueReference vr, size_t nvr, fmiInteger value[]);
fmiStatus FMU1ME_setBooleanVal(void **fmuv, const fmiValueReference dvr, size_t nvr, const unsigned char dvalue);
fmiStatus FMU1ME_setBoolean(void **fmuv, const fmiValueReference dvr, size_t nvr, const unsigned char value[]);
fmiStatus FMU1ME_getBoolean(void **fmuv, const fmiValueReference dvr, size_t nvr, unsigned char value[]);
fmiStatus FMU1ME_setString(void **fmuv, const fmiValueReference dvr, size_t nvr, const fmiString value[]);
fmiStatus FMU1ME_setStringVal(void **fmuv, const fmiValueReference dvr, size_t nvr, const fmiString);
fmiStatus FMU1ME_getString(void **fmuv, const fmiValueReference vr, size_t nvr, fmiString value[]);


void * FMU1_fmuInitializeME( const char * lib, fmiString instanceName, fmiString fmuLocation, fmiString fmuGUID, void* ssPtr);

void LoadFMU1MEFunctions(struct FMU1_ME_RTWCG * fmustruct);
void checkTerminateStatus(void **fmuv, const char* blkPath, fmiReal time);

#endif
