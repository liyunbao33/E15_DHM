/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.106
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Oct 11 17:35:20 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHM_h_
#define RTW_HEADER_DHM_h_
#ifndef DHM_COMMON_INCLUDES_
#define DHM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DHM_COMMON_INCLUDES_ */

#include "DHM_types.h"
#include "Rte_Type.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S3>/FLDoorHndDriver' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<S3>/FLDoorHndDriver' */
  uint32_T temporalCounter_i2;         /* '<S3>/FLDoorHndDriver' */
  uint32_T temporalCounter_i3;         /* '<S3>/FLDoorHndDriver' */
  uint32_T temporalCounter_i4;         /* '<S3>/FLDoorHndDriver' */
  uint8_T is_active_c19_DoorHndDriver; /* '<S3>/FLDoorHndDriver' */
  uint8_T is_Drive;                    /* '<S3>/FLDoorHndDriver' */
  uint8_T is_Unfold;                   /* '<S3>/FLDoorHndDriver' */
  uint8_T is_SoftStartStop;            /* '<S3>/FLDoorHndDriver' */
  uint8_T is_Icebreak;                 /* '<S3>/FLDoorHndDriver' */
  uint8_T is_Fold;                     /* '<S3>/FLDoorHndDriver' */
  uint8_T is_SoftStartStop_m;          /* '<S3>/FLDoorHndDriver' */
  uint8_T SL_e_CycleCount;             /* '<S3>/FLDoorHndDriver' */
  uint8_T SL_e_TickCount;              /* '<S3>/FLDoorHndDriver' */
  uint8_T temporalCounter_i5;          /* '<S3>/FLDoorHndDriver' */
  boolean_T SI_b_DoorHndUnfoldReq_prev;/* '<S3>/FLDoorHndDriver' */
  boolean_T SI_b_DoorHndUnfoldReq_start;/* '<S3>/FLDoorHndDriver' */
  boolean_T SI_b_DoorHndFoldReq_prev;  /* '<S3>/FLDoorHndDriver' */
  boolean_T SI_b_DoorHndFoldReq_start; /* '<S3>/FLDoorHndDriver' */
} DW_FLDoorHndDriver_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/FLDoorHndReq' */
  uint8_T is_active_c4_DoorHndReq;     /* '<S3>/FLDoorHndReq' */
  uint8_T is_c4_DoorHndReq;            /* '<S3>/FLDoorHndReq' */
  uint8_T is_AntiPlay;                 /* '<S3>/FLDoorHndReq' */
  uint8_T is_Unfold;                   /* '<S3>/FLDoorHndReq' */
  uint8_T is_Fold;                     /* '<S3>/FLDoorHndReq' */
  uint8_T SL_e_antiPlayCount;          /* '<S3>/FLDoorHndReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/FLDoorHndReq' */
  uint8_T temporalCounter_i3;          /* '<S3>/FLDoorHndReq' */
  uint8_T SI_e_DoorHndSet_prev;        /* '<S3>/FLDoorHndReq' */
  uint8_T SI_e_DoorHndSet_start;       /* '<S3>/FLDoorHndReq' */
  boolean_T SL_b_antiPlayFlg;          /* '<S3>/FLDoorHndReq' */
  boolean_T SL_b_UnfoldReqTrig;        /* '<S3>/FLDoorHndReq' */
  boolean_T SL_b_FoldReqTrig;          /* '<S3>/FLDoorHndReq' */
  boolean_T SI_b_CrashOutpSts_prev;    /* '<S3>/FLDoorHndReq' */
  boolean_T SI_b_CrashOutpSts_start;   /* '<S3>/FLDoorHndReq' */
  HndPos_Sts_E SI_m_HndPosSts_prev;    /* '<S3>/FLDoorHndReq' */
  HndPos_Sts_E SI_m_HndPosSts_start;   /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T SO_e_MotorCmd;               /* '<S3>/RRDoorHndDriver' */
  uint8_T SO_e_MotorPwm;               /* '<S3>/RRDoorHndDriver' */
  uint8_T SO_e_MotorCmd_o;             /* '<S3>/RLDoorHndDriver' */
  uint8_T SO_e_MotorPwm_h;             /* '<S3>/RLDoorHndDriver' */
  uint8_T SO_e_MotorCmd_m;             /* '<S3>/FRDoorHndDriver' */
  uint8_T SO_e_MotorPwm_c;             /* '<S3>/FRDoorHndDriver' */
  uint8_T SO_e_MotorCmd_p;             /* '<S3>/FLDoorHndDriver' */
  uint8_T SO_e_MotorPwm_l;             /* '<S3>/FLDoorHndDriver' */
  boolean_T SO_b_HndUnfoldReq;         /* '<S3>/RRDoorHndReq' */
  boolean_T SO_b_HndFoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_l;       /* '<S3>/RLDoorHndReq' */
  boolean_T SO_b_HndFoldReq_m;         /* '<S3>/RLDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_p;       /* '<S3>/FRDoorHndReq' */
  boolean_T SO_b_HndFoldReq_o;         /* '<S3>/FRDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_k;       /* '<S3>/FLDoorHndReq' */
  boolean_T SO_b_HndFoldReq_b;         /* '<S3>/FLDoorHndReq' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_DHM;            /* '<S3>/HndPosSts' */
  uint8_T is_active_c1_DHM;            /* '<S3>/DoorHndSetSts' */
  uint8_T SL_e_DrvDoorHndSetBackup;    /* '<S3>/DoorHndSetSts' */
  uint8_T SL_e_PassDoorHndSetBackup;   /* '<S3>/DoorHndSetSts' */
  uint8_T SI_e_DrvDoorHndSet_start;    /* '<S3>/DoorHndSetSts' */
  uint8_T SI_e_PassDoorHndSet_start;   /* '<S3>/DoorHndSetSts' */
  DW_FLDoorHndReq_DHM_T sf_RRDoorHndReq;/* '<S3>/RRDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_RRDoorHndDriver;/* '<S3>/RRDoorHndDriver' */
  DW_FLDoorHndReq_DHM_T sf_RLDoorHndReq;/* '<S3>/RLDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_RLDoorHndDriver;/* '<S3>/RLDoorHndDriver' */
  DW_FLDoorHndReq_DHM_T sf_FRDoorHndReq;/* '<S3>/FRDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_FRDoorHndDriver;/* '<S3>/FRDoorHndDriver' */
  DW_FLDoorHndReq_DHM_T sf_FLDoorHndReq;/* '<S3>/FLDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_FLDoorHndDriver;/* '<S3>/FLDoorHndDriver' */
} DW_DHM_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  UInt8 VeINP_CAN_VcuGearPosn_sig_VeINP;
              /* '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig' */
  Boolean VbINP_HWA_FLDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg' */
  Boolean VbINP_HWA_FRDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg' */
  Boolean VbINP_HWA_RLDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg' */
  Boolean VbINP_HWA_RRDoorAjar_flg_VbINP_;
                /* '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg' */
  Boolean VbINP_HWA_FLLockSts_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_FLLockSts_flg_VbINP_HWA_FLLockSts_flg' */
  Boolean VbINP_HWA_FRLockSts_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_FRLockSts_flg_VbINP_HWA_FRLockSts_flg' */
  Boolean VbINP_HWA_FLHadPos1_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_FLHadPos1_flg_VbINP_HWA_FLHadPos1_flg' */
  Boolean VbINP_HWA_FLHadPos2_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_FLHadPos2_flg_VbINP_HWA_FLHadPos2_flg' */
  Boolean VbINP_HWA_FRHadPos1_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg' */
  Boolean VbINP_HWA_FRHadPos2_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg' */
  Boolean VbINP_HWA_RLHadPos1_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg' */
  Boolean VbINP_HWA_RLHadPos2_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg' */
  Boolean VbINP_HWA_RRHadPos1_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg' */
  Boolean VbINP_HWA_RRHadPos2_flg_VbINP_H;
                  /* '<Root>/VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg' */
  UInt8 VeOUT_DLK_BCMPassengerDoorLockS;
  /* '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig' */
  UInt8 VeOUT_DLK_BdcDrvrDoorLockSts_si;
  /* '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig' */
  Boolean VbOUT_SP_CrashOutpSts_flg_VbOUT;
              /* '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  UInt8 VmOUT_DLK_LockSrc_enum_VmOUT_DL;
                    /* '<Root>/VmOUT_DLK_LockSrc_enum_VmOUT_DLK_LockSrc_enum' */
  Boolean VbOUT_DLK_FLUnlock_flg_VbOUT_DL;
                    /* '<Root>/VbOUT_DLK_FLUnlock_flg_VbOUT_DLK_FLUnlock_flg' */
  Boolean VbOUT_DLK_Unlock_flg_VbOUT_DLK_;
                        /* '<Root>/VbOUT_DLK_Unlock_flg_VbOUT_DLK_Unlock_flg' */
  UInt8 VeOUT_SP_EspVehSpd_kmh_VeOUT_SP;
                    /* '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' */
  Boolean VbINP_CAN_EspVehSpdVld_flg_VbIN;
            /* '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg' */
  Boolean VbINP_CAN_VcuRdySts_flg_VbINP_C;
                  /* '<Root>/VbINP_CAN_VcuRdySts_flg_VbINP_CAN_VcuRdySts_flg' */
  Boolean VbOUT_DLK_BdcDrvrDoorLockOpenRe;
  /* '<Root>/VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg_VbOUT_DLK_BdcDrvrDoorLockOpenReq_flg' */
  UInt8 VeINP_CFG_CountHndAntiPlay_sig_;
    /* '<Root>/VeINP_CFG_CountHndAntiPlay_sig_VeINP_CFG_CountHndAntiPlay_sig' */
  UInt8 VeINP_CFG_TiHndAntiPlay_sig_VeI;
          /* '<Root>/VeINP_CFG_TiHndAntiPlay_sig_VeINP_CFG_TiHndAntiPlay_sig' */
  UInt8 VeINP_CFG_TiHndAntiPlayDiable_s;
  /* '<Root>/VeINP_CFG_TiHndAntiPlayDiable_sig_VeINP_CFG_TiHndAntiPlayDiable_sig' */
  UInt8 VeINP_CAN_CdcDrivDoorHandSet_si;
  /* '<Root>/VeINP_CAN_CdcDrivDoorHandSet_sig_VeINP_CAN_CdcDrivDoorHandSet_sig' */
  UInt8 VeINP_CAN_CdcPassDoorHandSet_si;
  /* '<Root>/VeINP_CAN_CdcPassDoorHandSet_sig_VeINP_CAN_CdcPassDoorHandSet_sig' */
  Boolean VbINP_EPRM_BdcDrivDoorHandSetSt;
  /* '<Root>/VbINP_EPRM_BdcDrivDoorHandSetStsFromEE_flg_VbINP_EPRM_BdcDrivDoorHandSetStsFromEE_flg' */
  Boolean VbINP_EPRM_BdcPassDoorHandSetSt;
  /* '<Root>/VbINP_EPRM_BdcPassDoorHandSetStsFromEE_flg_VbINP_EPRM_BdcPassDoorHandSetStsFromEE_flg' */
  Boolean VbINP_EPRM_RLDoorHandButtonStsF;
  /* '<Root>/VbINP_EPRM_RLDoorHandButtonStsFromEE_flg_VbINP_EPRM_RLDoorHandButtonStsFromEE_flg' */
  Boolean VbINP_EPRM_RRDoorHandButtonStsF;
  /* '<Root>/VbINP_EPRM_RRDoorHandButtonStsFromEE_flg_VbINP_EPRM_RRDoorHandButtonStsFromEE_flg' */
  UInt8 VeINP_HWA_Voltage_100mV_VeINP_H;
                  /* '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV' */
} ExtU_DHM_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  UInt8 VeOUT_DHM_BDCDrvrDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig' */
  UInt8 VeOUT_DHM_BDCPassDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig' */
  UInt8 VeOUT_DHM_BDCLeReDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig' */
  UInt8 VeOUT_DHM_BDCRiReDoorHndSts_sig;
  /* '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig' */
  UInt8 VeOUT_DHM_FLHadUnfold_pct_VeOUT;
              /* '<Root>/VeOUT_DHM_FLHadUnfold_pct_VeOUT_DHM_FLHadUnfold_pct' */
  UInt8 VeOUT_DHM_FLHadFold_pct_VeOUT_D;
                  /* '<Root>/VeOUT_DHM_FLHadFold_pct_VeOUT_DHM_FLHadFold_pct' */
  UInt8 VeOUT_DHM_RLHadUnfold_pct_VeOUT;
              /* '<Root>/VeOUT_DHM_RLHadUnfold_pct_VeOUT_DHM_RLHadUnfold_pct' */
  UInt8 VeOUT_DHM_RLHadFold_pct_VeOUT_D;
                  /* '<Root>/VeOUT_DHM_RLHadFold_pct_VeOUT_DHM_RLHadFold_pct' */
  UInt8 VeOUT_DHM_FRHandleUnfold_pct_Ve;
        /* '<Root>/VeOUT_DHM_FRHandleUnfold_pct_VeOUT_DHM_FRHandleUnfold_pct' */
  UInt8 VeOUT_DHM_FRHandleFold_pct_VeOU;
            /* '<Root>/VeOUT_DHM_FRHandleFold_pct_VeOUT_DHM_FRHandleFold_pct' */
  UInt8 VeOUT_DHM_RRHadUnfold_pct_VeOUT;
              /* '<Root>/VeOUT_DHM_RRHadUnfold_pct_VeOUT_DHM_RRHadUnfold_pct' */
  UInt8 VeOUT_DHM_RRHadFold_pct_VeOUT_D;
                  /* '<Root>/VeOUT_DHM_RRHadFold_pct_VeOUT_DHM_RRHadFold_pct' */
  Boolean VbOUT_DHM_BdcDrivDoorHandSetSts;
  /* '<Root>/VbOUT_DHM_BdcDrivDoorHandSetSts_flg_VbOUT_DHM_BdcDrivDoorHandSetSts_flg' */
  Boolean VbOUT_DHM_BdcPassDoorHandSetSts;
  /* '<Root>/VbOUT_DHM_BdcPassDoorHandSetSts_flg_VbOUT_DHM_BdcPassDoorHandSetSts_flg' */
  Boolean VbOUT_DHM_BdcDrivDoorHandSetS_j;
  /* '<Root>/VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg_VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg' */
  Boolean VbOUT_DHM_BdcPassDoorHandSetS_a;
  /* '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg' */
  Boolean VbOUT_DHM_RLDoorHandSetSts_flg_;
    /* '<Root>/VbOUT_DHM_RLDoorHandSetSts_flg_VbOUT_DHM_RLDoorHandSetSts_flg' */
  Boolean VbOUT_DHM_RRDoorHandSetSts_flg_;
    /* '<Root>/VbOUT_DHM_RRDoorHandSetSts_flg_VbOUT_DHM_RRDoorHandSetSts_flg' */
  Boolean VbOUT_DHM_RLDoorHandButtonStsTo;
  /* '<Root>/VbOUT_DHM_RLDoorHandButtonStsToEE_flg_VbOUT_DHM_RLDoorHandButtonStsToEE_flg' */
  Boolean VbOUT_DHM_RRDoorHandButtonStsTo;
  /* '<Root>/VbOUT_DHM_RRDoorHandButtonStsToEE_flg_VbOUT_DHM_RRDoorHandButtonStsToEE_flg' */
  Boolean VbOUT_DHM_DrivDoorHandErrSts_fl;
  /* '<Root>/VbOUT_DHM_DrivDoorHandErrSts_flg_VbOUT_DHM_DrivDoorHandErrSts_flg' */
  Boolean VbOUT_DHM_PassDoorHandErrSts_fl;
  /* '<Root>/VbOUT_DHM_PassDoorHandErrSts_flg_VbOUT_DHM_PassDoorHandErrSts_flg' */
  Boolean VbOUT_DHM_RLDoorHandErrSts_flg_;
    /* '<Root>/VbOUT_DHM_RLDoorHandErrSts_flg_VbOUT_DHM_RLDoorHandErrSts_flg' */
  Boolean VbOUT_DHM_RRDoorHandErrSts_flg_;
    /* '<Root>/VbOUT_DHM_RRDoorHandErrSts_flg_VbOUT_DHM_RRDoorHandErrSts_flg' */
} ExtY_DHM_T;

