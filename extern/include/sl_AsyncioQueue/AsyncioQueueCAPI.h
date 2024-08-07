/* Copyright 2012-2018 The MathWorks, Inc. */

#ifndef ASYNCIO_QUEUE_CAPI_H
#define ASYNCIO_QUEUE_CAPI_H

#include "tmwtypes.h"

#ifndef DLL_EXPORT_SYM
#ifdef SL_INTERNAL
#include "package.h"
#else
#define DLL_EXPORT_SYM
#endif
#endif

#ifdef __cplusplus
#define ASYNCIOQUEUE_EXPORT_EXTERN_C extern "C" DLL_EXPORT_SYM
#else
#define ASYNCIOQUEUE_EXPORT_EXTERN_C extern DLL_EXPORT_SYM
#endif

typedef const char * sdiModelName;

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiInitializeRepository(void);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiInitializeForHostBasedTarget(
    boolean_T bStreamToHost,
    const char * sdrFileName,
    const char * logOptsFileName);

ASYNCIOQUEUE_EXPORT_EXTERN_C boolean_T sdiIsUsingInlineAsyncQueues(void);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiBindObserversAndStartStreamingEngine(sdiModelName modelName);

#if !defined(_WIN32) || !defined(__LCC__) || defined(__LCC64__)

typedef INT64_T sdiSignalHandle;
typedef INT64_T sdiDataTypeHandle;
typedef void * sdiAsyncQueueHandle;
typedef const CHAR16_T * sdiModelNameU;
typedef const char *const * sdiFullBlkPath;
typedef const CHAR16_T *const * sdiFullBlkPathU;
typedef const char *const * sdiSignalID;
typedef const CHAR16_T *const * sdiSignalIDU;
typedef const char * sdiSignalName;
typedef const CHAR16_T * sdiSignalNameU;
typedef CHAR16_T * sdiLabelU;
typedef const char * sdiSignalSourceUUID;
typedef INT64_T sdiSignalSourceIntegerUUID;
typedef char * sdiSignalPathToLeafElem;
typedef const CHAR16_T * sdiSignalPathToLeafElemU;
typedef const char * sdiAliasedName;
typedef const char * sdiEnumName;
typedef const char * sdiEnumClassification;
typedef const char ** const sdiEnumLabels;
typedef const char * sdiMetaDataName;
typedef const char * sdiStringMetaDataValue;
typedef const CHAR16_T * sdiStringMetaDataValueU;
typedef const CHAR16_T * sdiUnitsU;
typedef const char * sdiSubPath;
typedef const CHAR16_T * sdiSubPathU;

typedef const void * sdiAsyncRepoDataTypeHandle;
typedef void * sdiDataTypeTable;
typedef void * sdiHierarchyDefinition;
typedef const void * sdiHierarchyDefinitionInteral;

typedef enum {
    DATA_TYPE_DOUBLE = 0,
    DATA_TYPE_SINGLE,
    DATA_TYPE_INT8,
    DATA_TYPE_UINT8,
    DATA_TYPE_INT16,
    DATA_TYPE_UINT16,
    DATA_TYPE_INT32,
    DATA_TYPE_UINT32,
    DATA_TYPE_BOOLEAN
} sdiBuiltInDTypeId;

typedef enum {
    DIMENSIONS_MODE_FIXED,
    DIMENSIONS_MODE_VARIABLE
} sdiDimsMode;

typedef enum {
    REAL,
    COMPLEX
} sdiComplexity;

typedef struct {
    sdiFullBlkPath fullBlockPath;
    sdiSubPath subPath;
    sdiSignalID SID;
    unsigned int numBlockPathElems;
    int portIndex;
    sdiSignalName signalName;
    sdiSignalSourceUUID sigSourceUUID;
} sdiSignalSourceInfo;

typedef struct {
    sdiFullBlkPathU fullBlockPath;
    sdiSubPathU subPath;
    sdiSignalIDU SID;
    unsigned int numBlockPathElems;
    int portIndex;
    sdiSignalNameU signalName;
    sdiSignalSourceIntegerUUID sigSourceUUID;
} sdiSignalSourceInfoU;

typedef struct {
    int nDims;
    SLSize * dimensions;
} sdiDims;

typedef enum {
    SAMPLE_TIME_CONTINUOUS,
    SAMPLE_TIME_DISCRETE
} sdiSampleTimeContinuity;

typedef struct {
    const void * data;
    int blobLength;
} sdiBlobDescription;

typedef struct {
    int numericDT;
    int signedness;
    int wordLength;
} sdiFxpPropsUnspecifiedScaling;

