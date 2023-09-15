/*
 * File: DHM.c
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

#include "DHM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"

/* Named constants for Chart: '<S3>/DRIVER_DOOR HANDLE' */
#define DHM_IN_ACTIVE                  ((uint8)1U)
#define DHM_IN_FOLDING                 ((uint8)1U)
#define DHM_IN_FULL_CLOSE              ((uint8)2U)
#define DHM_IN_FULL_OPEN               ((uint8)3U)
#define DHM_IN_HALF_CLOSE              ((uint8)4U)
#define DHM_IN_HALF_OPEN               ((uint8)5U)
#define DHM_IN_INACTIVE                ((uint8)2U)
#define DHM_IN_INIT                    ((uint8)1U)
#define DHM_IN_SLEEP                   ((uint8)2U)
#define DHM_IN_UNFOLDING               ((uint8)6U)

/* Named constants for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
#define DHM_IN_OFF                     ((uint8)1U)
#define DHM_IN_ON                      ((uint8)2U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/* Forward declaration for local functions */
static boolean DHM_RLUnfold(void);
static boolean DHM_RRUnfold(void);
static boolean DHM_FRUnfold(void);
static boolean DHM_RLFold(void);
static boolean DHM_RRFold(void);
static boolean DHM_FRFold(void);
static void DHM_OUTPUT_STATUS(void);
static void DHM_FOLD_HANDLER(void);
static void DHM_enter_internal_c4_DHM(void);

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static boolean DHM_RLUnfold(void)
{
  Boolean tmpRead;
  boolean c;

  /* Inport: '<Root>/VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg(&tmpRead);
  if (tmpRead && ((DHM_DW.SI_b_RLHadPos2_prev != DHM_DW.SI_b_RLHadPos2_start) &&
                  DHM_DW.SI_b_RLHadPos2_start)) {
    DHM_DW.SL_b_RLUnfoldSucc = true;
    c = true;
  } else {
    c = DHM_DW.SL_b_RLUnfoldSucc;
  }

  return c;
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static boolean DHM_RRUnfold(void)
{
  Boolean tmpRead;
  boolean c;

  /* Inport: '<Root>/VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg(&tmpRead);
  if (tmpRead && ((DHM_DW.SI_b_RRHadPos2_prev != DHM_DW.SI_b_RRHadPos2_start) &&
                  DHM_DW.SI_b_RRHadPos2_start)) {
    DHM_DW.SL_b_RRUnfoldSucc = true;
    c = true;
  } else {
    c = DHM_DW.SL_b_RRUnfoldSucc;
  }

  return c;
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static boolean DHM_FRUnfold(void)
{
  Boolean tmpRead;
  boolean c;

  /* Inport: '<Root>/VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg(&tmpRead);
  if (tmpRead && ((DHM_DW.SI_b_FRHadPos2_prev != DHM_DW.SI_b_FRHadPos2_start) &&
                  DHM_DW.SI_b_FRHadPos2_start)) {
    DHM_DW.SL_b_FRUnfoldSucc = true;
    c = true;
  } else {
    c = DHM_DW.SL_b_FRUnfoldSucc;
  }

  return c;
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static boolean DHM_RLFold(void)
{
  Boolean tmpRead;
  Boolean tmpRead_0;

  /* Inport: '<Root>/VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg(&tmpRead_0);

  /* Inport: '<Root>/VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg(&tmpRead);
  return DHM_B.SO_b_HandleFold && ((!tmpRead) && (!tmpRead_0));
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static boolean DHM_RRFold(void)
{
  Boolean tmpRead;
  Boolean tmpRead_0;

  /* Inport: '<Root>/VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg(&tmpRead_0);

  /* Inport: '<Root>/VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg(&tmpRead);
  return DHM_B.SO_b_HandleFold && ((!tmpRead) && (!tmpRead_0));
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static boolean DHM_FRFold(void)
{
  Boolean tmpRead;
  Boolean tmpRead_0;

  /* Inport: '<Root>/VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg(&tmpRead_0);

  /* Inport: '<Root>/VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg(&tmpRead);
  return DHM_B.SO_b_HandleFold && ((!tmpRead) && (!tmpRead_0));
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static void DHM_OUTPUT_STATUS(void)
{
  Boolean tmpRead;
  Boolean tmpRead_0;
  Boolean tmpRead_1;
  Boolean tmpRead_2;
  Boolean tmpRead_3;
  Boolean tmpRead_4;

  /* Inport: '<Root>/VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg(&tmpRead);

  /* Inport: '<Root>/VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg(&tmpRead_0);
  switch (DHM_DW.is_OUTPUT_FR) {
   case DHM_IN_FOLDING:
    if (DHM_DW.SL_b_FRHalfClose && (DHM_DW.temporalCounter_i3 >= 250)) {
      /* HALF_CLOSE */
      DHM_DW.is_OUTPUT_FR = DHM_IN_HALF_CLOSE;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
    } else if ((!tmpRead) && (!tmpRead_0)) {
      /* FULL_CLOSE */
      DHM_DW.is_OUTPUT_FR = DHM_IN_FULL_CLOSE;
      DHM_DW.SL_e_BDCPassDoorHndSts = 0U;
    }
    break;

   case DHM_IN_FULL_CLOSE:
    if (tmpRead && (!tmpRead_0) && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_FR = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_FRHalfOpen = false;
      DHM_DW.SL_b_FRFullyOpen = false;
    }
    break;

   case DHM_IN_FULL_OPEN:
    if (tmpRead && (!tmpRead_0) && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_FR = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i3 = 0U;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_FRHalfOpen = false;
      DHM_DW.SL_b_FRFullyOpen = false;
    }
    break;

   case DHM_IN_HALF_CLOSE:
    tmpRead = (tmpRead && (!tmpRead_0));
    if (tmpRead && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_FR = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_FRHalfOpen = false;
      DHM_DW.SL_b_FRFullyOpen = false;
    } else if (tmpRead && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_FR = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i3 = 0U;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_FRHalfOpen = false;
      DHM_DW.SL_b_FRFullyOpen = false;
    }
    break;

   case DHM_IN_HALF_OPEN:
    tmpRead = (tmpRead && (!tmpRead_0));
    if (tmpRead && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_FR = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i3 = 0U;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_FRHalfOpen = false;
      DHM_DW.SL_b_FRFullyOpen = false;
    } else if (tmpRead && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_FR = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_FRHalfOpen = false;
      DHM_DW.SL_b_FRFullyOpen = false;
    }
    break;

   default:
    /* case IN_UNFOLDING: */
    if ((DHM_DW.SL_b_FRHalfOpen_prev != DHM_DW.SL_b_FRHalfOpen_start) &&
        DHM_DW.SL_b_FRHalfOpen_start) {
      /* HALF_OPEN */
      DHM_DW.is_OUTPUT_FR = DHM_IN_HALF_OPEN;
      DHM_DW.SL_e_BDCPassDoorHndSts = 2U;
    } else if (DHM_DW.SL_b_FRFullyOpen) {
      /* FULL_OPEN */
      DHM_DW.is_OUTPUT_FR = DHM_IN_FULL_OPEN;
      DHM_DW.SL_e_BDCPassDoorHndSts = 1U;
    }
    break;
  }

  /* Inport: '<Root>/VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg(&tmpRead_1);

  /* Inport: '<Root>/VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg(&tmpRead_2);
  switch (DHM_DW.is_OUTPUT_RL) {
   case DHM_IN_FOLDING:
    if (DHM_DW.SL_b_RLHalfClose && (DHM_DW.temporalCounter_i4 >= 250)) {
      /* HALF_CLOSE */
      DHM_DW.is_OUTPUT_RL = DHM_IN_HALF_CLOSE;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
    } else if ((!tmpRead_1) && (!tmpRead_2)) {
      /* FULL_CLOSE */
      DHM_DW.is_OUTPUT_RL = DHM_IN_FULL_CLOSE;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 0U;
    }
    break;

   case DHM_IN_FULL_CLOSE:
    if (tmpRead_1 && (!tmpRead_2) && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_RL = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RLHalfOpen = false;
      DHM_DW.SL_b_RLFullyOpen = false;
    }
    break;

   case DHM_IN_FULL_OPEN:
    if (tmpRead_1 && (!tmpRead_2) && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_RL = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i4 = 0U;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RLHalfOpen = false;
      DHM_DW.SL_b_RLFullyOpen = false;
    }
    break;

   case DHM_IN_HALF_CLOSE:
    tmpRead = (tmpRead_1 && (!tmpRead_2));
    if (tmpRead && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_RL = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RLHalfOpen = false;
      DHM_DW.SL_b_RLFullyOpen = false;
    } else if (tmpRead && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_RL = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i4 = 0U;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RLHalfOpen = false;
      DHM_DW.SL_b_RLFullyOpen = false;
    }
    break;

   case DHM_IN_HALF_OPEN:
    tmpRead = (tmpRead_1 && (!tmpRead_2));
    if (tmpRead && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_RL = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i4 = 0U;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RLHalfOpen = false;
      DHM_DW.SL_b_RLFullyOpen = false;
    } else if (tmpRead && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_RL = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RLHalfOpen = false;
      DHM_DW.SL_b_RLFullyOpen = false;
    }
    break;

   default:
    /* case IN_UNFOLDING: */
    if ((DHM_DW.SL_b_RLHalfOpen_prev != DHM_DW.SL_b_RLHalfOpen_start) &&
        DHM_DW.SL_b_RLHalfOpen_start) {
      /* HALF_OPEN */
      DHM_DW.is_OUTPUT_RL = DHM_IN_HALF_OPEN;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 2U;
    } else if (DHM_DW.SL_b_RLFullyOpen) {
      /* FULL_OPEN */
      DHM_DW.is_OUTPUT_RL = DHM_IN_FULL_OPEN;
      DHM_DW.SL_e_BDCLeReDoorHndSts = 1U;
    }
    break;
  }

  /* Inport: '<Root>/VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg' */
  (void)Rte_Read_VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg(&tmpRead_3);

  /* Inport: '<Root>/VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg(&tmpRead_4);
  switch (DHM_DW.is_OUTPUT_RR) {
   case DHM_IN_FOLDING:
    if (DHM_DW.SL_b_RRHalfClose && (DHM_DW.temporalCounter_i5 >= 250)) {
      /* HALF_CLOSE */
      DHM_DW.is_OUTPUT_RR = DHM_IN_HALF_CLOSE;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
    } else if ((!tmpRead_3) && (!tmpRead_4)) {
      /* FULL_CLOSE */
      DHM_DW.is_OUTPUT_RR = DHM_IN_FULL_CLOSE;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 0U;
    }
    break;

   case DHM_IN_FULL_CLOSE:
    if (tmpRead_3 && (!tmpRead_4) && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_RR = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_RRHalfOpen = false;
      DHM_DW.SL_b_RRFullyOpen = false;
    }
    break;

   case DHM_IN_FULL_OPEN:
    if (tmpRead_3 && (!tmpRead_4) && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_RR = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i5 = 0U;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_RRHalfOpen = false;
      DHM_DW.SL_b_RRFullyOpen = false;
    }
    break;

   case DHM_IN_HALF_CLOSE:
    tmpRead = (tmpRead_3 && (!tmpRead_4));
    if (tmpRead && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_RR = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_RRHalfOpen = false;
      DHM_DW.SL_b_RRFullyOpen = false;
    } else if (tmpRead && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_RR = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i5 = 0U;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_RRHalfOpen = false;
      DHM_DW.SL_b_RRFullyOpen = false;
    }
    break;

   case DHM_IN_HALF_OPEN:
    tmpRead = (tmpRead_3 && (!tmpRead_4));
    if (tmpRead && (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE)) {
      /* FOLDING */
      DHM_DW.is_OUTPUT_RR = DHM_IN_FOLDING;
      DHM_DW.temporalCounter_i5 = 0U;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_RRHalfOpen = false;
      DHM_DW.SL_b_RRFullyOpen = false;
    } else if (tmpRead && (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE)) {
      /* UNFOLDING */
      DHM_DW.is_OUTPUT_RR = DHM_IN_UNFOLDING;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_RRHalfOpen = false;
      DHM_DW.SL_b_RRFullyOpen = false;
    }
    break;

   default:
    /* case IN_UNFOLDING: */
    if ((DHM_DW.SL_b_RRHalfOpen_prev != DHM_DW.SL_b_RRHalfOpen_start) &&
        DHM_DW.SL_b_RRHalfOpen_start) {
      /* HALF_OPEN */
      DHM_DW.is_OUTPUT_RR = DHM_IN_HALF_OPEN;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 2U;
    } else if (DHM_DW.SL_b_RRFullyOpen) {
      /* FULL_OPEN */
      DHM_DW.is_OUTPUT_RR = DHM_IN_FULL_OPEN;
      DHM_DW.SL_e_BDCRiReDoorHndSts = 1U;
    }
    break;
  }
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static void DHM_FOLD_HANDLER(void)
{
  if (DHM_B.SO_b_HandleFold && (DHM_RLFold() || DHM_RRFold() || DHM_FRFold())) {
    if (DHM_RLFold() && DHM_RRFold() && DHM_FRFold()) {
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RRHalfClose = false;
      DHM_DW.SL_b_FOLD = true;
    } else if (DHM_RRFold() && DHM_FRFold()) {
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_RLHalfClose = true;
      DHM_DW.SL_b_RRHalfClose = false;
    } else if (DHM_RLFold() && DHM_FRFold()) {
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RRHalfClose = true;
    } else if (DHM_RLFold() && DHM_RRFold()) {
      DHM_DW.SL_b_FRHalfClose = true;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RRHalfClose = false;
    } else if (DHM_FRFold()) {
      DHM_DW.SL_b_FRHalfClose = false;
      DHM_DW.SL_b_RLHalfClose = true;
      DHM_DW.SL_b_RRHalfClose = true;
    } else if (DHM_RLFold()) {
      DHM_DW.SL_b_FRHalfClose = true;
      DHM_DW.SL_b_RLHalfClose = false;
      DHM_DW.SL_b_RRHalfClose = true;
    } else if (DHM_RRFold()) {
      DHM_DW.SL_b_FRHalfClose = true;
      DHM_DW.SL_b_RLHalfClose = true;
      DHM_DW.SL_b_RRHalfClose = false;
    }
  }
}