/* Real-time Model Data Structure */
struct tag_RTM_DHM_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DHM_T DHM_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DHM_T DHM_Y;

/* Model entry point functions */
extern void DHM_initialize(void);
extern void DHM_terminate(void);

/* Exported entry point function */
extern void DHM_Step(void);

/* Real-time Model object */
extern RT_MODEL_DHM_T *const DHM_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DHM'
 * '<S1>'   : 'DHM/DHM_Init'
 * '<S2>'   : 'DHM/DHM_Step_sys'
 * '<S3>'   : 'DHM/DHM_Step_sys/DHM'
 * '<S4>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant'
 * '<S5>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant1'
 * '<S6>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant2'
 * '<S7>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant3'
 * '<S8>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant4'
 * '<S9>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant5'
 * '<S10>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant6'
 * '<S11>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant7'
 * '<S12>'  : 'DHM/DHM_Step_sys/DHM/DoorHndSetSts'
 * '<S13>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver'
 * '<S14>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndReq'
 * '<S15>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver'
 * '<S16>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndReq'
 * '<S17>'  : 'DHM/DHM_Step_sys/DHM/HndPosSts'
 * '<S18>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver'
 * '<S19>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndReq'
 * '<S20>'  : 'DHM/DHM_Step_sys/DHM/RRDoorHndDriver'
 * '<S21>'  : 'DHM/DHM_Step_sys/DHM/RRDoorHndReq'
 * '<S22>'  : 'DHM/DHM_Step_sys/DHM/Recycle Bin'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
