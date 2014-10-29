/*
   ITU-T G.729A Speech Coder    ANSI-C Source Code
   Version 1.1    Last modified: September 1996
   Copyright (c) 1996,
   AT&T, France Telecom, NTT, Universite de Sherbrooke, Lucent Technologies
   All rights reserved.
*/

/*-------------------------------------------------------------------*
 * Function  Convolve:                                               *
 *           ~~~~~~~~~                                               *
 *-------------------------------------------------------------------*
 * Perform the convolution between two vectors x[] and h[] and       *
 * write the result in the vector y[].                               *
 * All vectors are of length N.                                      *
 *-------------------------------------------------------------------*/

#include "typedef.h"
#include "basic_op.h"
#include "ld8a.h"

void Convolve(
  int16_t x[],      /* (i)     : input vector                           */
  int16_t h[],      /* (i) Q12 : impulse response                       */
  int16_t y[],      /* (o)     : output vector                          */
  int16_t L         /* (i)     : vector size                            */
)
{
   int16_t i, n;
   int32_t s;

   for (n = 0; n < L; n++)
   {
     s = 0;
     for (i = 0; i <= n; i++)
       s = L_mac(s, x[i], h[n-i]);

     s    = L_shl(s, 3);                   /* h is in Q12 and saturation */
     y[n] = extract_h(s);
   }

   return;
}

/*-----------------------------------------------------*
 * procedure Syn_filt:                                 *
 *           ~~~~~~~~                                  *
 * Do the synthesis filtering 1/A(z).                  *
 *-----------------------------------------------------*/


void Syn_filt(
  int16_t a[],     /* (i) Q12 : a[m+1] prediction coefficients   (m=10)  */
  int16_t x[],     /* (i)     : input signal                             */
  int16_t y[],     /* (o)     : output signal                            */
  int16_t lg,      /* (i)     : size of filtering                        */
  int16_t mem[],   /* (i/o)   : memory associated with this filtering.   */
  int16_t update   /* (i)     : 0=no update, 1=update of memory.         */
)
{
  int16_t i, j;
  int32_t s;
  int16_t tmp[100];     /* This is usually done by memory allocation (lg+M) */
  int16_t *yy;

  /* Copy mem[] to yy[] */

  yy = tmp;

  for(i=0; i<M; i++)
  {
    *yy++ = mem[i];
  }

  /* Do the filtering. */

  for (i = 0; i < lg; i++)
  {
    s = L_mult(x[i], a[0]);
    for (j = 1; j <= M; j++)
      s = L_msu(s, a[j], yy[-j]);

    s = L_shl(s, 3);
    *yy++ = round(s);
  }

  for(i=0; i<lg; i++)
  {
    y[i] = tmp[i+M];
  }

  /* Update of memory if update==1 */

  if(update != 0)
     for (i = 0; i < M; i++)
     {
       mem[i] = y[lg-M+i];
     }

 return;
}

/*-----------------------------------------------------------------------*
 * procedure Residu:                                                     *
 *           ~~~~~~                                                      *
 * Compute the LPC residual  by filtering the input speech through A(z)  *
 *-----------------------------------------------------------------------*/

void Residu(
  int16_t a[],    /* (i) Q12 : prediction coefficients                     */
  int16_t x[],    /* (i)     : speech (values x[-m..-1] are needed         */
  int16_t y[],    /* (o)     : residual signal                             */
  int16_t lg      /* (i)     : size of filtering                           */
)
{
  int16_t i, j;
  int32_t s;

  for (i = 0; i < lg; i++)
  {
    s = L_mult(x[i], a[0]);
    for (j = 1; j <= M; j++)
      s = L_mac(s, a[j], x[i-j]);

    s = L_shl(s, 3);
    y[i] = round(s);
  }
  return;
}
