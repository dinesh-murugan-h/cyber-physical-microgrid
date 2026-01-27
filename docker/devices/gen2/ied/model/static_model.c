/*
 * static_model.c
 *
 * automatically generated from /home/dinesh/Documents/cyber-physical-microgrid/docker/devices/gen2/ied/model/gen2.cid
 */
#include "static_model.h"

static void initializeValues();

extern DataSet iedModelds_GEN2LD0_LLN0_ControlEvents;
extern DataSet iedModelds_GEN2LD0_LLN0_Measurements;
extern DataSet iedModelds_GEN2LD0_LLN0_Setpoints;


extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda0;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda1;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda2;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda3;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda4;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda5;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda6;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda7;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda8;

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda0 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO1$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda1
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda1 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO2$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda2
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda2 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO3$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda3
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda3 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO4$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda4
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda4 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO5$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda5
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda5 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO6$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda6
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda6 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO7$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda7
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda7 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO8$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda8
};

DataSetEntry iedModelds_GEN2LD0_LLN0_ControlEvents_fcda8 = {
  "GEN2LD0",
  false,
  "GGIO1$ST$SPCSO9$stVal", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_GEN2LD0_LLN0_ControlEvents = {
  "GEN2LD0",
  "LLN0$ControlEvents",
  9,
  &iedModelds_GEN2LD0_LLN0_ControlEvents_fcda0,
  &iedModelds_GEN2LD0_LLN0_Measurements
};

extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda0;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda1;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda2;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda3;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda4;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda5;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda6;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda7;

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda0 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn1$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda1
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda1 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn2$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda2
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda2 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn3$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda3
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda3 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn4$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda4
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda4 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn5$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda5
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda5 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn6$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda6
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda6 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn7$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda7
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Measurements_fcda7 = {
  "GEN2LD0",
  false,
  "GGIO1$MX$AnIn8$mag$f", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_GEN2LD0_LLN0_Measurements = {
  "GEN2LD0",
  "LLN0$Measurements",
  8,
  &iedModelds_GEN2LD0_LLN0_Measurements_fcda0,
  &iedModelds_GEN2LD0_LLN0_Setpoints
};

extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda0;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda1;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda2;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda3;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda4;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda5;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda6;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda7;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda8;
extern DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda9;

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda0 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO1$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda1
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda1 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO2$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda2
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda2 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO3$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda3
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda3 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO4$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda4
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda4 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO5$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda5
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda5 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO6$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda6
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda6 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO7$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda7
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda7 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO8$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda8
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda8 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO9$setMag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda9
};

DataSetEntry iedModelds_GEN2LD0_LLN0_Setpoints_fcda9 = {
  "GEN2LD0",
  false,
  "GGIO1$SP$DO10$setMag$f", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_GEN2LD0_LLN0_Setpoints = {
  "GEN2LD0",
  "LLN0$Setpoints",
  10,
  &iedModelds_GEN2LD0_LLN0_Setpoints_fcda0,
  NULL
};

LogicalDevice iedModel_GEN2LD0 = {
    LogicalDeviceModelType,
    "GEN2LD0",
    (ModelNode*) &iedModel,
    NULL,
    (ModelNode*) &iedModel_GEN2LD0_LLN0,
    NULL
};

LogicalNode iedModel_GEN2LD0_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_GEN2LD0,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod,
};

DataObject iedModel_GEN2LD0_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_GEN2LD0_LLN0,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod_q,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_GEN2LD0_LLN0,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_GEN2LD0_LLN0,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_GEN2LD0_LLN0,
    NULL,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_GEN2LD0_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_GEN2LD0_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_GEN2LD0,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyNam,
};

DataObject iedModel_GEN2LD0_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1,
    NULL,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy,
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode iedModel_GEN2LD0_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &iedModel_GEN2LD0,
    NULL,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod,
};

