#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int *in1, unsigned int *tmp1, unsigned int t3, unsigned int t0,
    unsigned int t1, unsigned int *in, unsigned int t2, unsigned int tmp[18],
    int j)
{
  for (j = 0; j < 2; j++)
     { IACA_START
      tmp1 = tmp + j;
      in1 = in + j;
      t2 = in1[2 * 4] + in1[2 * 8] - in1[2 * 2];
      t3 = in1[2 * 0] + (((int) (in1[2 * 6])) >> (1));
      t1 = in1[2 * 0] - in1[2 * 6];
      tmp1[6] = t1 - (((int) (t2)) >> (1));
      tmp1[16] = t1 + t2;
      t0 =
	MULH ((2) * (in1[2 * 2] + in1[2 * 4]),
	      ((int) ((0.93969262078590838405 / 2) * (1LL << 32) + 0.5)));
      t1 =
	MULH ((1) * (in1[2 * 4] - in1[2 * 8]),
	      -2 *
	      ((int) ((0.17364817766693034885 / 2) * (1LL << 32) + 0.5)));
      t2 =
	MULH ((2) * (in1[2 * 2] + in1[2 * 8]),
	      -((int) ((0.76604444311897803520 / 2) * (1LL << 32) + 0.5)));
      tmp1[10] = t3 - t0 - t2;
      tmp1[2] = t3 + t0 + t1;
      tmp1[14] = t3 + t2 - t1;
      tmp1[4] =
	MULH ((2) * (in1[2 * 5] + in1[2 * 7] - in1[2 * 1]),
	      -((int) ((0.86602540378443864676 / 2) * (1LL << 32) + 0.5)));
      t2 =
	MULH ((2) * (in1[2 * 1] + in1[2 * 5]),
	      ((int) ((0.98480775301220805936 / 2) * (1LL << 32) + 0.5)));
      t3 =
	MULH ((1) * (in1[2 * 5] - in1[2 * 7]),
	      -2 *
	      ((int) ((0.34202014332566873304 / 2) * (1LL << 32) + 0.5)));
      t0 =
	MULH ((2) * (in1[2 * 3]),
	      ((int) ((0.86602540378443864676 / 2) * (1LL << 32) + 0.5)));
      t1 =
	MULH ((2) * (in1[2 * 1] + in1[2 * 7]),
	      -((int) ((0.64278760968653932632 / 2) * (1LL << 32) + 0.5)));
      tmp1[0] = t2 + t3 + t0;
      tmp1[12] = t2 + t1 - t0;
      tmp1[8] = t3 - t1 - t0;
} IACA_END }
