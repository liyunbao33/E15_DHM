/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Oct  6 18:08:26 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHM_h_
#define RTW_HEADER_DHM_h_
#ifndef DHM_COMMON_INCLUDES_
#define DHM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_DHM.h"
#endif                                 /* DHM_COMMON_INCLUDES_ */

#include "DHM_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<S3>/FLDoorHndDriver' */
typedef struct {
  uint32 temporalCounter_i1;           /* '<S3>/FLDoorHndDriver' */
  uint32 temporalCounter_i2;           /* '<S3>/FLDoorHndDriver' */
  uint32 temporalCounter_i3;           /* '<S3>/FLDoorHndDriver' */
  uint32 temporalCounter_i4;           /* '<S3>/FLDoorHndDriver' */
  uint8 is_active_c19_DoorHndDriver;   /* '<S3>/FLDoorHndDriver' */
  uint8 is_Drive;                      /* '<S3>/FLDoorHndDriver' */
  uint8 is_Unfold;                     /* '<S3>/FLDoorHndDriver' */
  uint8 is_SoftStartStop;              /* '<S3>/FLDoorHndDriver' */
  uint8 is_Icebreak;                   /* '<S3>/FLDoorHndDriver' */
  uint8 is_Fold;                       /* '<S3>/FLDoorHndDriver' */
  uint8 is_SoftStartStop_m;            /* '<S3>/FLDoorHndDriver' */
  uint8 SL_e_CycleCount;               /* '<S3>/FLDoorHndDriver' */
  uint8 temporalCounter_i5;            /* '<S3>/FLDoorHndDriver' */
  boolean SI_b_DoorHndUnfoldReq_prev;  /* '<S3>/FLDoorHndDriver' */
  boolean SI_b_DoorHndUnfoldReq_start; /* '<S3>/FLDoorHndDriver' */
  boolean SI_b_DoorHndFoldReq_prev;    /* '<S3>/FLDoorHndDriver' */
  boolean SI_b_DoorHndFoldReq_start;   /* '<S3>/FLDoorHndDriver' */
} DW_FLDoorHndDriver_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint16 temporalCounter_i3;           /* '<S3>/FLDoorHndReq' */
  uint8 is_active_c4_DoorHndReq;       /* '<S3>/FLDoorHndReq' */
  uint8 is_AntiPlay;                   /* '<S3>/FLDoorHndReq' */
  uint8 is_Unfold;                     /* '<S3>/FLDoorHndReq' */
  uint8 is_Fold;                       /* '<S3>/FLDoorHndReq' */
  uint8 SL_e_antiPlayCount;            /* '<S3>/FLDoorHndReq' */
  uint8 SL_b_antiPlayFlg;              /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i1;            /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FLDoorHndReq' */
  uint8 SI_e_DoorHndSet_prev;          /* '<S3>/FLDoorHndReq' */
  uint8 SI_e_DoorHndSet_start;         /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_prev;      /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_start;     /* '<S3>/FLDoorHndReq' */
  HndPos_Sts_E SI_m_HndPosSts_prev;    /* '<S3>/FLDoorHndReq' */
  HndPos_Sts_E SI_m_HndPosSts_start;   /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  UInt8 TmpSignalConversionAtVeINP_HWA_;
  UInt8 TmpSignalConversionAtVeINP_CAN_;
  UInt8 TmpSignalConversionAtVeINP_CA_a;
  uint8 SO_e_MotorCmd;                 /* '<S3>/RRDoorHndDriver' */
  uint8 SO_e_MotorPwm;                 /* '<S3>/RRDoorHndDriver' */
  uint8 SO_e_MotorCmd_o;               /* '<S3>/RLDoorHndDriver' */
  uint8 SO_e_MotorPwm_h;               /* '<S3>/RLDoorHndDriver' */
  uint8 SO_e_MotorCmd_m;               /* '<S3>/FRDoorHndDriver' */
  uint8 SO_e_MotorPwm_c;               /* '<S3>/FRDoorHndDriver' */
  uint8 SO_e_MotorCmd_p;               /* '<S3>/FLDoorHndDriver' */
  uint8 SO_e_MotorPwm_l;               /* '<S3>/FLDoorHndDriver' */
  boolean SO_b_HndUnfoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndFoldReq;             /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_l;         /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HndFoldReq_m;           /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HndUnfoldReq_p;         /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndFoldReq_o;           /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_k;         /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HndFoldReq_b;           /* '<S3>/FLDoorHndReq' */
  boolean SO_b_DrvDoorHndSetSts;       /* '<S3>/DoorHndSetSts' */
  boolean SO_b_DrvDoorHndBtnSetSts;    /* '<S3>/DoorHndSetSts' */
  boolean SO_b_PassDoorHndSetSts;      /* '<S3>/DoorHndSetSts' */
  boolean SO_b_PassDoorHndBtnSetSts;   /* '<S3>/DoorHndSetSts' */
  HndPos_Sts_E SI_m_FLDoorHndPosSts;   /* '<S3>/HndPosSts' */
  HndPos_Sts_E SI_m_FRDoorHndPosSts;   /* '<S3>/HndPosSts' */
  HndPos_Sts_E SI_m_RLDoorHndPosSts;   /* '<S3>/HndPosSts' */
  HndPos_Sts_E SI_m_RRDoorHndPosSts;   /* '<S3>/HndPosSts' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  uint8 E15_DHM;                       /* '<S3>/Data Store Memory' */
  uint8 is_active_c3_DHM;              /* '<S3>/HndPosSts' */
  uint8 is_active_c1_DHM;              /* '<S3>/DoorHndSetSts' */
  uint8 SL_e_DrvDoorHndSetBackup;      /* '<S3>/DoorHndSetSts' */
  uint8 SL_e_PassDoorHndSetBackup;     /* '<S3>/DoorHndSetSts' */
  uint8 SI_e_DrvDoorHndSet_prev;       /* '<S3>/DoorHndSetSts' */
  uint8 SI_e_DrvDoorHndSet_start;      /* '<S3>/DoorHndSetSts' */
  uint8 SI_e_PassDoorHndSet_prev;      /* '<S3>/DoorHndSetSts' */
  uint8 SI_e_PassDoorHndSet_start;     /* '<S3>/DoorHndSetSts' */
  DW_FLDoorHndReq_DHM_T sf_RRDoorHndReq;/* '<S3>/RRDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_RRDoorHndDriver;/* '<S3>/RRDoorHndDriver' */
  DW_FLDoorHndReq_DHM_T sf_RLDoorHndReq;/* '<S3>/RLDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_RLDoorHndDriver;/* '<S3>/RLDoorHndDriver' */
  DW_FLDoorHndReq_DHM_T sf_FRDoorHndReq;/* '<S3>/FRDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_FRDoorHndDriver;/* '<S3>/FRDoorHndDriver' */
  DW_FLDoorHndReq_DHM_T sf_FLDoorHndReq;/* '<S3>/FLDoorHndReq' */
  DW_FLDoorHndDriver_DHM_T sf_FLDoorHndDriver;/* '<S3>/FLDoorHndDriver' */
} DW_DHM_T;

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Compare' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 */

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
