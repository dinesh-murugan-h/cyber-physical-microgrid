/*
 * static_model.c
 *
 * automatically generated from src/scl/IED_GEN.icd
 */
#include "gen1_static_model.h"

static void initializeValues();

extern DataSet GEN1_iedModelds_GEN1_LLN0_GenMeasDS;


extern DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda0;
extern DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda1;
extern DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda2;
extern DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda3;

DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda0 = {
  "GEN1",
  false,
  "MMXU1$MX$PhV", 
  -1,
  NULL,
  NULL,
  &GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda1
};

DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda1 = {
  "GEN1",
  false,
  "MMXU1$MX$A", 
  -1,
  NULL,
  NULL,
  &GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda2
};

DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda2 = {
  "GEN1",
  false,
  "MMXU1$MX$Hz", 
  -1,
  NULL,
  NULL,
  &GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda3
};

DataSetEntry GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda3 = {
  "GEN1",
  false,
  "MMXU1$MX$TotW", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet GEN1_iedModelds_GEN1_LLN0_GenMeasDS = {
  "GEN1",
  "LLN0$GenMeasDS",
  4,
  &GEN1_iedModelds_GEN1_LLN0_GenMeasDS_fcda0,
  NULL
};

LogicalDevice GEN1_iedModel_GEN1 = {
    LogicalDeviceModelType,
    "GEN1",
    (ModelNode*) &GEN1_iedModel,
    NULL,
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0,
    NULL
};

LogicalNode GEN1_iedModel_GEN1_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &GEN1_iedModel_GEN1,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1,
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod,
};

DataObject GEN1_iedModel_GEN1_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0,
    NULL,
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute GEN1_iedModel_GEN1_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod,
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod,
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode GEN1_iedModel_GEN1_MMXU1 = {
    LogicalNodeModelType,
    "MMXU1",
    (ModelNode*) &GEN1_iedModel_GEN1,
    NULL,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
};

DataObject GEN1_iedModel_GEN1_MMXU1_PhV = {
    DataObjectModelType,
    "PhV",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA,
    0,
    -1
};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsA = {
    DataAttributeModelType,
    "phsA",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsA_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsA_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsA,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsB = {
    DataAttributeModelType,
    "phsB",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsB_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsB_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsB_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsB_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsB,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsC = {
    DataAttributeModelType,
    "phsC",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsC_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsC_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsC_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_phsC_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_phsC,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_neut = {
    DataAttributeModelType,
    "neut",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_neut_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_neut_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_neut_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_neut_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_neut,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_PhV_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_PhV,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject GEN1_iedModel_GEN1_MMXU1_A = {
    DataObjectModelType,
    "A",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA,
    0,
    -1
};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsA = {
    DataAttributeModelType,
    "phsA",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsA_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsA_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsA,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsB = {
    DataAttributeModelType,
    "phsB",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsB_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsB_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsB_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsB_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsB,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsC = {
    DataAttributeModelType,
    "phsC",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsC_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsC_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsC_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_phsC_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_phsC,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_neut = {
    DataAttributeModelType,
    "neut",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_neut_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_neut_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_neut_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_neut_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_neut,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_A_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_A,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject GEN1_iedModel_GEN1_MMXU1_Hz = {
    DataObjectModelType,
    "Hz",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag,
    0,
    -1
};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_instMag = {
    DataAttributeModelType,
    "instMag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_instMag_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_instMag_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_instMag_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_instMag_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_instMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_Hz_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_Hz,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject GEN1_iedModel_GEN1_MMXU1_TotW = {
    DataObjectModelType,
    "TotW",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1,
    NULL,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag,
    0,
    -1
};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_instMag = {
    DataAttributeModelType,
    "instMag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_instMag_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag_q,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_instMag_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_instMag_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_instMag_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_instMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW,
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute GEN1_iedModel_GEN1_MMXU1_TotW_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &GEN1_iedModel_GEN1_MMXU1_TotW,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

extern ReportControlBlock GEN1_iedModel_GEN1_LLN0_report0;
extern ReportControlBlock GEN1_iedModel_GEN1_LLN0_report1;

ReportControlBlock GEN1_iedModel_GEN1_LLN0_report0 = {&GEN1_iedModel_GEN1_LLN0, "GenReport01", "GEN1_RPT01", false, "GenMeasDS", 1, 19, 63, 0, 1000, {0x4, 0x7f, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &GEN1_iedModel_GEN1_LLN0_report1};
ReportControlBlock GEN1_iedModel_GEN1_LLN0_report1 = {&GEN1_iedModel_GEN1_LLN0, "GenReport02", "GEN1_RPT01", false, "GenMeasDS", 1, 19, 63, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};







IedModel GEN1_iedModel = {
    "IED_GEN1",
    &GEN1_iedModel_GEN1,
    &GEN1_iedModelds_GEN1_LLN0_GenMeasDS,
    &GEN1_iedModel_GEN1_LLN0_report0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{
}
