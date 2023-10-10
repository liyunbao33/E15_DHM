/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.97
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 10 15:36:51 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "DHM_types.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S3>/FLDoorHndDriver' */
#define DHM_IN_Check                   ((uint8_T)1U)
#define DHM_IN_Fold                    ((uint8_T)1U)
#define DHM_IN_IceBrk                  ((uint8_T)2U)
#define DHM_IN_IceBrkWait              ((uint8_T)3U)
#define DHM_IN_Icebreak                ((uint8_T)1U)
#define DHM_IN_Idle                    ((uint8_T)2U)
#define DHM_IN_Interrupt1              ((uint8_T)3U)
#define DHM_IN_Interrupt2              ((uint8_T)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define DHM_IN_SoftStartStop           ((uint8_T)2U)
#define DHM_IN_SoftStartStop_f         ((uint8_T)1U)
#define DHM_IN_Step1                   ((uint8_T)1U)
#define DHM_IN_Step2                   ((uint8_T)2U)
#define DHM_IN_Step3                   ((uint8_T)3U)
#define DHM_IN_Step4                   ((uint8_T)4U)
#define DHM_IN_Stop                    ((uint8_T)3U)
#define DHM_IN_Stop_o                  ((uint8_T)2U)
#define DHM_IN_Unfold                  ((uint8_T)5U)

/* Named constants for Chart: '<S3>/FLDoorHndReq' */
#define DHM_IN_Clean                   ((uint8_T)1U)
#define DHM_IN_Count                   ((uint8_T)2U)
#define DHM_IN_CrashUnfoldReq          ((uint8_T)1U)
#define DHM_IN_FoldReq                 ((uint8_T)1U)
#define DHM_IN_Idle_g                  ((uint8_T)2U)
#define DHM_IN_NormalUnfoldReq         ((uint8_T)3U)
#define DHM_IN_SpecUnfoldReq           ((uint8_T)4U)
#define DHM_IN_TrigAndClean            ((uint8_T)3U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/* External inputs (root inport signals with default storage) */
ExtU_DHM_T DHM_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DHM_T DHM_Y;

/* Real-time model */
static RT_MODEL_DHM_T DHM_M_;
RT_MODEL_DHM_T *const DHM_M = &DHM_M_;

/* Forward declaration for local functions */
static real_T DHM_GetPwm_j(real_T x, UInt8 rtu_SI_e_Volt100mV);
static real_T DHM_LinPwmStepTime_p(real_T t, UInt8 rtu_SI_e_Volt100mV);
static real_T DHM_GetPwm(real_T x, UInt8 rtu_SI_e_Volt100mV);
static real_T DHM_LinPwmStepTime(real_T t, UInt8 rtu_SI_e_Volt100mV);
static void DHM_Unfold(UInt8 rtu_SI_e_Volt100mV, HndPos_Sts_E
  rtu_SI_m_DoorHndPosSts, boolean_T *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB,
  uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T
  *rty_SO_b_Error, DW_FLDoorHndDriver_DHM_T *localDW);

/* Forward declaration for local functions */
static real_T DHM_GetHndPosSts(real_T pos1, real_T pos2);
static uint8_T DHM_safe_cast_to_HndPos_Sts_E(uint8_T input);
static void DHM_inner_default_DrvDoorHndSet(const uint8_T
  *SI_e_DrvDoorHndSet_prev, const HndPos_Sts_E *SI_m_FLDoorHndPosSts);
static void DH_inner_default_PassDoorHndSet(const uint8_T
  *SI_e_PassDoorHndSet_prev, const HndPos_Sts_E *SI_m_FRDoorHndPosSts, const
  HndPos_Sts_E *SI_m_RLDoorHndPosSts, const HndPos_Sts_E *SI_m_RRDoorHndPosSts);

/* Function for Chart: '<S3>/FLDoorHndDriver' */
static real_T DHM_GetPwm_j(real_T x, UInt8 rtu_SI_e_Volt100mV)
{
  real_T y;
  y = x * 100.0 / (real_T)rtu_SI_e_Volt100mV;

  /*  扩大100倍，浮点转整型  */
  if (y > 100.0) {
    y = 100.0;
  }

  return y;
}

/* Function for Chart: '<S3>/FLDoorHndDriver' */
static real_T DHM_LinPwmStepTime_p(real_T t, UInt8 rtu_SI_e_Volt100mV)
{
  real_T y;
  y = t / (DHM_GetPwm_j(120.0, rtu_SI_e_Volt100mV) - DHM_GetPwm_j(70.0,
            rtu_SI_e_Volt100mV));

  /*  时间t按PWM区间差值等分(单位:100mV)  */
  if (y == 0.0) {
    y = 1.0;
  }

  return y;
}

/* Function for Chart: '<S3>/FLDoorHndDriver' */
static real_T DHM_GetPwm(real_T x, UInt8 rtu_SI_e_Volt100mV)
{
  real_T y;
  y = x * 100.0 / (real_T)rtu_SI_e_Volt100mV;
  if (y > 100.0) {
    y = 100.0;
  }

  return y;
}

/* Function for Chart: '<S3>/FLDoorHndDriver' */
static real_T DHM_LinPwmStepTime(real_T t, UInt8 rtu_SI_e_Volt100mV)
{
  real_T y;
  y = t / (DHM_GetPwm(100.0, rtu_SI_e_Volt100mV) - DHM_GetPwm(70.0,
            rtu_SI_e_Volt100mV));

  /*  时间t按PWM区间差值等分(单位:100mV)  */
  if (y == 0.0) {
    y = 1.0;
  }

  return y;
}

