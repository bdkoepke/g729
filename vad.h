/*
   ITU-T G.729A Annex B     ANSI-C Source Code
   Version 1.3    Last modified: August 1997
   Copyright (c) 1996, France Telecom, Rockwell International,
                       Universite de Sherbrooke.
   All rights reserved.
*/

#define     NP            12                  /* Increased LPC order */
#define     NOISE         0
#define     VOICE         1
#define     INIT_FRAME    32
#define     INIT_COUNT    20
#define     ZC_START      120
#define     ZC_END        200

void vad_init(void);

void vad(
         int16_t rc,
         int16_t *lsf, 
         int16_t *r_h,
         int16_t *r_l,
         int16_t exp_R0,
         int16_t *sigpp,
         int16_t frm_count,
         int16_t prev_marker,
         int16_t pprev_marker,
         int16_t *marker);

