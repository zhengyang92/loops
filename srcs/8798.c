#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int s2, unsigned int t3, int i, unsigned int s3, unsigned int s0,
    unsigned int s1, unsigned int t1, unsigned int t0, unsigned int tmp[18],
    unsigned int t2, int *buf, int j, int *out, const int icos36h[9],
    int *win, const int icos36[9])
{
  for (j = 0; j < 4; j++)
    {
      t0 = tmp[i];
      t1 = tmp[i + 2];
      s0 = t1 + t0;
      s2 = t1 - t0;
      t2 = tmp[i + 1];
      t3 = tmp[i + 3];
      s1 = MULH ((2) * (t3 + t2), icos36h[j]);
      s3 =
	(((int64_t) ((int) (t3 - t2)) * (int64_t) ((icos36[8 - j]))) >> (23));
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
}}
