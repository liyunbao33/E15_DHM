/*
 * File: DHM_private.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 12 09:30:35 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHM_private_h_
#define RTW_HEADER_DHM_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "DHM_types.h"
#include "DHM.h"

extern void DHM_FLDoorHndDriver_Init(boolean *rty_SO_b_MotorA, boolean
  *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm, boolean *
  rty_SO_b_Error);
extern void DHM_FLDoorHndDriver(UInt8 rtu_SI_e_Volt100mV, HndPos_Sts_E
  rtu_SI_m_DoorHndPosSts, boolean rtu_SI_b_DoorHndFoldReq, boolean
  rtu_SI_b_DoorHndUnfoldReq, boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
  DW_FLDoorHndDriver_DHM_T *localDW);
extern void DHM_FLDoorHndReq_Init(boolean *rty_SO_b_HndUnfoldReq, boolean
  *rty_SO_b_HndFoldReq);
extern void DHM_FLDoorHndReq(Boolean rtu_SI_b_CrashOutpSts, Gear_Posn_E
  rtu_SI_m_GearPosn, UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
  Boolean rtu_SI_b_DoorLock, Boolean rtu_SI_b_DoorOpen, Door_Sts_E
  rtu_SI_m_DoorLockSts, HndPos_Sts_E rtu_SI_m_HndPosSts, boolean
  rtu_SI_b_DoorHndSetSts, UInt8 rtu_SI_e_DoorHndSet, boolean
  *rty_SO_b_HndUnfoldReq, boolean *rty_SO_b_HndFoldReq, DW_FLDoorHndReq_DHM_T
  *localDW);

#endif                                 /* RTW_HEADER_DHM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