DataObject iedModel_GEN2LD0_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod_q,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn2 = {
    DataObjectModelType,
    "AnIn2",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn2_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn2_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn3 = {
    DataObjectModelType,
    "AnIn3",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn3_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn3_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn4 = {
    DataObjectModelType,
    "AnIn4",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn4_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn4_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn5 = {
    DataObjectModelType,
    "AnIn5",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn5_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn5_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn5_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn5_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn6 = {
    DataObjectModelType,
    "AnIn6",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn6_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn6_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn6_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn6_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn7 = {
    DataObjectModelType,
    "AnIn7",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn7_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn7_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn7_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn7_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn7,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_AnIn8 = {
    DataObjectModelType,
    "AnIn8",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8_mag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn8_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn8_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn8_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_AnIn8_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_AnIn8,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO2 = {
    DataObjectModelType,
    "SPCSO2",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO2_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO3 = {
    DataObjectModelType,
    "SPCSO3",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO3_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO4 = {
    DataObjectModelType,
    "SPCSO4",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO4_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO5 = {
    DataObjectModelType,
    "SPCSO5",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO5_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO6 = {
    DataObjectModelType,
    "SPCSO6",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO6_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO7 = {
    DataObjectModelType,
    "SPCSO7",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO7_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO7,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO8 = {
    DataObjectModelType,
    "SPCSO8",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO8_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO8,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_SPCSO9 = {
    DataObjectModelType,
    "SPCSO9",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_stVal,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_ctlNum,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_SPCSO9_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_SPCSO9,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_Ind2 = {
    DataObjectModelType,
    "Ind2",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_Ind3 = {
    DataObjectModelType,
    "Ind3",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_Ind4 = {
    DataObjectModelType,
    "Ind4",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4_stVal,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_Ind4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_Ind4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO1 = {
    DataObjectModelType,
    "DO1",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO1_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO1_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO2 = {
    DataObjectModelType,
    "DO2",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO2_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO2_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO3 = {
    DataObjectModelType,
    "DO3",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO3_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO3_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO4 = {
    DataObjectModelType,
    "DO4",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO4_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO4_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO5 = {
    DataObjectModelType,
    "DO5",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO5_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO5_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO5_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO5_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO6 = {
    DataObjectModelType,
    "DO6",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO6_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO6_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO6_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO6_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO7 = {
    DataObjectModelType,
    "DO7",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO7_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO7_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO7_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO7_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO7,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO8 = {
    DataObjectModelType,
    "DO8",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO8_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO8_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO8_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO8_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO8,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO9 = {
    DataObjectModelType,
    "DO9",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO9_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO9_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO9_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO9_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO9,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_GEN2LD0_GGIO1_DO10 = {
    DataObjectModelType,
    "DO10",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1,
    NULL,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10_setMag,
    0,
    -1
};

DataAttribute iedModel_GEN2LD0_GGIO1_DO10_setMag = {
    DataAttributeModelType,
    "setMag",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10_q,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10_setMag_f,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO10_setMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10_setMag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO10_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10,
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10_t,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_GEN2LD0_GGIO1_DO10_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GEN2LD0_GGIO1_DO10,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

extern ReportControlBlock iedModel_GEN2LD0_LLN0_report0;
extern ReportControlBlock iedModel_GEN2LD0_LLN0_report1;
extern ReportControlBlock iedModel_GEN2LD0_LLN0_report2;
extern ReportControlBlock iedModel_GEN2LD0_LLN0_report3;
extern ReportControlBlock iedModel_GEN2LD0_LLN0_report4;
extern ReportControlBlock iedModel_GEN2LD0_LLN0_report5;

ReportControlBlock iedModel_GEN2LD0_LLN0_report0 = {&iedModel_GEN2LD0_LLN0, "ControlEventsRCB01", "ControlEvents", false, "ControlEvents", 1, 17, 239, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &iedModel_GEN2LD0_LLN0_report1};
ReportControlBlock iedModel_GEN2LD0_LLN0_report1 = {&iedModel_GEN2LD0_LLN0, "ControlEventsRCB02", "ControlEvents", false, "ControlEvents", 1, 17, 239, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &iedModel_GEN2LD0_LLN0_report2};
ReportControlBlock iedModel_GEN2LD0_LLN0_report2 = {&iedModel_GEN2LD0_LLN0, "MeasurementsRCB01", "Measurements", false, "Measurements", 1, 17, 239, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &iedModel_GEN2LD0_LLN0_report3};
ReportControlBlock iedModel_GEN2LD0_LLN0_report3 = {&iedModel_GEN2LD0_LLN0, "MeasurementsRCB02", "Measurements", false, "Measurements", 1, 17, 239, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &iedModel_GEN2LD0_LLN0_report4};
ReportControlBlock iedModel_GEN2LD0_LLN0_report4 = {&iedModel_GEN2LD0_LLN0, "SetpointsRCB01", "Setpoints", false, "Setpoints", 1, 17, 239, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &iedModel_GEN2LD0_LLN0_report5};
ReportControlBlock iedModel_GEN2LD0_LLN0_report5 = {&iedModel_GEN2LD0_LLN0, "SetpointsRCB02", "Setpoints", false, "Setpoints", 1, 17, 239, 0, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};







IedModel iedModel = {
    "GEN2",
    &iedModel_GEN2LD0,
    &iedModelds_GEN2LD0_LLN0_ControlEvents,
    &iedModel_GEN2LD0_LLN0_report0,
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

iedModel_GEN2LD0_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

iedModel_GEN2LD0_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

iedModel_GEN2LD0_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO5_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO6_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO7_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO8_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GEN2LD0_GGIO1_SPCSO9_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);
}