/* Function for Chart: '<S3>/FLDoorHndDriver' */
static void DHM_Unfold(UInt8 rtu_SI_e_Volt100mV, HndPos_Sts_E
  rtu_SI_m_DoorHndPosSts, boolean_T *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB,
  uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T
  *rty_SO_b_Error, DW_FLDoorHndDriver_DHM_T *localDW)
{
  if ((localDW->SI_b_DoorHndFoldReq_prev != localDW->SI_b_DoorHndFoldReq_start) &&
      localDW->SI_b_DoorHndFoldReq_start) {
    if (localDW->is_Unfold == DHM_IN_SoftStartStop) {
      switch (localDW->is_SoftStartStop) {
       case DHM_IN_Step1:
        {
          real_T tmp_0;
          tmp_0 = DHM_GetPwm_j(120.0, rtu_SI_e_Volt100mV);
          if (tmp_0 < 256.0) {
            if (tmp_0 >= 0.0) {
              *rty_SO_e_MotorPwm = (uint8_T)tmp_0;
            } else {
              *rty_SO_e_MotorPwm = 0U;
            }
          } else {
            *rty_SO_e_MotorPwm = MAX_uint8_T;
          }

          localDW->is_SoftStartStop = DHM_IN_NO_ACTIVE_CHILD;
        }
        break;

       case DHM_IN_Step4:
        {
          real_T tmp_0;
          tmp_0 = DHM_GetPwm_j(70.0, rtu_SI_e_Volt100mV);
          if (tmp_0 < 256.0) {
            if (tmp_0 >= 0.0) {
              *rty_SO_e_MotorPwm = (uint8_T)tmp_0;
            } else {
              *rty_SO_e_MotorPwm = 0U;
            }
          } else {
            *rty_SO_e_MotorPwm = MAX_uint8_T;
          }

          localDW->is_SoftStartStop = DHM_IN_NO_ACTIVE_CHILD;
        }
        break;

       default:
        localDW->is_SoftStartStop = DHM_IN_NO_ACTIVE_CHILD;
        break;
      }

      localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    } else {
      localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
      localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    }

    localDW->is_Drive = DHM_IN_Interrupt1;
    localDW->temporalCounter_i5 = 0U;

    /*  折叠打断展开  */
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Unfold) {
     case DHM_IN_Icebreak:
      {
        switch (localDW->is_Icebreak) {
         case DHM_IN_Check:
          *rty_SO_e_MotorCmd = 0U;
          if (localDW->SL_e_CycleCount >= 3) {
            *rty_SO_b_Error = true;

            /*  破冰达到指定次数，报错  */
            localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Drive = DHM_IN_Idle;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorPwm = 0U;
          } else if (localDW->temporalCounter_i5 >= 100) {
            localDW->is_Icebreak = DHM_IN_IceBrk;
            localDW->temporalCounter_i5 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_b_MotorA = true;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorPwm = 100U;
          }
          break;

         case DHM_IN_IceBrk:
          {
            *rty_SO_e_MotorCmd = 1U;
            if (rtu_SI_m_DoorHndPosSts == Hnd_Unfold) {
              /*  破冰完成  */
              localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
              localDW->is_Unfold = DHM_IN_Stop;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorPwm = 0U;
              *rty_SO_b_Error = false;
            } else if (localDW->temporalCounter_i5 >= 200) {
              int32_T tmp;
              localDW->is_Icebreak = DHM_IN_Check;
              localDW->temporalCounter_i5 = 0U;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorPwm = 0U;
              tmp = localDW->SL_e_CycleCount + 1;
              if (localDW->SL_e_CycleCount + 1 > 255) {
                tmp = 255;
              }

              localDW->SL_e_CycleCount = (uint8_T)tmp;
            }
          }
          break;

         default:
          /* case IN_IceBrkWait: */
          *rty_SO_e_MotorCmd = 0U;
          if (localDW->temporalCounter_i5 >= 100) {
            localDW->is_Icebreak = DHM_IN_IceBrk;
            localDW->temporalCounter_i5 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_b_MotorA = true;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorPwm = 100U;
          }
          break;
        }
      }
      break;

     case DHM_IN_SoftStartStop:
      {
        switch (localDW->is_SoftStartStop) {
         case DHM_IN_Step1:
          {
            *rty_SO_e_MotorCmd = 1U;
            if (localDW->temporalCounter_i5 >= 30) {
              real_T tmp_0;
              tmp_0 = DHM_GetPwm_j(120.0, rtu_SI_e_Volt100mV);
              if (tmp_0 < 256.0) {
                if (tmp_0 >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8_T)tmp_0;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }

              localDW->is_SoftStartStop = DHM_IN_Step2;
              localDW->temporalCounter_i5 = 0U;

              /*  保持驱动至门把手展开  */
            } else {
              /*  初始电压为7V(单位:100mV)  */
            }
          }
          break;

         case DHM_IN_Step2:
          if (localDW->temporalCounter_i5 >= 250) {
            /*  超时进入破冰  */
            localDW->is_SoftStartStop = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Unfold = DHM_IN_Icebreak;
            localDW->SL_e_CycleCount = 0U;
            localDW->is_Icebreak = DHM_IN_IceBrkWait;
            localDW->temporalCounter_i5 = 0U;

            /*  破冰延时  */
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorPwm = 0U;
          } else if (rtu_SI_m_DoorHndPosSts == Hnd_Unfold) {
            /*  检测门把手是否展开  */
            localDW->is_SoftStartStop = DHM_IN_Step3;
            localDW->temporalCounter_i5 = 0U;

            /*  检测到门把手展开后进行过驱  */
          }
          break;

         case DHM_IN_Step3:
          {
            if (localDW->temporalCounter_i5 >= 60) {
              real_T tmp_0;

              /*  过驱时间:600ms  */
              localDW->is_SoftStartStop = DHM_IN_Step4;
              localDW->temporalCounter_i2 = 0U;
              localDW->temporalCounter_i5 = 0U;

              /*  软停(线性降压)  */
              tmp_0 = DHM_GetPwm_j(120.0, rtu_SI_e_Volt100mV);
              if (tmp_0 < 256.0) {
                if (tmp_0 >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8_T)tmp_0;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }
            }
          }
          break;

         default:
          {
            /* case IN_Step4: */
            if (localDW->temporalCounter_i5 >= 35) {
              real_T tmp_0;

              /*  正常驱动完成  */
              tmp_0 = DHM_GetPwm_j(70.0, rtu_SI_e_Volt100mV);
              if (tmp_0 < 256.0) {
                if (tmp_0 >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8_T)tmp_0;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }

              localDW->is_SoftStartStop = DHM_IN_NO_ACTIVE_CHILD;
              localDW->is_Unfold = DHM_IN_Stop;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorPwm = 0U;
              *rty_SO_b_Error = false;
            } else {
              /*  初始电压为12V(单位:100mV)  */
            }
          }
          break;
        }
      }
      break;

     default:
      /* case IN_Stop: */
      localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
      localDW->is_Drive = DHM_IN_Idle;
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorPwm = 0U;
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorHndDriver'
 *    '<S3>/FRDoorHndDriver'
 *    '<S3>/RLDoorHndDriver'
 *    '<S3>/RRDoorHndDriver'
 */
void DHM_FLDoorHndDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
  boolean_T *rty_SO_b_Error)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorHndDriver'
 *    '<S3>/FRDoorHndDriver'
 *    '<S3>/RLDoorHndDriver'
 *    '<S3>/RRDoorHndDriver'
 */
void DHM_FLDoorHndDriver(UInt8 rtu_SI_e_Volt100mV, HndPos_Sts_E
  rtu_SI_m_DoorHndPosSts, boolean_T rtu_SI_b_DoorHndFoldReq, boolean_T
  rtu_SI_b_DoorHndUnfoldReq, boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
  boolean_T *rty_SO_b_Error, DW_FLDoorHndDriver_DHM_T *localDW)
{
  uint32_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  uint32_T tmp_3;

  /* Chart: '<S3>/FLDoorHndDriver' */
  tmp_0 = (uint32_T)DHM_LinPwmStepTime_p(30.0, rtu_SI_e_Volt100mV);
  if (localDW->temporalCounter_i1 < tmp_0) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S3>/FLDoorHndDriver' */
  tmp_1 = (uint32_T)DHM_LinPwmStepTime_p(35.0, rtu_SI_e_Volt100mV);
  if (localDW->temporalCounter_i2 < tmp_1) {
    localDW->temporalCounter_i2++;
  }

  /* Chart: '<S3>/FLDoorHndDriver' */
  tmp_2 = (uint32_T)DHM_LinPwmStepTime(30.0, rtu_SI_e_Volt100mV);
  if (localDW->temporalCounter_i3 < tmp_2) {
    localDW->temporalCounter_i3++;
  }

  /* Chart: '<S3>/FLDoorHndDriver' */
  tmp_3 = (uint32_T)DHM_LinPwmStepTime(35.0, rtu_SI_e_Volt100mV);
  if (localDW->temporalCounter_i4 < tmp_3) {
    localDW->temporalCounter_i4++;
  }

  if (localDW->temporalCounter_i5 < 255U) {
    localDW->temporalCounter_i5++;
  }

  localDW->SI_b_DoorHndUnfoldReq_prev = localDW->SI_b_DoorHndUnfoldReq_start;
  localDW->SI_b_DoorHndUnfoldReq_start = rtu_SI_b_DoorHndUnfoldReq;
  localDW->SI_b_DoorHndFoldReq_prev = localDW->SI_b_DoorHndFoldReq_start;
  localDW->SI_b_DoorHndFoldReq_start = rtu_SI_b_DoorHndFoldReq;

  /* Chart: '<S3>/FLDoorHndDriver' */
  if (localDW->is_active_c19_DoorHndDriver == 0U) {
    localDW->SI_b_DoorHndUnfoldReq_prev = rtu_SI_b_DoorHndUnfoldReq;
    localDW->SI_b_DoorHndFoldReq_prev = rtu_SI_b_DoorHndFoldReq;
    localDW->is_active_c19_DoorHndDriver = 1U;
    localDW->is_Drive = DHM_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Drive) {
     case DHM_IN_Fold:
      {
        if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
             localDW->SI_b_DoorHndUnfoldReq_start) &&
            localDW->SI_b_DoorHndUnfoldReq_start) {
          if (localDW->is_Fold == DHM_IN_SoftStartStop_f) {
            switch (localDW->is_SoftStartStop_m) {
             case DHM_IN_Step1:
              {
                real_T tmp;
                tmp = DHM_GetPwm(100.0, rtu_SI_e_Volt100mV);
                if (tmp < 256.0) {
                  if (tmp >= 0.0) {
                    *rty_SO_e_MotorPwm = (uint8_T)tmp;
                  } else {
                    *rty_SO_e_MotorPwm = 0U;
                  }
                } else {
                  *rty_SO_e_MotorPwm = MAX_uint8_T;
                }

                localDW->is_SoftStartStop_m = DHM_IN_NO_ACTIVE_CHILD;
              }
              break;

             case DHM_IN_Step4:
              {
                real_T tmp;
                tmp = DHM_GetPwm(70.0, rtu_SI_e_Volt100mV);
                if (tmp < 256.0) {
                  if (tmp >= 0.0) {
                    *rty_SO_e_MotorPwm = (uint8_T)tmp;
                  } else {
                    *rty_SO_e_MotorPwm = 0U;
                  }
                } else {
                  *rty_SO_e_MotorPwm = MAX_uint8_T;
                }

                localDW->is_SoftStartStop_m = DHM_IN_NO_ACTIVE_CHILD;
              }
              break;

             default:
              localDW->is_SoftStartStop_m = DHM_IN_NO_ACTIVE_CHILD;
              break;
            }

            localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
          } else {
            localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
          }

          localDW->is_Drive = DHM_IN_Interrupt2;
          localDW->temporalCounter_i5 = 0U;

          /*  展开打断折叠  */
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorPwm = 0U;
        } else if (localDW->is_Fold == DHM_IN_SoftStartStop_f) {
          switch (localDW->is_SoftStartStop_m) {
           case DHM_IN_Step1:
            {
              *rty_SO_e_MotorCmd = 2U;
              if (localDW->temporalCounter_i5 >= 30) {
                real_T tmp;
                tmp = DHM_GetPwm(100.0, rtu_SI_e_Volt100mV);
                if (tmp < 256.0) {
                  if (tmp >= 0.0) {
                    *rty_SO_e_MotorPwm = (uint8_T)tmp;
                  } else {
                    *rty_SO_e_MotorPwm = 0U;
                  }
                } else {
                  *rty_SO_e_MotorPwm = MAX_uint8_T;
                }

                localDW->is_SoftStartStop_m = DHM_IN_Step2;
                localDW->temporalCounter_i5 = 0U;

                /*  保持驱动至门把手折叠  */
              } else {
                /*  初始电压为7V(单位:100mV)  */
              }
            }
            break;

           case DHM_IN_Step2:
            if (localDW->temporalCounter_i5 >= 250) {
              *rty_SO_b_Error = true;

              /*  超时报错  */
              localDW->is_SoftStartStop_m = DHM_IN_NO_ACTIVE_CHILD;
              localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
              localDW->is_Drive = DHM_IN_Idle;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorPwm = 0U;
            } else if (rtu_SI_m_DoorHndPosSts == Hnd_Fold) {
              localDW->is_SoftStartStop_m = DHM_IN_Step3;

              /*  检测到门把手展开后进行过驱  */
            }
            break;

           case DHM_IN_Step3:
            {
              real_T tmp;

              /*  过驱时间:0ms  */
              localDW->is_SoftStartStop_m = DHM_IN_Step4;
              localDW->temporalCounter_i4 = 0U;
              localDW->temporalCounter_i5 = 0U;
              tmp = DHM_GetPwm(100.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8_T)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }
            }
            break;

           default:
            {
              /* case IN_Step4: */
              if (localDW->temporalCounter_i5 >= 35) {
                real_T tmp;
                tmp = DHM_GetPwm(70.0, rtu_SI_e_Volt100mV);
                if (tmp < 256.0) {
                  if (tmp >= 0.0) {
                    *rty_SO_e_MotorPwm = (uint8_T)tmp;
                  } else {
                    *rty_SO_e_MotorPwm = 0U;
                  }
                } else {
                  *rty_SO_e_MotorPwm = MAX_uint8_T;
                }

                localDW->is_SoftStartStop_m = DHM_IN_NO_ACTIVE_CHILD;
                localDW->is_Fold = DHM_IN_Stop_o;
                *rty_SO_e_MotorCmd = 0U;
                *rty_SO_b_MotorA = false;
                *rty_SO_b_MotorB = false;
                *rty_SO_e_MotorPwm = 0U;
                *rty_SO_b_Error = false;
              } else {
                /*  初始电压为10V(单位:100mV)  */
              }
            }
            break;
          }
        } else {
          /* case IN_Stop: */
          localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
          localDW->is_Drive = DHM_IN_Idle;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorPwm = 0U;
        }
      }
      break;

     case DHM_IN_Idle:
      {
        *rty_SO_e_MotorCmd = 0U;
        if ((localDW->SI_b_DoorHndFoldReq_prev !=
             localDW->SI_b_DoorHndFoldReq_start) &&
            localDW->SI_b_DoorHndFoldReq_start) {
          real_T tmp;
          localDW->is_Drive = DHM_IN_Fold;
          localDW->is_Fold = DHM_IN_SoftStartStop_f;
          localDW->is_SoftStartStop_m = DHM_IN_Step1;
          localDW->temporalCounter_i3 = 0U;
          localDW->temporalCounter_i5 = 0U;
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          tmp = DHM_GetPwm(70.0, rtu_SI_e_Volt100mV);
          if (tmp < 256.0) {
            if (tmp >= 0.0) {
              *rty_SO_e_MotorPwm = (uint8_T)tmp;
            } else {
              *rty_SO_e_MotorPwm = 0U;
            }
          } else {
            *rty_SO_e_MotorPwm = MAX_uint8_T;
          }
        } else if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
                    localDW->SI_b_DoorHndUnfoldReq_start) &&
                   localDW->SI_b_DoorHndUnfoldReq_start) {
          real_T tmp;
          localDW->is_Drive = DHM_IN_Unfold;
          localDW->is_Unfold = DHM_IN_SoftStartStop;
          localDW->is_SoftStartStop = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;
          localDW->temporalCounter_i5 = 0U;

          /*  软启(线性升压)  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          tmp = DHM_GetPwm_j(70.0, rtu_SI_e_Volt100mV);
          if (tmp < 256.0) {
            if (tmp >= 0.0) {
              *rty_SO_e_MotorPwm = (uint8_T)tmp;
            } else {
              *rty_SO_e_MotorPwm = 0U;
            }
          } else {
            *rty_SO_e_MotorPwm = MAX_uint8_T;
          }
        }
      }
      break;

     case DHM_IN_Interrupt1:
      {
        *rty_SO_e_MotorCmd = 0U;
        if (localDW->temporalCounter_i5 >= 10) {
          real_T tmp;
          localDW->is_Drive = DHM_IN_Fold;
          localDW->is_Fold = DHM_IN_SoftStartStop_f;
          localDW->is_SoftStartStop_m = DHM_IN_Step1;
          localDW->temporalCounter_i3 = 0U;
          localDW->temporalCounter_i5 = 0U;
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          tmp = DHM_GetPwm(70.0, rtu_SI_e_Volt100mV);
          if (tmp < 256.0) {
            if (tmp >= 0.0) {
              *rty_SO_e_MotorPwm = (uint8_T)tmp;
            } else {
              *rty_SO_e_MotorPwm = 0U;
            }
          } else {
            *rty_SO_e_MotorPwm = MAX_uint8_T;
          }
        }
      }
      break;

     case DHM_IN_Interrupt2:
      {
        *rty_SO_e_MotorCmd = 0U;
        if (localDW->temporalCounter_i5 >= 10) {
          real_T tmp;
          localDW->is_Drive = DHM_IN_Unfold;
          localDW->is_Unfold = DHM_IN_SoftStartStop;
          localDW->is_SoftStartStop = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;
          localDW->temporalCounter_i5 = 0U;

          /*  软启(线性升压)  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          tmp = DHM_GetPwm_j(70.0, rtu_SI_e_Volt100mV);
          if (tmp < 256.0) {
            if (tmp >= 0.0) {
              *rty_SO_e_MotorPwm = (uint8_T)tmp;
            } else {
              *rty_SO_e_MotorPwm = 0U;
            }
          } else {
            *rty_SO_e_MotorPwm = MAX_uint8_T;
          }
        }
      }
      break;

     default:
      /* case IN_Unfold: */
      DHM_Unfold(rtu_SI_e_Volt100mV, rtu_SI_m_DoorHndPosSts, rty_SO_b_MotorA,
                 rty_SO_b_MotorB, rty_SO_e_MotorCmd, rty_SO_e_MotorPwm,
                 rty_SO_b_Error, localDW);
      break;
    }
  }

  if (localDW->temporalCounter_i1 == tmp_0) {
    localDW->temporalCounter_i1 = 0U;
  }

  if (localDW->temporalCounter_i2 == tmp_1) {
    localDW->temporalCounter_i2 = 0U;
  }

  if (localDW->temporalCounter_i3 == tmp_2) {
    localDW->temporalCounter_i3 = 0U;
  }

  if (localDW->temporalCounter_i4 == tmp_3) {
    localDW->temporalCounter_i4 = 0U;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorHndReq'
 *    '<S3>/FRDoorHndReq'
 *    '<S3>/RLDoorHndReq'
 *    '<S3>/RRDoorHndReq'
 */
void DHM_FLDoorHndReq_Init(boolean_T *rty_SO_b_HndUnfoldReq, boolean_T
  *rty_SO_b_HndFoldReq)
{
  *rty_SO_b_HndUnfoldReq = false;
  *rty_SO_b_HndFoldReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorHndReq'
 *    '<S3>/FRDoorHndReq'
 *    '<S3>/RLDoorHndReq'
 *    '<S3>/RRDoorHndReq'
 */
void DHM_FLDoorHndReq(Boolean rtu_SI_b_CrashOutpSts, Gear_Posn_E
                      rtu_SI_m_GearPosn, UInt8 rtu_SI_e_EspVehSpd, Boolean
                      rtu_SI_b_EspVehSpdVld, Boolean rtu_SI_b_DoorLock, Boolean
                      rtu_SI_b_DoorOpen, Door_Sts_E rtu_SI_m_DoorLockSts,
                      HndPos_Sts_E rtu_SI_m_HndPosSts, boolean_T
                      rtu_SI_b_DoorHndSetSts, UInt8 rtu_SI_e_DoorHndSet,
                      boolean_T *rty_SO_b_HndUnfoldReq, boolean_T
                      *rty_SO_b_HndFoldReq, DW_FLDoorHndReq_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 32767U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 7U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 7U) {
    localDW->temporalCounter_i3++;
  }

  localDW->SI_m_HndPosSts_prev = localDW->SI_m_HndPosSts_start;
  localDW->SI_m_HndPosSts_start = rtu_SI_m_HndPosSts;
  localDW->SI_e_DoorHndSet_prev = localDW->SI_e_DoorHndSet_start;
  localDW->SI_e_DoorHndSet_start = rtu_SI_e_DoorHndSet;
  localDW->SI_b_CrashOutpSts_prev = localDW->SI_b_CrashOutpSts_start;
  localDW->SI_b_CrashOutpSts_start = rtu_SI_b_CrashOutpSts;

  /* Chart: '<S3>/FLDoorHndReq' */
  if (localDW->is_active_c4_DoorHndReq == 0U) {
    localDW->SI_m_HndPosSts_prev = rtu_SI_m_HndPosSts;
    localDW->SI_e_DoorHndSet_prev = rtu_SI_e_DoorHndSet;
    localDW->SI_b_CrashOutpSts_prev = rtu_SI_b_CrashOutpSts;
    localDW->is_active_c4_DoorHndReq = 1U;
    localDW->is_AntiPlay = DHM_IN_Count;
    localDW->temporalCounter_i1 = 0U;
    if (((localDW->SI_m_HndPosSts_prev != localDW->SI_m_HndPosSts_start) &&
         (localDW->SI_m_HndPosSts_start == Hnd_Fold)) ||
        ((localDW->SI_m_HndPosSts_prev != localDW->SI_m_HndPosSts_start) &&
         (localDW->SI_m_HndPosSts_start == Hnd_Unfold))) {
      int32_T tmp;
      tmp = localDW->SL_e_antiPlayCount + 1;
      if (localDW->SL_e_antiPlayCount + 1 > 255) {
        tmp = 255;
      }

      localDW->SL_e_antiPlayCount = (uint8_T)tmp;
    }

    localDW->is_Unfold = DHM_IN_Idle_g;
    *rty_SO_b_HndUnfoldReq = false;
    localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen || (!rtu_SI_b_DoorLock)) &&
      localDW->SL_b_UnfoldReqTrig);
    localDW->is_Fold = DHM_IN_Idle_g;
    *rty_SO_b_HndFoldReq = false;
    localDW->SL_b_FoldReqTrig = (((rtu_SI_e_EspVehSpd > 20) ||
      rtu_SI_b_EspVehSpdVld || (rtu_SI_m_DoorLockSts == Door_Lock)) &&
      localDW->SL_b_FoldReqTrig);
  } else {
    switch (localDW->is_AntiPlay) {
     case DHM_IN_Clean:
      {
        localDW->is_AntiPlay = DHM_IN_Count;
        localDW->temporalCounter_i1 = 0U;
        if (((localDW->SI_m_HndPosSts_prev != localDW->SI_m_HndPosSts_start) &&
             (localDW->SI_m_HndPosSts_start == Hnd_Fold)) ||
            ((localDW->SI_m_HndPosSts_prev != localDW->SI_m_HndPosSts_start) &&
             (localDW->SI_m_HndPosSts_start == Hnd_Unfold))) {
          int32_T tmp;
          tmp = localDW->SL_e_antiPlayCount + 1;
          if (localDW->SL_e_antiPlayCount + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_antiPlayCount = (uint8_T)tmp;
        }
      }
      break;

     case DHM_IN_Count:
      {
        if ((localDW->temporalCounter_i1 < 3000) && (localDW->SL_e_antiPlayCount
             >= 10)) {
          localDW->is_AntiPlay = DHM_IN_TrigAndClean;
          localDW->temporalCounter_i1 = 0U;
          localDW->SL_b_antiPlayFlg = true;
          localDW->SL_e_antiPlayCount = 0U;
        } else if (localDW->temporalCounter_i1 >= 3000) {
          localDW->is_AntiPlay = DHM_IN_Clean;
          localDW->SL_e_antiPlayCount = 0U;
        } else if (((localDW->SI_m_HndPosSts_prev !=
                     localDW->SI_m_HndPosSts_start) &&
                    (localDW->SI_m_HndPosSts_start == Hnd_Fold)) ||
                   ((localDW->SI_m_HndPosSts_prev !=
                     localDW->SI_m_HndPosSts_start) &&
                    (localDW->SI_m_HndPosSts_start == Hnd_Unfold))) {
          int32_T tmp;
          tmp = localDW->SL_e_antiPlayCount + 1;
          if (localDW->SL_e_antiPlayCount + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_antiPlayCount = (uint8_T)tmp;
        }
      }
      break;

     default:
      {
        /* case IN_TrigAndClean: */
        if (localDW->temporalCounter_i1 >= 18000) {
          localDW->SL_b_antiPlayFlg = false;
          localDW->is_AntiPlay = DHM_IN_Count;
          localDW->temporalCounter_i1 = 0U;
          if (((localDW->SI_m_HndPosSts_prev != localDW->SI_m_HndPosSts_start) &&
               (localDW->SI_m_HndPosSts_start == Hnd_Fold)) ||
              ((localDW->SI_m_HndPosSts_prev != localDW->SI_m_HndPosSts_start) &&
               (localDW->SI_m_HndPosSts_start == Hnd_Unfold))) {
            int32_T tmp;
            tmp = localDW->SL_e_antiPlayCount + 1;
            if (localDW->SL_e_antiPlayCount + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_antiPlayCount = (uint8_T)tmp;
          }
        }
      }
      break;
    }

    switch (localDW->is_Unfold) {
     case DHM_IN_CrashUnfoldReq:
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_Unfold = DHM_IN_Idle_g;
        *rty_SO_b_HndUnfoldReq = false;
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen || (!rtu_SI_b_DoorLock))
          && localDW->SL_b_UnfoldReqTrig);
      }
      break;

     case DHM_IN_Idle_g:
      if ((((rtu_SI_e_EspVehSpd <= 20) && (!rtu_SI_b_EspVehSpdVld)) ||
           (rtu_SI_m_GearPosn == Gear_P) || rtu_SI_b_EspVehSpdVld) &&
          (rtu_SI_b_DoorOpen || (!rtu_SI_b_DoorLock)) &&
          (!localDW->SL_b_UnfoldReqTrig) && (localDW->SI_m_HndPosSts_start !=
           Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_NormalUnfoldReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
        localDW->SL_b_UnfoldReqTrig = true;
      } else if ((((localDW->SI_e_DoorHndSet_prev !=
                    localDW->SI_e_DoorHndSet_start) &&
                   (localDW->SI_e_DoorHndSet_start == 4)) ||
                  ((localDW->SI_e_DoorHndSet_prev !=
                    localDW->SI_e_DoorHndSet_start) &&
                   (localDW->SI_e_DoorHndSet_start == 3))) &&
                 (localDW->SI_m_HndPosSts_start != Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_SpecUnfoldReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
      } else if ((localDW->SI_b_CrashOutpSts_prev !=
                  localDW->SI_b_CrashOutpSts_start) &&
                 localDW->SI_b_CrashOutpSts_start &&
                 (localDW->SI_m_HndPosSts_start != Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_CrashUnfoldReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
      } else {
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen || (!rtu_SI_b_DoorLock))
          && localDW->SL_b_UnfoldReqTrig);
      }
      break;

     case DHM_IN_NormalUnfoldReq:
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_Unfold = DHM_IN_Idle_g;
        *rty_SO_b_HndUnfoldReq = false;
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen || (!rtu_SI_b_DoorLock))
          && localDW->SL_b_UnfoldReqTrig);
      }
      break;

     default:
      /* case IN_SpecUnfoldReq: */
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_Unfold = DHM_IN_Idle_g;
        *rty_SO_b_HndUnfoldReq = false;
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen || (!rtu_SI_b_DoorLock))
          && localDW->SL_b_UnfoldReqTrig);
      }
      break;
    }

    if (localDW->is_Fold == DHM_IN_FoldReq) {
      if (localDW->temporalCounter_i3 >= 5) {
        localDW->is_Fold = DHM_IN_Idle_g;
        *rty_SO_b_HndFoldReq = false;
        localDW->SL_b_FoldReqTrig = (((rtu_SI_e_EspVehSpd > 20) ||
          rtu_SI_b_EspVehSpdVld || (rtu_SI_m_DoorLockSts == Door_Lock)) &&
          localDW->SL_b_FoldReqTrig);
      }

      /* case IN_Idle: */
    } else if ((((rtu_SI_e_EspVehSpd > 20) && (!rtu_SI_b_EspVehSpdVld)) ||
                (rtu_SI_m_DoorLockSts == Door_Lock)) && (rtu_SI_m_HndPosSts !=
                Hnd_Fold) && (!localDW->SL_b_antiPlayFlg) &&
               (!localDW->SL_b_FoldReqTrig) && (!rtu_SI_b_DoorHndSetSts)) {
      localDW->is_Fold = DHM_IN_FoldReq;
      localDW->temporalCounter_i3 = 0U;
      *rty_SO_b_HndFoldReq = true;
      localDW->SL_b_FoldReqTrig = true;
    } else {
      localDW->SL_b_FoldReqTrig = (((rtu_SI_e_EspVehSpd > 20) ||
        rtu_SI_b_EspVehSpdVld || (rtu_SI_m_DoorLockSts == Door_Lock)) &&
        localDW->SL_b_FoldReqTrig);
    }
  }

  /* End of Chart: '<S3>/FLDoorHndReq' */
}

