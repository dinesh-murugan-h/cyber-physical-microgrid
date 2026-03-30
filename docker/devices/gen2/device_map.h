
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


static const MbToIecFloatMap GEN2_FLOAT_MAP[] = {
    { "GEN2.P_gen2",        "GEN2LD0/GGIO1.AnIn1.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn1_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn1_t },
    { "GEN2.P_gen2_pu",     "GEN2LD0/GGIO1.AnIn2.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn2_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn2_t },
    { "GEN2.V_gen2_pu",     "GEN2LD0/GGIO1.AnIn3.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn3_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn3_t },
    { "GEN2.Q_gen2_pu",     "GEN2LD0/GGIO1.AnIn4.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn4_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn4_t },
    { "GEN2.freq_gen2_pu",  "GEN2LD0/GGIO1.AnIn5.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn5_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn5_t },
    { "GEN2.DroopPG2",      "GEN2LD0/GGIO1.AnIn6.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn6_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn6_t },
    { "GEN2.DroopQG2",      "GEN2LD0/GGIO1.AnIn7.mag.f", IEDMODEL_GEN2LD0_GGIO1_AnIn7_mag_f, IEDMODEL_GEN2LD0_GGIO1_AnIn7_t },
};

#define GEN2_FLOAT_MAP_COUNT ((int)(sizeof(GEN2_FLOAT_MAP) / sizeof(GEN2_FLOAT_MAP[0])))


#define GEN2_CBG2_DO        IEDMODEL_GEN2LD0_GGIO1_SPCSO1
#define GEN2_CBG2_STVAL     IEDMODEL_GEN2LD0_GGIO1_SPCSO1_stVal
#define GEN2_CBG2_T         IEDMODEL_GEN2LD0_GGIO1_SPCSO1_t
#define GEN2_CBG2_CTLMODEL  IEDMODEL_GEN2LD0_GGIO1_SPCSO1_ctlModel


#define GEN2_CBG2_COIL_NAME "GEN2.CBG2"


typedef struct {
    DataAttribute* mag_f;       
    const char*    modbus_name; 
    float          deadband;    
} IecSpToMbMap;

#define GEN2_DO1_MAG_F   IEDMODEL_GEN2LD0_GGIO1_DO1_setMag_f
#define GEN2_DO3_MAG_F   IEDMODEL_GEN2LD0_GGIO1_DO3_setMag_f

static const IecSpToMbMap GEN2_SETPOINT_MAP[] = {
    { GEN2_DO1_MAG_F, "GEN2.PrefG2",   1e-6f},
    { GEN2_DO3_MAG_F, "GEN2.QrefG2",    1e-6f },
};

#define GEN2_SETPOINT_MAP_COUNT ((int)(sizeof(GEN2_SETPOINT_MAP) / sizeof(GEN2_SETPOINT_MAP[0])))
