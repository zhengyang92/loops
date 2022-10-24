#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int gamma_tab[276], int HB[46][8][4], int c2, int idx, int c1,
    const int acos_icc_invq[8], int icc, int HA[46][8][4],
    const int alpha_tab[276], int iid)
{
  IACA_START for (icc = 0; icc < 8; icc++)
    {
      {
	int alpha, beta;
	int ca, sa, cb, sb;
	alpha = acos_icc_invq[icc];
	beta = (int) (((int64_t) alpha * 1518500250 + 0x40000000) >> 31);
	alpha >>= 1;
	beta = (int) (((int64_t) beta * (c1 - c2) + 0x40000000) >> 31);
	av_sincos_sf (beta + alpha, &sa, &ca);
	av_sincos_sf (beta - alpha, &sb, &cb);
	HA[iid][icc][0] = (int) (((int64_t) c2 * ca + 0x20000000) >> 30);
	HA[iid][icc][1] = (int) (((int64_t) c1 * cb + 0x20000000) >> 30);
	HA[iid][icc][2] = (int) (((int64_t) c2 * sa + 0x20000000) >> 30);
	HA[iid][icc][3] = (int) (((int64_t) c1 * sb + 0x20000000) >> 30);
      }
      {
	int alpha_int, gamma_int;
	int alpha_c_int, alpha_s_int, gamma_c_int, gamma_s_int;
	alpha_int = alpha_tab[idx];
	gamma_int = gamma_tab[idx];
	av_sincos_sf (alpha_int, &alpha_s_int, &alpha_c_int);
	av_sincos_sf (gamma_int, &gamma_s_int, &gamma_c_int);
	alpha_c_int =
	  (int) (((int64_t) alpha_c_int * 1518500250 + 0x20000000) >> 30);
	alpha_s_int =
	  (int) (((int64_t) alpha_s_int * 1518500250 + 0x20000000) >> 30);
	HB[iid][icc][0] =
	  (int) (((int64_t) alpha_c_int * gamma_c_int + 0x20000000) >> 30);
	HB[iid][icc][1] =
	  (int) (((int64_t) alpha_s_int * gamma_c_int + 0x20000000) >> 30);
	HB[iid][icc][2] =
	  -(int) (((int64_t) alpha_s_int * gamma_s_int + 0x20000000) >> 30);
	HB[iid][icc][3] =
	  (int) (((int64_t) alpha_c_int * gamma_s_int + 0x20000000) >> 30);
      } if (icc < 5 || icc > 6)
	idx++;
     } IACA_END
}