/* Function for Chart: '<S3>/HndPosSts' */
static real_T DHM_GetHndPosSts(real_T pos1, real_T pos2)
{
  real_T status;
  if ((pos1 == 0.0) && (pos2 == 0.0)) {
    status = 0.0;
  } else if ((pos1 == 1.0) && (pos2 == 1.0)) {
    status = 1.0;
  } else if ((pos1 == 1.0) && (pos2 == 0.0)) {
    status = 2.0;
  } else {
    status = 3.0;
  }

  return status;
}

static uint8_T DHM_safe_cast_to_HndPos_Sts_E(uint8_T input)
{
  uint8_T output;

  /* Initialize output value to default value for HndPos_Sts_E (Hnd_Fold) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of HndPos_Sts_E */
    output = input;
  }

  return output;
}

/* Function for Chart: '<S3>/DoorHndSetSts' */
static void DHM_inner_default_DrvDoorHndSet(const uint8_T
  *SI_e_DrvDoorHndSet_prev, const HndPos_Sts_E *SI_m_FLDoorHndPosSts)
{
  if (*SI_e_DrvDoorHndSet_prev != DHM_DW.SI_e_DrvDoorHndSet_start) {
    /* Inport: '<Root>/VeINP_CAN_CdcDrivDoorHandSet_sig_VeINP_CAN_CdcDrivDoorHandSet_sig' */
    DHM_DW.SL_e_DrvDoorHndSetBackup = DHM_U.VeINP_CAN_CdcDrivDoorHandSet_si;
  } else {
    switch (DHM_DW.SL_e_DrvDoorHndSetBackup) {
     case 4:
      /* Outport: '<Root>/VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg_VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg' */
      DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j = ((*SI_m_FLDoorHndPosSts ==
        Hnd_Unfold) || DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j);
      break;

     case 3:
      /* Outport: '<Root>/VbOUT_DHM_RLDoorHandButtonStsToEE_flg_VbOUT_DHM_RLDoorHandButtonStsToEE_flg' */
      DHM_Y.VbOUT_DHM_RLDoorHandButtonStsTo = true;

      /* Outport: '<Root>/VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg_VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg' */
      DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j = ((*SI_m_FLDoorHndPosSts ==
        Hnd_Unfold) || DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j);
      break;

     case 6:
      /* Outport: '<Root>/VbOUT_DHM_RLDoorHandButtonStsToEE_flg_VbOUT_DHM_RLDoorHandButtonStsToEE_flg' */
      DHM_Y.VbOUT_DHM_RLDoorHandButtonStsTo = true;
      break;

     case 5:
      /* Outport: '<Root>/VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg_VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg' */
      DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j = false;

      /* Outport: '<Root>/VbOUT_DHM_RLDoorHandButtonStsToEE_flg_VbOUT_DHM_RLDoorHandButtonStsToEE_flg' */
      DHM_Y.VbOUT_DHM_RLDoorHandButtonStsTo = false;
      break;

     default:
      /* Outport: '<Root>/VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg_VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg' incorporates:
       *  Inport: '<Root>/VbINP_EPRM_BdcDrivDoorHandSetStsFromEE_flg_VbINP_EPRM_BdcDrivDoorHandSetStsFromEE_flg'
       */
      DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j =
        DHM_U.VbINP_EPRM_BdcDrivDoorHandSetSt;

      /* Outport: '<Root>/VbOUT_DHM_RLDoorHandButtonStsToEE_flg_VbOUT_DHM_RLDoorHandButtonStsToEE_flg' incorporates:
       *  Inport: '<Root>/VbINP_EPRM_RLDoorHandButtonStsFromEE_flg_VbINP_EPRM_RLDoorHandButtonStsFromEE_flg'
       */
      DHM_Y.VbOUT_DHM_RLDoorHandButtonStsTo =
        DHM_U.VbINP_EPRM_RLDoorHandButtonStsF;
      break;
    }
  }
}

