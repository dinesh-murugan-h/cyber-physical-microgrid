// docker/devices/PV/device_map.h
#pragma once

#include <stdint.h>
#include "iec61850_model.h"
#include "static_model.h"

/* ---------------------------
   Modbus -> IEC (MX) mapping
   --------------------------- */
typedef struct {
    const char* modbus_name;
    const char* iec_path;          /* debug prints */
    DataAttribute* mag_f;          /* ...AnInX.mag.f */
    DataAttribute* t;              /* ...AnInX.t */
} MbToIecFloatMap;

/* Your existing mapping (KEEP as you have it) */
static const MbToIecFloatMap PV_FLOAT_MAP[] = {
    { "PV.P_PV",        "PVLD0/GGIO1.AnIn1.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn1_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn1_t },
    { "PV.V_PV",     "PVLD0/GGIO1.AnIn2.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn2_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn2_t },
    { "PV.I_PV",     "PVLD0/GGIO1.AnIn3.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn3_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn3_t },
    { "PV.DutyCycle",     "PVLD0/GGIO1.AnIn4.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn4_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn4_t },
    { "PV.Irradiance",  "PVLD0/GGIO1.AnIn5.mag.f", IEDMODEL_PVLD0_GGIO1_AnIn5_mag_f, IEDMODEL_PVLD0_GGIO1_AnIn5_t },
};

#define PV_FLOAT_MAP_COUNT ((int)(sizeof(PV_FLOAT_MAP) / sizeof(PV_FLOAT_MAP[0])))

/* ---------------------------
   CONTROL: CBPV uses SPCS01
   --------------------------- */
#define PV_CBPV_DO        IEDMODEL_PVLD0_GGIO1_SPCSO1
#define PV_CBPV_STVAL     IEDMODEL_PVLD0_GGIO1_SPCSO1_stVal
#define PV_CBPV_T         IEDMODEL_PVLD0_GGIO1_SPCSO1_t
#define PV_CBPV_CTLMODEL  IEDMODEL_PVLD0_GGIO1_SPCSO1_ctlModel

/* Modbus coil name for breaker command */
#define PV_CBPV_COIL_NAME "PV.CBPV"

/* ---------------------------
   CONTROL: CurtailEnable uses SPCS02
   --------------------------- */
#define PV_CurtailEnable_DO        IEDMODEL_PVLD0_GGIO1_SPCSO2
#define PV_CurtailEnable_STVAL     IEDMODEL_PVLD0_GGIO1_SPCSO2_stVal
#define PV_CurtailEnable_T         IEDMODEL_PVLD0_GGIO1_SPCSO2_t
#define PV_CurtailEnable_CTLMODEL  IEDMODEL_PVLD0_GGIO1_SPCSO2_ctlModel

/* Modbus coil name for CurtailEnable command */
#define PV_CurtailEnable_COIL_NAME "PV.CurtailEnable"

/* ---------------------------
   SETPOINTS: GGIO DO1..DO4 (SP)
   Client writes DOx.setMag.f
   We mirror to Modbus HR names
   --------------------------- */
typedef struct {
    DataAttribute* mag_f;        /* DOx.setMag.f */
    const char*    modbus_name;  /* point name in your devmap (HR) */
    float          deadband;     /* change threshold to write Modbus */
} IecSpToMbMap;

#define PV_DO1_MAG_F   IEDMODEL_PVLD0_GGIO1_DO1_setMag_f

static const IecSpToMbMap PV_SETPOINT_MAP[] = {
    { PV_DO1_MAG_F, "PV.CurtailValue",   1e-6f},
};

#define PV_SETPOINT_MAP_COUNT ((int)(sizeof(PV_SETPOINT_MAP) / sizeof(PV_SETPOINT_MAP[0])))