/* Function for Chart: '<S3>/PASSENGER_DOOR_HANDLES' */
static void DHM_enter_internal_c4_DHM(void)
{
  DHM_DW.is_UNFOLD_ACT = DHM_IN_INACTIVE;
  DHM_B.SO_b_HandleUnfold = false;
  DHM_DW.is_FOLD_ACT = DHM_IN_INACTIVE;
  DHM_B.SO_b_HandleFold = false;
  DHM_DW.is_FR = DHM_IN_OFF;
  DHM_DW.is_RL = DHM_IN_OFF;
  DHM_DW.is_RR = DHM_IN_OFF;
  DHM_DW.is_OUTPUT_FR = DHM_IN_FULL_CLOSE;
  DHM_DW.SL_e_BDCPassDoorHndSts = 0U;
  DHM_DW.is_OUTPUT_RL = DHM_IN_FULL_CLOSE;
  DHM_DW.SL_e_BDCLeReDoorHndSts = 0U;
  DHM_DW.is_OUTPUT_RR = DHM_IN_FULL_CLOSE;
  DHM_DW.SL_e_BDCRiReDoorHndSts = 0U;
  DHM_DW.is_FOLD_SLEEP_PERMIT = DHM_IN_INIT;
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  Boolean tmpRead;
  Boolean tmpRead_0;
  Boolean tmpRead_1;
  Boolean tmpRead_2;
  Boolean tmpRead_3;
  Boolean tmpRead_4;
  Boolean tmpRead_5;
  Boolean tmpRead_6;
  Boolean tmpRead_7;
  Boolean tmpRead_8;
  Boolean tmpRead_9;
  Boolean tmpRead_a;
  Boolean tmpRead_b;
  Boolean tmpRead_c;
  boolean guard1 = false;
  boolean guard2 = false;

  /* Inport: '<Root>/VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_RRHadPos2_flg_VbINP_HWA_RRHadPos2_flg(&tmpRead_c);

  /* Inport: '<Root>/VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_RLHadPos2_flg_VbINP_HWA_RLHadPos2_flg(&tmpRead_a);

  /* Inport: '<Root>/VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_FRHadPos2_flg_VbINP_HWA_FRHadPos2_flg(&tmpRead_8);

  /* Inport: '<Root>/VbINP_HWA_FLHadPos2_flg_VbINP_HWA_FLHadPos2_flg' */
  (void)Rte_Read_VbINP_HWA_FLHadPos2_flg_VbINP_HWA_FLHadPos2_flg(&tmpRead_6);

  /* Inport: '<Root>/VbINP_HWA_FRLockSts_flg_VbINP_HWA_FRLockSts_flg' */
  (void)Rte_Read_VbINP_HWA_FRLockSts_flg_VbINP_HWA_FRLockSts_flg(&tmpRead_4);

  /* Inport: '<Root>/VbINP_HWA_FLLockSts_flg_VbINP_HWA_FLLockSts_flg' */
  (void)Rte_Read_VbINP_HWA_FLLockSts_flg_VbINP_HWA_FLLockSts_flg(&tmpRead_3);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* SignalConversion generated from: '<S2>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   */
  (void)Rte_Read_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg
    (&DHM_B.TmpSignalConversionAtVbINP_CAN_);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  (void)Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh
    (&DHM_B.TmpSignalConversionAtVeOUT_SP_E);

  /* SignalConversion generated from: '<S2>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   */
  (void)Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg
    (&DHM_B.TmpSignalConversionAtVbOUT_SP_C);

  /* SignalConversion generated from: '<S2>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig'
   */
  (void)
    Rte_Read_VeOUT_DLK_BCMPassengerDoorLockStatus_sig_VeOUT_DLK_BCMPassengerDoorLockStatus_sig
    (&DHM_B.TmpSignalConversionAtVeOUT_DLK_);

  /* SignalConversion generated from: '<S2>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig'
   */
  (void)
    Rte_Read_VeOUT_DLK_BdcDrvrDoorLockSts_sig_VeOUT_DLK_BdcDrvrDoorLockSts_sig
    (&DHM_B.TmpSignalConversionAtVeOUT_DL_l);

  /* SignalConversion generated from: '<S2>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig'
   */
  (void)Rte_Read_VeINP_CAN_VcuGearPosn_sig_VeINP_CAN_VcuGearPosn_sig
    (&DHM_B.TmpSignalConversionAtVeINP_CAN_);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_VcuRdySts_flg_VbINP_CAN_VcuRdySts_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_VcuRdySts_flg_VbINP_CAN_VcuRdySts_flg'
   */
  (void)Rte_Read_VbINP_CAN_VcuRdySts_flg_VbINP_CAN_VcuRdySts_flg
    (&DHM_B.TmpSignalConversionAtVbINP_CA_m);

  /* Chart: '<S3>/DRIVER_DOOR HANDLE' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FLHadPos1_flg_VbINP_HWA_FLHadPos1_flg'
   */
  if (DHM_DW.temporalCounter_i1_p < 255U) {
    DHM_DW.temporalCounter_i1_p++;
  }

  if (DHM_DW.temporalCounter_i2_b < 255U) {
    DHM_DW.temporalCounter_i2_b++;
  }

  if (DHM_DW.temporalCounter_i3_h < 255U) {
    DHM_DW.temporalCounter_i3_h++;
  }

  DHM_DW.SI_e_BcmPassDoorLckSts_prev_n = DHM_DW.SI_e_BcmPassDoorLckSts_start_p;
  DHM_DW.SI_e_BcmPassDoorLckSts_start_p = DHM_B.TmpSignalConversionAtVeOUT_DLK_;
  DHM_DW.SI_e_BcmDrvrDoorLckSts_prev_a = DHM_DW.SI_e_BcmDrvrDoorLckSts_start_p;
  DHM_DW.SI_e_BcmDrvrDoorLckSts_start_p = DHM_B.TmpSignalConversionAtVeOUT_DL_l;
  DHM_DW.SI_b_FLLockSts_prev = DHM_DW.SI_b_FLLockSts_start;
  DHM_DW.SI_b_FLLockSts_start = tmpRead_3;
  DHM_DW.SI_b_CrashOutpSts_prev_b = DHM_DW.SI_b_CrashOutpSts_start_n;
  DHM_DW.SI_b_CrashOutpSts_start_n = DHM_B.TmpSignalConversionAtVbOUT_SP_C;
  DHM_DW.SI_b_FLHadPos2_prev = DHM_DW.SI_b_FLHadPos2_start;
  DHM_DW.SI_b_FLHadPos2_start = tmpRead_6;
  if (DHM_DW.is_active_c3_DHM == 0U) {
    DHM_DW.SI_e_BcmPassDoorLckSts_prev_n = DHM_B.TmpSignalConversionAtVeOUT_DLK_;
    DHM_DW.SI_e_BcmDrvrDoorLckSts_prev_a = DHM_B.TmpSignalConversionAtVeOUT_DL_l;
    DHM_DW.SI_b_FLLockSts_prev = tmpRead_3;
    DHM_DW.SI_b_CrashOutpSts_prev_b = DHM_B.TmpSignalConversionAtVbOUT_SP_C;
    DHM_DW.SI_b_FLHadPos2_prev = tmpRead_6;
    DHM_DW.is_active_c3_DHM = 1U;
    DHM_DW.is_UNFOLD_ACT_l = DHM_IN_INACTIVE;
    DHM_B.SO_b_FLHadUnfold = false;
    DHM_DW.is_FOLD_ACT_d = DHM_IN_INACTIVE;
    DHM_B.SO_b_FLHadFold = false;
    DHM_DW.is_OUTPUT_STATUS = DHM_IN_FULL_CLOSE;
    DHM_DW.SL_e_BDCDrvrDoorHndSts = 0U;
    DHM_DW.is_FOLD_SLEEP_PERMIT_j = DHM_IN_INIT;
  } else {
    (void)Rte_Read_VbINP_HWA_FLHadPos1_flg_VbINP_HWA_FLHadPos1_flg(&tmpRead_5);
    (void)Rte_Read_VbINP_HWA_FLDoorAjar_flg_VbINP_HWA_FLDoorAjar_flg(&tmpRead);
    guard1 = false;
    guard2 = false;
    if (DHM_DW.is_UNFOLD_ACT_l == DHM_IN_ACTIVE) {
      if (DHM_DW.SL_b_Crash_g && (tmpRead_5 && ((DHM_DW.SI_b_FLHadPos2_prev !=
             DHM_DW.SI_b_FLHadPos2_start) && DHM_DW.SI_b_FLHadPos2_start))) {
        DHM_DW.SL_b_OpenFully = true;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_Crash_g = false;
        guard2 = true;
      } else if (tmpRead_5 && ((DHM_DW.SI_b_FLHadPos2_prev !=
                   DHM_DW.SI_b_FLHadPos2_start) && DHM_DW.SI_b_FLHadPos2_start))
      {
        DHM_DW.SL_b_OpenFully = true;
        guard2 = true;
      } else if ((DHM_DW.temporalCounter_i2_b >= 250) && (!DHM_DW.SL_b_Crash_g))
      {
        /* IceBreaking(TBD) */
        DHM_DW.SL_b_HalfOpen = true;

        /* Time's Up */
        guard2 = true;
      }

      /* case IN_INACTIVE: */
    } else if ((DHM_DW.SI_b_CrashOutpSts_prev_b !=
                DHM_DW.SI_b_CrashOutpSts_start_n) &&
               DHM_DW.SI_b_CrashOutpSts_start_n) {
      DHM_DW.SL_b_Crash_g = true;
      guard1 = true;

      /* SI_e_EspVehSpd < 3 &&SI_b_EspVehSpdVld == 1 &&... */
    } else if ((!DHM_B.TmpSignalConversionAtVbOUT_SP_C) && (DHM_DW.is_FOLD_ACT_d
                != DHM_IN_ACTIVE) && (((DHM_B.SO_e_BDCDrvrDoorHndSts == 2) &&
                 tmpRead) || ((DHM_DW.SI_b_FLLockSts_prev !=
                  DHM_DW.SI_b_FLLockSts_start) && (!DHM_DW.SI_b_FLLockSts_start))))
    {
      /* Condition */
      /* Half Opened */
      /* DRIVER DOOR UNLOCKED (HWA) */
      guard1 = true;
    } else {
      /* hasChangedTo(SI_e_VcuGearPosn, 1) &&... */
    }

    if (guard2) {
      DHM_DW.is_UNFOLD_ACT_l = DHM_IN_INACTIVE;
      DHM_B.SO_b_FLHadUnfold = false;
    }

    if (guard1) {
      DHM_DW.is_UNFOLD_ACT_l = DHM_IN_ACTIVE;
      DHM_DW.temporalCounter_i2_b = 0U;
      DHM_B.SO_b_FLHadUnfold = true;
    }

    if (DHM_DW.is_FOLD_ACT_d == DHM_IN_ACTIVE) {
      guard1 = false;
      if ((!tmpRead_5) && (!tmpRead_6)) {
        DHM_DW.SL_b_HalfClose = false;
        guard1 = true;
      } else if (DHM_DW.temporalCounter_i1_p >= 250) {
        DHM_DW.SL_b_HalfClose = true;

        /* Time's Up */
        guard1 = true;
      }

      if (guard1) {
        DHM_DW.is_FOLD_ACT_d = DHM_IN_INACTIVE;
        DHM_B.SO_b_FLHadFold = false;
      }

      /* case IN_INACTIVE: */
    } else if ((DHM_DW.is_UNFOLD_ACT_l != DHM_IN_ACTIVE) &&
               (((DHM_B.TmpSignalConversionAtVeOUT_DL_l == 0) &&
                 ((DHM_DW.SI_e_BcmPassDoorLckSts_prev_n !=
                   DHM_DW.SI_e_BcmPassDoorLckSts_start_p) &&
                  (DHM_DW.SI_e_BcmPassDoorLckSts_start_p == 0))) ||
                ((DHM_DW.SI_e_BcmDrvrDoorLckSts_prev_a !=
                  DHM_DW.SI_e_BcmDrvrDoorLckSts_start_p) &&
                 (DHM_DW.SI_e_BcmDrvrDoorLckSts_start_p == 0) &&
                 (DHM_B.TmpSignalConversionAtVeOUT_DLK_ == 0)))) {
      DHM_DW.is_FOLD_ACT_d = DHM_IN_ACTIVE;
      DHM_DW.temporalCounter_i1_p = 0U;
      DHM_B.SO_b_FLHadFold = true;
    }

    switch (DHM_DW.is_OUTPUT_STATUS) {
     case DHM_IN_FOLDING:
      if (DHM_DW.SL_b_HalfClose && (DHM_DW.temporalCounter_i3_h >= 250)) {
        /* HALF_CLOSE */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_HALF_CLOSE;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
      } else if ((!tmpRead_5) && (!tmpRead_6)) {
        /* FULL_CLOSE */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_FULL_CLOSE;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 0U;
      }
      break;

     case DHM_IN_FULL_CLOSE:
      if (tmpRead_5 && (!tmpRead_6) && (DHM_DW.is_UNFOLD_ACT_l == DHM_IN_ACTIVE))
      {
        /* UNFOLDING */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_UNFOLDING;
        DHM_DW.temporalCounter_i3_h = 0U;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
        DHM_DW.SL_b_HalfClose = false;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_OpenFully = false;
      }
      break;

     case DHM_IN_FULL_OPEN:
      if (tmpRead_5 && (!tmpRead_6) && (DHM_DW.is_FOLD_ACT_d == DHM_IN_ACTIVE))
      {
        /* FOLDING */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_FOLDING;
        DHM_DW.temporalCounter_i3_h = 0U;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
        DHM_DW.SL_b_HalfClose = false;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_OpenFully = false;
      }
      break;

     case DHM_IN_HALF_CLOSE:
      tmpRead_3 = (tmpRead_5 && (!tmpRead_6));
      if (tmpRead_3 && (DHM_DW.is_UNFOLD_ACT_l == DHM_IN_ACTIVE)) {
        /* UNFOLDING */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_UNFOLDING;
        DHM_DW.temporalCounter_i3_h = 0U;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
        DHM_DW.SL_b_HalfClose = false;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_OpenFully = false;
      } else if (tmpRead_3 && (DHM_DW.is_FOLD_ACT_d == DHM_IN_ACTIVE)) {
        /* FOLDING */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_FOLDING;
        DHM_DW.temporalCounter_i3_h = 0U;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
        DHM_DW.SL_b_HalfClose = false;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_OpenFully = false;
      }
      break;

     case DHM_IN_HALF_OPEN:
      tmpRead_3 = (tmpRead_5 && (!tmpRead_6));
      if (tmpRead_3 && (DHM_DW.is_FOLD_ACT_d == DHM_IN_ACTIVE)) {
        /* FOLDING */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_FOLDING;
        DHM_DW.temporalCounter_i3_h = 0U;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
        DHM_DW.SL_b_HalfClose = false;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_OpenFully = false;
      } else if (tmpRead_3 && (DHM_DW.is_UNFOLD_ACT_l == DHM_IN_ACTIVE)) {
        /* UNFOLDING */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_UNFOLDING;
        DHM_DW.temporalCounter_i3_h = 0U;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
        DHM_DW.SL_b_HalfClose = false;
        DHM_DW.SL_b_HalfOpen = false;
        DHM_DW.SL_b_OpenFully = false;
      }
      break;

     default:
      /* case IN_UNFOLDING: */
      if (DHM_DW.SL_b_HalfOpen && (DHM_DW.temporalCounter_i3_h >= 250)) {
        /* HALF_OPEN */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_HALF_OPEN;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 2U;
      } else if (DHM_DW.SL_b_OpenFully) {
        /* FULL_OPEN */
        DHM_DW.is_OUTPUT_STATUS = DHM_IN_FULL_OPEN;
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 1U;
      }
      break;
    }

    if ((!tmpRead_5) && tmpRead_6) {
      DHM_B.SO_e_BDCDrvrDoorHndSts = 3U;

      /* Big Error */
    } else {
      if (DHM_DW.is_OUTPUT_STATUS == DHM_IN_HALF_CLOSE) {
        DHM_DW.SL_e_BDCDrvrDoorHndSts = 3U;

        /* Error Half close */
      } else {
        /* Ice Breaker */
      }

      DHM_B.SO_e_BDCDrvrDoorHndSts = DHM_DW.SL_e_BDCDrvrDoorHndSts;

      /* OUTPUT */
    }

    if (DHM_DW.is_FOLD_SLEEP_PERMIT_j == DHM_IN_INIT) {
      if ((DHM_DW.is_UNFOLD_ACT_l == DHM_IN_INACTIVE) && (DHM_DW.is_FOLD_ACT_d ==
           DHM_IN_INACTIVE)) {
        DHM_DW.is_FOLD_SLEEP_PERMIT_j = DHM_IN_SLEEP;
      }

      /* case IN_SLEEP: */
    } else if ((DHM_DW.is_UNFOLD_ACT_l == DHM_IN_ACTIVE) ||
               (DHM_DW.is_FOLD_ACT_d == DHM_IN_ACTIVE)) {
      DHM_DW.is_FOLD_SLEEP_PERMIT_j = DHM_IN_INIT;
    }
  }

  /* End of Chart: '<S3>/DRIVER_DOOR HANDLE' */

  /* Chart: '<S3>/PASSENGER_DOOR_HANDLES' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg'
   *  Inport: '<Root>/VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg'
   *  Inport: '<Root>/VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg'
   */
  if (DHM_DW.temporalCounter_i1 < 255U) {
    DHM_DW.temporalCounter_i1++;
  }

  if (DHM_DW.temporalCounter_i2 < 255U) {
    DHM_DW.temporalCounter_i2++;
  }

  if (DHM_DW.temporalCounter_i3 < 255U) {
    DHM_DW.temporalCounter_i3++;
  }

  if (DHM_DW.temporalCounter_i4 < 255U) {
    DHM_DW.temporalCounter_i4++;
  }

  if (DHM_DW.temporalCounter_i5 < 255U) {
    DHM_DW.temporalCounter_i5++;
  }

  DHM_DW.SI_b_RLHadPos2_prev = DHM_DW.SI_b_RLHadPos2_start;
  DHM_DW.SI_b_RLHadPos2_start = tmpRead_a;
  DHM_DW.SI_b_RRHadPos2_prev = DHM_DW.SI_b_RRHadPos2_start;
  DHM_DW.SI_b_RRHadPos2_start = tmpRead_c;
  DHM_DW.SI_b_FRHadPos2_prev = DHM_DW.SI_b_FRHadPos2_start;
  DHM_DW.SI_b_FRHadPos2_start = tmpRead_8;
  DHM_DW.SI_b_FRLockSts_prev = DHM_DW.SI_b_FRLockSts_start;
  DHM_DW.SI_b_FRLockSts_start = tmpRead_4;
  DHM_DW.SI_b_CrashOutpSts_prev = DHM_DW.SI_b_CrashOutpSts_start;
  DHM_DW.SI_b_CrashOutpSts_start = DHM_B.TmpSignalConversionAtVbOUT_SP_C;
  DHM_DW.SI_e_BcmPassDoorLckSts_prev = DHM_DW.SI_e_BcmPassDoorLckSts_start;
  DHM_DW.SI_e_BcmPassDoorLckSts_start = DHM_B.TmpSignalConversionAtVeOUT_DL_l;
  DHM_DW.SI_e_BcmDrvrDoorLckSts_prev = DHM_DW.SI_e_BcmDrvrDoorLckSts_start;
  DHM_DW.SI_e_BcmDrvrDoorLckSts_start = DHM_B.TmpSignalConversionAtVeOUT_DLK_;
  DHM_DW.SL_b_FRHalfOpen_prev = DHM_DW.SL_b_FRHalfOpen_start;
  DHM_DW.SL_b_FRHalfOpen_start = DHM_DW.SL_b_FRHalfOpen;
  DHM_DW.SL_b_RLHalfOpen_prev = DHM_DW.SL_b_RLHalfOpen_start;
  DHM_DW.SL_b_RLHalfOpen_start = DHM_DW.SL_b_RLHalfOpen;
  DHM_DW.SL_b_RRHalfOpen_prev = DHM_DW.SL_b_RRHalfOpen_start;
  DHM_DW.SL_b_RRHalfOpen_start = DHM_DW.SL_b_RRHalfOpen;
  if (DHM_DW.is_active_c4_DHM == 0U) {
    DHM_DW.SI_b_RLHadPos2_prev = tmpRead_a;
    DHM_DW.SI_b_RRHadPos2_prev = tmpRead_c;
    DHM_DW.SI_b_FRHadPos2_prev = tmpRead_8;
    DHM_DW.SI_b_FRLockSts_prev = tmpRead_4;
    DHM_DW.SI_b_CrashOutpSts_prev = DHM_B.TmpSignalConversionAtVbOUT_SP_C;
    DHM_DW.SI_e_BcmPassDoorLckSts_prev = DHM_B.TmpSignalConversionAtVeOUT_DL_l;
    DHM_DW.SI_e_BcmDrvrDoorLckSts_prev = DHM_B.TmpSignalConversionAtVeOUT_DLK_;
    DHM_DW.is_active_c4_DHM = 1U;
    DHM_enter_internal_c4_DHM();
  } else {
    (void)Rte_Read_VbINP_HWA_RRHadPos1_flg_VbINP_HWA_RRHadPos1_flg(&tmpRead_b);
    (void)Rte_Read_VbINP_HWA_RLHadPos1_flg_VbINP_HWA_RLHadPos1_flg(&tmpRead_9);
    (void)Rte_Read_VbINP_HWA_FRHadPos1_flg_VbINP_HWA_FRHadPos1_flg(&tmpRead_7);
    (void)Rte_Read_VbINP_HWA_FRDoorAjar_flg_VbINP_HWA_FRDoorAjar_flg(&tmpRead_0);
    (void)Rte_Read_VbINP_HWA_RLDoorAjar_flg_VbINP_HWA_RLDoorAjar_flg(&tmpRead_1);
    (void)Rte_Read_VbINP_HWA_RRDoorAjar_flg_VbINP_HWA_RRDoorAjar_flg(&tmpRead_2);
    guard1 = false;
    guard2 = false;
    if (DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE) {
      if ((DHM_DW.is_FR == DHM_IN_ON) && (DHM_DW.is_RL == DHM_IN_ON) &&
          (DHM_DW.is_RR == DHM_IN_ON)) {
        DHM_DW.SL_b_FRFullyOpen = true;
        DHM_DW.SL_b_RLFullyOpen = true;
        DHM_DW.SL_b_RRFullyOpen = true;
        DHM_DW.SL_b_Crash = false;
        guard2 = true;
      } else if (DHM_DW.SL_b_UNFOLD) {
        DHM_DW.SL_b_UNFOLD = false;
        guard2 = true;
      } else if ((DHM_DW.temporalCounter_i1 >= 250) && (!DHM_DW.SL_b_Crash) &&
                 ((!DHM_RLUnfold()) || (!DHM_RRUnfold()) || (!DHM_FRUnfold())))
      {
        /* IceBreaking Mode(TBD) */
        DHM_DW.SL_b_FRHalfOpen = true;
        DHM_DW.SL_b_RLHalfOpen = true;
        DHM_DW.SL_b_RRHalfOpen = true;
        guard2 = true;
      }

      /* case IN_INACTIVE: */
    } else if ((DHM_DW.SI_b_CrashOutpSts_prev != DHM_DW.SI_b_CrashOutpSts_start)
               && DHM_DW.SI_b_CrashOutpSts_start) {
      DHM_DW.SL_b_Crash = true;
      guard1 = true;

      /* SI_e_EspVehSpd < 3 &&SI_b_EspVehSpdVld == 1 &&... */
    } else if ((!DHM_B.TmpSignalConversionAtVbOUT_SP_C) && (DHM_DW.is_FOLD_ACT
                != DHM_IN_ACTIVE) && (((DHM_DW.UnitDelay2_DSTATE == 2) &&
                 tmpRead_0) || ((DHM_DW.UnitDelay4_DSTATE == 2) && tmpRead_1) ||
                ((DHM_DW.UnitDelay5_DSTATE == 2) && tmpRead_2) ||
                ((DHM_DW.SI_b_FRLockSts_prev != DHM_DW.SI_b_FRLockSts_start) &&
                 (!DHM_DW.SI_b_FRLockSts_start)))) {
      /* Condition */
      /*  Passenger Side Unlocked (HWA) */
      guard1 = true;
    } else {
      /* hasChangedTo(SI_e_VcuGearPosn, 1) &&... */
    }

    if (guard2) {
      DHM_DW.is_UNFOLD_ACT = DHM_IN_INACTIVE;
      DHM_B.SO_b_HandleUnfold = false;
    }

    if (guard1) {
      DHM_DW.is_UNFOLD_ACT = DHM_IN_ACTIVE;
      DHM_DW.temporalCounter_i1 = 0U;
      DHM_B.SO_b_HandleUnfold = true;
    }

    if ((DHM_DW.SI_b_CrashOutpSts_prev != DHM_DW.SI_b_CrashOutpSts_start) &&
        DHM_DW.SI_b_CrashOutpSts_start) {
      DHM_DW.is_FOLD_ACT = DHM_IN_INACTIVE;
      DHM_B.SO_b_HandleFold = false;
    } else if (DHM_DW.is_FOLD_ACT == DHM_IN_ACTIVE) {
      guard1 = false;
      if (DHM_DW.SL_b_FOLD) {
        DHM_DW.SL_b_FOLD = false;
        guard1 = true;

        /*   */
      } else if ((DHM_DW.temporalCounter_i2 >= 250) && ((!DHM_RLFold()) ||
                  (!DHM_RRFold()) || (!DHM_FRFold()))) {
        guard1 = true;
      }

      if (guard1) {
        DHM_DW.is_FOLD_ACT = DHM_IN_INACTIVE;
        DHM_B.SO_b_HandleFold = false;
      }

      /* case IN_INACTIVE: */
    } else if ((DHM_DW.is_UNFOLD_ACT != DHM_IN_ACTIVE) &&
               (((DHM_B.TmpSignalConversionAtVeOUT_DLK_ == 0) &&
                 ((DHM_DW.SI_e_BcmPassDoorLckSts_prev !=
                   DHM_DW.SI_e_BcmPassDoorLckSts_start) &&
                  (DHM_DW.SI_e_BcmPassDoorLckSts_start == 0))) ||
                ((DHM_DW.SI_e_BcmDrvrDoorLckSts_prev !=
                  DHM_DW.SI_e_BcmDrvrDoorLckSts_start) &&
                 (DHM_DW.SI_e_BcmDrvrDoorLckSts_start == 0) &&
                 (DHM_B.TmpSignalConversionAtVeOUT_DL_l == 0)))) {
      DHM_DW.is_FOLD_ACT = DHM_IN_ACTIVE;
      DHM_DW.temporalCounter_i2 = 0U;
      DHM_B.SO_b_HandleFold = true;
      DHM_DW.SL_b_RLUnfoldSucc = false;
      DHM_DW.SL_b_RRUnfoldSucc = false;
      DHM_DW.SL_b_FRUnfoldSucc = false;
    }

    if (DHM_DW.is_FR == DHM_IN_OFF) {
      if (DHM_DW.SL_b_Crash && (tmpRead_7 && ((DHM_DW.SI_b_FRHadPos2_prev !=
             DHM_DW.SI_b_FRHadPos2_start) && DHM_DW.SI_b_FRHadPos2_start))) {
        DHM_DW.is_FR = DHM_IN_ON;
        DHM_DW.SL_b_FRFullyOpen = true;
      }

      /* case IN_ON: */
    } else if (!DHM_DW.SL_b_Crash) {
      DHM_DW.is_FR = DHM_IN_OFF;
    }

    if (DHM_DW.is_RL == DHM_IN_OFF) {
      if (DHM_DW.SL_b_Crash && (tmpRead_9 && ((DHM_DW.SI_b_RLHadPos2_prev !=
             DHM_DW.SI_b_RLHadPos2_start) && DHM_DW.SI_b_RLHadPos2_start))) {
        DHM_DW.is_RL = DHM_IN_ON;
        DHM_DW.SL_b_RLFullyOpen = true;
      }

      /* case IN_ON: */
    } else if (!DHM_DW.SL_b_Crash) {
      DHM_DW.is_RL = DHM_IN_OFF;
    }

    if (DHM_DW.is_RR == DHM_IN_OFF) {
      if (DHM_DW.SL_b_Crash && (tmpRead_b && ((DHM_DW.SI_b_RRHadPos2_prev !=
             DHM_DW.SI_b_RRHadPos2_start) && DHM_DW.SI_b_RRHadPos2_start))) {
        DHM_DW.is_RR = DHM_IN_ON;
        DHM_DW.SL_b_RRFullyOpen = true;
      }

      /* case IN_ON: */
    } else if (!DHM_DW.SL_b_Crash) {
      DHM_DW.is_RR = DHM_IN_OFF;
    }

    if (DHM_B.SO_b_HandleUnfold && (!DHM_DW.SL_b_Crash) && (DHM_RLUnfold() ||
         DHM_RRUnfold() || DHM_FRUnfold())) {
      if (DHM_RLUnfold() && DHM_RRUnfold() && DHM_FRUnfold()) {
        DHM_DW.SL_b_FRFullyOpen = true;
        DHM_DW.SL_b_RLFullyOpen = true;
        DHM_DW.SL_b_RRFullyOpen = true;
        DHM_DW.SL_b_UNFOLD = true;
      } else if (DHM_RRUnfold() && DHM_FRUnfold()) {
        DHM_DW.SL_b_FRFullyOpen = true;
        DHM_DW.SL_b_RRFullyOpen = true;
      } else if (DHM_RLUnfold() && DHM_FRUnfold()) {
        DHM_DW.SL_b_FRFullyOpen = true;
        DHM_DW.SL_b_RLFullyOpen = true;
      } else if (DHM_RLUnfold() && DHM_RRUnfold()) {
        DHM_DW.SL_b_RLFullyOpen = true;
        DHM_DW.SL_b_RRFullyOpen = true;
      } else if (DHM_FRUnfold()) {
        DHM_DW.SL_b_FRFullyOpen = true;
      } else if (DHM_RLUnfold()) {
        DHM_DW.SL_b_RLFullyOpen = true;
      } else if (DHM_RRUnfold()) {
        DHM_DW.SL_b_RRFullyOpen = true;
      }
    }

    DHM_OUTPUT_STATUS();
    if ((!tmpRead_7) && tmpRead_8) {
      DHM_DW.SL_e_BDCPassDoorHndSts = 3U;

      /* Error */
    } else if (DHM_DW.is_OUTPUT_FR == DHM_IN_HALF_CLOSE) {
      DHM_DW.SL_e_BDCPassDoorHndSts = 3U;

      /* Error Half close */
    } else {
      /* Ice Break */
    }

    DHM_B.SO_e_BDCPassDoorHndSts = DHM_DW.SL_e_BDCPassDoorHndSts;

    /* FR OUTPUT */
    if ((!tmpRead_9) && tmpRead_a) {
      DHM_DW.SL_e_BDCLeReDoorHndSts = 3U;

      /* Error */
    } else if (DHM_DW.is_OUTPUT_RL == DHM_IN_HALF_CLOSE) {
      DHM_DW.SL_e_BDCLeReDoorHndSts = 3U;

      /* Error Half close */
    } else {
      /* IceBreak */
    }

    DHM_B.SO_e_BDCLeReDoorHndSts = DHM_DW.SL_e_BDCLeReDoorHndSts;

    /* RL OUTPUT */
    DHM_B.SO_e_BDCRiReDoorHndSts = DHM_DW.SL_e_BDCRiReDoorHndSts;

    /* RR OUTPUT */
    if (DHM_DW.is_FOLD_SLEEP_PERMIT == DHM_IN_INIT) {
      if ((DHM_DW.is_UNFOLD_ACT == DHM_IN_INACTIVE) && (DHM_DW.is_FOLD_ACT ==
           DHM_IN_INACTIVE)) {
        DHM_DW.is_FOLD_SLEEP_PERMIT = DHM_IN_SLEEP;
      }

      /* case IN_SLEEP: */
    } else if ((DHM_DW.is_UNFOLD_ACT == DHM_IN_ACTIVE) || (DHM_DW.is_FOLD_ACT ==
                DHM_IN_ACTIVE)) {
      DHM_DW.is_FOLD_SLEEP_PERMIT = DHM_IN_INIT;
    }

    DHM_FOLD_HANDLER();
  }

  /* End of Chart: '<S3>/PASSENGER_DOOR_HANDLES' */

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  DHM_DW.UnitDelay2_DSTATE = DHM_B.SO_e_BDCPassDoorHndSts;

  /* Update for UnitDelay: '<S3>/Unit Delay4' */
  DHM_DW.UnitDelay4_DSTATE = DHM_B.SO_e_BDCLeReDoorHndSts;

  /* Update for UnitDelay: '<S3>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE = DHM_B.SO_e_BDCRiReDoorHndSts;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg' */
  (void)Rte_Write_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg
    (DHM_B.SO_b_FLHadUnfold);

  /* Outport: '<Root>/VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg' */
  (void)Rte_Write_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg
    (DHM_B.SO_b_FLHadFold);

  /* Outport: '<Root>/VbOUT_DHM_HandleUnfold_flg_VbOUT_DHM_HandleUnfold_flg' */
  (void)Rte_Write_VbOUT_DHM_HandleUnfold_flg_VbOUT_DHM_HandleUnfold_flg
    (DHM_B.SO_b_HandleUnfold);

  /* Outport: '<Root>/VbOUT_DHM_HandleFold_flg_VbOUT_DHM_HandleFold_flg' */
  (void)Rte_Write_VbOUT_DHM_HandleFold_flg_VbOUT_DHM_HandleFold_flg
    (DHM_B.SO_b_HandleFold);

  /* Outport: '<Root>/VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig' */
  (void)
    Rte_Write_VeOUT_DHM_BDCDrvrDoorHndSts_sig_VeOUT_DHM_BDCDrvrDoorHndSts_sig
    (DHM_B.SO_e_BDCDrvrDoorHndSts);

  /* Outport: '<Root>/VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig' */
  (void)
    Rte_Write_VeOUT_DHM_BDCPassDoorHndSts_sig_VeOUT_DHM_BDCPassDoorHndSts_sig
    (DHM_B.SO_e_BDCPassDoorHndSts);

  /* Outport: '<Root>/VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig' */
  (void)
    Rte_Write_VeOUT_DHM_BDCLeReDoorHndSts_sig_VeOUT_DHM_BDCLeReDoorHndSts_sig
    (DHM_B.SO_e_BDCLeReDoorHndSts);

  /* Outport: '<Root>/VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig' */
  (void)
    Rte_Write_VeOUT_DHM_BDCRiReDoorHndSts_sig_VeOUT_DHM_BDCRiReDoorHndSts_sig
    (DHM_B.SO_e_BDCRiReDoorHndSts);
}

/* Model initialize function */
void DHM_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