/* Function for Chart: '<S3>/DoorHndSetSts' */
static void DH_inner_default_PassDoorHndSet(const uint8_T
  *SI_e_PassDoorHndSet_prev, const HndPos_Sts_E *SI_m_FRDoorHndPosSts, const
  HndPos_Sts_E *SI_m_RLDoorHndPosSts, const HndPos_Sts_E *SI_m_RRDoorHndPosSts)
{
  if (*SI_e_PassDoorHndSet_prev != DHM_DW.SI_e_PassDoorHndSet_start) {
    /* Inport: '<Root>/VeINP_CAN_CdcPassDoorHandSet_sig_VeINP_CAN_CdcPassDoorHandSet_sig' */
    DHM_DW.SL_e_PassDoorHndSetBackup = DHM_U.VeINP_CAN_CdcPassDoorHandSet_si;
  } else {
    switch (DHM_DW.SL_e_PassDoorHndSetBackup) {
     case 4:
      /* Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg' */
      DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a = (((*SI_m_FRDoorHndPosSts ==
        Hnd_Unfold) && (*SI_m_RLDoorHndPosSts == Hnd_Unfold) &&
        (*SI_m_RRDoorHndPosSts == Hnd_Unfold)) ||
        DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a);
      break;

     case 3:
      /* Outport: '<Root>/VbOUT_DHM_RRDoorHandButtonStsToEE_flg_VbOUT_DHM_RRDoorHandButtonStsToEE_flg' */
      DHM_Y.VbOUT_DHM_RRDoorHandButtonStsTo = true;

      /* Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg' */
      DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a = (((*SI_m_FRDoorHndPosSts ==
        Hnd_Unfold) && (*SI_m_RLDoorHndPosSts == Hnd_Unfold) &&
        (*SI_m_RRDoorHndPosSts == Hnd_Unfold)) ||
        DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a);
      break;

     case 6:
      /* Outport: '<Root>/VbOUT_DHM_RRDoorHandButtonStsToEE_flg_VbOUT_DHM_RRDoorHandButtonStsToEE_flg' */
      DHM_Y.VbOUT_DHM_RRDoorHandButtonStsTo = true;
      break;

     case 5:
      /* Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg' */
      DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a = false;

      /* Outport: '<Root>/VbOUT_DHM_RRDoorHandButtonStsToEE_flg_VbOUT_DHM_RRDoorHandButtonStsToEE_flg' */
      DHM_Y.VbOUT_DHM_RRDoorHandButtonStsTo = false;
      break;

     default:
      /* Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg' incorporates:
       *  Inport: '<Root>/VbINP_EPRM_BdcPassDoorHandSetStsFromEE_flg_VbINP_EPRM_BdcPassDoorHandSetStsFromEE_flg'
       */
      DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a =
        DHM_U.VbINP_EPRM_BdcPassDoorHandSetSt;

      /* Outport: '<Root>/VbOUT_DHM_RRDoorHandButtonStsToEE_flg_VbOUT_DHM_RRDoorHandButtonStsToEE_flg' incorporates:
       *  Inport: '<Root>/VbINP_EPRM_RRDoorHandButtonStsFromEE_flg_VbINP_EPRM_RRDoorHandButtonStsFromEE_flg'
       */
      DHM_Y.VbOUT_DHM_RRDoorHandButtonStsTo =
        DHM_U.VbINP_EPRM_RRDoorHandButtonStsF;
      break;
    }
  }
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  Gear_Posn_E rtb_DataTypeConversion2;
  HndPos_Sts_E SI_m_FLDoorHndPosSts;
  HndPos_Sts_E SI_m_FRDoorHndPosSts;
  HndPos_Sts_E SI_m_RLDoorHndPosSts;
  HndPos_Sts_E SI_m_RRDoorHndPosSts;
  uint8_T SI_e_DrvDoorHndSet_prev;
  uint8_T SI_e_PassDoorHndSet_prev;
  boolean_T SO_b_Error_g;
  boolean_T SO_b_MotorA_i;
  boolean_T SO_b_MotorB_b;
  Door_Sts_E rtb_DataTypeConversion1;

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Chart: '<S3>/HndPosSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLHadPos1_flg_VbINP_HWA_FLHadPos1_flg'
   *  Inport: '<Root>/VbINP_HWA_FLHadPos2_flg_VbINP_HWA_FLHadPos2_flg'
   *  Inport: '<Root>/VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg'
   *  Inport: '<Root>/VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg'
   *  Inport: '<Root>/VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg'
   *  Inport: '<Root>/VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg'
   *  Inport: '<Root>/VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg'
   *  Inport: '<Root>/VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg'
   */
  if (DHM_DW.is_active_c3_DHM == 0U) {
    real_T tmp;
    DHM_DW.is_active_c3_DHM = 1U;
    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_FLHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_FLHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_FLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_FLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_FLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }

    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_FRHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_FRHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_FRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_FRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_FRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }

    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_RLHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_RLHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_RLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_RLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_RLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }

    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_RRHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_RRHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_RRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_RRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_RRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }
  } else {
    real_T tmp;
    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_FLHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_FLHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_FLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_FLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_FLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }

    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_FRHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_FRHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_FRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_FRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_FRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }

    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_RLHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_RLHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_RLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_RLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_RLDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }

    tmp = DHM_GetHndPosSts((real_T)DHM_U.VbINP_HWA_RRHadPos1_flg_VbINP_H,
      (real_T)DHM_U.VbINP_HWA_RRHadPos2_flg_VbINP_H);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        SI_m_RRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)(int32_T)
          tmp);
      } else {
        SI_m_RRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      SI_m_RRDoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }
  }

  /* End of Chart: '<S3>/HndPosSts' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   */
  rtb_DataTypeConversion2 = DHM_U.VeINP_CAN_VcuGearPosn_sig_VeINP;

  /* Chart: '<S3>/DoorHndSetSts' incorporates:
   *  Inport: '<Root>/VeINP_CAN_CdcDrivDoorHandSet_sig_VeINP_CAN_CdcDrivDoorHandSet_sig'
   *  Inport: '<Root>/VeINP_CAN_CdcPassDoorHandSet_sig_VeINP_CAN_CdcPassDoorHandSet_sig'
   */
  SI_e_DrvDoorHndSet_prev = DHM_DW.SI_e_DrvDoorHndSet_start;
  DHM_DW.SI_e_DrvDoorHndSet_start = DHM_U.VeINP_CAN_CdcDrivDoorHandSet_si;
  SI_e_PassDoorHndSet_prev = DHM_DW.SI_e_PassDoorHndSet_start;
  DHM_DW.SI_e_PassDoorHndSet_start = DHM_U.VeINP_CAN_CdcPassDoorHandSet_si;
  if (DHM_DW.is_active_c1_DHM == 0U) {
    DHM_DW.is_active_c1_DHM = 1U;
    DHM_inner_default_DrvDoorHndSet(&DHM_U.VeINP_CAN_CdcDrivDoorHandSet_si,
      &SI_m_FLDoorHndPosSts);
    DH_inner_default_PassDoorHndSet(&DHM_U.VeINP_CAN_CdcPassDoorHandSet_si,
      &SI_m_FRDoorHndPosSts, &SI_m_RLDoorHndPosSts, &SI_m_RRDoorHndPosSts);
  } else {
    DHM_inner_default_DrvDoorHndSet(&SI_e_DrvDoorHndSet_prev,
      &SI_m_FLDoorHndPosSts);
    DH_inner_default_PassDoorHndSet(&SI_e_PassDoorHndSet_prev,
      &SI_m_FRDoorHndPosSts, &SI_m_RLDoorHndPosSts, &SI_m_RRDoorHndPosSts);
  }

  /* End of Chart: '<S3>/DoorHndSetSts' */

  /* Chart: '<S3>/FLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FLLockSts_flg_VbINP_HWA_FLLockSts_flg'
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeINP_CAN_CdcDrivDoorHandSet_sig_VeINP_CAN_CdcDrivDoorHandSet_sig'
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg_VbOUT_DHM_BdcDrivDoorHandSetStsToEE_flg'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   rtb_DataTypeConversion2,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   DHM_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   DHM_U.VbINP_HWA_FLLockSts_flg_VbINP_H,
                   DHM_U.VbINP_HWA_FLDoorAjar_flg_VbINP_, (Door_Sts_E)
                   DHM_U.VeOUT_DLK_BdcDrvrDoorLockSts_si, SI_m_FLDoorHndPosSts,
                   DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetS_j,
                   DHM_U.VeINP_CAN_CdcDrivDoorHandSet_si,
                   &DHM_B.SO_b_HndUnfoldReq_k, &DHM_B.SO_b_HndFoldReq_b,
                   &DHM_DW.sf_FLDoorHndReq);

  /* Chart: '<S3>/FLDoorHndDriver' incorporates:
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  DHM_FLDoorHndDriver(DHM_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      SI_m_FLDoorHndPosSts, DHM_B.SO_b_HndFoldReq_b,
                      DHM_B.SO_b_HndUnfoldReq_k, &SO_b_MotorA_i, &SO_b_MotorB_b,
                      &DHM_B.SO_e_MotorCmd_p, &DHM_B.SO_e_MotorPwm_l,
                      &SO_b_Error_g, &DHM_DW.sf_FLDoorHndDriver);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   */
  rtb_DataTypeConversion1 = (Door_Sts_E)DHM_U.VeOUT_DLK_BCMPassengerDoorLockS;

  /* Chart: '<S3>/RLDoorHndReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_FRLockSts_flg_VbINP_HWA_FRLockSts_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeINP_CAN_CdcPassDoorHandSet_sig_VeINP_CAN_CdcPassDoorHandSet_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   rtb_DataTypeConversion2,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   DHM_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   DHM_U.VbINP_HWA_FRLockSts_flg_VbINP_H,
                   DHM_U.VbINP_HWA_RLDoorAjar_flg_VbINP_,
                   rtb_DataTypeConversion1, SI_m_RLDoorHndPosSts,
                   DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a,
                   DHM_U.VeINP_CAN_CdcPassDoorHandSet_si,
                   &DHM_B.SO_b_HndUnfoldReq_l, &DHM_B.SO_b_HndFoldReq_m,
                   &DHM_DW.sf_RLDoorHndReq);

  /* Chart: '<S3>/RLDoorHndDriver' incorporates:
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  DHM_FLDoorHndDriver(DHM_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      SI_m_RLDoorHndPosSts, DHM_B.SO_b_HndUnfoldReq_l,
                      DHM_B.SO_b_HndFoldReq_m, &SO_b_MotorA_i, &SO_b_MotorB_b,
                      &DHM_B.SO_e_MotorCmd_o, &DHM_B.SO_e_MotorPwm_h,
                      &SO_b_Error_g, &DHM_DW.sf_RLDoorHndDriver);

  /* Chart: '<S3>/FRDoorHndReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FRLockSts_flg_VbINP_HWA_FRLockSts_flg'
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeINP_CAN_CdcPassDoorHandSet_sig_VeINP_CAN_CdcPassDoorHandSet_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   rtb_DataTypeConversion2,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   DHM_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   DHM_U.VbINP_HWA_FRLockSts_flg_VbINP_H,
                   DHM_U.VbINP_HWA_FRDoorAjar_flg_VbINP_,
                   rtb_DataTypeConversion1, SI_m_FRDoorHndPosSts,
                   DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a,
                   DHM_U.VeINP_CAN_CdcPassDoorHandSet_si,
                   &DHM_B.SO_b_HndUnfoldReq_p, &DHM_B.SO_b_HndFoldReq_o,
                   &DHM_DW.sf_FRDoorHndReq);

  /* Chart: '<S3>/FRDoorHndDriver' incorporates:
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  DHM_FLDoorHndDriver(DHM_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      SI_m_FRDoorHndPosSts, DHM_B.SO_b_HndUnfoldReq_p,
                      DHM_B.SO_b_HndFoldReq_o, &SO_b_MotorA_i, &SO_b_MotorB_b,
                      &DHM_B.SO_e_MotorCmd_m, &DHM_B.SO_e_MotorPwm_c,
                      &SO_b_Error_g, &DHM_DW.sf_FRDoorHndDriver);

  /* Chart: '<S3>/RRDoorHndReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VbINP_HWA_FRLockSts_flg_VbINP_HWA_FRLockSts_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeINP_CAN_CdcPassDoorHandSet_sig_VeINP_CAN_CdcPassDoorHandSet_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg_VbOUT_DHM_BdcPassDoorHandSetStsToEE_flg'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   rtb_DataTypeConversion2,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   DHM_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   DHM_U.VbINP_HWA_FRLockSts_flg_VbINP_H,
                   DHM_U.VbINP_HWA_RRDoorAjar_flg_VbINP_,
                   rtb_DataTypeConversion1, SI_m_RRDoorHndPosSts,
                   DHM_Y.VbOUT_DHM_BdcPassDoorHandSetS_a,
                   DHM_U.VeINP_CAN_CdcPassDoorHandSet_si,
                   &DHM_B.SO_b_HndUnfoldReq, &DHM_B.SO_b_HndFoldReq,
                   &DHM_DW.sf_RRDoorHndReq);

  /* Chart: '<S3>/RRDoorHndDriver' incorporates:
   *  Inport: '<Root>/VeINP_HWA_Voltage_100mV_VeINP_HWA_Voltage_100mV'
   */
  DHM_FLDoorHndDriver(DHM_U.VeINP_HWA_Voltage_100mV_VeINP_H,
                      SI_m_RRDoorHndPosSts, DHM_B.SO_b_HndUnfoldReq,
                      DHM_B.SO_b_HndFoldReq, &SO_b_MotorA_i, &SO_b_MotorB_b,
                      &DHM_B.SO_e_MotorCmd, &DHM_B.SO_e_MotorPwm, &SO_b_Error_g,
                      &DHM_DW.sf_RRDoorHndDriver);

  /* Outport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  DHM_Y.VeOUT_DHM_BDCDrvrDoorHndSts_sig = SI_m_FLDoorHndPosSts;

  /* Outport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  DHM_Y.VeOUT_DHM_BDCPassDoorHndSts_sig = SI_m_FRDoorHndPosSts;

  /* Outport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  DHM_Y.VeOUT_DHM_BDCLeReDoorHndSts_sig = SI_m_RLDoorHndPosSts;

  /* Outport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  DHM_Y.VeOUT_DHM_BDCRiReDoorHndSts_sig = SI_m_RRDoorHndPosSts;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd_p == 1) {
    /* Outport: '<Root>/VeOUT_DHM_FLHadUnfold_pct_VeOUT_DHM_FLHadUnfold_pct' */
    DHM_Y.VeOUT_DHM_FLHadUnfold_pct_VeOUT = DHM_B.SO_e_MotorPwm_l;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_FLHadUnfold_pct_VeOUT_DHM_FLHadUnfold_pct' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    DHM_Y.VeOUT_DHM_FLHadUnfold_pct_VeOUT = 0U;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd_o == 1) {
    /* Outport: '<Root>/VeOUT_DHM_RLHadUnfold_pct_VeOUT_DHM_RLHadUnfold_pct' */
    DHM_Y.VeOUT_DHM_RLHadUnfold_pct_VeOUT = DHM_B.SO_e_MotorPwm_h;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_RLHadUnfold_pct_VeOUT_DHM_RLHadUnfold_pct' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    DHM_Y.VeOUT_DHM_RLHadUnfold_pct_VeOUT = 0U;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd_o == 2) {
    /* Outport: '<Root>/VeOUT_DHM_RLHadFold_pct_VeOUT_DHM_RLHadFold_pct' */
    DHM_Y.VeOUT_DHM_RLHadFold_pct_VeOUT_D = DHM_B.SO_e_MotorPwm_h;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_RLHadFold_pct_VeOUT_DHM_RLHadFold_pct' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    DHM_Y.VeOUT_DHM_RLHadFold_pct_VeOUT_D = 0U;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Switch: '<S3>/Switch3' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd_m == 1) {
    /* Outport: '<Root>/VeOUT_DHM_FRHandleUnfold_pct_VeOUT_DHM_FRHandleUnfold_pct' */
    DHM_Y.VeOUT_DHM_FRHandleUnfold_pct_Ve = DHM_B.SO_e_MotorPwm_c;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_FRHandleUnfold_pct_VeOUT_DHM_FRHandleUnfold_pct' incorporates:
     *  Constant: '<S3>/Constant5'
     */
    DHM_Y.VeOUT_DHM_FRHandleUnfold_pct_Ve = 0U;
  }

  /* End of Switch: '<S3>/Switch3' */

  /* Switch: '<S3>/Switch4' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd_m == 2) {
    /* Outport: '<Root>/VeOUT_DHM_FRHandleFold_pct_VeOUT_DHM_FRHandleFold_pct' */
    DHM_Y.VeOUT_DHM_FRHandleFold_pct_VeOU = DHM_B.SO_e_MotorPwm_c;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_FRHandleFold_pct_VeOUT_DHM_FRHandleFold_pct' incorporates:
     *  Constant: '<S3>/Constant6'
     */
    DHM_Y.VeOUT_DHM_FRHandleFold_pct_VeOU = 0U;
  }

  /* End of Switch: '<S3>/Switch4' */

  /* Switch: '<S3>/Switch5' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd == 1) {
    /* Outport: '<Root>/VeOUT_DHM_RRHadUnfold_pct_VeOUT_DHM_RRHadUnfold_pct' */
    DHM_Y.VeOUT_DHM_RRHadUnfold_pct_VeOUT = DHM_B.SO_e_MotorPwm;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_RRHadUnfold_pct_VeOUT_DHM_RRHadUnfold_pct' incorporates:
     *  Constant: '<S3>/Constant7'
     */
    DHM_Y.VeOUT_DHM_RRHadUnfold_pct_VeOUT = 0U;
  }

  /* End of Switch: '<S3>/Switch5' */

  /* Switch: '<S3>/Switch6' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd_p == 2) {
    /* Outport: '<Root>/VeOUT_DHM_FLHadFold_pct_VeOUT_DHM_FLHadFold_pct' */
    DHM_Y.VeOUT_DHM_FLHadFold_pct_VeOUT_D = DHM_B.SO_e_MotorPwm_l;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_FLHadFold_pct_VeOUT_DHM_FLHadFold_pct' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    DHM_Y.VeOUT_DHM_FLHadFold_pct_VeOUT_D = 0U;
  }

  /* End of Switch: '<S3>/Switch6' */

  /* Switch: '<S3>/Switch7' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   */
  if (DHM_B.SO_e_MotorCmd == 2) {
    /* Outport: '<Root>/VeOUT_DHM_RRHadFold_pct_VeOUT_DHM_RRHadFold_pct' */
    DHM_Y.VeOUT_DHM_RRHadFold_pct_VeOUT_D = DHM_B.SO_e_MotorPwm;
  } else {
    /* Outport: '<Root>/VeOUT_DHM_RRHadFold_pct_VeOUT_DHM_RRHadFold_pct' incorporates:
     *  Constant: '<S3>/Constant8'
     */
    DHM_Y.VeOUT_DHM_RRHadFold_pct_VeOUT_D = 0U;
  }

  /* End of Switch: '<S3>/Switch7' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VbOUT_DHM_BdcDrivDoorHandSetSts_flg_VbOUT_DHM_BdcDrivDoorHandSetSts_flg' */
  DHM_Y.VbOUT_DHM_BdcDrivDoorHandSetSts = false;

  /* Outport: '<Root>/VbOUT_DHM_BdcPassDoorHandSetSts_flg_VbOUT_DHM_BdcPassDoorHandSetSts_flg' */
  DHM_Y.VbOUT_DHM_BdcPassDoorHandSetSts = false;

  /* Outport: '<Root>/VbOUT_DHM_RLDoorHandSetSts_flg_VbOUT_DHM_RLDoorHandSetSts_flg' */
  DHM_Y.VbOUT_DHM_RLDoorHandSetSts_flg_ = false;

  /* Outport: '<Root>/VbOUT_DHM_RRDoorHandSetSts_flg_VbOUT_DHM_RRDoorHandSetSts_flg' */
  DHM_Y.VbOUT_DHM_RRDoorHandSetSts_flg_ = false;

  /* Outport: '<Root>/VbOUT_DHM_DrivDoorHandErrSts_flg_VbOUT_DHM_DrivDoorHandErrSts_flg' */
  DHM_Y.VbOUT_DHM_DrivDoorHandErrSts_fl = false;

  /* Outport: '<Root>/VbOUT_DHM_PassDoorHandErrSts_flg_VbOUT_DHM_PassDoorHandErrSts_flg' */
  DHM_Y.VbOUT_DHM_PassDoorHandErrSts_fl = false;

  /* Outport: '<Root>/VbOUT_DHM_RLDoorHandErrSts_flg_VbOUT_DHM_RLDoorHandErrSts_flg' */
  DHM_Y.VbOUT_DHM_RLDoorHandErrSts_flg_ = false;

  /* Outport: '<Root>/VbOUT_DHM_RRDoorHandErrSts_flg_VbOUT_DHM_RRDoorHandErrSts_flg' */
  DHM_Y.VbOUT_DHM_RRDoorHandErrSts_flg_ = false;
}

