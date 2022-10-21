#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef int32_t MPA_INT;
typedef int16_t OUT_INT;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t incr, MPA_INT * synth_buf, int64_t sum2, const MPA_INT * w,
    int64_t sum, const MPA_INT * p, OUT_INT * samples, const MPA_INT * w2,
    int j, OUT_INT * samples2)
{
  for (j = 1; j < 16; j++)
     { IACA_START
      sum2 = 0;
      p = synth_buf + 16 + j;
      {
	int tmp;
	tmp = p[0 * 64];
	((sum) += ((int64_t) ((w)[0 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[0 * 64]) * (int64_t) (tmp)));
	tmp = p[1 * 64];
	((sum) += ((int64_t) ((w)[1 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[1 * 64]) * (int64_t) (tmp)));
	tmp = p[2 * 64];
	((sum) += ((int64_t) ((w)[2 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[2 * 64]) * (int64_t) (tmp)));
	tmp = p[3 * 64];
	((sum) += ((int64_t) ((w)[3 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[3 * 64]) * (int64_t) (tmp)));
	tmp = p[4 * 64];
	((sum) += ((int64_t) ((w)[4 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[4 * 64]) * (int64_t) (tmp)));
	tmp = p[5 * 64];
	((sum) += ((int64_t) ((w)[5 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[5 * 64]) * (int64_t) (tmp)));
	tmp = p[6 * 64];
	((sum) += ((int64_t) ((w)[6 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[6 * 64]) * (int64_t) (tmp)));
	tmp = p[7 * 64];
	((sum) += ((int64_t) ((w)[7 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2)[7 * 64]) * (int64_t) (tmp)));
      };
      p = synth_buf + 48 - j;
      {
	int tmp;
	tmp = p[0 * 64];
	((sum) -= ((int64_t) ((w + 32)[0 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[0 * 64]) * (int64_t) (tmp)));
	tmp = p[1 * 64];
	((sum) -= ((int64_t) ((w + 32)[1 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[1 * 64]) * (int64_t) (tmp)));
	tmp = p[2 * 64];
	((sum) -= ((int64_t) ((w + 32)[2 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[2 * 64]) * (int64_t) (tmp)));
	tmp = p[3 * 64];
	((sum) -= ((int64_t) ((w + 32)[3 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[3 * 64]) * (int64_t) (tmp)));
	tmp = p[4 * 64];
	((sum) -= ((int64_t) ((w + 32)[4 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[4 * 64]) * (int64_t) (tmp)));
	tmp = p[5 * 64];
	((sum) -= ((int64_t) ((w + 32)[5 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[5 * 64]) * (int64_t) (tmp)));
	tmp = p[6 * 64];
	((sum) -= ((int64_t) ((w + 32)[6 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[6 * 64]) * (int64_t) (tmp)));
	tmp = p[7 * 64];
	((sum) -= ((int64_t) ((w + 32)[7 * 64]) * (int64_t) (tmp)));
	((sum2) -= ((int64_t) ((w2 + 32)[7 * 64]) * (int64_t) (tmp)));
      };
      *samples = round_sample (&sum);
      samples += incr;
      sum += sum2;
      *samples2 = round_sample (&sum);
      samples2 -= incr;
      w++;
      w2--;
} IACA_END }
