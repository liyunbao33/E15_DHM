/*
 * File: DHM_types.h
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

#ifndef RTW_HEADER_DHM_types_h_
#define RTW_HEADER_DHM_types_h_
#include "Rte_Type.h"
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_Door_Sts_E_
#define DEFINED_TYPEDEF_FOR_Door_Sts_E_

typedef enum {
  Door_Lock = 0,                       /* Default value */
  Door_Unlock,
  Door_Not_Used,
  Door_Error
} Door_Sts_E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gear_Posn_E_
#define DEFINED_TYPEDEF_FOR_Gear_Posn_E_

typedef uint8 Gear_Posn_E;

/* enum Gear_Posn_E */
#define Gear_Reserved1                 ((Gear_Posn_E)0U)         /* Default value */
#define Gear_P                         ((Gear_Posn_E)1U)
#define Gear_R                         ((Gear_Posn_E)2U)
#define Gear_N                         ((Gear_Posn_E)3U)
#define Gear_D                         ((Gear_Posn_E)4U)
#define Gear_Reserved2                 ((Gear_Posn_E)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_HndPos_Sts_E_
#define DEFINED_TYPEDEF_FOR_HndPos_Sts_E_

typedef uint8 HndPos_Sts_E;

/* enum HndPos_Sts_E */
#define Hnd_Fold                       ((HndPos_Sts_E)0U)        /* Default value */
#define Hnd_Unfold                     ((HndPos_Sts_E)1U)
#define Hnd_Half_Unfold                ((HndPos_Sts_E)2U)
#define Hnd_Error                      ((HndPos_Sts_E)3U)
#endif
#endif                                 /* RTW_HEADER_DHM_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
