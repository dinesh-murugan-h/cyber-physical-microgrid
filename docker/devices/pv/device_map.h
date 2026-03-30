
#pragma once

#include <stdint.h>
#include "iec61850_model.h"
#include "static_model.h"


typedef struct {
    const char* modbus_name;
    const char* iec_path;         
    DataAttribute* mag_f;         
    DataAttribute* t;             
} MbToIecFloatMap;


static const MbToIecFloatMap PV_FLOAT_MAP[] = {
    { "PV.P_PV",        "PVLD0/GGIO1.AnIn1.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn1_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn1_t },
    { "PV.V_PV",     "PVLD0/GGIO1.AnIn2.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn2_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn2_t },
    { "PV.I_PV",     "PVLD0/GGIO1.AnIn3.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn3_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn3_t },
    { "PV.DutyCycle",     "PVLD0/GGIO1.AnIn4.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn4_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn4_t },
    { "PV.Irradiance",  "PVLD0/GGIO1.AnIn5.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn5_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn5_t },
};

#define PV_FLOAT_MAP_COUNT ((int)(sizeof(PV_FLOAT_MAP) / sizeof(PV_FLOAT_MAP[0])))


#define PV_CBPV_DO        IEDMODEL_PVLD0_GGIO1_SPCSO1
#define PV_CBPV_STVAL     IEDMODEL_PVLD0_GGIO1_SPCSO1_stVal
#define PV_CBPV_T         IEDMODEL_PVLD0_GGIO1_SPCSO1_t
#define PV_CBPV_CTLMODEL  IEDMODEL_PVLD0_GGIO1_SPCSO1_ctlModel


#define PV_CBPV_COIL_NAME "PV.CBPV"


#define PV_CurtailEnable_DO        IEDMODEL_PVLD0_GGIO1_SPCSO2
#define PV_CurtailEnable_STVAL     IEDMODEL_PVLD0_GGIO1_SPCSO2_stVal
#define PV_CurtailEnable_T         IEDMODEL_PVLD0_GGIO1_SPCSO2_t
#define PV_CurtailEnable_CTLMODEL  IEDMODEL_PVLD0_GGIO1_SPCSO2_ctlModel


#define PV_CurtailEnable_COIL_NAME "PV.CurtailEnable"


typedef struct {
    DataAttribute* mag_f;       
    const char*    modbus_name; 
    float          deadband;    
} IecSpToMbMap;

#define PV_DO1_MAG_F   IEDMODEL_PVLD0_GGIO1_DO1_setMag_f

static const IecSpToMbMap PV_SETPOINT_MAP[] = {
    { PV_DO1_MAG_F, "PV.CurtailValue",   1e-6f},
};

#define PV_SETPOINT_MAP_COUNT ((int)(sizeof(PV_SETPOINT_MAP) / sizeof(PV_SETPOINT_MAP[0])))