typedef struct {
    int numericDT;
    int signedness;
    int wordLength;
    int fractionLength;
} sdiFxpPropsBinaryPointScaling;

typedef struct {
    int numericDT;
    int signedness;
    int wordLength;
    double slpAdjustmentFactor;
    int fixedExponent;
    double bias;
} sdiFxpPropsSlpBiasScaling;

typedef enum {
    ENUM_INT8   = 2,
    ENUM_UINT8  = 3,
    ENUM_INT16  = 4,
    ENUM_UINT16 = 5,
    ENUM_INT32  = 6,
    ENUM_UINT32 = 7,
    NOT_AN_ENUM = 100
} sdiEnumerationBaseClass;

typedef enum {
    LEAF_BUILT_IN,
    LEAF_FIXED_POINT,
    LEAF_ENUM,
    LEAF_STRING
} sdiLeafSignalDataTypeClass;

typedef struct {
    sdiSignalPathToLeafElem signalPath;
    sdiBuiltInDTypeId builtInDataTypeId;
    sdiFxpPropsUnspecifiedScaling * fxpPropsUnspecifiedScaling;
    sdiFxpPropsBinaryPointScaling * fxpPropsBinaryPointScaling;
    sdiFxpPropsSlpBiasScaling * fxpPropsSlpBiasScaling;
    sdiEnumerationBaseClass enumerationBaseClass;
    sdiLeafSignalDataTypeClass signalDataTypeClass;
    int byteOffset;
    sdiComplexity complexity;
    sdiDims dims;
    sdiDimsMode dimsMode;
    int isLinearInterp;
} sdiLeafElementInfo;

typedef struct {
    sdiSignalPathToLeafElemU signalPathU;
    sdiBuiltInDTypeId builtInDataTypeId;
    sdiFxpPropsUnspecifiedScaling * fxpPropsUnspecifiedScaling;
    sdiFxpPropsBinaryPointScaling * fxpPropsBinaryPointScaling;
    sdiFxpPropsSlpBiasScaling * fxpPropsSlpBiasScaling;
    sdiEnumerationBaseClass enumerationBaseClass;
    sdiLeafSignalDataTypeClass signalDataTypeClass;
    int sigDataTypeId;
    int rawDataTypeId;
    sdiAsyncRepoDataTypeHandle hDataType;
    int byteOffset;
    sdiComplexity complexity;
    sdiDims dims;
    sdiDimsMode dimsMode;
    int isLinearInterp;
    sdiUnitsU unitsU;
} sdiLeafElementInfoU;

typedef struct {
    sdiSignalNameU signalName;
    sdiAsyncRepoDataTypeHandle hDataType;
    sdiDims dims;
    sdiDimsMode dimsMode;
    sdiComplexity complexity;
    int isLinearInterp;
    const char * units;
} sdiVirtualBusLeafElementInfoU;

typedef enum {
    ROLLBACK_NORMAL = 0,
    ROLLBACK_KEEP_INIT_VALUES = 1
} sdiRollbackMode;

typedef struct sdiVideoInfo sdiVideoInfo;
typedef uint32_T(*sdiEncodeImageFrameFcn) (const sdiVideoInfo *, const void *, void *);
struct sdiVideoInfo {
    uint32_T imageWidth;
    uint32_T imageHeight;
    double frameRate;
    sdiBuiltInDTypeId pixelBaseType;
    uint32_T maxFrameBytes;
    sdiEncodeImageFrameFcn encodeFcn;
    const char * observerType;
};

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiLabelU sdiGetLabelFromChars(sdiSignalName);
ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiFreeLabel(sdiLabelU);
ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiFreeName(sdiSignalNameU);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoGetBuiltInDataTypeHandle(
    const sdiBuiltInDTypeId dataTypeClassification);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoCreateAliasedDataType(
    sdiAliasedName aliasedName,
    const sdiBuiltInDTypeId dataTypeClassification);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetAliasedDataTypeName(
    sdiAsyncRepoDataTypeHandle hDT,
    sdiAliasedName aliasedName);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoCreateEnumDataType(
    sdiEnumName enumName,
    sdiEnumClassification enumClassification,
    const int numValues,
    const int *const values,
    sdiEnumLabels labels);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoCreateFixedPointDataType_BinaryPointScaling(
    const int numericType,
    const int signedness,
    const int wordLength,
    const int fractionLength);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoCreateFixedPointDataType_SlopeBiasScaling(
    const int numericType,
    const int signedness,
    const int wordLength,
    const double slopeAdjFactor,
    const int fixedExponent,
    const double bias);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoGetPointerDataTypeHandle(void);

