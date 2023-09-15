/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Sep  2 08:17:27 2023
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

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  UInt8 TmpSignalConversionAtVeOUT_SP_E;
  UInt8 TmpSignalConversionAtVeOUT_DLK_;
  UInt8 TmpSignalConversionAtVeOUT_DL_l;
  UInt8 TmpSignalConversionAtVeINP_CAN_;
  uint8 SO_e_BDCPassDoorHndSts;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SO_e_BDCLeReDoorHndSts;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SO_e_BDCRiReDoorHndSts;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SO_e_BDCDrvrDoorHndSts;        /* '<S3>/DRIVER_DOOR HANDLE' */
  Boolean TmpSignalConversionAtVbINP_CAN_;
  Boolean TmpSignalConversionAtVbOUT_SP_C;
  Boolean TmpSignalConversionAtVbINP_CA_m;
  boolean SO_b_HandleFold;             /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SO_b_HandleUnfold;           /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SO_b_FLHadUnfold;            /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SO_b_FLHadFold;              /* '<S3>/DRIVER_DOOR HANDLE' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  uint8 UnitDelay2_DSTATE;             /* '<S3>/Unit Delay2' */
  uint8 UnitDelay4_DSTATE;             /* '<S3>/Unit Delay4' */
  uint8 UnitDelay5_DSTATE;             /* '<S3>/Unit Delay5' */
  uint8 is_active_c4_DHM;              /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_UNFOLD_ACT;                 /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_FOLD_ACT;                   /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_FR;                         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_RL;                         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_RR;                         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_FOLD_SLEEP_PERMIT;          /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_OUTPUT_FR;                  /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_OUTPUT_RL;                  /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_OUTPUT_RR;                  /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SL_e_BDCPassDoorHndSts;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SL_e_BDCLeReDoorHndSts;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SL_e_BDCRiReDoorHndSts;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 temporalCounter_i1;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 temporalCounter_i2;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 temporalCounter_i3;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 temporalCounter_i4;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 temporalCounter_i5;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SI_e_BcmPassDoorLckSts_prev;   /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SI_e_BcmPassDoorLckSts_start;  /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SI_e_BcmDrvrDoorLckSts_prev;   /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 SI_e_BcmDrvrDoorLckSts_start;  /* '<S3>/PASSENGER_DOOR_HANDLES' */
  uint8 is_active_c3_DHM;              /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 is_FOLD_ACT_d;                 /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 is_UNFOLD_ACT_l;               /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 is_OUTPUT_STATUS;              /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 is_FOLD_SLEEP_PERMIT_j;        /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 SL_e_BDCDrvrDoorHndSts;        /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 temporalCounter_i1_p;          /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 temporalCounter_i2_b;          /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 temporalCounter_i3_h;          /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 SI_e_BcmPassDoorLckSts_prev_n; /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 SI_e_BcmPassDoorLckSts_start_p;/* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 SI_e_BcmDrvrDoorLckSts_prev_a; /* '<S3>/DRIVER_DOOR HANDLE' */
  uint8 SI_e_BcmDrvrDoorLckSts_start_p;/* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SL_b_Crash;                  /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RRFullyOpen;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RLFullyOpen;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FRFullyOpen;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RLHalfOpen;             /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FRHalfOpen;             /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RRHalfOpen;             /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RLHalfClose;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FRHalfClose;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RRHalfClose;            /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FOLD;                   /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_UNFOLD;                 /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RLUnfoldSucc;           /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RRUnfoldSucc;           /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FRUnfoldSucc;           /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_RLHadPos2_prev;         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_RLHadPos2_start;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_RRHadPos2_prev;         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_RRHadPos2_start;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_FRHadPos2_prev;         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_FRHadPos2_start;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_FRLockSts_prev;         /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_FRLockSts_start;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_CrashOutpSts_prev;      /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SI_b_CrashOutpSts_start;     /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FRHalfOpen_prev;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_FRHalfOpen_start;       /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RLHalfOpen_prev;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RLHalfOpen_start;       /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RRHalfOpen_prev;        /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_RRHalfOpen_start;       /* '<S3>/PASSENGER_DOOR_HANDLES' */
  boolean SL_b_Crash_g;                /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SL_b_OpenFully;              /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SL_b_HalfOpen;               /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SL_b_HalfClose;              /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SI_b_FLLockSts_prev;         /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SI_b_FLLockSts_start;        /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SI_b_CrashOutpSts_prev_b;    /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SI_b_CrashOutpSts_start_n;   /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SI_b_FLHadPos2_prev;         /* '<S3>/DRIVER_DOOR HANDLE' */
  boolean SI_b_FLHadPos2_start;        /* '<S3>/DRIVER_DOOR HANDLE' */
} DW_DHM_T;

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Logical Operator' : Unused code path elimination
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
 * '<S4>'   : 'DHM/DHM_Step_sys/DHM/DRIVER_DOOR HANDLE'
 * '<S5>'   : 'DHM/DHM_Step_sys/DHM/PASSENGER_DOOR_HANDLES'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
