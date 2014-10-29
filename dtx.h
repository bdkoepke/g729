/*
   ITU-T G.729A Annex B     ANSI-C Source Code
   Version 1.3    Last modified: August 1997
   Copyright (c) 1996, France Telecom, Rockwell International,
                       Universite de Sherbrooke.
   All rights reserved.
*/

/*--------------------------------------------------------------------------*
 * Prototypes for DTX/CNG                                                   *
 *--------------------------------------------------------------------------*/

/* Encoder DTX/CNG functions */
void Init_Cod_cng(void);
void Cod_cng(
  int16_t *exc,          /* (i/o) : excitation array                     */
  int16_t pastVad,       /* (i)   : previous VAD decision                */
  int16_t *lsp_old_q,    /* (i/o) : previous quantized lsp               */
  int16_t *Aq,           /* (o)   : set of interpolated LPC coefficients */
  int16_t *ana,          /* (o)   : coded SID parameters                 */
  int16_t freq_prev[MA_NP][M],
                        /* (i/o) : previous LPS for quantization        */
  int16_t *seed          /* (i/o) : random generator seed                */
);
void Update_cng(
  int16_t *r_h,      /* (i) :   MSB of frame autocorrelation        */
  int16_t exp_r,     /* (i) :   scaling factor associated           */
  int16_t Vad        /* (i) :   current Vad decision                */
);

/* SID gain Quantization */
void Qua_Sidgain(
  int16_t *ener,     /* (i)   array of energies                   */
  int16_t *sh_ener,  /* (i)   corresponding scaling factors       */
  int16_t nb_ener,   /* (i)   number of energies or               */
  int16_t *enerq,    /* (o)   decoded energies in dB              */
  int16_t *idx       /* (o)   SID gain quantization index         */
);

/* CNG excitation generation */
void Calc_exc_rand(
  int16_t cur_gain,      /* (i)   :   target sample gain                 */
  int16_t *exc,          /* (i/o) :   excitation array                   */
  int16_t *seed,         /* (i)   :   current Vad decision               */
  int32_t flag_cod         /* (i)   :   encoder/decoder flag               */
);

/* SID LSP Quantization */
void Get_freq_prev(int16_t x[MA_NP][M]);
void Update_freq_prev(int16_t x[MA_NP][M]);
void Get_decfreq_prev(int16_t x[MA_NP][M]);
void Update_decfreq_prev(int16_t x[MA_NP][M]);

/* Decoder CNG generation */
void Init_Dec_cng(void);
void Dec_cng(
  int16_t past_ftyp,     /* (i)   : past frame type                      */
  int16_t sid_sav,       /* (i)   : energy to recover SID gain           */
  int16_t sh_sid_sav,    /* (i)   : corresponding scaling factor         */
  int16_t *parm,         /* (i)   : coded SID parameters                 */
  int16_t *exc,          /* (i/o) : excitation array                     */
  int16_t *lsp_old,      /* (i/o) : previous lsp                         */
  int16_t *A_t,          /* (o)   : set of interpolated LPC coefficients */
  int16_t *seed,         /* (i/o) : random generator seed                */
  int16_t freq_prev[MA_NP][M]
                        /* (i/o) : previous LPS for quantization        */
);
int16_t read_frame(FILE *f_serial, int16_t *parm);

/*--------------------------------------------------------------------------*
 * Constants for DTX/CNG                                                    *
 *--------------------------------------------------------------------------*/

/* DTX constants */
#define FLAG_COD        (int32_t)1
#define FLAG_DEC        (int32_t)0
#define INIT_SEED       11111
#define FR_SID_MIN      3
#define NB_SUMACF       3
#define NB_CURACF       2
#define NB_GAIN         2
#define FRAC_THRESH1    4855
#define FRAC_THRESH2    3161
#define A_GAIN0         28672

#define SIZ_SUMACF      (NB_SUMACF * MP1)
#define SIZ_ACF         (NB_CURACF * MP1)
#define A_GAIN1         4096    /* 32768L - A_GAIN0 */

#define RATE_8000       80      /* Full rate  (8000 bit/s)       */
#define RATE_SID        15      /* SID                           */
#define RATE_0           0      /* 0 bit/s rate                  */

/* CNG excitation generation constant */
                                        /* alpha = 0.5 */
#define FRAC1           19043           /* (sqrt(40)xalpha/2 - 1) * 32768 */
#define K0              24576           /* (1 - alpha ** 2) in Q15        */
#define G_MAX           5000

