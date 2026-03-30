
#pragma once

#include "iec61850_model.h"
#include "static_model.h"


typedef struct {
    const char* modbus_name;
    const char* iec_path;         
    DataAttribute* mag_f;         
    DataAttribute* t;             
} MbToIecFloatMap;


static const MbToIecFloatMap PCC1_FLOAT_MAP[] = {
    { "PCC1.vUtility_rms",   "PCC1LD0/GGIO1.AnIn1.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn1_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn1_t },
    { "PCC1.vMicro_rms",     "PCC1LD0/GGIO1.AnIn2.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn2_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn2_t },
    { "PCC1.iUtility_rms",   "PCC1LD0/GGIO1.AnIn3.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn3_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn3_t },
    { "PCC1.iMicro_rms",     "PCC1LD0/GGIO1.AnIn4.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn4_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn4_t },
    { "PCC1.phiUtility",     "PCC1LD0/GGIO1.AnIn5.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn5_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn5_t },
    { "PCC1.phiMicro",       "PCC1LD0/GGIO1.AnIn6.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn6_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn6_t },
    { "PCC1.PGrid",          "PCC1LD0/GGIO1.AnIn7.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn7_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn7_t },
    { "PCC1.QGrid",          "PCC1LD0/GGIO1.AnIn8.mag.f", IEDMODEL_PCC1LD0_GGIO1_AnIn8_mag_f, IEDMODEL_PCC1LD0_GGIO1_AnIn8_t },
};

#define PCC1_FLOAT_MAP_COUNT ((int)(sizeof(PCC1_FLOAT_MAP) / sizeof(PCC1_FLOAT_MAP[0])))




#define PCC1_GRIDENABLE_COIL_NAME "PCC1.gridEnable"
#define PCC1_GRIDENABLE_DO        (IEDMODEL_PCC1LD0_GGIO1_SPCSO1)
#define PCC1_GRIDENABLE_STVAL     (IEDMODEL_PCC1LD0_GGIO1_SPCSO1_stVal)
#define PCC1_GRIDENABLE_T         (IEDMODEL_PCC1LD0_GGIO1_SPCSO1_t)

#define PCC1_GRIDENABLE_CTLMODEL  (IEDMODEL_PCC1LD0_GGIO1_SPCSO1_ctlModel)


#define PCC1_SYNCHSTART_COIL_NAME "PCC1.synchStart"
#define PCC1_SYNCHSTART_DO        (IEDMODEL_PCC1LD0_GGIO1_SPCSO2)
#define PCC1_SYNCHSTART_STVAL     (IEDMODEL_PCC1LD0_GGIO1_SPCSO2_stVal)
#define PCC1_SYNCHSTART_T         (IEDMODEL_PCC1LD0_GGIO1_SPCSO2_t)
#define PCC1_SYNCHSTART_CTLMODEL  (IEDMODEL_PCC1LD0_GGIO1_SPCSO2_ctlModel)
