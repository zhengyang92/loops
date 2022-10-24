#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int t1, int i, int s2, int s1, int tmp[18], int s0, int s3, int j,
    int *out, int *buf, const int icos36h[9], int *win, int t0, int t3,
    const int icos36[9], int t2)
{
  IACA_START for (j = 0; j < 4; j++)
    {
      t0 = tmp[i];
      t1 = tmp[i + 2];
      s0 = t1 + t0;
      s2 = t1 - t0;
      t2 = tmp[i + 1];
      t3 = tmp[i + 3];
      s1 = MULH ((2) * (t3 + t2), icos36h[j]);
      s3 = (((int64_t) (t3 - t2) * (int64_t) (icos36[8 - j])) >> (23));
      t0 = s0 + s1;
      t1 = s0 - s1;
      out[(9 + j) * 32] = MULH ((1) * (t1), win[9 + j]) + buf[4 * (9 + j)];
      out[(8 - j) * 32] = MULH ((1) * (t1), win[8 - j]) + buf[4 * (8 - j)];
      buf[4 * (9 + j)] =
	MULH ((1) * (t0),
	      win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + j]);
      buf[4 * (8 - j)] =
	MULH ((1) * (t0),
	      win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 8 - j]);
      t0 = s2 + s3;
      t1 = s2 - s3;
      out[(9 + 8 - j) * 32] =
	MULH ((1) * (t1), win[9 + 8 - j]) + buf[4 * (9 + 8 - j)];
      out[j * 32] = MULH ((1) * (t1), win[j]) + buf[4 * (j)];
      buf[4 * (9 + 8 - j)] =
	MULH ((1) * (t0),
	      win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + 8 - j]);
      buf[4 * (j)] =
	MULH ((1) * (t0),
	      win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + j]);
      i += 4;
     } IACA_END
}