typedef enum {
    STRING_CHAR_ARRAY,
    STRING_FL_USTRING_PTR
} SDI_String_Format;

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoGetStringDataTypeHandle(void);
ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoGetCharArrayStringDataTypeHandle(void);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncRepoDataTypeHandle sdiAsyncRepoGetInt64DataTypeHandle(boolean_T bSigned);

ASYNCIOQUEUE_EXPORT_EXTERN_C int sdiGetDataSizeInBytes(
    const sdiAsyncRepoDataTypeHandle hDataType);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiHierarchyDefinition sdiCreateBusHierDefinition(
    sdiHierarchyDefinition parentHier,
    sdiSignalName name,
    const sdiDims * dims,
    const int busTypeBytes);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAddBusHierLeaf(
    sdiHierarchyDefinition parentHier,
    sdiSignalName name,
    sdiUnitsU units,
    int byteOffset,
    const sdiAsyncRepoDataTypeHandle hDT,
    const sdiComplexity complexity,
    const sdiDims * dims,
    const sdiSampleTimeContinuity sampleTimeContinuity);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAddBusHierLeafWithCustomHierarchy(
    sdiHierarchyDefinition parentHier,
    sdiSignalName name,
    sdiUnitsU units,
    int byteOffset,
    const sdiAsyncRepoDataTypeHandle hDT,
    const sdiComplexity complexity,
    const sdiDims * dims,
    const sdiSampleTimeContinuity sampleTimeContinuity,
    const sdiSignalPathToLeafElemU customHierarchy,
    const sdiSignalPathToLeafElemU customBlockPath);