/* Model initialize function */
void DHM_initialize(void)
{
  {
    boolean_T SO_b_Error_g;
    boolean_T SO_b_MotorA_i;
    boolean_T SO_b_MotorB_b;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorHndDriver' */
    DHM_FLDoorHndDriver_Init(&SO_b_MotorA_i, &SO_b_MotorB_b,
      &DHM_B.SO_e_MotorCmd_p, &DHM_B.SO_e_MotorPwm_l, &SO_b_Error_g);

    /* SystemInitialize for Chart: '<S3>/FLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_k, &DHM_B.SO_b_HndFoldReq_b);

    /* SystemInitialize for Chart: '<S3>/FRDoorHndDriver' */
    DHM_FLDoorHndDriver_Init(&SO_b_MotorA_i, &SO_b_MotorB_b,
      &DHM_B.SO_e_MotorCmd_m, &DHM_B.SO_e_MotorPwm_c, &SO_b_Error_g);

    /* SystemInitialize for Chart: '<S3>/FRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_p, &DHM_B.SO_b_HndFoldReq_o);

    /* SystemInitialize for Chart: '<S3>/RLDoorHndDriver' */
    DHM_FLDoorHndDriver_Init(&SO_b_MotorA_i, &SO_b_MotorB_b,
      &DHM_B.SO_e_MotorCmd_o, &DHM_B.SO_e_MotorPwm_h, &SO_b_Error_g);

    /* SystemInitialize for Chart: '<S3>/RLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_l, &DHM_B.SO_b_HndFoldReq_m);

    /* SystemInitialize for Chart: '<S3>/RRDoorHndDriver' */
    DHM_FLDoorHndDriver_Init(&SO_b_MotorA_i, &SO_b_MotorB_b,
      &DHM_B.SO_e_MotorCmd, &DHM_B.SO_e_MotorPwm, &SO_b_Error_g);

    /* SystemInitialize for Chart: '<S3>/RRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq, &DHM_B.SO_b_HndFoldReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
  }
}

/* Model terminate function */
void DHM_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
