
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


static const MbToIecFloatMap GEN1_FLOAT_MAP[] = {
    { "GEN1.P_gen1",        "GEN1LD0/GGIO1.AnIn1.mag.f", IEDMODEL_GEN1LD0_GGIO1_AnIn1_mag_f, IEDMODEL_GEN1LD0_GGIO1_AnIn1_t },
    { "GEN1.P_gen1_pu",     "GEN1LD0/GGIO1.AnIn2.mag.f", IEDMODEL_GEN1LD0_GGIO1_AnIn2_mag_f, IEDMODEL_GEN1LD0_GGIO1_AnIn2_t },
    { "GEN1.V_gen1_pu",     "GEN1LD0/GGIO1.AnIn3.mag.f", IEDMODEL_GEN1LD0_GGIO1_AnIn3_mag_f, IEDMODEL_GEN1LD0_GGIO1_AnIn3_t },
    { "GEN1.Q_gen1_pu",     "GEN1LD0/GGIO1.AnIn4.mag.f", IEDMODEL_GEN1LD0_GGIO1_AnIn4_mag_f, IEDMODEL_GEN1LD0_GGIO1_AnIn4_t },
    { "GEN1.freq_gen1_pu",  "GEN1LD0/GGIO1.AnIn5.mag.f", IEDMODEL_GEN1LD0_GGIO1_AnIn5_mag_f, IEDMODEL_GEN1LD0_GGIO1_AnIn5_t },
};

#define GEN1_FLOAT_MAP_COUNT ((int)(sizeof(GEN1_FLOAT_MAP) / sizeof(GEN1_FLOAT_MAP[0])))


#define GEN1_CBG1_DO        IEDMODEL_GEN1LD0_GGIO1_SPCSO1
#define GEN1_CBG1_STVAL     IEDMODEL_GEN1LD0_GGIO1_SPCSO1_stVal
#define GEN1_CBG1_T         IEDMODEL_GEN1LD0_GGIO1_SPCSO1_t
#define GEN1_CBG1_CTLMODEL  IEDMODEL_GEN1LD0_GGIO1_SPCSO1_ctlModel


#define GEN1_CBG1_COIL_NAME "GEN1.CBG1"


typedef struct {
    DataAttribute* mag_f;       
    const char*    modbus_name; 
    float          deadband;    
} IecSpToMbMap;

#define GEN1_DO1_MAG_F   IEDMODEL_GEN1LD0_GGIO1_DO1_setMag_f
#define GEN1_DO2_MAG_F   IEDMODEL_GEN1LD0_GGIO1_DO2_setMag_f
#define GEN1_DO3_MAG_F   IEDMODEL_GEN1LD0_GGIO1_DO3_setMag_f
#define GEN1_DO4_MAG_F   IEDMODEL_GEN1LD0_GGIO1_DO4_setMag_f

static const IecSpToMbMap GEN1_SETPOINT_MAP[] = {
    { GEN1_DO1_MAG_F, "GEN1.PrefG1",   1e-6f},
    { GEN1_DO2_MAG_F, "GEN1.DroopPG1",  1e-6f },
    { GEN1_DO3_MAG_F, "GEN1.QrefG1",    1e-6f },
    { GEN1_DO4_MAG_F, "GEN1.DroopQG1",  1e-6f },
};

#define GEN1_SETPOINT_MAP_COUNT ((int)(sizeof(GEN1_SETPOINT_MAP) / sizeof(GEN1_SETPOINT_MAP[0])))