ASYNCIOQUEUE_EXPORT_EXTERN_C boolean_T sdiIsAsyncQueueDisabled(sdiAsyncQueueHandle hAsyncQueue);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiAsyncRepoCreateAsyncioQueue(
    const sdiAsyncRepoDataTypeHandle hDataType,
    const sdiSignalSourceInfoU * sigSourceInfo,
    const char_T *const modelRefPath,
    const char_T *const sigSourceUUIDstr,
    const sdiComplexity complexity,
    const sdiDims * dims,
    const sdiDimsMode dimsMode,
    const sdiSampleTimeContinuity sampleTimeContinuity,
    const char_T *const units);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiStartAsyncioQueueCreation(
    const sdiAsyncRepoDataTypeHandle hDataType,
    const sdiSignalSourceInfoU * sigSourceInfo,
    const char_T *const modelRefPath,
    const char_T *const sigSourceUUIDstr,
    const sdiComplexity complexity,
    const sdiDims * dims,
    const sdiDimsMode dimsMode,
    const sdiSampleTimeContinuity sampleTimeContinuity,
    const char_T *const units);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiCompleteAsyncioQueueCreation(
    const sdiAsyncQueueHandle hAsyncQueue,
    const sdiAsyncRepoDataTypeHandle hDataType,
    const sdiSignalSourceInfoU * sigSourceInfo);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiCreateAsyncQueueForNVBus(
    sdiHierarchyDefinition * hierarchy,
    const sdiSignalSourceInfoU * sigSourceInfo,
    const char_T *const modelRefPath,
    const char_T *const sigSourceUUIDstr,
    const int busSize,
    const sdiDims * dims,
    const sdiSampleTimeContinuity sampleTimeContinuity,
    const int decimation,
    const int maxPoints,
    sdiSignalName loggedName,
    sdiSignalName origSignalName,
    sdiSignalName propName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiCreateAsyncQueuesForVirtualBus(
    const sdiSignalSourceInfoU * sigSourceInfo,
    const char_T *const modelRefPath,
    const char_T *const sigSourceUUIDstr,
    const int numLeafSignals,
    const sdiVirtualBusLeafElementInfoU *const infoForAllLeafSignals,
    sdiAsyncQueueHandle *hAsyncQueues);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiCreateAsyncQueuesForVirtualBusWithExportSettings(
    const sdiSignalSourceInfoU * sigSourceInfo,
    const char_T *const modelRefPath,
    const char_T *const sigSourceUUIDstr,
    const int numLeafSignals,
    const sdiVirtualBusLeafElementInfoU *const infoForAllLeafSignals,
    sdiAsyncQueueHandle *hAsyncQueues,
    const int decimation,
    const int maxPoints,
    sdiSignalName loggedName,
    sdiSignalName origSignalName,
    sdiSignalName propName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetSignalExportSettings(
    sdiAsyncQueueHandle hAsyncQueue,
    const int decimation,
    const int maxPoints);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetSignalExportName(
    sdiAsyncQueueHandle hAsyncQueue,
    sdiSignalNameU loggedName,
    sdiSignalNameU signalName,
    sdiSignalNameU propagatedName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetSignalDomainType(
    sdiAsyncQueueHandle hAsyncQueue,
    const char_T *const type);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetSignalExportOrder(
    sdiAsyncQueueHandle hAsyncQueue,
    const int val);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetRollbackMode(
    sdiAsyncQueueHandle hAsyncQueue,
    sdiRollbackMode mode);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSignalSampleTimeString(
    sdiAsyncQueueHandle hAsyncQueue,
    const char_T * sampleTime,
    const double discreteIncrement,
    const double stopTime);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSignalIsFrameBased(
    sdiAsyncQueueHandle hAsyncQueue,
    const boolean_T isFrame);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiDisableCompressedTime(
    sdiAsyncQueueHandle hAsyncQueue);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiEnableTemporalOrdering(
    sdiAsyncQueueHandle hAsyncQueue,
    const int enableOrdering);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiDisableDataThinning(
    sdiAsyncQueueHandle hAsyncQueue);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetRunStartTime(
    sdiAsyncQueueHandle hAsyncQueue,
    const double runStartTime);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetModelDisplayNameForQueue(
    sdiAsyncQueueHandle hAsyncQueue,
    const sdiModelNameU modelDisplayName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiWriteSignal(
    sdiAsyncQueueHandle hAsyncQueue,
    const double time,
    const void *const data);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSynchronouslyFlushAllQueuesInThisModel(
    sdiModelName modelName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSynchronouslyFlushAllQueuesInThisModelU(
    sdiModelNameU modelName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiPurgeAllRunDataIfStepbackOverStartTime(
    sdiModelNameU modelName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiRollbackModelToPreviousTime(
    sdiModelName modelName,
    const double time);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiRollbackModelToPreviousTimeU(
    sdiModelNameU modelName,
    const double time);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetModelSimStatusToInactive(
    sdiModelNameU modelName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiTerminateStreaming(
    sdiAsyncQueueHandle * hAsyncQueue);

ASYNCIOQUEUE_EXPORT_EXTERN_C boolean_T sdiIsQueueStreaming(const sdiAsyncQueueHandle);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiStartProfiling(
    const char * phase);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiStopProfiling(
    const char * phase);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSignalNameForVirtualBus(
    sdiAsyncQueueHandle hAsyncQueue,
    const sdiSignalNameU signalName);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiGetDataTypeHandle(
    sdiDataTypeTable dataTypeTable,
    const int sigDataTypeId,
    const int rawDataTypeId);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiGetBuiltInDataTypeHandle(
    const sdiBuiltInDTypeId dataTypeClassification);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiCreateAliasedDataType(
    sdiAliasedName aliasedName,
    const sdiBuiltInDTypeId dataTypeClassification);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiCreateEnumDataType(
    sdiEnumName enumName,
    sdiEnumClassification enumClassification,
    const int numValues,
    const int *const values,
    sdiEnumLabels labels);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiCreateFixedPointDataType_UnspecifiedScaling(
    const int numericType,
    const int signedness,
    const int wordLength);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiCreateFixedPointDataType_BinaryPointScaling(
    const int numericType,
    const int signedness,
    const int wordLength,
    const int fractionLength);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiDataTypeHandle sdiCreateFixedPointDataType_SlopeBiasScaling(
    const int numericType,
    const int signedness,
    const int wordLength,
    const double slopeAdjFactor,
    const int fixedExponent,
    const double bias);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiSignalHandle sdiCreateSignal(
    const sdiSignalHandle *const hParent,
    const sdiDimsMode dimensionsMode,
    const sdiDims dims,
    const sdiComplexity complexity,
    const sdiSampleTimeContinuity sampleTimeContinuity,
    const sdiDataTypeHandle hDataType);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSignalDomainType(
    sdiSignalHandle hSig,
    const char_T *const type);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiSignalHandle sdiCreateHierarchicalSignal(
    const sdiSignalHandle *const hParent,
    const sdiDimsMode dimensionsMode,
    const sdiDims dims);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSourceInfo(
    const sdiSignalHandle hSig,
    const sdiSignalSourceInfo sigSourceInfo);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSourceInfoU(
    const sdiSignalHandle hSig,
    const sdiSignalSourceInfoU sigSourceInfo);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetSourceInfoU(
    const sdiSignalHandle hSig,
    const sdiSignalSourceInfoU sigSourceInfo);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoSetCommonSignalPropertiesForBus(
    const sdiSignalHandle hRoot,
    const sdiModelNameU topModel);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiRegisterSignalWithAsyncioQueue(
    const sdiSignalHandle hSig);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiAsyncRepoRegisterSignalWithAsyncioQueue(
    const sdiSignalHandle hSig,
    const sdiSignalSourceInfoU sigSourceInfo,
    const sdiComplexity complexity,
    const sdiDims dims,
    const sdiDimsMode dimsMode,
    const sdiSampleTimeContinuity sampleTimeContinuity);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiRegisterHierarchicalSignalWithAsyncioQueue(
    const sdiSignalHandle hSig,
    const int numLeafSignals,
    const sdiLeafElementInfo *const infoForAllLeafSignals,
    const int busSize);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiAsyncRepoRegisterHierarchicalSignalWithAsyncioQueue(
    const sdiSignalHandle hSig,
    const sdiSignalSourceIntegerUUID sigSourceUUID,
    const int numLeafSignals,
    const sdiLeafElementInfo *const infoForAllLeafSignals,
    const int busSize,
    const int numBlockPathElems,
    const sdiFullBlkPathU fullBlockPath,
    const int portIndex,
    const sdiDims dims,
    const sdiDimsMode dimsMode,
    const sdiSampleTimeContinuity sampleTimeContinuity);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetQueueIsForVerifySignalStreaming(
    sdiAsyncQueueHandle hQueue,
    const int isForVerifySignalStreaming);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiBindQueueWithTestResult(
    sdiAsyncQueueHandle hQueue,
    int *const pResultAddress);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoAddIntMetaData(
    sdiAsyncQueueHandle hQueue,
    sdiMetaDataName name,
    const int value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAddIntMetaData(
    const sdiSignalHandle hSig,
    sdiMetaDataName name,
    const int value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoAddFloatMetaData(
    sdiAsyncQueueHandle hQueue,
    sdiMetaDataName name,
    const double value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAddFloatMetaData(
    const sdiSignalHandle hSig,
    sdiMetaDataName name,
    const double value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoAddStringMetaData(
    sdiAsyncQueueHandle hQueue,
    sdiMetaDataName name,
    sdiStringMetaDataValue value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAsyncRepoAddStringMetaDataU(
    sdiAsyncQueueHandle hQueue,
    sdiMetaDataName name,
    sdiStringMetaDataValueU value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAddStringMetaData(
    const sdiSignalHandle hSig,
    sdiMetaDataName name,
    sdiStringMetaDataValue value);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAddStringMetaDataU(
    const sdiSignalHandle hSig,
    sdiMetaDataName name,
    sdiStringMetaDataValueU value);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiAsyncQueueHandle sdiCreateForEachParent(
    const sdiSignalSourceInfoU * sigSourceInfo,
    const char_T *const modelRefPath,
    const sdiDims * dims,
    sdiSignalNameU loggedName,
    sdiSignalNameU origSignalName,
    sdiSignalNameU propName,
    sdiDims * mdlRefDims);

ASYNCIOQUEUE_EXPORT_EXTERN_C sdiLabelU sdiUpdateForEachLeafName(
    sdiSignalSourceInfoU * sigSourceInfo,
    sdiAsyncQueueHandle hParent);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiAttachForEachIterationToParent(
    sdiAsyncQueueHandle hParent,
    sdiAsyncQueueHandle hChild,
    const sdiDims * iterIdx);

ASYNCIOQUEUE_EXPORT_EXTERN_C void* sdiGetLoggingIntervals(
    const char_T *const fullPath);

ASYNCIOQUEUE_EXPORT_EXTERN_C void* sdiGetSlioCatalogue(
    const char_T *const fullPath);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSlioSdiWriteSignal(
    sdiAsyncQueueHandle hAsyncQueue,
    void* accessor,
    const int portIdx,
    const double time,
    const void *const data);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSlioIsLoggingSignal(
    const char *modelBlockPath,
    const char *localBlockPath,
    const unsigned int portIdx,
    const char *loggedName);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiEnableRemoteInstrumentationForModel(sdiSignalSourceInfoU signalInfo);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiDisableRemoteInstrumentationForModel(sdiSignalSourceInfoU signalInfo);

ASYNCIOQUEUE_EXPORT_EXTERN_C void sdiSetSignalAsVideo(
    sdiAsyncQueueHandle hAsyncQueue,
    const sdiVideoInfo * pMetaData);

#endif
#endif

