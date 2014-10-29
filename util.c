/*
   ITU-T G.729A Speech Coder with Annex B    ANSI-C Source Code
   Version 1.3    Last modified: August 1997

   Copyright (c) 1996,
   AT&T, France Telecom, NTT, Universite de Sherbrooke, Lucent Technologies,
   Rockwell International
   All rights reserved.
*/

/*-------------------------------------------------------------------*
 * Function  Set zero()                                              *
 *           ~~~~~~~~~~                                              *
 * Set vector x[] to zero                                            *
 *-------------------------------------------------------------------*/

#include "typedef.h"
#include "basic_op.h"
#include "ld8a.h"

void Set_zero(
  int16_t x[],       /* (o)    : vector to clear     */
  int16_t L          /* (i)    : length of vector    */
)
{
   int16_t i;

   for (i = 0; i < L; i++)
     x[i] = 0;

   return;
}
/*-------------------------------------------------------------------*
 * Function  Copy:                                                   *
 *           ~~~~~                                                   *
 * Copy vector x[] to y[]                                            *
 *-------------------------------------------------------------------*/

void Copy(
  int16_t x[],      /* (i)   : input vector   */
  int16_t y[],      /* (o)   : output vector  */
  int16_t L         /* (i)   : vector length  */
)
{
   int16_t i;

   for (i = 0; i < L; i++)
     y[i] = x[i];

   return;
}

/* Random generator  */

int16_t Random(int16_t *seed)
{

  /* seed = seed*31821 + 13849; */
  *seed = extract_l(L_add(L_shr(L_mult(*seed, 31821), 1), 13849L));

  return(*seed);
}



