/*___________________________________________________________________________
 |                                                                           |
 |   Constants and Globals                                                   |
 |___________________________________________________________________________|
*/
extern int32_t Overflow;
extern int32_t Carry;

#define MAX_32 (int32_t)0x7fffffffL
#define MIN_32 (int32_t)0x80000000L

#define MAX_16 (int16_t)0x7fff
#define MIN_16 (int16_t)0x8000


/*___________________________________________________________________________
 |                                                                           |
 |   Operators prototypes                                                    |
 |___________________________________________________________________________|
*/

int16_t sature(int32_t L_var1);             /* Limit to 16 bits,    1 */
int16_t add(int16_t var1, int16_t var2);     /* Short add,           1 */
int16_t sub(int16_t var1, int16_t var2);     /* Short sub,           1 */
int16_t abs_s(int16_t var1);                /* Short abs,           1 */
int16_t shl(int16_t var1, int16_t var2);     /* Short shift left,    1 */
int16_t shr(int16_t var1, int16_t var2);     /* Short shift right,   1 */
int16_t mult(int16_t var1, int16_t var2);    /* Short mult,          1 */
int32_t L_mult(int16_t var1, int16_t var2);  /* Long mult,           1 */
int16_t negate(int16_t var1);               /* Short negate,        1 */
int16_t extract_h(int32_t L_var1);          /* Extract high,        1 */
int16_t extract_l(int32_t L_var1);          /* Extract low,         1 */
int16_t _round(int32_t L_var1);              /* Round,               1 */
int32_t L_mac(int32_t L_var3, int16_t var1, int16_t var2); /* Mac,    1 */
int32_t L_msu(int32_t L_var3, int16_t var1, int16_t var2); /* Msu,    1 */
int32_t L_macNs(int32_t L_var3, int16_t var1, int16_t var2);/* Mac without sat, 1*/
int32_t L_msuNs(int32_t L_var3, int16_t var1, int16_t var2);/* Msu without sat, 1*/

int32_t L_add(int32_t L_var1, int32_t L_var2);   /* Long add,        2 */
int32_t L_sub(int32_t L_var1, int32_t L_var2);   /* Long sub,        2 */
int32_t L_add_c(int32_t L_var1, int32_t L_var2); /*Long add with c,  2 */
int32_t L_sub_c(int32_t L_var1, int32_t L_var2); /*Long sub with c,  2 */
int32_t L_negate(int32_t L_var1);               /* Long negate,     2 */
int16_t mult_r(int16_t var1, int16_t var2);  /* Mult with round,     2 */
int32_t L_shl(int32_t L_var1, int16_t var2); /* Long shift left,     2 */
int32_t L_shr(int32_t L_var1, int16_t var2); /* Long shift right,    2 */
int16_t shr_r(int16_t var1, int16_t var2);/* Shift right with round, 2 */
int16_t mac_r(int32_t L_var3, int16_t var1, int16_t var2);/* Mac with rounding, 2*/
int16_t msu_r(int32_t L_var3, int16_t var1, int16_t var2);/* Msu with rounding, 2*/
int32_t L_deposit_h(int16_t var1);       /* 16 bit var1 -> MSB,     2 */
int32_t L_deposit_l(int16_t var1);       /* 16 bit var1 -> LSB,     2 */

int32_t L_shr_r(int32_t L_var1, int16_t var2);/* Long shift right with round,  3*/
int32_t L_abs(int32_t L_var1);            /* Long abs,              3 */

int32_t L_sat(int32_t L_var1);            /* Long saturation,       4 */

int16_t norm_s(int16_t var1);             /* Short norm,           15 */

int16_t div_s(int16_t var1, int16_t var2); /* Short division,       18 */

int16_t norm_l(int32_t L_var1);           /* Long norm,            30 */

